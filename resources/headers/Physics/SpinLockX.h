#ifndef SPINLOCKX_H
#define SPINLOCKX_H

/****************************************

Spinlock is similar to a mutex, but appears to be faster because of atomic operations

by Alexander Thoma
@(#)Author:
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

#include <atomic>
#include <thread>

namespace phyX
{
	namespace detail
	{
		/*
		Spinlock is similar to a mutex, but appears to be faster because of atomic operations
		*/
		class SpinLockX
		{
		public:
			SpinLockX();
			~SpinLockX();

			//get the lock
			void lock();
			//try to get the lock
			bool try_lock();
			//release the lock
			void unlock();

		private:
			std::atomic_flag m_flag;
			const std::chrono::microseconds m_waitingtime;
		};
	}
}

#endif