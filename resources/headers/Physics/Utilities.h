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

#include "CPhysiX.h"

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

	//copy of vektor vec and free choice of w value
	Vektoria::CHVector inline CopyVectorInfos(Vektoria::CHVector const& vec, float const& wValue)
	{
		return Vektoria::CHVector(vec.x, vec.y, vec.z, wValue);
	}

	//projects vector vec onto vector target
	Vektoria::CHVector inline ProjectVector(Vektoria::CHVector& vec, Vektoria::CHVector& target)
	{
		target.MakeDirection();
		return CopyVectorInfos(target * ((target * vec) / target.LengthSquare()), 1.0f);
	}

	//returns true if both matrices are the same
	bool CompareCHMat(Vektoria::CHMat* m1, Vektoria::CHMat* m2);

	Vektoria::CHVector inline MultipleScalar(Vektoria::CHVector const& vec_left, Vektoria::CHVector const& vec_right)
	{
		return Vektoria::CHVector(vec_left.x * vec_right.x, vec_left.y * vec_right.y, vec_left.z * vec_right.z, 0.f);
	}

	//returns a vektor that has a value of one for every value of the origin vector that is not zero
	Vektoria::CHVector inline AbsOne(Vektoria::CHVector const& vec)
	{
		return Vektoria::CHVector(static_cast<float>(abs(vec.x) > phyX::detail::FLOATCOMPENSATION), static_cast<float>(abs(vec.y) > phyX::detail::FLOATCOMPENSATION), static_cast<float>(abs(vec.z) > phyX::detail::FLOATCOMPENSATION), 0.f);
	}
}

Vektoria::CHVector operator- (const Vektoria::CHVector& lhs, const Vektoria::CHVector& rhs);
Vektoria::CHVector operator+ (const Vektoria::CHVector& lhs, const Vektoria::CHVector& rhs);
Vektoria::CHMat operator* (Vektoria::CHMat& mat, float factor);