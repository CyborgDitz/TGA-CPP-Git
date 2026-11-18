#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <chrono>

#include "Shared/Utility.h"
#include "Student Code/Vector4.h"
#include "Student Code/Vector4.h" //Double include to check pragma once use

/// <summary>
/// This is a hack to emulate the TGA vector for the task of convertion
/// It only works because they happen to have the same name
/// </summary>
namespace Tga
{
	template<class T>
	class Vector4
	{
	public:
		T x;
		T y;
		T z;
		T w;
		Vector4() :x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}
		Vector4(const T aX, const T aY, const T aZ, const T aW) :x(aX), y(aY), z(aZ), w(aW) {}
		Vector4(const Vector4<T>&) = default;
		Vector4& operator=(const Vector4&) = default;
	};
}
using TgaVectorf = Tga::Vector4<float>;
using TgaVectord = Tga::Vector4<double>;
using TgaVectori = Tga::Vector4<int>;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Vector4f = CommonUtilities::Vector4<float>;
using Vector4d = CommonUtilities::Vector4<double>;
using Vector4i = CommonUtilities::Vector4<int>;

namespace Vectors
{


	TEST_CLASS(Vector4Test)
	{
	private:
		void TestVector4(const Vector4f& aExpected, const Vector4f& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, ourToleranceF, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, ourToleranceF, aMessageTemplate);
			Assert::AreEqual(aExpected.z, aResult.z, ourToleranceF, aMessageTemplate);
			Assert::AreEqual(aExpected.w, aResult.w, ourToleranceF, aMessageTemplate);
		}

		void TestVector4(const Vector4d& aExpected, const Vector4d& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, ourToleranceD, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, ourToleranceD, aMessageTemplate);
			Assert::AreEqual(aExpected.z, aResult.z, ourToleranceD, aMessageTemplate);
			Assert::AreEqual(aExpected.w, aResult.w, ourToleranceD, aMessageTemplate);
		}

		void TestVector4(const Vector4i& aExpected, const Vector4i& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, aMessageTemplate);
			Assert::AreEqual(aExpected.z, aResult.z, aMessageTemplate);
			Assert::AreEqual(aExpected.w, aResult.w, aMessageTemplate);
		}

	public:
		// Testing if all neccessary const:s are declared
		TEST_METHOD(V4_Const)
		{
			const float x = 3.1459f;
			const float y = 1.4392f;
			const float z = -2.4392f;
			const float w = -4.f;
			const float s = 41.7942f;
			const Vector4f zero;
			const Vector4f lhs(x, y, z, w);
			const Vector4f rhs(x, y, z, w);
			Vector4f mutableVector(rhs);
			mutableVector = lhs;
			Vector4d vectord = lhs.ToType<double>();
			Tga::Vector4<float> tgavectorf = lhs.ToTga();
			float mutableFloat;
			mutableVector = -rhs;
			mutableFloat = rhs.LengthSqr();
			mutableFloat = rhs.Length();
			mutableVector = lhs.GetNormalized();
			mutableVector.Normalize();
			mutableFloat = lhs.Dot(rhs);
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

		TEST_METHOD(V4_Size)
		{
			Vector4f fvector;
			Vector4i ivector;
			Vector4d dvector;
			Assert::IsTrue(sizeof(float) * 4 == sizeof(fvector), L"Vector 4 float has a different size than expected");
			Assert::IsTrue(sizeof(double) * 4 == sizeof(dvector), L"Vector 4 double has a different size than expected");
			Assert::IsTrue(sizeof(int) * 4 == sizeof(ivector), L"Vector 4 int has a different size than expected");
		}

		TEST_METHOD(V4_Default_Constructor)
		{
			// Testing Vector4<float> default initialisation
			Vector4f noInitF;

			Assert::AreEqual(0.0f, noInitF.x, L"Default initialisation: Element x of Vector4<float> is not initialised properly.");
			Assert::AreEqual(0.0f, noInitF.y, L"Default initialisation: Element y of Vector4<float> is not initialised properly.");
			Assert::AreEqual(0.0f, noInitF.z, L"Default initialisation: Element z of Vector4<float> is not initialised properly.");
			Assert::AreEqual(0.0f, noInitF.w, L"Default initialisation: Element w of Vector4<float> is not initialised properly.");

			// Testing Vector4<double> default initialisation
			Vector4d noInitD;

			Assert::AreEqual(0.0, noInitD.x, L"Default initialisation: Element x of Vector4<double> is not initialised properly.");
			Assert::AreEqual(0.0, noInitD.y, L"Default initialisation: Element y of Vector4<double> is not initialised properly.");
			Assert::AreEqual(0.0, noInitD.z, L"Default initialisation: Element z of Vector4<double> is not initialised properly.");
			Assert::AreEqual(0.0, noInitD.w, L"Default initialisation: Element w of Vector4<double> is not initialised properly.");

			// Testing Vector4<int> default initialisation
			Vector4i noInitI;

			Assert::AreEqual(0, noInitI.x, L"Default initialisation: Element x of Vector4<int> is not initialised properly.");
			Assert::AreEqual(0, noInitI.y, L"Default initialisation: Element y of Vector4<int> is not initialised properly.");
			Assert::AreEqual(0, noInitI.z, L"Default initialisation: Element z of Vector4<int> is not initialised properly.");
			Assert::AreEqual(0, noInitI.w, L"Default initialisation: Element w of Vector4<int> is not initialised properly.");
		}
		TEST_METHOD(V4_Constructor)
		{
			// Testing Vector4<float> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				float rndX = TestUtility::GetRandomFloat();
				float rndY = TestUtility::GetRandomFloat();
				float rndZ = TestUtility::GetRandomFloat();
				float rndW = TestUtility::GetRandomFloat();
				Vector4f initF(rndX, rndY, rndZ, rndW);

				Assert::AreEqual(rndX, initF.x, L"Random initialisation: Element x of Vector4<float> is not initialised properly.");
				Assert::AreEqual(rndY, initF.y, L"Random initialisation: Element y of Vector4<float> is not initialised properly.");
				Assert::AreEqual(rndZ, initF.z, L"Random initialisation: Element z of Vector4<float> is not initialised properly.");
				Assert::AreEqual(rndW, initF.w, L"Random initialisation: Element w of Vector4<float> is not initialised properly.");
			}

			// Testing Vector4<double> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				double rndX = TestUtility::GetRandomInt();
				double rndY = TestUtility::GetRandomInt();
				double rndZ = TestUtility::GetRandomInt();
				double rndW = TestUtility::GetRandomInt();
				Vector4d initD(rndX, rndY, rndZ, rndW);

				Assert::AreEqual(rndX, initD.x, L"Random initialisation: Element x of Vector4<double> is not initialised properly.");
				Assert::AreEqual(rndY, initD.y, L"Random initialisation: Element y of Vector4<double> is not initialised properly.");
				Assert::AreEqual(rndZ, initD.z, L"Random initialisation: Element z of Vector4<double> is not initialised properly.");
				Assert::AreEqual(rndW, initD.w, L"Random initialisation: Element w of Vector4<double> is not initialised properly.");
			}

			// Testing Vector<int> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				int rndX = TestUtility::GetRandomInt();
				int rndY = TestUtility::GetRandomInt();
				int rndZ = TestUtility::GetRandomInt();
				int rndW = TestUtility::GetRandomInt();
				Vector4i initI(rndX, rndY, rndZ, rndW);

				Assert::AreEqual(rndX, initI.x, L"Random initialisation: Element x of Vector4<int> is not initialised properly.");
				Assert::AreEqual(rndY, initI.y, L"Random initialisation: Element y of Vector4<int> is not initialised properly.");
				Assert::AreEqual(rndZ, initI.z, L"Random initialisation: Element z of Vector4<int> is not initialised properly.");
				Assert::AreEqual(rndW, initI.w, L"Random initialisation: Element w of Vector4<int> is not initialised properly.");
			}
		}

		// Compiler generated version as stated in the assignment description, test included for reference and completeness
		TEST_METHOD(V4_Copy_Constructor)
		{
			// Testing Vector4<float> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				float rndX = TestUtility::GetRandomFloat();
				float rndY = TestUtility::GetRandomFloat();
				float rndZ = TestUtility::GetRandomFloat();
				float rndW = TestUtility::GetRandomFloat();
				Vector4f left(rndX, rndY, rndZ, rndW);
				Vector4f copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector4<float> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector4<float> is not initialised properly.");
				Assert::AreEqual(rndZ, copy.z, L"Copy constructor: Element z of Vector4<float> is not initialised properly.");
				Assert::AreEqual(rndW, copy.w, L"Copy constructor: Element w of Vector4<float> is not initialised properly.");
			}

			// Testing Vector4<double> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				double rndX = TestUtility::GetRandomInt();
				double rndY = TestUtility::GetRandomInt();
				double rndZ = TestUtility::GetRandomInt();
				double rndW = TestUtility::GetRandomInt();
				Vector4d left(rndX, rndY, rndZ, rndW);
				Vector4d copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector4<double> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector4<double> is not initialised properly.");
				Assert::AreEqual(rndZ, copy.z, L"Copy constructor: Element z of Vector4<double> is not initialised properly.");
				Assert::AreEqual(rndW, copy.w, L"Copy constructor: Element w of Vector4<double> is not initialised properly.");
			}

			// Testing Vector4<int> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				int rndX = TestUtility::GetRandomInt();
				int rndY = TestUtility::GetRandomInt();
				int rndZ = TestUtility::GetRandomInt();
				int rndW = TestUtility::GetRandomInt();
				Vector4i left(rndX, rndY, rndZ, rndW);
				Vector4i copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector4<int> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector4<int> is not initialised properly.");
				Assert::AreEqual(rndZ, copy.z, L"Copy constructor: Element z of Vector4<int> is not initialised properly.");
				Assert::AreEqual(rndW, copy.w, L"Copy constructor: Element w of Vector4<int> is not initialised properly.");
			}
		}

		// Compiler generated version as stated in the assignment description, test included for reference and completeness
		TEST_METHOD(V4_Assignment)
		{
			// Testing Vector4<float> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector4f left(TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat());
				Vector4f right(TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(right.z, left.z, L"Assignment operator: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(right.w, left.w, L"Assignment operator: Element w of Vector4<float> has an incorrect value.");
			}

			// Testing Vector4<double> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector4d left(TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble());
				Vector4d right(TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(right.z, left.z, L"Assignment operator: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(right.w, left.w, L"Assignment operator: Element w of Vector4<double> has an incorrect value.");
			}

			// Testing Vector4<int> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector4i left(TestUtility::GetRandomInt(), TestUtility::GetRandomInt(), TestUtility::GetRandomInt(), TestUtility::GetRandomInt());
				Vector4i right(TestUtility::GetRandomInt(), TestUtility::GetRandomInt(), TestUtility::GetRandomInt(), TestUtility::GetRandomInt());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(right.z, left.z, L"Assignment operator: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(right.w, left.w, L"Assignment operator: Element w of Vector4<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V4_ToTGAConvertion)
		{
			const Vector4i intVector(3, 4, 5, 6);
			const TgaVectori intTest = intVector.ToTga();
			Assert::AreEqual(3, intTest.x);
			Assert::AreEqual(4, intTest.y);
			Assert::AreEqual(5, intTest.z);
			Assert::AreEqual(6, intTest.w);

			const Vector4f floatVector(3.f, -4.f, 5.f, -6.f);
			const TgaVectorf floatTest = floatVector.ToTga();
			Assert::AreEqual(3.f, floatTest.x);
			Assert::AreEqual(-4.f, floatTest.y);
			Assert::AreEqual(5.f, floatTest.z);
			Assert::AreEqual(-6.f, floatTest.w);

			const Vector4d doubleVector(-3., -4., -5., -6.);
			const TgaVectord doubleTest = doubleVector.ToTga();
			Assert::AreEqual(-3., doubleTest.x);
			Assert::AreEqual(-4., doubleTest.y);
			Assert::AreEqual(-5., doubleTest.z);
			Assert::AreEqual(-6., doubleTest.w);
		}

		TEST_METHOD(V4_ToOtherTypeConvertion)
		{
			const Vector4i intVector(3, 4, 5, 6);
			const Vector4f floatVector(3.5f, -4.5f, 5.5f, -6.5f);
			const Vector4d doubleVector(-3.9, -4.9, -5.9, -6.9);

			Vector4i fromFloati = floatVector.ToType<int>();
			Vector4i fromDoublei = doubleVector.ToType<int>();
			TestVector4({ 3,-4,5,-6 }, fromFloati, L"Float To Int Failed");
			TestVector4({ -3,-4,-5,-6 }, fromDoublei, L"Double To Int Failed");

			Vector4f fromIntf = intVector.ToType<float>();
			Vector4f fromDoublef = doubleVector.ToType<float>();
			TestVector4({ 3.0f,4.0f,5.0f,6.0f }, fromIntf, L"Int To Float Failed");
			TestVector4({ -3.9f,-4.9f,-5.9f,-6.9f }, fromDoublef, L"Double To Float Failed");

			Vector4d fromIntd = intVector.ToType<double>();
			Vector4d fromFloatd = floatVector.ToType<double>();
			TestVector4({ 3.0, 4.0, 5.0, 6.0 }, fromIntd, L"Int To Double Failed");
			TestVector4({ 3.5, -4.5, 5.5, -6.5 }, fromFloatd, L"Float to Double Failed");
		}

		TEST_METHOD(V4_Negation)
		{
			Vector4i intResult;
			const Vector4i intVector(3, 4, 5, 6);
			intResult = -intVector;
			Assert::AreEqual(-3, intResult.x);
			Assert::AreEqual(-4, intResult.y);
			Assert::AreEqual(-5, intResult.z);
			Assert::AreEqual(-6, intResult.w);

			Vector4f floatResult;
			const Vector4f floatVector(3.f, -4.f, 5.f, -6.f);
			floatResult = -floatVector;
			Assert::AreEqual(-3.f, floatResult.x);
			Assert::AreEqual(4.f, floatResult.y);
			Assert::AreEqual(-5.f, floatResult.z);
			Assert::AreEqual(6.f, floatResult.w);

			Vector4d doubleResult;
			const Vector4d doubleVector(-3., -4., -5., -6);
			doubleResult = -doubleVector;
			Assert::AreEqual(3., doubleResult.x);
			Assert::AreEqual(4., doubleResult.y);
			Assert::AreEqual(5., doubleResult.z);
			Assert::AreEqual(6., doubleResult.w);
		}
		TEST_METHOD(V4_Addition)
		{
			// Test Vector4<float> addition
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();
				float wRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();
				float wRnd2 = TestUtility::GetRandomFloat();

				Vector4f left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4f right(xRnd2, yRnd2, zRnd2, wRnd2);

				// Test operator+
				Vector4f result = left + right;
				float xResult = xRnd1 + xRnd2;
				float yResult = yRnd1 + yRnd2;
				float zResult = zRnd1 + zRnd2;
				float wResult = wRnd1 + wRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Addition: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Addition: Element w of Vector4<float> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"AdditionEqual: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.w, left.w, L"AdditionEqual: Element w of Vector4<float> has an incorrect value.");
			}

			// Test Vector4<double> addition
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();
				double wRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();
				double wRnd2 = TestUtility::GetRandomDouble();

				Vector4d left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4d right(xRnd2, yRnd2, zRnd2, wRnd2);

				// Test operator+
				Vector4d result = left + right;
				double xResult = xRnd1 + xRnd2;
				double yResult = yRnd1 + yRnd2;
				double zResult = zRnd1 + zRnd2;
				double wResult = wRnd1 + wRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Addition: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Addition: Element w of Vector4<double> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"AdditionEqual: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.w, left.w, L"AdditionEqual: Element w of Vector4<double> has an incorrect value.");
			}

			// Test Vector4<int> addition
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();
				int wRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();
				int wRnd2 = TestUtility::GetRandomInt();

				Vector4i left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4i right(xRnd2, yRnd2, zRnd2, wRnd2);

				// Test operator+
				Vector4i result = left + right;
				int xResult = xRnd1 + xRnd2;
				int yResult = yRnd1 + yRnd2;
				int zResult = zRnd1 + zRnd2;
				int wResult = wRnd1 + wRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Addition: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Addition: Element w of Vector4<int> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"AdditionEqual: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.w, left.w, L"AdditionEqual: Element w of Vector4<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V4_Subtraction)
		{
			// Test Vector4<float> subtraction
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();
				float wRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();
				float wRnd2 = TestUtility::GetRandomFloat();

				Vector4f left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4f right(xRnd2, yRnd2, zRnd2, wRnd2);

				// Test operator+
				Vector4f result = left - right;
				float xResult = xRnd1 - xRnd2;
				float yResult = yRnd1 - yRnd2;
				float zResult = zRnd1 - zRnd2;
				float wResult = wRnd1 - wRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Subtraction: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Subtraction: Element w of Vector4<float> has an incorrect value.");

				// Test operator+=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"SubtractionEqual: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.w, left.w, L"SubtractionEqual: Element w of Vector4<float> has an incorrect value.");
			}

			// Test Vector4<double> subtraction
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();
				double wRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();
				double wRnd2 = TestUtility::GetRandomDouble();

				Vector4d left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4d right(xRnd2, yRnd2, zRnd2, wRnd2);

				// Test operator+
				Vector4d result = left - right;
				double xResult = xRnd1 - xRnd2;
				double yResult = yRnd1 - yRnd2;
				double zResult = zRnd1 - zRnd2;
				double wResult = wRnd1 - wRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Subtraction: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Subtraction: Element w of Vector4<double> has an incorrect value.");

				// Test operator+=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"SubtractionEqual: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.w, left.w, L"SubtractionEqual: Element w of Vector4<double> has an incorrect value.");
			}

			// Test Vector4<int> subtraction
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();
				int wRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();
				int wRnd2 = TestUtility::GetRandomInt();

				Vector4i left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4i right(xRnd2, yRnd2, zRnd2, wRnd2);

				// Test operator-
				Vector4i result = left - right;
				int xResult = xRnd1 - xRnd2;
				int yResult = yRnd1 - yRnd2;
				int zResult = zRnd1 - zRnd2;
				int wResult = wRnd1 - wRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Subtraction: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Subtraction: Element w of Vector4<int> has an incorrect value.");

				// Test operator-=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.z, left.z, L"SubtractionEqual: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.w, left.w, L"SubtractionEqual: Element w of Vector4<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V4_Scalar_Multiplication)
		{
			// Test Vector4<float> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();
				float wRnd = TestUtility::GetRandomFloat();

				float scalar = TestUtility::GetRandomFloat();

				Vector4f vec4(xRnd, yRnd, zRnd, wRnd);

				Vector4f result = vec4 * scalar;
				float xResult = xRnd * scalar;
				float yResult = yRnd * scalar;
				float zResult = zRnd * scalar;
				float wResult = wRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Vector * scalar: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Vector * scalar: Element w of Vector4<float> has an incorrect value.");

				Vector4f result2 = scalar * vec4;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.z, result2.z, L"Scalar * vector: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.w, result2.w, L"Scalar * vector: Element w of Vector4<float> has an incorrect value.");

				// Test operator*=
				vec4 *= scalar;

				Assert::AreEqual(result.x, vec4.x, L"Vector *= scalar: Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.y, vec4.y, L"Vector *= scalar: Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.z, vec4.z, L"Vector *= scalar: Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(result.w, vec4.w, L"Vector *= scalar: Element w of Vector4<float> has an incorrect value.");
			}

			// Test Vector4<double> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();
				double wRnd = TestUtility::GetRandomDouble();

				double scalar = TestUtility::GetRandomDouble();

				Vector4d vec4(xRnd, yRnd, zRnd, wRnd);

				Vector4d result = vec4 * scalar;
				double xResult = xRnd * scalar;
				double yResult = yRnd * scalar;
				double zResult = zRnd * scalar;
				double wResult = wRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Vector * scalar: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Vector * scalar: Element w of Vector4<double> has an incorrect value.");

				Vector4d result2 = scalar * vec4;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.z, result2.z, L"Scalar * vector: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.w, result2.w, L"Scalar * vector: Element w of Vector4<double> has an incorrect value.");

				// Test operator*=
				vec4 *= scalar;

				Assert::AreEqual(result.x, vec4.x, L"Vector *= scalar: Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.y, vec4.y, L"Vector *= scalar: Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.z, vec4.z, L"Vector *= scalar: Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(result.w, vec4.w, L"Vector *= scalar: Element w of Vector4<double> has an incorrect value.");
			}

			// Test Vector4<int> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				int xRnd = TestUtility::GetRandomInt();
				int yRnd = TestUtility::GetRandomInt();
				int zRnd = TestUtility::GetRandomInt();
				int wRnd = TestUtility::GetRandomInt();

				int scalar = TestUtility::GetRandomInt();

				Vector4i vec4(xRnd, yRnd, zRnd, wRnd);

				Vector4i result = vec4 * scalar;
				int xResult = xRnd * scalar;
				int yResult = yRnd * scalar;
				int zResult = zRnd * scalar;
				int wResult = wRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(zResult, result.z, L"Vector * scalar: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(wResult, result.w, L"Vector * scalar: Element w of Vector4<int> has an incorrect value.");

				Vector4i result2 = scalar * vec4;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.z, result2.z, L"Scalar * vector: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.w, result2.w, L"Scalar * vector: Element w of Vector4<int> has an incorrect value.");

				// Test operator*=
				vec4 *= scalar;

				Assert::AreEqual(result.x, vec4.x, L"Vector *= scalar: Element x of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.y, vec4.y, L"Vector *= scalar: Element y of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.z, vec4.z, L"Vector *= scalar: Element z of Vector4<int> has an incorrect value.");
				Assert::AreEqual(result.w, vec4.w, L"Vector *= scalar: Element w of Vector4<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V4_Division)
		{
			// Test Vector4<float> division
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();
				float wRnd = TestUtility::GetRandomFloat();

				float scalar = TestUtility::GetRandomFloat();

				Vector4f vec4(xRnd, yRnd, zRnd, wRnd);

				Vector4f result = vec4 / scalar;
				float xResult = xRnd / scalar;
				float yResult = yRnd / scalar;
				float zResult = zRnd / scalar;
				float wResult = wRnd / scalar;
				Vector4f expected(xResult, yResult, zResult, wResult);
				TestVector4(expected, result, L"Division with floats failed");
				// Test operator/=
				vec4 /= scalar;
				TestVector4(expected, vec4, L"Division and assign with floats failed");
			}

			// Test Vector4<double> division
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();
				double wRnd = TestUtility::GetRandomDouble();

				double scalar = TestUtility::GetRandomDouble();

				Vector4d vec4(xRnd, yRnd, zRnd, wRnd);

				Vector4d result = vec4 / scalar;
				double xResult = xRnd / scalar;
				double yResult = yRnd / scalar;
				double zResult = zRnd / scalar;
				double wResult = wRnd / scalar;

				Vector4d expected(xResult, yResult, zResult, wResult);
				TestVector4(expected, result, L"Division with doubles failed");
				// Test operator/=
				vec4 /= scalar;
				TestVector4(expected, vec4, L"Division and assign with doubles failed");

			}

			// Test Vector4<int> division
			for (int i = 0; i < 100; ++i)
			{
				int xRnd = TestUtility::GetRandomInt();
				int yRnd = TestUtility::GetRandomInt();
				int zRnd = TestUtility::GetRandomInt();
				int wRnd = TestUtility::GetRandomInt();

				int scalar = TestUtility::GetRandomInt();

				Vector4i vec4(xRnd, yRnd, zRnd, wRnd);

				Vector4i result = vec4 / scalar;
				int xResult = xRnd / scalar;
				int yResult = yRnd / scalar;
				int zResult = zRnd / scalar;
				int wResult = wRnd / scalar;

				Vector4i expected(xResult, yResult, zResult, wResult);
				TestVector4(expected, result, L"Division with ints failed");
				// Test operator/=
				vec4 /= scalar;
				TestVector4(expected, vec4, L"Division and assign with ints failed");

			}
		}

		TEST_METHOD(V4_Length)
		{
			// Test Vector4<float> Length methods
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();
				float wRnd = TestUtility::GetRandomFloat();

				Vector4f vec4(xRnd, yRnd, zRnd, wRnd);
				float lengthSqr = (xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd) + (wRnd * wRnd);
				float length = std::sqrt(lengthSqr);

				Assert::AreEqual(length, vec4.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector4<float> with random values.");
				Assert::AreEqual(lengthSqr, vec4.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector4<float> with random values.");
			}

			// Test Vector4<double> Length methods
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();
				double wRnd = TestUtility::GetRandomDouble();

				Vector4d vec4(xRnd, yRnd, zRnd, wRnd);
				double lengthSqr = (xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd) + (wRnd * wRnd);
				double length = std::sqrt(lengthSqr);

				Assert::AreEqual(length, vec4.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector3<double> with random values.");
				Assert::AreEqual(lengthSqr, vec4.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector3<double> with random values.");
			}
		}

		// This test can result in a false positive (says it failed when the code is correct). 
		// This I probably due to the scheduler which can pause a process to fix something else in the OS
		// Run the several times if a failure happens. 
		// Through simple testing this test has a <10% false positive rate (so 3 failures in a row is at worst case a 0.1% chance)
		TEST_METHOD(V4_LengthSqrIsFasterThanLength)
		{
			constexpr size_t ammount = 10000000;
			{
				Vector4f* vectors = new Vector4f[ammount];
				float* results = new float[ammount];
				float* resultsSqr = new float[ammount];
				for (size_t i = 0; i < ammount; i++)
				{
					vectors[i].x = TestUtility::GetRandomFloat();
					vectors[i].y = TestUtility::GetRandomFloat();
					vectors[i].z = TestUtility::GetRandomFloat();
					vectors[i].w = TestUtility::GetRandomFloat();
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
				Logger::WriteMessage(" float Vector4 Lengths: ");
				Logger::WriteMessage(std::to_string(LengthDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");
				Logger::WriteMessage("\n");
				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" float Vector4 Squared Lengths: ");
				Logger::WriteMessage(std::to_string(LengthSqrDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");

				Assert::IsTrue(LengthDuration >= LengthSqrDuration, 
					L"LengthSqr is slower than Length. This should not be the case. Try the test again because the scheduler can affect this measurement");
			}
			Logger::WriteMessage("\n");
			{
				Vector4d* vectors = new Vector4d[ammount];
				double* results = new double[ammount];
				double* resultsSqr = new double[ammount];
				for (size_t i = 0; i < ammount; i++)
				{
					vectors[i].x = TestUtility::GetRandomDouble();
					vectors[i].y = TestUtility::GetRandomDouble();
					vectors[i].z = TestUtility::GetRandomDouble();
					vectors[i].w = TestUtility::GetRandomDouble();
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
				Logger::WriteMessage(" double Vector4 Lengths: ");
				Logger::WriteMessage(std::to_string(LengthDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");
				Logger::WriteMessage("\n");
				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" double Vector4 Squared Lengths: ");
				Logger::WriteMessage(std::to_string(LengthSqrDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");

				Assert::IsTrue(LengthDuration >= LengthSqrDuration, 
					L"LengthSqr is slower than Length. This should not be the case. Try the test again because the scheduler can affect this measurement");
			}
		}

		TEST_METHOD(V4_Unit_Vector_Length)
		{
			// Test Vector4<float> Length methods on unit vectors
			Vector4f unitXf, unitYf, unitZf, unitWf;
			unitXf.x = 1.0f;
			unitYf.y = 1.0f;
			unitZf.z = 1.0f;
			unitWf.w = 1.0f;

			Assert::AreEqual(1.0f, unitXf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector4<float> with values (1.0f, 0.0f, 0.0f, 0.0f).");
			Assert::AreEqual(1.0f, unitXf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector4<float> with values (1.0f, 0.0f, 0.0f, 0.0f).");

			Assert::AreEqual(1.0f, unitYf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector4<float> with values (0.0f, 1.0f, 0.0f, 0.0f).");
			Assert::AreEqual(1.0f, unitYf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector4<float> with values (0.0f, 1.0f, 0.0f, 0.0f).");

			Assert::AreEqual(1.0f, unitZf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector4<float> with values (0.0f, 0.0f, 1.0f, 0.0f).");
			Assert::AreEqual(1.0f, unitZf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector4<float> with values (0.0f, 0.0f, 1.0f, 0.0f).");

			Assert::AreEqual(1.0f, unitWf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector4<float> with values (0.0f, 0.0f, 0.0f, 1.0f).");
			Assert::AreEqual(1.0f, unitWf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector4<float> with values (0.0f, 0.0f, 0.0f, 1.0f).");

			// Test Vector4<double> Length methods on unit vectors
			Vector4d unitXd, unitYd, unitZd, unitWd;
			unitXd.x = 1.0f;
			unitYd.y = 1.0f;
			unitZd.z = 1.0f;
			unitWd.w = 1.0f;

			Assert::AreEqual(1.0, unitXd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector4<double> with values (1.0, 0.0, 0.0, 0.0).");
			Assert::AreEqual(1.0, unitXd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector4<double> with values (1.0, 0.0, 0.0, 0.0).");

			Assert::AreEqual(1.0, unitYd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector4<double> with values (0.0, 1.0, 0.0, 0.0).");
			Assert::AreEqual(1.0, unitYd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector4<double> with values (0.0, 1.0, 0.0, 0.0).");

			Assert::AreEqual(1.0, unitZd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector4<double> with values (0.0, 0.0, 1.0, 0.0).");
			Assert::AreEqual(1.0, unitZd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector4<double> with values (0.0, 0.0, 1.0, 0.0).");

			Assert::AreEqual(1.0, unitWd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector4<double> with values (0.0, 0.0, 0.0, 1.0).");
			Assert::AreEqual(1.0, unitWd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector4<double> with values (0.0, 0.0, 0.0, 1.0).");

			// Test Vector<int> Length methods on unit vectors
			Vector4i unitXi, unitYi, unitZi, unitWi;
			unitXi.x = 1;
			unitYi.y = 1;
			unitZi.z = 1;
			unitWi.w = 1;

			Assert::AreEqual(1, unitXi.Length(), L"Length(): Incorrect length returned for Vector4<int> with values (1, 0, 0, 0).");
			Assert::AreEqual(1, unitXi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector4<int> with values (1, 0, 0, 0).");

			Assert::AreEqual(1, unitYi.Length(), L"Length(): Incorrect length returned for Vector4<int> with values (0, 1, 0, 0).");
			Assert::AreEqual(1, unitYi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector4<int> with values (0, 1, 0, 0).");

			Assert::AreEqual(1, unitZi.Length(), L"Length(): Incorrect length returned for Vector4<int> with values (0, 0, 1, 0).");
			Assert::AreEqual(1, unitZi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector4<int> with values (0, 0, 1, 0).");

			Assert::AreEqual(1, unitWi.Length(), L"Length(): Incorrect length returned for Vector4<int> with values (0, 0, 0, 1).");
			Assert::AreEqual(1, unitWi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector4<int> with values (0, 0, 0, 1).");
		}

		TEST_METHOD(V4_Normalise)
		{
			// Test Vector4<float> Normalise methods
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();
				float zRnd = TestUtility::GetRandomFloat();
				float wRnd = TestUtility::GetRandomFloat();

				Vector4f vec4(xRnd, yRnd, zRnd, wRnd);
				Vector4f normalised = vec4.GetNormalized();

				float length = std::sqrt((xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd) + (wRnd * wRnd));
				float lengthInv = 1.0f / length;

				float resultX = xRnd * lengthInv;
				float resultY = yRnd * lengthInv;
				float resultZ = zRnd * lengthInv;
				float resultW = wRnd * lengthInv;

				Assert::AreEqual(resultX, normalised.x, ourToleranceF, L"GetNormalized(): Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(resultY, normalised.y, ourToleranceF, L"GetNormalized(): Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(resultZ, normalised.z, ourToleranceF, L"GetNormalized(): Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(resultW, normalised.w, ourToleranceF, L"GetNormalized(): Element w of Vector4<float> has an incorrect value.");

				vec4.Normalize();
				Assert::AreEqual(normalised.x, vec4.x, ourToleranceF, L"Normalized(): Element x of Vector4<float> has an incorrect value.");
				Assert::AreEqual(normalised.y, vec4.y, ourToleranceF, L"Normalized(): Element y of Vector4<float> has an incorrect value.");
				Assert::AreEqual(normalised.z, vec4.z, ourToleranceF, L"Normalized(): Element z of Vector4<float> has an incorrect value.");
				Assert::AreEqual(normalised.w, vec4.w, ourToleranceF, L"Normalized(): Element w of Vector4<float> has an incorrect value.");
			}

			// Test Vector4<double> Normalise methods
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();
				double zRnd = TestUtility::GetRandomDouble();
				double wRnd = TestUtility::GetRandomDouble();

				Vector4d vec4(xRnd, yRnd, zRnd, wRnd);
				Vector4d normalised = vec4.GetNormalized();

				double length = std::sqrt((xRnd * xRnd) + (yRnd * yRnd) + (zRnd * zRnd) + (wRnd * wRnd));
				double lengthInv = 1.0 / length;

				double resultX = xRnd * lengthInv;
				double resultY = yRnd * lengthInv;
				double resultZ = zRnd * lengthInv;
				double resultW = wRnd * lengthInv;

				Assert::AreEqual(resultX, normalised.x, ourToleranceD, L"GetNormalized(): Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(resultY, normalised.y, ourToleranceD, L"GetNormalized(): Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(resultZ, normalised.z, ourToleranceD, L"GetNormalized(): Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(resultW, normalised.w, ourToleranceD, L"GetNormalized(): Element w of Vector4<double> has an incorrect value.");

				vec4.Normalize();
				Assert::AreEqual(normalised.x, vec4.x, ourToleranceD, L"Normalize(): Element x of Vector4<double> has an incorrect value.");
				Assert::AreEqual(normalised.y, vec4.y, ourToleranceD, L"Normalize(): Element y of Vector4<double> has an incorrect value.");
				Assert::AreEqual(normalised.z, vec4.z, ourToleranceD, L"Normalize(): Element z of Vector4<double> has an incorrect value.");
				Assert::AreEqual(normalised.w, vec4.w, ourToleranceD, L"Normalize(): Element w of Vector4<double> has an incorrect value.");
			}
		}

		TEST_METHOD(V4_Length_Zero_Vector)
		{
			// Test Vector4<float> Length methods for zero vector
			Vector4f vec4f;

			Assert::AreEqual(0.0f, vec4f.Length(), ourToleranceF, L"Length(): Vector4<float> Zero vector doesn't have zero length.");
			Assert::AreEqual(0.0f, vec4f.LengthSqr(), ourToleranceF, L"Length(): Vector4<float> Zero vector doesn't have zero squared length.");

			// Test Vector4<double> Length methods for zero vector
			Vector4d vec4d;

			Assert::AreEqual(0.0, vec4d.Length(), ourToleranceD, L"Length(): Vector4<double> Zero vector doesn't have zero length.");
			Assert::AreEqual(0.0, vec4d.LengthSqr(), ourToleranceD, L"Length(): Vector4<double> Zero vector doesn't have zero squared length.");

			// Test Vector4<int> Length methods for zero vector
			Vector4i vec4i;

			Assert::AreEqual(0, vec4i.Length(), L"Length(): Vector4<int> Zero vector doesn't have zero length.");
			Assert::AreEqual(0, vec4i.LengthSqr(), L"Length(): Vector4<int> Zero vector doesn't have zero squared length.");
		}

		TEST_METHOD(V4_Normalise_Zero_Vector)
		{
			// Test Vector4<float> Normalise methods for zero vector
			Vector4f vec4f;
			Vector4f normalisedF = vec4f.GetNormalized();
			vec4f.Normalize();

			Assert::AreEqual(0.0f, normalisedF.x, ourToleranceF, L"GetNormalized() on zero vector: Element x of Vector4<float> is not 0.0f.");
			Assert::AreEqual(0.0f, normalisedF.y, ourToleranceF, L"GetNormalized() on zero vector: Element y of Vector4<float> is not 0.0f.");
			Assert::AreEqual(0.0f, normalisedF.z, ourToleranceF, L"GetNormalized() on zero vector: Element z of Vector4<float> is not 0.0f.");
			Assert::AreEqual(0.0f, normalisedF.w, ourToleranceF, L"GetNormalized() on zero vector: Element w of Vector4<float> is not 0.0f.");

			Assert::AreEqual(0.0f, vec4f.x, ourToleranceF, L"Normalize(): Element x of Vector4<float> is not 0.0f.");
			Assert::AreEqual(0.0f, vec4f.y, ourToleranceF, L"Normalize(): Element y of Vector4<float> is not 0.0f.");
			Assert::AreEqual(0.0f, vec4f.z, ourToleranceF, L"Normalize(): Element z of Vector4<float> is not 0.0f.");
			Assert::AreEqual(0.0f, vec4f.w, ourToleranceF, L"Normalize(): Element w of Vector4<float> is not 0.0f.");

			// Test Vector4<double> Normalise methods for zero vector
			Vector4d vec4d;
			Vector4d normalisedD = vec4d.GetNormalized();
			vec4d.Normalize();

			Assert::AreEqual(0.0, normalisedD.x, ourToleranceD, L"GetNormalized() on zero vector: Element x of Vector4<double> is not 0.0.");
			Assert::AreEqual(0.0, normalisedD.y, ourToleranceD, L"GetNormalized() on zero vector: Element y of Vector4<double> is not 0.0.");
			Assert::AreEqual(0.0, normalisedD.z, ourToleranceD, L"GetNormalized() on zero vector: Element z of Vector4<double> is not 0.0.");
			Assert::AreEqual(0.0, normalisedD.w, ourToleranceD, L"GetNormalized() on zero vector: Element w of Vector4<double> is not 0.0.");

			Assert::AreEqual(0.0, vec4d.x, ourToleranceD, L"Normalize(): Element x of Vector4<double> is not 0.0.");
			Assert::AreEqual(0.0, vec4d.y, ourToleranceD, L"Normalize(): Element y of Vector4<double> is not 0.0.");
			Assert::AreEqual(0.0, vec4d.z, ourToleranceD, L"Normalize(): Element z of Vector4<double> is not 0.0.");
			Assert::AreEqual(0.0, vec4d.w, ourToleranceD, L"Normalize(): Element w of Vector4<double> is not 0.0.");

			// Test Vector4<int> Normalise methods for zero vector
			Vector4i vec4i;
			Vector4i normalisedI = vec4i.GetNormalized();
			vec4i.Normalize();

			Assert::AreEqual(0, normalisedI.x, L"GetNormalized() on zero vector: Element x of Vector4<int> is not 0.");
			Assert::AreEqual(0, normalisedI.y, L"GetNormalized() on zero vector: Element y of Vector4<int> is not 0.");
			Assert::AreEqual(0, normalisedI.z, L"GetNormalized() on zero vector: Element z of Vector4<int> is not 0.");
			Assert::AreEqual(0, normalisedI.w, L"GetNormalized() on zero vector: Element w of Vector4<int> is not 0.");

			Assert::AreEqual(0, vec4i.x, L"Normalize(): Element x of Vector4<int> is not 0.");
			Assert::AreEqual(0, vec4i.y, L"Normalize(): Element y of Vector4<int> is not 0.");
			Assert::AreEqual(0, vec4i.z, L"Normalize(): Element z of Vector4<int> is not 0.");
			Assert::AreEqual(0, vec4i.w, L"Normalize(): Element w of Vector4<int> is not 0.");
		}

		TEST_METHOD(V4_Component_Multiplication)
		{
			Vector4i lhs(1, 2, 3, 4);
			Vector4i rhs(5, 6, 7, 8);
			Vector4i product = lhs * rhs;

			Assert::AreEqual(5, product.x, L"The x element is wrong in the component multiplication product.");
			Assert::AreEqual(12, product.y, L"The y element is wrong in the component multiplication product.");
			Assert::AreEqual(21, product.z, L"The z element is wrong in the component multiplication product.");
			Assert::AreEqual(32, product.w, L"The w element is wrong in the component multiplication product.");

			// Exhastive Test Vector4<float> component product
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();
				float wRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();
				float wRnd2 = TestUtility::GetRandomFloat();

				Vector4f left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4f right(xRnd2, yRnd2, zRnd2, wRnd2);

				Vector4f result = left * right;
				Vector4f resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, ourToleranceF, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, ourToleranceF, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.z, resultRL.z, ourToleranceF, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.w, resultRL.w, ourToleranceF, L"The component multiplication product should be the same regardless of order.");

				float resultX = xRnd1 * xRnd2;
				float resultY = yRnd1 * yRnd2;
				float resultZ = zRnd1 * zRnd2;
				float resultW = wRnd1 * wRnd2;

				Assert::AreEqual(resultX, result.x, ourToleranceF, L"The x element is wrong in the component multiplication product for Vector4<float>.");
				Assert::AreEqual(resultY, result.y, ourToleranceF, L"The y element is wrong in the component multiplication product for Vector4<float>.");
				Assert::AreEqual(resultZ, result.z, ourToleranceF, L"The z element is wrong in the component multiplication product for Vector4<float>.");
				Assert::AreEqual(resultW, result.w, ourToleranceF, L"The w element is wrong in the component multiplication product for Vector4<float>.");
			}

			// Exhastive Test Vector4<double> component product
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();
				double wRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();
				double wRnd2 = TestUtility::GetRandomDouble();

				Vector4d left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4d right(xRnd2, yRnd2, zRnd2, wRnd2);

				Vector4d result = left * right;
				Vector4d resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, ourToleranceD, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, ourToleranceD, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.z, resultRL.z, ourToleranceD, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.w, resultRL.w, ourToleranceD, L"The component multiplication product should be the same regardless of order.");

				double resultX = xRnd1 * xRnd2;
				double resultY = yRnd1 * yRnd2;
				double resultZ = zRnd1 * zRnd2;
				double resultW = wRnd1 * wRnd2;

				Assert::AreEqual(resultX, result.x, ourToleranceD, L"The x element is wrong in the component multiplication product for Vector4<double>.");
				Assert::AreEqual(resultY, result.y, ourToleranceD, L"The y element is wrong in the component multiplication product for Vector4<double>.");
				Assert::AreEqual(resultZ, result.z, ourToleranceD, L"The z element is wrong in the component multiplication product for Vector4<double>.");
				Assert::AreEqual(resultW, result.w, ourToleranceD, L"The w element is wrong in the component multiplication product for Vector4<double>.");
			}

			// Exhastive Test Vector4<int> component product
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();
				int wRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();
				int wRnd2 = TestUtility::GetRandomInt();

				Vector4i left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4i right(xRnd2, yRnd2, zRnd2, wRnd2);

				Vector4i result = left * right;
				Vector4i resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.z, resultRL.z, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.w, resultRL.w, L"The component multiplication product should be the same regardless of order.");

				int resultX = xRnd1 * xRnd2;
				int resultY = yRnd1 * yRnd2;
				int resultZ = zRnd1 * zRnd2;
				int resultW = wRnd1 * wRnd2;

				Assert::AreEqual(resultX, result.x, L"The x element is wrong in the component multiplication product for Vector4<int>.");
				Assert::AreEqual(resultY, result.y, L"The y element is wrong in the component multiplication product for Vector4<int>.");
				Assert::AreEqual(resultZ, result.z, L"The z element is wrong in the component multiplication product for Vector4<int>.");
				Assert::AreEqual(resultW, result.w, L"The w element is wrong in the component multiplication product for Vector4<int>.");
			}
		}
		TEST_METHOD(V4_Dot)
		{
			// Test Vector4<float> Dot product
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();
				float zRnd1 = TestUtility::GetRandomFloat();
				float wRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();
				float zRnd2 = TestUtility::GetRandomFloat();
				float wRnd2 = TestUtility::GetRandomFloat();

				Vector4f left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4f right(xRnd2, yRnd2, zRnd2, wRnd2);

				float dotLR = left.Dot(right);
				float dotRL = right.Dot(left);
				float result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2) + (zRnd1 * zRnd2) + (wRnd1 * wRnd2);

				Assert::AreEqual(dotLR, dotRL, ourToleranceF, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector4<float>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector4<float>.");
			}

			// Test Vector4<double> Dot product
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();
				double zRnd1 = TestUtility::GetRandomDouble();
				double wRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();
				double zRnd2 = TestUtility::GetRandomDouble();
				double wRnd2 = TestUtility::GetRandomDouble();

				Vector4d left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4d right(xRnd2, yRnd2, zRnd2, wRnd2);

				double dotLR = left.Dot(right);
				double dotRL = right.Dot(left);
				double result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2) + (zRnd1 * zRnd2) + (wRnd1 * wRnd2);

				Assert::AreEqual(dotLR, dotRL, ourToleranceD, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector4<double>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector4<double>.");
			}

			// Test Vector4<int> Dot product
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();
				int zRnd1 = TestUtility::GetRandomInt();
				int wRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();
				int zRnd2 = TestUtility::GetRandomInt();
				int wRnd2 = TestUtility::GetRandomInt();

				Vector4i left(xRnd1, yRnd1, zRnd1, wRnd1);
				Vector4i right(xRnd2, yRnd2, zRnd2, wRnd2);

				int dotLR = left.Dot(right);
				int dotRL = right.Dot(left);
				int result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2) + (zRnd1 * zRnd2) + (wRnd1 * wRnd2);

				Assert::AreEqual(dotLR, dotRL, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector4<int>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector4<int>.");
			}
		}

	private:
		static const float ourToleranceF;
		static const double ourToleranceD;
	};

	const float Vector4Test::ourToleranceF = 0.00001f;
	const double Vector4Test::ourToleranceD = 0.00001;
}