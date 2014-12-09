#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <list>
#include <functional>

/****************************************

Callback class
It's a container for collecting callbacks and execute them.

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

namespace phyX
{
	namespace detail
	{
		//callback collection
		template<typename ...Args>
		class Callbacks
		{
		public:
			Callbacks()
			{

			}
			~Callbacks()
			{
				_callbacks.clear();
			}

			//calls all callbacks
			void operator()(Args... args)
			{
				for each (std::function<void(Args...)> call in _callbacks)
					call(args...);

			}

			//adds a function to the callbacks
			void operator+= (std::function<void(Args...)> callback)
			{
				_callbacks.push_back(callback);
			}

			//remove function from callbacks
			void operator-= (std::function<void(Args...)> callback)
			{
				for (auto iter = _callbacks.begin(); iter != _callbacks.end(); ++iter)
				{
					if (callback.target_type().hash_code() == (*iter).target_type().hash_code())
					{
						_callbacks.erase(iter);
						break;
					}
				}
			}

		private:

			//container of all callbacks
			std::list<std::function<void(Args...)>> _callbacks;

		};

	}
}

#endif