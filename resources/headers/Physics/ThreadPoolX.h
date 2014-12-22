#ifndef THREADPOOLX_H
#define THREADPOOLX_H

/****************************************

A pool of threads, that handles all your tasks you pass

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
****************************************/


#include <vector>
#include <stack>
#include <thread>
#include <atomic>
#include <functional>
#include <mutex>

#include "SpinLockX.h"

namespace phyX
{
	namespace detail
	{
		//A pool of threads, that handles all your tasks you pass
		class ThreadPoolX
		{

		public:
			ThreadPoolX(unsigned int size);
			~ThreadPoolX();

			//add a task to the workers list
			template<typename ...Args>
			void addTask(void(*func)(Args...), Args... args);

			//add a task to the workers list
			template<class Class, typename ...Args>
			void addTask(void(Class::*func)(Args...), Class* c, Args... args);

			//add multiple tasks to the workers list by passing the tasks in a vector
			void addMultipleTasks(std::vector<std::function<void()>>& tasks);

			//wait until all tasks are done
			void WaitForTasksDone();

		private:

			//Workers of the pool, every worker is a thread handling the pool tasks
			class Worker
			{
			public:
				Worker(ThreadPoolX* pool);
				~Worker();

			private:
				std::thread* m_process;
				ThreadPoolX* m_pool;
				std::function<void()> m_myTask;
				const std::chrono::microseconds m_duration;

				void DoWork();
				bool GrabTask();
			};

			const unsigned int m_size;
			bool m_running;
			std::vector<Worker*> m_workers;

			std::vector<std::function<void()>> m_tasks;
			std::atomic<int> m_tasksToDo;
			SpinLockX m_taskLock;

		};

		template<typename ...Args>
		void ThreadPoolX::addTask(void(*func)(Args...), Args... args)
		{
			m_taskLock.lock();
			m_tasks.insert(m_tasks.begin(), std::bind(func, args...));
			m_taskLock.unlock();
			++m_tasksToDo;
		}


		template<class Class, typename ...Args>
		void ThreadPoolX::addTask(void(Class::*func)(Args...), Class* c, Args... args)
		{
			m_taskLock.lock();
			m_tasks.insert(m_tasks.begin(), std::bind(func, c, args...));
			m_taskLock.unlock();
			++m_tasksToDo;
		}

	}
}
#endif