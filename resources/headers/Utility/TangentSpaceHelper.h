#pragma once


#include "Root.h"

namespace rs {

	class TangentSpaceHelper
	{
	public:
		static void calculateTangentsAndBitangents(Vektoria::CGeo* geo);

	private:

		TangentSpaceHelper();
		~TangentSpaceHelper();

		struct Face {
			Vektoria::CVertex* v1;
			Vektoria::CVertex* v2;
			Vektoria::CVertex* v3;
		};

		struct Vec2 {
			float X;
			float Y;
		};

		static void calculateTangents(std::vector<Face>& faces);
	};

}