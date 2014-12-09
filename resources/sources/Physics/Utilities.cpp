#include "Physics\Utilities.h"

/*****************************************

#Utilities.cpp

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

#include <Fcntl.h>
#include <Root.h>
#include <math.h>
#include <iterator>

namespace phyX_utilties
{
	void CreateConsole()
	{

		AllocConsole();

		HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
		int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
		FILE* hf_out = _fdopen(hCrt, "w");
		setvbuf(hf_out, NULL, _IONBF, 1);
		*stdout = *hf_out;

		HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
		hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
		FILE* hf_in = _fdopen(hCrt, "r");
		setvbuf(hf_in, NULL, _IONBF, 128);
		*stdin = *hf_in;
	}

	std::string CHVector2String(Vektoria::CHVector* vec){

		std::ostringstream stream;
		stream << "(" << vec->x << "|" << vec->y << "|" << vec->z << ")";

		return stream.str();
	}

	bool CompareCHMat(Vektoria::CHMat* m1, Vektoria::CHMat* m2){

		float *ptr = &m1->m_fx00, *ptr2 = &m2->m_fx00;

		for (int i = 0; i < 16; ++i)
		{
			if (*ptr != *ptr2)
				return false;

			++ptr, ++ptr2;
		}

		return true;
	}

	Vektoria::CHVector ProjectVector(Vektoria::CHVector vec, Vektoria::CHVector target)
	{
		target.MakeDirection();
		return CopyVectorInfos(target * ((target * vec) / target.LengthSquare()), 1.0f);
	}

	Vektoria::CHVector CopyVectorInfos(Vektoria::CHVector vec, float wValue)
	{
		return Vektoria::CHVector(vec.x, vec.y, vec.z, wValue);
	}

}

Vektoria::CHVector operator- (const Vektoria::CHVector& lhs, const Vektoria::CHVector& rhs)
{
	return Vektoria::CHVector(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vektoria::CHVector operator+ (const Vektoria::CHVector& lhs, const Vektoria::CHVector& rhs)
{
	return Vektoria::CHVector(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vektoria::CHMat operator* (Vektoria::CHMat& mat, float factor)
{
	Vektoria::CHMat mRet = mat;
	mRet.m_fx01 *= factor;
	mRet.m_fx02 *= factor;
	mRet.m_fx03 *= factor;
	mRet.m_fx10 *= factor;
	mRet.m_fx12 *= factor;
	mRet.m_fx13 *= factor;
	mRet.m_fx20 *= factor;
	mRet.m_fx21 *= factor; 
	mRet.m_fx23 *= factor;
	mRet.m_fx30 *= factor;
	mRet.m_fx31 *= factor;
	mRet.m_fx32 *= factor;

	return mRet;
}