#include "Physics\SpinLockX.h"

/*****************************************

#Spinlock.cpp

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

namespace phyX
{
	namespace detail
	{
		SpinLockX::SpinLockX() 
			: m_waitingtime(std::chrono::microseconds(100))
		{
			m_flag._My_flag = ATOMIC_FLAG_INIT;
		}

		SpinLockX::~SpinLockX()
		{
		}

		void SpinLockX::lock()
		{
			while (m_flag.test_and_set(std::memory_order_acquire)){
				std::this_thread::yield();
				std::this_thread::sleep_for(m_waitingtime);
			}
		}

		bool SpinLockX::try_lock()
		{
			return m_flag.test_and_set(std::memory_order_acquire);
		}

		void SpinLockX::unlock()
		{
			m_flag.clear(std::memory_order_release);
		}
	}
}