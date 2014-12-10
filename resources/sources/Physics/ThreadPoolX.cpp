#include "ThreadPoolX.h"

/*****************************************

#ThreadPoolX.cpp

@(#)Author: Alexander Thoma

▄████▄  ▒█████  ▓█████▄ ▓█████ ▒██   ██▒
▒██▀ ▀█ ▒██▒  ██▒▒██▀ ██▌▓█   ▀ ▒▒ █ █ ▒░
▒▓█    ▄▒██░  ██▒░██   █▌▒███   ░░  █   ░
▒▓▓▄ ▄██▒██   ██░░▓█▄   ▌▒▓█  ▄  ░ █ █ ▒
▒ ▓███▀ ░ ████▓▒░░▒████▓ ░▒████▒▒██▒ ▒██▒
░ ░▒ ▒  ░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░▒▒ ░ ░▓ ░
░  ▒    ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░░░   ░▒ ░
░       ░ ░ ░ ▒   ░ ░  ░    ░    ░    ░
░ ░         ░ ░     ░       ░  ░ ░    ░
░
*****************************************/

#include <iostream>


namespace phyX
{
	namespace detail
	{
		ThreadPoolX::ThreadPoolX(unsigned int size) : m_size(size), m_running(true)
		{
			m_tasksToDo.store(0);

			for (unsigned int i = 0; i < m_size; ++i)
				m_workers.push_back(new Worker(this));
		}

		ThreadPoolX::~ThreadPoolX()
		{
			m_running = false;
			for (unsigned int i = 0; i < m_size; ++i)
				delete m_workers.at(i);
		}

		void ThreadPoolX::addMultipleTasks(std::vector<std::function<void()>>& tasks)
		{
			m_taskLock.lock();
			m_tasks.insert(m_tasks.end(), tasks.begin(), tasks.end());
			m_tasksToDo.fetch_add(tasks.size());
			m_taskLock.unlock();
		}

		void ThreadPoolX::WaitForTasksDone()
		{
			while (m_tasksToDo > 0)
				std::this_thread::sleep_for(std::chrono::microseconds(100));
		}

		/******************************

			ThreadPoolX::Worker

			******************************/

		ThreadPoolX::Worker::Worker(ThreadPoolX* pool) : m_pool(pool), m_duration(std::chrono::microseconds(10))
		{
			m_process = new std::thread(&ThreadPoolX::Worker::DoWork, this);
		}

		ThreadPoolX::Worker::~Worker()
		{
			if (m_process->joinable())
				m_process->join();

			delete m_process;
#ifdef _DEBUG
			std::cout << "Worker finished" << std::endl;
#endif
		}

		void ThreadPoolX::Worker::DoWork()
		{
			while (m_pool->m_running)
			{
				while (GrabTask())
				{
					m_myTask();
					--m_pool->m_tasksToDo;
				}
				std::this_thread::yield();
				std::this_thread::sleep_for(m_duration);
			}
		}

		bool ThreadPoolX::Worker::GrabTask()
		{
			m_pool->m_taskLock.lock();

			if (m_pool->m_tasks.size() > 0)
			{
				m_myTask = m_pool->m_tasks.back();
				m_pool->m_tasks.pop_back();
				m_pool->m_taskLock.unlock();
				return true;
			}

			m_pool->m_taskLock.unlock();
			return false;

		}
	}
}