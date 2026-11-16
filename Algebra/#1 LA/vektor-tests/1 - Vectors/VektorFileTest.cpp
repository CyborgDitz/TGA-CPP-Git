#include "stdafx.h"
#include "CppUnitTest.h"

#include "Student Code/Vector.h"
#include "Student Code/Vector.h" //Double include to check pragma once use

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Vector4f = CommonUtilities::Vector4<float>;
using Vector4d = CommonUtilities::Vector4<double>;
using Vector4i = CommonUtilities::Vector4<int>;

using Vector3f = CommonUtilities::Vector3<float>;
using Vector3d = CommonUtilities::Vector3<double>;
using Vector3i = CommonUtilities::Vector3<int>;

using Vector2f = CommonUtilities::Vector2<float>;
using Vector2d = CommonUtilities::Vector2<double>;
using Vector2i = CommonUtilities::Vector2<int>;


namespace Vectors
{
	TEST_CLASS(VectorFile)
	{
	public:
		// Compilation test, if this file compiles it has passed
		TEST_METHOD(V_FileValid)
		{
			{
				Vector2d d;
				Vector2f f;
				Vector2i i;
			}
			{
				Vector3d d;
				Vector3f f;
				Vector3i i;
			}
			{
				Vector4d d;
				Vector4f f;
				Vector4i i;
			}
		}
	};
}