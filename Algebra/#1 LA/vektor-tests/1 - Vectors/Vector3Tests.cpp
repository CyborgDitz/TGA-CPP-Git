#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <chrono>

#include "Shared/Utility.h"
#include "Student Code/Vector3.h"
#include "Student Code/Vector3.h"//Double include to check pragma once use

/// <summary>
/// This is a hack to emulate the TGA vector for the task of convertion
/// It only works because they happen to have the same name
/// </summary>
//namespace Tga
//{
//	template<class T>
//	class Vector3
//	{
//	public:
//		T x;
//		T y;
//		T z;
//		Vector3() :x(T(0)), y(T(0)), z(T(0)) {}
//		Vector3(const T aX, const T aY, const T aZ) :x(aX), y(aY), z(aZ) {}
//	};
//}
using TgaVectorf = Tga::Vector3<float>;
using TgaVectord = Tga::Vector3<double>;
using TgaVectori = Tga::Vector3<int>;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Vector3f = CommonUtilities::Vector3<float>;
using Vector3d = CommonUtilities::Vector3<double>;
using Vector3i = CommonUtilities::Vector3<int>;

namespace Vectors
{
	TEST_CLASS(Vector3Test)
	{
		void TestVector3(const Vector3f& aExpected, const Vector3f& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, ourToleranceF, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, ourToleranceF, aMessageTemplate);
			Assert::AreEqual(aExpected.z, aResult.z, ourToleranceF, aMessageTemplate);

		}

		void TestVector3(const Vector3d& aExpected, const Vector3d& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, ourToleranceD, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, ourToleranceD, aMessageTemplate);
			Assert::AreEqual(aExpected.z, aResult.z, ourToleranceD, aMessageTemplate);

		}

		void TestVector3(const Vector3i& aExpected, const Vector3i& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, aMessageTemplate);
			Assert::AreEqual(aExpected.z, aResult.z, aMessageTemplate);

		}
	public:
		// Testing if all neccessary const:s are 
		// declared, This is a compile time test
		TEST_METHOD(V3_Const)
		{
			const float x = 3.1459f;
			const float y = 1.4392f;
			const float z = -2.4392f;
			const float s = 41.7942f;
			const Vector3f zero;
			const Vector3f lhs(x, y, z);
			const Vector3f rhs(x, y, z);
			Vector3f mutableVector(rhs);
			mutableVector = lhs;
			Vector3d vectord = lhs.ToType<double>();
			Tga::Vector3<float> tgavectorf = lhs.ToTga();
			float mutableFloat;
			mutableVector = -rhs;
			mutableFloat = rhs.LengthSqr();
			mutableFloat = rhs.Length();
			mutableVector = lhs.GetNormalized();
			mutableVector.Normalize(); 
			mutableFloat = lhs.Dot(rhs);
			mutableVector = lhs.Cross(rhs);
			mutableVector = lhs + rhs;
			mutableVector = lhs - rhs;
			mutableVector = lhs * s;
			mutableVector = s * rhs;
			mutableVector = lhs * rhs;
			mutableVector = lhs / s;
			mutableVector += lhs;
			mutableVector -= lhs;
			mutableVector *= s;
			mutableVector /= s;
		}
		TEST_METHOD(V3_Size)
		{
			Vector3f fvector;
			Vector3i ivector;
			Vector3d dvector;
			Assert::IsTrue(sizeof(float) * 3 == sizeof(fvector), L"Vector 3 float has a different size than expected");
			Assert::IsTrue(sizeof(double) * 3 == sizeof(dvector), L"Vector 3 double has a different size than expected");
			Assert::IsTrue(sizeof(int) * 3 == sizeof(ivector), L"Vector 3 int has a different size than expected");
		}
		TEST_METHOD(V3_Default_Constructor)
		{
			// Testing Vector3<float> default initialisation
			Vector3f noInitF;

			Assert::AreEqual(0.0f, noInitF.x, L"Default initialisation: Element x of Vector3<float> is not initialised properly.");
			Assert::AreEqual(0.0f, noInitF.y, L"Default initialisation: Element y of Vector3<float> is not initialised properly.");
			Assert::AreEqual(0.0f, noInitF.z, L"Default initialisation: Element z of Vector3<float> is not initialised properly.");

			// Testing Vector3<double> default initialisation
			Vector3d noInitD;

			Assert::AreEqual(0.0, noInitD.x, L"Default initialisation: Element x of Vector3<double> is not initialised properly.");
			Assert::AreEqual(0.0, noInitD.y, L"Default initialisation: Element y of Vector3<double> is not initialised properly.");
			Assert::AreEqual(0.0, noInitD.z, L"Default initialisation: Element z of Vector3<double> is not initialised properly.");

			// Testing Vector3<int> default initialisation
			Vector3i noInitI;

			Assert::AreEqual(0, noInitI.x, L"Default initialisation: Element x of Vector3<int> is not initialised properly.");
			Assert::AreEqual(0, noInitI.y, L"Default initialisation: Element y of Vector3<int> is not initialised properly.");
			Assert::AreEqual(0, noInitI.z, L"Default initialisation: Element z of Vector3<int> is not initialised properly.");
		}

		TEST_METHOD(V3_Constructor)
		{
			// Testing Vector3<float> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				float rndX = TestUtility::GetRandomFloat();
				float rndY = TestUtility::GetRandomFloat();
				float rndZ = TestUtility::GetRandomFloat();
				Vector3f initF(rndX, rndY, rndZ);

				Assert::AreEqual(rndX, initF.x, L"Random initialisation: Element x of Vector3<float> is not initialised properly.");
				Assert::AreEqual(rndY, initF.y, L"Random initialisation: Element y of Vector3<float> is not initialised properly.");
				Assert::AreEqual(rndZ, initF.z, L"Random initialisation: Element z of Vector3<float> is not initialised properly.");
			}

			// Testing Vector3<double> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				double rndX = TestUtility::GetRandomInt();
				double rndY = TestUtility::GetRandomInt();
				double rndZ = TestUtility::GetRandomInt();
				Vector3d initD(rndX, rndY, rndZ);

				Assert::AreEqual(rndX, initD.x, L"Random initialisation: Element x of Vector3<double> is not initialised properly.");
				Assert::AreEqual(rndY, initD.y, L"Random initialisation: Element y of Vector3<double> is not initialised properly.");
				Assert::AreEqual(rndZ, initD.z, L"Random initialisation: Element z of Vector3<double> is not initialised properly.");
			}

			// Testing Vector<int> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				int rndX = TestUtility::GetRandomInt();
				int rndY = TestUtility::GetRandomInt();
				int rndZ = TestUtility::GetRandomInt();
				Vector3i initI(rndX, rndY, rndZ);

				Assert::AreEqual(rndX, initI.x, L"Random initialisation: Element x of Vector3<int> is not initialised properly.");
				Assert::AreEqual(rndY, initI.y, L"Random initialisation: Element y of Vector3<int> is not initialised properly.");
				Assert::AreEqual(rndZ, initI.z, L"Random initialisation: Element z of Vector3<int> is not initialised properly.");
			}
		}

		// Compiler generated version as stated in the assignment description, test included for reference and completeness
		TEST_METHOD(V3_Copy_Constructor)
		{
			// Testing Vector3<float> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				float rndX = TestUtility::GetRandomFloat();
				float rndY = TestUtility::GetRandomFloat();
				float rndZ = TestUtility::GetRandomFloat();
				Vector3f left(rndX, rndY, rndZ);
				Vector3f copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector3<float> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector3<float> is not initialised properly.");
				Assert::AreEqual(rndZ, copy.z, L"Copy constructor: Element z of Vector3<float> is not initialised properly.");
			}

			// Testing Vector3<double> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				double rndX = TestUtility::GetRandomInt();
				double rndY = TestUtility::GetRandomInt();
				double rndZ = TestUtility::GetRandomInt();
				Vector3d left(rndX, rndY, rndZ);
				Vector3d copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector3<double> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector3<double> is not initialised properly.");
				Assert::AreEqual(rndZ, copy.z, L"Copy constructor: Element z of Vector3<double> is not initialised properly.");
			}

			// Testing Vector3<int> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				int rndX = TestUtility::GetRandomInt();
				int rndY = TestUtility::GetRandomInt();
				int rndZ = TestUtility::GetRandomInt();
				Vector3i left(rndX, rndY, rndZ);
				Vector3i copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector3<int> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector3<int> is not initialised properly.");
				Assert::AreEqual(rndZ, copy.z, L"Copy constructor: Element z of Vector3<int> is not initialised properly.");
			}
		}

		// Compiler generated version as stated in the assignment description, test included for reference and completeness
		TEST_METHOD(V3_Assignment)
		{
			// Testing Vector3<float> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector3f left(TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat());
				Vector3f right(TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(right.z, left.z, L"Assignment operator: Element z of Vector3<float> has an incorrect value.");
			}

			// Testing Vector3<double> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector3d left(TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble());
				Vector3d right(TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(right.z, left.z, L"Assignment operator: Element z of Vector3<double> has an incorrect value.");
			}

			// Testing Vector3<int> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector3i left(TestUtility::GetRandomInt(), TestUtility::GetRandomInt(), TestUtility::GetRandomInt());
				Vector3i right(TestUtility::GetRandomInt(), TestUtility::GetRandomInt(), TestUtility::GetRandomInt());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(right.z, left.z, L"Assignment operator: Element z of Vector3<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V3_ToTGAConvertion)
		{
			const Vector3i intVector(3, 4, 5);
			const TgaVectori intTest = intVector.ToTga();
			Assert::AreEqual(3, intTest.x);
			Assert::AreEqual(4, intTest.y);
			Assert::AreEqual(5, intTest.z);

			const Vector3f floatVector(3.f, -4.f, 5.f);
			const TgaVectorf floatTest = floatVector.ToTga();
			Assert::AreEqual(3.f, floatTest.x);
			Assert::AreEqual(-4.f, floatTest.y);
			Assert::AreEqual(5.f, floatTest.z);

			const Vector3d doubleVector(-3., -4., -5.);
			const TgaVectord doubleTest = doubleVector.ToTga();
			Assert::AreEqual(-3., doubleTest.x);
			Assert::AreEqual(-4., doubleTest.y);
			Assert::AreEqual(-5., doubleTest.z);
		}

		TEST_METHOD(V3_ToOtherTypeConvertion)
		{
			const Vector3i intVector(3, 4, 5);
			const Vector3f floatVector(3.5f, -4.5f, 5.5f);
			const Vector3d doubleVector(-3.9, -4.9, -5.9);

			Vector3i fromFloati = floatVector.ToType<int>();
			Vector3i fromDoublei = doubleVector.ToType<int>();
			TestVector3({ 3,-4,5 }, fromFloati, L"Float To Int Failed");
			TestVector3({ -3,-4,-5 }, fromDoublei, L"Double To Int Failed");

			Vector3f fromIntf = intVector.ToType<float>();
			Vector3f fromDoublef = doubleVector.ToType<float>();
			TestVector3({ 3.0f,4.0f,5.0f }, fromIntf, L"Int To Float Failed");
			TestVector3({ -3.9f,-4.9f,-5.9f }, fromDoublef, L"Double To Float Failed");

			Vector3d fromIntd = intVector.ToType<double>();
			Vector3d fromFloatd = floatVector.ToType<double>();
			TestVector3({ 3.0, 4.0, 5.0 }, fromIntd, L"Int To Double Failed");
			TestVector3({ 3.5, -4.5, 5.5 }, fromFloatd, L"Float to Double Failed");
		}

		TEST_METHOD(V3_Negation)
		{
			Vector3i intResult;
			const Vector3i intVector(3, 4, 5);
			intResult = -intVector;
			Assert::AreEqual(-3, intResult.x);
			Assert::AreEqual(-4, intResult.y);
			Assert::AreEqual(-5, intResult.z);

			Vector3f floatResult;
			const Vector3f floatVector(3.f, -4.f, 5.f);
			floatResult = -floatVector;
			Assert::AreEqual(-3.f, floatResult.x);
			Assert::AreEqual(4.f, floatResult.y);
			Assert::AreEqual(-5.f, floatResult.z);

			Vector3d doubleResult;
			const Vector3d doubleVector(-3., -4., -5.);
			doubleResult = -doubleVector;
			Assert::AreEqual(3., doubleResult.x);
			Assert::AreEqual(4., doubleResult.y);
			Assert::AreEqual(5., doubleResult.z);
		}

		TEST_METHOD(V3_Addition)
		{
			// Test Vector3<float> addition
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();

				Vector3f left(xRnd1, yRnd1, zRnd1);
				Vector3f right(xRnd2, yRnd2, zRnd2);

				// Test operator+
				Vector3f result = left + right;
				float xResult = xRnd1 + xRnd2;
				float yResult = yRnd1 + yRnd2;
				float zResult = zRnd1 + zRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Addition: Element z of Vector3<float> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"AdditionEqual: Element z of Vector3<float> has an incorrect value.");
			}

			// Test Vector3<double> addition
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();

				Vector3d left(xRnd1, yRnd1, zRnd1);
				Vector3d right(xRnd2, yRnd2, zRnd2);

				// Test operator+
				Vector3d result = left + right;
				double xResult = xRnd1 + xRnd2;
				double yResult = yRnd1 + yRnd2;
				double zResult = zRnd1 + zRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Addition: Element z of Vector3<double> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"AdditionEqual: Element z of Vector3<double> has an incorrect value.");
			}

			// Test Vector3<int> addition
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();

				Vector3i left(xRnd1, yRnd1, zRnd1);
				Vector3i right(xRnd2, yRnd2, zRnd2);

				// Test operator+
				Vector3i result = left + right;
				int xResult = xRnd1 + xRnd2;
				int yResult = yRnd1 + yRnd2;
				int zResult = zRnd1 + zRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Addition: Element z of Vector3<int> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"AdditionEqual: Element z of Vector3<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V3_Subtraction)
		{
			// Test Vector3<float> subtraction
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();

				Vector3f left(xRnd1, yRnd1, zRnd1);
				Vector3f right(xRnd2, yRnd2, zRnd2);

				// Test operator+
				Vector3f result = left - right;
				float xResult = xRnd1 - xRnd2;
				float yResult = yRnd1 - yRnd2;
				float zResult = zRnd1 - zRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Subtraction: Element z of Vector3<float> has an incorrect value.");

				// Test operator+=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"SubtractionEqual: Element z of Vector3<float> has an incorrect value.");
			}

			// Test Vector3<double> subtraction
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();

				Vector3d left(xRnd1, yRnd1, zRnd1);
				Vector3d right(xRnd2, yRnd2, zRnd2);

				// Test operator+
				Vector3d result = left - right;
				double xResult = xRnd1 - xRnd2;
				double yResult = yRnd1 - yRnd2;
				double zResult = zRnd1 - zRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Subtraction: Element z of Vector3<double> has an incorrect value.");

				// Test operator+=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"SubtractionEqual: Element z of Vector3<double> has an incorrect value.");
			}

			// Test Vector3<int> subtraction
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();

				Vector3i left(xRnd1, yRnd1, zRnd1);
				Vector3i right(xRnd2, yRnd2, zRnd2);

				// Test operator-
				Vector3i result = left - right;
				int xResult = xRnd1 - xRnd2;
				int yResult = yRnd1 - yRnd2;
				int zResult = zRnd1 - zRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Subtraction: Element z of Vector3<int> has an incorrect value.");

				// Test operator-=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"SubtractionEqual: Element z of Vector3<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V3_Scalar_Multiplication)
		{
			// Test Vector3<float> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();

				float scalar = TestUtility::GetRandomFloat();

				Vector3f vec3(xRnd, yRnd, zRnd);

				Vector3f result = vec3 * scalar;
				float xResult = xRnd * scalar;
				float yResult = yRnd * scalar;
				float zResult = zRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Vector * scalar: Element z of Vector3<float> has an incorrect value.");

				Vector3f result2 = scalar * vec3;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.z, result2.z, L"Scalar * vector: Element z of Vector3<float> has an incorrect value.");

				// Test operator*=
				vec3 *= scalar;

				Assert::AreEqual(result.x, vec3.x, L"Vector *= scalar: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.y, vec3.y, L"Vector *= scalar: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.z, vec3.z, L"Vector *= scalar: Element z of Vector3<float> has an incorrect value.");
			}

			// Test Vector3<double> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();

				double scalar = TestUtility::GetRandomDouble();

				Vector3d vec3(xRnd, yRnd, zRnd);

				Vector3d result = vec3 * scalar;
				double xResult = xRnd * scalar;
				double yResult = yRnd * scalar;
				double zResult = zRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Vector * scalar: Element z of Vector3<double> has an incorrect value.");

				Vector3d result2 = scalar * vec3;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.z, result2.z, L"Scalar * vector: Element z of Vector3<double> has an incorrect value.");

				// Test operator*=
				vec3 *= scalar;

				Assert::AreEqual(result.x, vec3.x, L"Vector *= scalar: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.y, vec3.y, L"Vector *= scalar: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.z, vec3.z, L"Vector *= scalar: Element z of Vector3<double> has an incorrect value.");
			}

			// Test Vector3<int> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				int xRnd = TestUtility::GetRandomInt();
				int yRnd = TestUtility::GetRandomInt();
				int zRnd = TestUtility::GetRandomInt();

				int scalar = TestUtility::GetRandomInt();

				Vector3i vec3(xRnd, yRnd, zRnd);

				Vector3i result = vec3 * scalar;
				int xResult = xRnd * scalar;
				int yResult = yRnd * scalar;
				int zResult = zRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Vector * scalar: Element z of Vector3<int> has an incorrect value.");

				Vector3i result2 = scalar * vec3;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.z, result2.z, L"Scalar * vector: Element z of Vector3<int> has an incorrect value.");

				// Test operator*=
				vec3 *= scalar;

				Assert::AreEqual(result.x, vec3.x, L"Vector *= scalar: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.y, vec3.y, L"Vector *= scalar: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.z, vec3.z, L"Vector *= scalar: Element z of Vector3<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V3_Division)
		{
			// Test Vector3<float> division
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();

				float scalar = TestUtility::GetRandomFloat();

				Vector3f vec3(xRnd, yRnd, zRnd);

				Vector3f result = vec3 / scalar;
				float xResult = xRnd / scalar;
				float yResult = yRnd / scalar;
				float zResult = zRnd / scalar;

				Vector3f expected(xResult, yResult, zResult);
				TestVector3(expected, result, L"Division with floats failed");
				// Test operator/=
				vec3 /= scalar;
				TestVector3(expected, vec3, L"Division and assign with floats failed");
			}

			// Test Vector3<double> division
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();

				double scalar = TestUtility::GetRandomDouble();

				Vector3d vec3(xRnd, yRnd, zRnd);

				Vector3d result = vec3 / scalar;
				double xResult = xRnd / scalar;
				double yResult = yRnd / scalar;
				double zResult = zRnd / scalar;

				Vector3d expected(xResult, yResult, zResult);
				TestVector3(expected, result, L"Division with doubles failed");
				// Test operator/=
				vec3 /= scalar;
				TestVector3(expected, vec3, L"Division and assign with doubles failed");

			}

			// Test Vector3<int> division
			for (int i = 0; i < 100; ++i)
			{
				int xRnd = TestUtility::GetRandomInt();
				int yRnd = TestUtility::GetRandomInt();
				int zRnd = TestUtility::GetRandomInt();

				int scalar = TestUtility::GetRandomInt();

				Vector3i vec3(xRnd, yRnd, zRnd);

				Vector3i result = vec3 / scalar;
				int xResult = xRnd / scalar;
				int yResult = yRnd / scalar;
				int zResult = zRnd / scalar;

				Vector3i expected(xResult, yResult, zResult);
				TestVector3(expected, result, L"Division with ints failed");
				// Test operator/=
				vec3 /= scalar;
				TestVector3(expected, vec3, L"Division and assign with ints failed");

			}
		}

		TEST_METHOD(V3_Length)
		{
			// Test Vector3<float> Length methods
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();

				Vector3f vec3(xRnd, yRnd, zRnd);
				float lengthSqr = (xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd);
				float length = std::sqrt(lengthSqr);

				Assert::AreEqual(length, vec3.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector3<float> with random values.");
				Assert::AreEqual(lengthSqr, vec3.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector3<float> with random values.");
			}

			// Test Vector3<double> Length methods
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();

				Vector3d vec3(xRnd, yRnd, zRnd);
				double lengthSqr = (xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd);
				double length = std::sqrt(lengthSqr);

				Assert::AreEqual(length, vec3.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector3<double> with random values.");
				Assert::AreEqual(lengthSqr, vec3.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector3<double> with random values.");
			}
		}

		// This test can result in a false positive (says it failed when the code is correct). 
		// This I probably due to the scheduler which can pause a process to fix something else in the OS
		// Run the several times if a failure happens. 
		// Through simple testing this test has a <10% false positive rate (so 3 failures in a row is at worst case a 0.1% chance)
		TEST_METHOD(V3_LengthSqrIsFasterThanLength)
		{
			constexpr size_t ammount = 10000000;
			{
				Vector3f* vectors = new Vector3f[ammount];
				float* results = new float[ammount];
				float* resultsSqr = new float[ammount];
				for (size_t i = 0; i < ammount; i++)
				{
					vectors[i].x = TestUtility::GetRandomFloat();
					vectors[i].y = TestUtility::GetRandomFloat();
					vectors[i].z = TestUtility::GetRandomFloat();
				}

				using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
				using Duration = std::chrono::milliseconds;

				TimePoint startLength = std::chrono::high_resolution_clock::now();
				for (size_t i = 0; i < ammount; i++)
				{
					results[i] = vectors[i].Length();
				}
				TimePoint endLength = std::chrono::high_resolution_clock::now();
				Duration LengthDuration = std::chrono::duration_cast<Duration>(endLength - startLength);

				TimePoint startLengthSqr = std::chrono::high_resolution_clock::now();
				for (size_t i = 0; i < ammount; i++)
				{
					resultsSqr[i] = vectors[i].LengthSqr();
				}
				TimePoint endLengthSqr = std::chrono::high_resolution_clock::now();
				Duration LengthSqrDuration = std::chrono::duration_cast<Duration>(endLengthSqr - startLengthSqr);
				delete[] vectors;
				delete[] results;
				delete[] resultsSqr;

				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" float Vector3 Lengths: ");
				Logger::WriteMessage(std::to_string(LengthDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");
				Logger::WriteMessage("\n");
				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" float Vector3 Squared Lengths: ");
				Logger::WriteMessage(std::to_string(LengthSqrDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");

				Assert::IsTrue(LengthDuration >= LengthSqrDuration,
					L"LengthSqr is slower than Length. This should not be the case. Try the test again because the scheduler can affect this measurement");
			}
			Logger::WriteMessage("\n");
			{
				Vector3d* vectors = new Vector3d[ammount];
				double* results = new double[ammount];
				double* resultsSqr = new double[ammount];
				for (size_t i = 0; i < ammount; i++)
				{
					vectors[i].x = TestUtility::GetRandomDouble();
					vectors[i].y = TestUtility::GetRandomDouble();
					vectors[i].z = TestUtility::GetRandomDouble();
				}

				using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
				using Duration = std::chrono::milliseconds;

				TimePoint startLength = std::chrono::high_resolution_clock::now();
				for (size_t i = 0; i < ammount; i++)
				{
					results[i] = vectors[i].Length();
				}
				TimePoint endLength = std::chrono::high_resolution_clock::now();
				Duration LengthDuration = std::chrono::duration_cast<Duration>(endLength - startLength);

				TimePoint startLengthSqr = std::chrono::high_resolution_clock::now();
				for (size_t i = 0; i < ammount; i++)
				{
					resultsSqr[i] = vectors[i].LengthSqr();
				}
				TimePoint endLengthSqr = std::chrono::high_resolution_clock::now();
				Duration LengthSqrDuration = std::chrono::duration_cast<Duration>(endLengthSqr - startLengthSqr);
				delete[] vectors;
				delete[] results;
				delete[] resultsSqr;

				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" float Vector3 Lengths: ");
				Logger::WriteMessage(std::to_string(LengthDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");
				Logger::WriteMessage("\n");
				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" float Vector3 Squared Lengths: ");
				Logger::WriteMessage(std::to_string(LengthSqrDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");

				Assert::IsTrue(LengthDuration >= LengthSqrDuration, 
					L"LengthSqr is slower than Length. This should not be the case. Try the test again because the scheduler can affect this measurement");
			}
		}

		TEST_METHOD(V3_Unit_Vector_Length)
		{
			// Test Vector3<float> Length methods on unit vectors
			Vector3f unitXf, unitYf, unitZf;
			unitXf.x = 1.0f;
			unitYf.y = 1.0f;
			unitZf.z = 1.0f;

			Assert::AreEqual(1.0f, unitXf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector3<float> with values (1.0f, 0.0f, 0.0f).");
			Assert::AreEqual(1.0f, unitXf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector3<float> with values (1.0f, 0.0f, 0.0f).");

			Assert::AreEqual(1.0f, unitYf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector3<float> with values (0.0f, 1.0f, 0.0f).");
			Assert::AreEqual(1.0f, unitYf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector3<float> with values (0.0f, 1.0f, 0.0f).");

			Assert::AreEqual(1.0f, unitZf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector3<float> with values (0.0f, 0.0f, 1.0f).");
			Assert::AreEqual(1.0f, unitZf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector3<float> with values (0.0f, 0.0f, 1.0f).");

			// Test Vector3<double> Length methods on unit vectors
			Vector3d unitXd, unitYd, unitZd;
			unitXd.x = 1.0f;
			unitYd.y = 1.0f;
			unitZd.z = 1.0f;

			Assert::AreEqual(1.0, unitXd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector3<double> with values (1.0, 0.0, 0.0).");
			Assert::AreEqual(1.0, unitXd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector3<double> with values (1.0, 0.0, 0.0).");

			Assert::AreEqual(1.0, unitYd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector3<double> with values (0.0, 1.0, 0.0.");
			Assert::AreEqual(1.0, unitYd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector3<double> with values (0.0, 1.0, 0.0).");

			Assert::AreEqual(1.0, unitZd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector3<double> with values (0.0, 0.0, 1.0.");
			Assert::AreEqual(1.0, unitZd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector3<double> with values (0.0, 0.0, 1.0).");

			// Test Vector<int> Length methods on unit vectors
			Vector3i unitXi, unitYi, unitZi;
			unitXi.x = 1;
			unitYi.y = 1;
			unitZi.z = 1;

			Assert::AreEqual(1, unitXi.Length(), L"Length(): Incorrect length returned for Vector3<int> with values (1, 0, 0).");
			Assert::AreEqual(1, unitXi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector3<int> with values (1, 0, 0).");

			Assert::AreEqual(1, unitYi.Length(), L"Length(): Incorrect length returned for Vector3<int> with values (0, 1, 0).");
			Assert::AreEqual(1, unitYi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector3<int> with values (0, 1, 0).");

			Assert::AreEqual(1, unitZi.Length(), L"Length(): Incorrect length returned for Vector3<int> with values (0, 0, 1).");
			Assert::AreEqual(1, unitZi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector3<int> with values (0, 0, 1).");
		}

		TEST_METHOD(V3_Normalise)
		{
			// Test Vector3<float> Normalise methods
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();

				Vector3f vec3(xRnd, yRnd, zRnd);
				Vector3f normalised = vec3.GetNormalized();

				float length = std::sqrt((xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd));
				float lengthInv = 1.0f / length;

				float resultX = xRnd * lengthInv;
				float resultY = yRnd * lengthInv;
				float resultZ = zRnd * lengthInv;

				Assert::AreEqual(resultX, normalised.x, ourToleranceF, L"GetNormalized(): Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(resultY, normalised.y, ourToleranceF, L"GetNormalized(): Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(resultZ, normalised.z, ourToleranceF, L"GetNormalized(): Element z of Vector3<float> has an incorrect value.");

				vec3.Normalize();
				Assert::AreEqual(normalised.x, vec3.x, ourToleranceF, L"Normalize(): Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(normalised.y, vec3.y, ourToleranceF, L"Normalize(): Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(normalised.z, vec3.z, ourToleranceF, L"Normalize(): Element z of Vector3<float> has an incorrect value.");
			}

			// Test Vector3<double> Normalise methods
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();

				Vector3d vec3(xRnd, yRnd, zRnd);
				Vector3d normalised = vec3.GetNormalized();

				double length = std::sqrt((xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd));
				double lengthInv = 1.0 / length;

				double resultX = xRnd * lengthInv;
				double resultY = yRnd * lengthInv;
				double resultZ = zRnd * lengthInv;

				Assert::AreEqual(resultX, normalised.x, ourToleranceD, L"GetNormalized(): Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(resultY, normalised.y, ourToleranceD, L"GetNormalized(): Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(resultZ, normalised.z, ourToleranceD, L"GetNormalized(): Element z of Vector3<double> has an incorrect value.");

				vec3.Normalize();
				Assert::AreEqual(normalised.x, vec3.x, ourToleranceD, L"Normalize(): Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(normalised.y, vec3.y, ourToleranceD, L"Normalize(): Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(normalised.z, vec3.z, ourToleranceD, L"Normalize(): Element z of Vector3<double> has an incorrect value.");
			}
		}

		TEST_METHOD(V3_Length_Zero_Vector)
		{
			// Test Vector3<float> Length methods for zero vector
			Vector3f vec3f;

			Assert::AreEqual(0.0f, vec3f.Length(), ourToleranceF, L"Length(): Vector3<float> Zero vector doesn't have zero length.");
			Assert::AreEqual(0.0f, vec3f.LengthSqr(), ourToleranceF, L"Length(): Vector3<float> Zero vector doesn't have zero squared length.");

			// Test Vector3<double> Length methods for zero vector
			Vector3d vec3d;

			Assert::AreEqual(0.0, vec3d.Length(), ourToleranceD, L"Length(): Vector3<double> Zero vector doesn't have zero length.");
			Assert::AreEqual(0.0, vec3d.LengthSqr(), ourToleranceD, L"Length(): Vector3<double> Zero vector doesn't have zero squared length.");

			// Test Vector3<int> Length methods for zero vector
			Vector3i vec3i;

			Assert::AreEqual(0, vec3i.Length(), L"Length(): Vector3<int> Zero vector doesn't have zero length.");
			Assert::AreEqual(0, vec3i.LengthSqr(), L"Length(): Vector3<int> Zero vector doesn't have zero squared length.");
		}

		TEST_METHOD(V3_Normalise_Zero_Vector)
		{
			// Test Vector3<float> Normalise methods for zero vector
			Vector3f vec3f;
			Vector3f normalisedF = vec3f.GetNormalized();
			vec3f.Normalize();

			Assert::AreEqual(0.0f, normalisedF.x, ourToleranceF, L"GetNormalized() on zero vector: Element x of Vector3<float> is not 0.0f.");
			Assert::AreEqual(0.0f, normalisedF.y, ourToleranceF, L"GetNormalized() on zero vector: Element y of Vector3<float> is not 0.0f.");
			Assert::AreEqual(0.0f, normalisedF.z, ourToleranceF, L"GetNormalized() on zero vector: Element z of Vector3<float> is not 0.0f.");

			Assert::AreEqual(0.0f, vec3f.x, ourToleranceF, L"Normalize(): Element x of Vector3<float> is not 0.0f.");
			Assert::AreEqual(0.0f, vec3f.y, ourToleranceF, L"Normalize(): Element y of Vector3<float> is not 0.0f.");
			Assert::AreEqual(0.0f, vec3f.z, ourToleranceF, L"Normalize(): Element z of Vector3<float> is not 0.0f.");

			// Test Vector3<double> Normalise methods for zero vector
			Vector3d vec3d;
			Vector3d normalisedD = vec3d.GetNormalized();
			vec3d.Normalize();

			Assert::AreEqual(0.0, normalisedD.x, ourToleranceD, L"GetNormalized() on zero vector: Element x of Vector3<double> is not 0.0.");
			Assert::AreEqual(0.0, normalisedD.y, ourToleranceD, L"GetNormalized() on zero vector: Element y of Vector3<double> is not 0.0.");
			Assert::AreEqual(0.0, normalisedD.z, ourToleranceD, L"GetNormalized() on zero vector: Element z of Vector3<double> is not 0.0.");

			Assert::AreEqual(0.0, vec3d.x, ourToleranceD, L"Normalize(): Element x of Vector3<double> is not 0.0.");
			Assert::AreEqual(0.0, vec3d.y, ourToleranceD, L"Normalize(): Element y of Vector3<double> is not 0.0.");
			Assert::AreEqual(0.0, vec3d.z, ourToleranceD, L"Normalize(): Element z of Vector3<double> is not 0.0.");

			// Test Vector3<int> Normalise methods for zero vector
			Vector3i vec3i;
			Vector3i normalisedI = vec3i.GetNormalized();
			vec3i.Normalize();

			Assert::AreEqual(0, normalisedI.x, L"GetNormalized() on zero vector: Element x of Vector3<int> is not 0.");
			Assert::AreEqual(0, normalisedI.y, L"GetNormalized() on zero vector: Element y of Vector3<int> is not 0.");
			Assert::AreEqual(0, normalisedI.z, L"GetNormalized() on zero vector: Element z of Vector3<int> is not 0.");

			Assert::AreEqual(0, vec3i.x, L"Normalize(): Element x of Vector3<int> is not 0.");
			Assert::AreEqual(0, vec3i.y, L"Normalize(): Element y of Vector3<int> is not 0.");
			Assert::AreEqual(0, vec3i.z, L"Normalize(): Element z of Vector3<int> is not 0.");
		}

		TEST_METHOD(V3_Component_Multiplication)
		{
			Vector3i lhs(1, 2, 3);
			Vector3i rhs(5, 6, 7);
			Vector3i product = lhs * rhs;

			Assert::AreEqual(5, product.x, L"The x element is wrong in the component multiplication product.");
			Assert::AreEqual(12, product.y, L"The y element is wrong in the component multiplication product.");
			Assert::AreEqual(21, product.z, L"The z element is wrong in the component multiplication product.");

			// Exhastive Test Vector3<float> component product
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();

				Vector3f left(xRnd1, yRnd1, zRnd1);
				Vector3f right(xRnd2, yRnd2, zRnd2);

				Vector3f result = left * right;
				Vector3f resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, ourToleranceF, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, ourToleranceF, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.z, resultRL.z, ourToleranceF, L"The component multiplication product should be the same regardless of order.");

				float resultX = xRnd1 * xRnd2;
				float resultY = yRnd1 * yRnd2;
				float resultZ = zRnd1 * zRnd2;

				Assert::AreEqual(resultX, result.x, ourToleranceF, L"The x element is wrong in the component multiplication product for Vector3<float>.");
				Assert::AreEqual(resultY, result.y, ourToleranceF, L"The y element is wrong in the component multiplication product for Vector3<float>.");
				Assert::AreEqual(resultZ, result.z, ourToleranceF, L"The z element is wrong in the component multiplication product for Vector3<float>.");
			}

			// Exhastive Test Vector3<double> component product
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();

				Vector3d left(xRnd1, yRnd1, zRnd1);
				Vector3d right(xRnd2, yRnd2, zRnd2);

				Vector3d result = left * right;
				Vector3d resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, ourToleranceD, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, ourToleranceD, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.z, resultRL.z, ourToleranceD, L"The component multiplication product should be the same regardless of order.");

				double resultX = xRnd1 * xRnd2;
				double resultY = yRnd1 * yRnd2;
				double resultZ = zRnd1 * zRnd2;

				Assert::AreEqual(resultX, result.x, ourToleranceD, L"The x element is wrong in the component multiplication product for Vector3<double>.");
				Assert::AreEqual(resultY, result.y, ourToleranceD, L"The y element is wrong in the component multiplication product for Vector3<double>.");
				Assert::AreEqual(resultZ, result.z, ourToleranceD, L"The z element is wrong in the component multiplication product for Vector3<double>.");
			}

			// Exhastive Test Vector3<int> component product
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();

				Vector3i left(xRnd1, yRnd1, zRnd1);
				Vector3i right(xRnd2, yRnd2, zRnd2);

				Vector3i result = left * right;
				Vector3i resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.z, resultRL.z, L"The component multiplication product should be the same regardless of order.");

				int resultX = xRnd1 * xRnd2;
				int resultY = yRnd1 * yRnd2;
				int resultZ = zRnd1 * zRnd2;

				Assert::AreEqual(resultX, result.x, L"The x element is wrong in the component multiplication product for Vector3<int>.");
				Assert::AreEqual(resultY, result.y, L"The y element is wrong in the component multiplication product for Vector3<int>.");
				Assert::AreEqual(resultZ, result.z, L"The z element is wrong in the component multiplication product for Vector3<int>.");
			}
		}
		TEST_METHOD(V3_Dot)
		{
			// Test Vector3<float> Dot product
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();

				Vector3f left(xRnd1, yRnd1, zRnd1);
				Vector3f right(xRnd2, yRnd2, zRnd2);

				float dotLR = left.Dot(right);
				float dotRL = right.Dot(left);
				float result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2) + (zRnd1 * zRnd2);

				Assert::AreEqual(dotLR, dotRL, ourToleranceF, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector3<float>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector3<float>.");
			}

			// Test Vector3<double> Dot product
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();

				Vector3d left(xRnd1, yRnd1, zRnd1);
				Vector3d right(xRnd2, yRnd2, zRnd2);

				double dotLR = left.Dot(right);
				double dotRL = right.Dot(left);
				double result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2) + (zRnd1 * zRnd2);

				Assert::AreEqual(dotLR, dotRL, ourToleranceD, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector3<double>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector3<double>.");
			}

			// Test Vector3<int> Dot product
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();

				Vector3i left(xRnd1, yRnd1, zRnd1);
				Vector3i right(xRnd2, yRnd2, zRnd2);

				int dotLR = left.Dot(right);
				int dotRL = right.Dot(left);
				int result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2) + (zRnd1 * zRnd2);

				Assert::AreEqual(dotLR, dotRL, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector3<int>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector3<int>.");
			}
		}

		TEST_METHOD(V3_Cross)
		{
			// Test Vector3<float> Cross product
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();

				Vector3f left(xRnd1, yRnd1, zRnd1);
				Vector3f right(xRnd2, yRnd2, zRnd2);

				Vector3f cross = left.Cross(right);
				Vector3f crossInv = right.Cross(left);
				Vector3f result = Vector3f((left.y * right.z) - (left.z * right.y), (left.z * right.x) - (left.x * right.z), (left.x * right.y) - (left.y * right.x));

				Assert::AreEqual(-cross.x, crossInv.x, ourToleranceF, L"Cross product: a x b should be equal to -(b x a), but element x of the resulting Vector3<float> has an incorrect value.");
				Assert::AreEqual(-cross.y, crossInv.y, ourToleranceF, L"Cross product: a x b should be equal to -(b x a), but element y of the resulting Vector3<float> has an incorrect value.");
				Assert::AreEqual(-cross.z, crossInv.z, ourToleranceF, L"Cross product: a x b should be equal to -(b x a), but element z of the resulting Vector3<float> has an incorrect value.");

				Assert::AreEqual(result.x, cross.x, L"Cross product: Element x of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.y, cross.y, L"Cross product: Element y of Vector3<float> has an incorrect value.");
				Assert::AreEqual(result.z, cross.z, L"Cross product: Element z of Vector3<float> has an incorrect value.");
			}

			// Test Vector3<double> Cross product
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();

				Vector3d left(xRnd1, yRnd1, zRnd1);
				Vector3d right(xRnd2, yRnd2, zRnd2);

				Vector3d cross = left.Cross(right);
				Vector3d crossInv = right.Cross(left);
				Vector3d result = Vector3d((left.y * right.z) - (left.z * right.y), (left.z * right.x) - (left.x * right.z), (left.x * right.y) - (left.y * right.x));

				Assert::AreEqual(-cross.x, crossInv.x, ourToleranceD, L"Cross product: a x b should be equal to -(b x a), but element x of the resulting Vector3<double> has an incorrect value.");
				Assert::AreEqual(-cross.y, crossInv.y, ourToleranceD, L"Cross product: a x b should be equal to -(b x a), but element y of the resulting Vector3<double> has an incorrect value.");
				Assert::AreEqual(-cross.z, crossInv.z, ourToleranceD, L"Cross product: a x b should be equal to -(b x a), but element z of the resulting Vector3<double> has an incorrect value.");

				Assert::AreEqual(result.x, cross.x, L"Cross product: Element x of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.y, cross.y, L"Cross product: Element y of Vector3<double> has an incorrect value.");
				Assert::AreEqual(result.z, cross.z, L"Cross product: Element z of Vector3<double> has an incorrect value.");
			}

			// Test Vector3<int> Cross product
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();

				Vector3i left(xRnd1, yRnd1, zRnd1);
				Vector3i right(xRnd2, yRnd2, zRnd2);

				Vector3i cross = left.Cross(right);
				Vector3i crossInv = right.Cross(left);
				Vector3i result = Vector3i((left.y * right.z) - (left.z * right.y), (left.z * right.x) - (left.x * right.z), (left.x * right.y) - (left.y * right.x));

				Assert::AreEqual(-cross.x, crossInv.x, L"Cross product: a x b should be equal to -(b x a), but element x of the resulting Vector3<int> has an incorrect value.");
				Assert::AreEqual(-cross.y, crossInv.y, L"Cross product: a x b should be equal to -(b x a), but element y of the resulting Vector3<int> has an incorrect value.");
				Assert::AreEqual(-cross.z, crossInv.z, L"Cross product: a x b should be equal to -(b x a), but element z of the resulting Vector3<int> has an incorrect value.");

				Assert::AreEqual(result.x, cross.x, L"Cross product: Element x of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.y, cross.y, L"Cross product: Element y of Vector3<int> has an incorrect value.");
				Assert::AreEqual(result.z, cross.z, L"Cross product: Element z of Vector3<int> has an incorrect value.");
			}
		}

	private:
		static const float ourToleranceF;
		static const double ourToleranceD;
	};

	const float Vector3Test::ourToleranceF = 0.00001f;
	const double Vector3Test::ourToleranceD = 0.00001;
}