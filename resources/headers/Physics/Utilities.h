#pragma once
/*****************************************
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
#include <HVector.h>
#include <HMat.h>
#include <functional>

namespace phyX_utilties
{
	//creates console with std::out and std::in
	void CreateConsole();
	
	//converts memberfunctionpointer to function pointer
	template<class Class, typename ...Args>
	inline std::function<void(Args...)> Member2FuncPtr(void(Class::*func)(Args...), Class* obj)
	{
		return [=](Args... args){(obj->*func)(args...);};
	}
			
	//vector to string
	std::string CHVector2String(Vektoria::CHVector* vec);

	//projects vector vec onto vector target
	Vektoria::CHVector ProjectVector(Vektoria::CHVector vec, Vektoria::CHVector target);

	//copy of vektor vec and free choice of w value
	Vektoria::CHVector CopyVectorInfos(Vektoria::CHVector vec, float wValue);

	//returns true if both matrices are the same
	bool CompareCHMat(Vektoria::CHMat* m1, Vektoria::CHMat* m2);
}

Vektoria::CHVector operator- (const Vektoria::CHVector& lhs, const Vektoria::CHVector& rhs);
Vektoria::CHVector operator+ (const Vektoria::CHVector& lhs, const Vektoria::CHVector& rhs);
Vektoria::CHMat operator* (Vektoria::CHMat& mat, float factor);