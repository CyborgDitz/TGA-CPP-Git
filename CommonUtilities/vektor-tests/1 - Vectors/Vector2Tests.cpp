#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <chrono>

#include "Shared/Utility.h"
#include "Student Code/Vector2.h"
#include "Student Code/Vector2.h"//Double include to check pragma once use

/// <summary>
/// This is a hack to emulate the TGA vector for the task of convertion
/// It only works because they happen to have the same name
/// </summary>
namespace Tga
{
	template<class T>
	class Vector2
	{
	public:
		T x;
		T y;

		Vector2() :x(T(0)), y(T(0)) {}
		Vector2(const T aX, const T aY) :x(aX), y(aY) {}
		Vector2(const Vector2<T>&) = default;
		Vector2& operator=(const Vector2&) = default;
	};
}
using TgaVectorf = Tga::Vector2<float>;
using TgaVectord = Tga::Vector2<double>;
using TgaVectori = Tga::Vector2<int>;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using Vector2f = CommonUtilities::Vector2<float>;
using Vector2d = CommonUtilities::Vector2<double>;
using Vector2i = CommonUtilities::Vector2<int>;

namespace Vectors
{
	TEST_CLASS(Vector2Test)
	{
		void TestVector2(const Vector2f& aExpected, const Vector2f& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, ourToleranceF, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, ourToleranceF, aMessageTemplate);
		}

		void TestVector2(const Vector2d& aExpected, const Vector2d& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, ourToleranceD, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, ourToleranceD, aMessageTemplate);
		}

		void TestVector2(const Vector2i& aExpected, const Vector2i& aResult, const wchar_t* aMessageTemplate = L"")
		{
			Assert::AreEqual(aExpected.x, aResult.x, aMessageTemplate);
			Assert::AreEqual(aExpected.y, aResult.y, aMessageTemplate);
		}
	public:

		// Testing if all neccessary const:s are declared
		TEST_METHOD(V2_Const)
		{
			const float x = 3.1459f;
			const float y = 1.4392f;
			const float s = 41.7942f;
			const Vector2f zero;
			const Vector2f lhs(x, y);
			const Vector2f rhs(x, y);
			Vector2f mutableVector(rhs);
			mutableVector = lhs;
			Vector2d vectord = lhs.ToType<double>();
			Tga::Vector2<float> tgavectorf = lhs.ToTga();
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
		TEST_METHOD(V2_Size)
		{
			Vector2f fvector;
			Vector2i ivector;
			Vector2d dvector;
			Assert::IsTrue(sizeof(float) * 2 == sizeof(fvector), L"Vector 2 float has a different size than expected");
			Assert::IsTrue(sizeof(double) * 2 == sizeof(dvector), L"Vector 2 double has a different size than expected");
			Assert::IsTrue(sizeof(int) * 2 == sizeof(ivector), L"Vector 2 int has a different size than expected");
		}
		TEST_METHOD(V2_Default_Constructor)
		{
			// Testing Vector2<float> default initialisation
			Vector2f noInitF;

			Assert::AreEqual(0.0f, noInitF.x, L"Default initialisation: Element x of Vector2<float> is not initialised properly.");
			Assert::AreEqual(0.0f, noInitF.y, L"Default initialisation: Element y of Vector2<float> is not initialised properly.");

			// Testing Vector2<double> default initialisation
			Vector2d noInitD;

			Assert::AreEqual(0.0, noInitD.x, L"Default initialisation: Element x of Vector2<double> is not initialised properly.");
			Assert::AreEqual(0.0, noInitD.y, L"Default initialisation: Element y of Vector2<double> is not initialised properly.");

			// Testing Vector2<int> default initialisation
			Vector2i noInitI;

			Assert::AreEqual(0, noInitI.x, L"Default initialisation: Element x of Vector2<int> is not initialised properly.");
			Assert::AreEqual(0, noInitI.y, L"Default initialisation: Element y of Vector2<int> is not initialised properly.");
		}

		TEST_METHOD(V2_Constructor)
		{
			// Testing Vector2<float> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				float rndX = TestUtility::GetRandomFloat();
				float rndY = TestUtility::GetRandomFloat();
				Vector2f initF(rndX, rndY);

				Assert::AreEqual(rndX, initF.x, L"Random initialisation: Element x of Vector2<float> is not initialised properly.");
				Assert::AreEqual(rndY, initF.y, L"Random initialisation: Element y of Vector2<float> is not initialised properly.");
			}

			// Testing Vector2<double> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				double rndX = TestUtility::GetRandomInt();
				double rndY = TestUtility::GetRandomInt();
				Vector2d initD(rndX, rndY);

				Assert::AreEqual(rndX, initD.x, L"Random initialisation: Element x of Vector2<double> is not initialised properly.");
				Assert::AreEqual(rndY, initD.y, L"Random initialisation: Element y of Vector2<double> is not initialised properly.");
			}

			// Testing Vector<int> parameter initialisation
			for (int i = 0; i < 100; ++i)
			{
				int rndX = TestUtility::GetRandomInt();
				int rndY = TestUtility::GetRandomInt();
				Vector2i initI(rndX, rndY);

				Assert::AreEqual(rndX, initI.x, L"Random initialisation: Element x of Vector2<int> is not initialised properly.");
				Assert::AreEqual(rndY, initI.y, L"Random initialisation: Element y of Vector2<int> is not initialised properly.");
			}
		}

		// Compiler generated version as stated in the assignment description, test included for reference and completeness
		TEST_METHOD(V2_Copy_Constructor)
		{
			// Testing Vector2<float> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				float rndX = TestUtility::GetRandomFloat();
				float rndY = TestUtility::GetRandomFloat();
				Vector2f left(rndX, rndY);
				Vector2f copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector2<float> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector2<float> is not initialised properly.");
			}

			// Testing Vector2<double> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				double rndX = TestUtility::GetRandomInt();
				double rndY = TestUtility::GetRandomInt();
				Vector2d left(rndX, rndY);
				Vector2d copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector2<double> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector2<double> is not initialised properly.");
			}

			// Testing Vector2<int> copy constructor
			for (int i = 0; i < 100; ++i)
			{
				int rndX = TestUtility::GetRandomInt();
				int rndY = TestUtility::GetRandomInt();
				Vector2i left(rndX, rndY);
				Vector2i copy(left);

				Assert::AreEqual(rndX, copy.x, L"Copy constructor: Element x of Vector2<int> is not initialised properly.");
				Assert::AreEqual(rndY, copy.y, L"Copy constructor: Element y of Vector2<int> is not initialised properly.");
			}
		}

		// Compiler generated version as stated in the assignment description, test included for reference and completeness
		TEST_METHOD(V2_Assignment)
		{
			// Testing Vector2<float> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector2f left(TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat());
				Vector2f right(TestUtility::GetRandomFloat(), TestUtility::GetRandomFloat());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector2<float> has an incorrect value.");
			}

			// Testing Vector2<double> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector2d left(TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble());
				Vector2d right(TestUtility::GetRandomDouble(), TestUtility::GetRandomDouble());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector2<double> has an incorrect value.");
			}

			// Testing Vector2<int> assignment operator
			for (int i = 0; i < 100; ++i)
			{
				Vector2i left(TestUtility::GetRandomInt(), TestUtility::GetRandomInt());
				Vector2i right(TestUtility::GetRandomInt(), TestUtility::GetRandomInt());

				left = right;

				Assert::AreEqual(right.x, left.x, L"Assignment operator: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(right.y, left.y, L"Assignment operator: Element y of Vector2<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V2_ToTGAConvertion)
		{
			const Vector2i intVector(3, 4);
			const TgaVectori intTest = intVector.ToTga();
			Assert::AreEqual(3, intTest.x);
			Assert::AreEqual(4, intTest.y);
			
			const Vector2f floatVector(3.f, -4.f);
			const TgaVectorf floatTest = floatVector.ToTga();
			Assert::AreEqual(3.f, floatTest.x);
			Assert::AreEqual(-4.f, floatTest.y);
			
			const Vector2d doubleVector(-3., -4.);
			const TgaVectord doubleTest = doubleVector.ToTga();
			Assert::AreEqual(-3., doubleTest.x);
			Assert::AreEqual(-4., doubleTest.y);
					}

		TEST_METHOD(V2_ToOtherTypeConvertion)
		{
			const Vector2i intVector(3, 4);
			const Vector2f floatVector(3.5f, -4.5f);
			const Vector2d doubleVector(-3.9, -4.9);

			Vector2i fromFloati = floatVector.ToType<int>();
			Vector2i fromDoublei = doubleVector.ToType<int>();
			TestVector2({ 3,-4 }, fromFloati, L"Float To Int Failed");
			TestVector2({ -3,-4 }, fromDoublei, L"Double To Int Failed");

			Vector2f fromIntf = intVector.ToType<float>();
			Vector2f fromDoublef = doubleVector.ToType<float>();
			TestVector2({ 3.0f,4.0f }, fromIntf, L"Int To Float Failed");
			TestVector2({ -3.9f,-4.9f }, fromDoublef, L"Double To Float Failed");

			Vector2d fromIntd = intVector.ToType<double>();
			Vector2d fromFloatd = floatVector.ToType<double>();
			TestVector2({ 3.0, 4.0 }, fromIntd, L"Int To Double Failed");
			TestVector2({ 3.5, -4.5 }, fromFloatd, L"Float to Double Failed");
		}

		TEST_METHOD(V2_Negation)
		{
			Vector2i intResult;
			const Vector2i intVector(3, 4);
			intResult = -intVector;
			Assert::AreEqual(-3, intResult.x);
			Assert::AreEqual(-4, intResult.y);

			Vector2f floatResult;
			const Vector2f floatVector(3.f, -4.f);
			floatResult = -floatVector;
			Assert::AreEqual(-3.f, floatResult.x);
			Assert::AreEqual(4.f, floatResult.y);

			Vector2d doubleResult;
			const Vector2d doubleVector(-3., -4.);
			doubleResult = -doubleVector;
			Assert::AreEqual(3., doubleResult.x);
			Assert::AreEqual(4., doubleResult.y);
		}

		TEST_METHOD(V2_Addition)
		{
			// Test Vector2<float> addition
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();

				Vector2f left(xRnd1, yRnd1);
				Vector2f right(xRnd2, yRnd2);

				// Test operator+
				Vector2f result = left + right;
				float xResult = xRnd1 + xRnd2;
				float yResult = yRnd1 + yRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector2<float> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector2<float> has an incorrect value.");
			}

			// Test Vector2<double> addition
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();

				Vector2d left(xRnd1, yRnd1);
				Vector2d right(xRnd2, yRnd2);

				// Test operator+
				Vector2d result = left + right;
				double xResult = xRnd1 + xRnd2;
				double yResult = yRnd1 + yRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector2<double> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector2<double> has an incorrect value.");
			}

			// Test Vector2<int> addition
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();

				Vector2i left(xRnd1, yRnd1);
				Vector2i right(xRnd2, yRnd2);

				// Test operator+
				Vector2i result = left + right;
				int xResult = xRnd1 + xRnd2;
				int yResult = yRnd1 + yRnd2;

				Assert::AreEqual(xResult, result.x, L"Addition: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Addition: Element y of Vector2<int> has an incorrect value.");

				// Test operator+=
				left += right;

				Assert::AreEqual(result.x, left.x, L"AdditionEqual: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"AdditionEqual: Element y of Vector2<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V2_Subtraction)
		{
			// Test Vector2<float> subtraction
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();

				Vector2f left(xRnd1, yRnd1);
				Vector2f right(xRnd2, yRnd2);

				// Test operator+
				Vector2f result = left - right;
				float xResult = xRnd1 - xRnd2;
				float yResult = yRnd1 - yRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector2<float> has an incorrect value.");

				// Test operator+=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector2<float> has an incorrect value.");
			}

			// Test Vector2<double> subtraction
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();

				Vector2d left(xRnd1, yRnd1);
				Vector2d right(xRnd2, yRnd2);

				// Test operator+
				Vector2d result = left - right;
				double xResult = xRnd1 - xRnd2;
				double yResult = yRnd1 - yRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector2<double> has an incorrect value.");

				// Test operator+=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector2<double> has an incorrect value.");
			}

			// Test Vector2<int> subtraction
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();

				Vector2i left(xRnd1, yRnd1);
				Vector2i right(xRnd2, yRnd2);

				// Test operator-
				Vector2i result = left - right;
				int xResult = xRnd1 - xRnd2;
				int yResult = yRnd1 - yRnd2;

				Assert::AreEqual(xResult, result.x, L"Subtraction: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Subtraction: Element y of Vector2<int> has an incorrect value.");

				// Test operator-=
				left -= right;

				Assert::AreEqual(result.x, left.x, L"SubtractionEqual: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(result.y, left.y, L"SubtractionEqual: Element y of Vector2<int> has an incorrect value.");
			}
		}

		TEST_METHOD(V2_Scalar_Multiplication)
		{
			// Test Vector2<float> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();

				float scalar = TestUtility::GetRandomFloat();

				Vector2f vec2(xRnd, yRnd);

				Vector2f result = vec2 * scalar;
				float xResult = xRnd * scalar;
				float yResult = yRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector2<float> has an incorrect value.");

				Vector2f result2 = scalar * vec2;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector2<float> has an incorrect value.");

				// Test operator*=
				vec2 *= scalar;

				Assert::AreEqual(result.x, vec2.x, L"Vector *= scalar: Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(result.y, vec2.y, L"Vector *= scalar: Element y of Vector2<float> has an incorrect value.");
			}

			// Test Vector2<double> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();

				double scalar = TestUtility::GetRandomDouble();

				Vector2d vec2(xRnd, yRnd);

				Vector2d result = vec2 * scalar;
				double xResult = xRnd * scalar;
				double yResult = yRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector2<double> has an incorrect value.");

				Vector2d result2 = scalar * vec2;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector2<double> has an incorrect value.");

				// Test operator*=
				vec2 *= scalar;

				Assert::AreEqual(result.x, vec2.x, L"Vector *= scalar: Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(result.y, vec2.y, L"Vector *= scalar: Element y of Vector2<double> has an incorrect value.");
			}

			// Test Vector2<int> multiplication with scalar
			for (int i = 0; i < 100; ++i)
			{
				int xRnd = TestUtility::GetRandomInt();
				int yRnd = TestUtility::GetRandomInt();

				int scalar = TestUtility::GetRandomInt();

				Vector2i vec2(xRnd, yRnd);

				Vector2i result = vec2 * scalar;
				int xResult = xRnd * scalar;
				int yResult = yRnd * scalar;

				Assert::AreEqual(xResult, result.x, L"Vector * scalar: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(yResult, result.y, L"Vector * scalar: Element y of Vector2<int> has an incorrect value.");

				Vector2i result2 = scalar * vec2;
				Assert::AreEqual(result.x, result2.x, L"Scalar * vector: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(result.y, result2.y, L"Scalar * vector: Element y of Vector2<int> has an incorrect value.");

				// Test operator*=
				vec2 *= scalar;

				Assert::AreEqual(result.x, vec2.x, L"Vector *= scalar: Element x of Vector2<int> has an incorrect value.");
				Assert::AreEqual(result.y, vec2.y, L"Vector *= scalar: Element y of Vector2<int> has an incorrect value.");
			}
		}
		TEST_METHOD(V2_Division)
		{
			// Test Vector2<float> division
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();

				float scalar = TestUtility::GetRandomFloat();

				Vector2f vec2(xRnd, yRnd);

				Vector2f result = vec2 / scalar;
				float xResult = xRnd / scalar;
				float yResult = yRnd / scalar;

				Vector2f expected(xResult, yResult);
				TestVector2(expected, result, L"Division with floats failed");
				// Test operator/=
				vec2 /= scalar;
				TestVector2(expected, vec2, L"Division and assign with floats failed");
			}

			// Test Vector2<double> division
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();

				double scalar = TestUtility::GetRandomDouble();

				Vector2d vec2(xRnd, yRnd);

				Vector2d result = vec2 / scalar;
				double xResult = xRnd / scalar;
				double yResult = yRnd / scalar;

				Vector2d expected(xResult, yResult);
				TestVector2(expected, result, L"Division with doubles failed");
				// Test operator/=
				vec2 /= scalar;
				TestVector2(expected, vec2, L"Division and assign with doubles failed");

			}

			// Test Vector2<int> division
			for (int i = 0; i < 100; ++i)
			{
				int xRnd = TestUtility::GetRandomInt();
				int yRnd = TestUtility::GetRandomInt();

				int scalar = TestUtility::GetRandomInt();

				Vector2i vec2(xRnd, yRnd);

				Vector2i result = vec2 / scalar;
				int xResult = xRnd / scalar;
				int yResult = yRnd / scalar;


				Vector2i expected(xResult, yResult);
				TestVector2(expected, result, L"Division with ints failed");
				// Test operator/=
				vec2 /= scalar;
				TestVector2(expected, vec2, L"Division and assign with ints failed");

			}
		}
		TEST_METHOD(V2_Length)
		{
			// Test Vector2<float> Length methods
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();

				Vector2f vec2(xRnd, yRnd);
				float lengthSqr = (xRnd * xRnd) + (yRnd * yRnd);
				float length = std::sqrt(lengthSqr);

				Assert::AreEqual(length, vec2.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector2<float> with random values.");
				Assert::AreEqual(lengthSqr, vec2.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector2<float> with random values.");
			}

			// Test Vector2<double> Length methods
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();

				Vector2d vec2(xRnd, yRnd);
				double lengthSqr = (xRnd * xRnd) + (yRnd * yRnd);
				double length = std::sqrt(lengthSqr);

				Assert::AreEqual(length, vec2.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector2<double> with random values.");
				Assert::AreEqual(lengthSqr, vec2.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector2<double> with random values.");
			}
		}

		// This test can result in a false positive (says it failed when the code is correct). 
		// This I probably due to the scheduler which can pause a process to fix something else in the OS
		// Run the several times if a failure happens. 
		// Through simple testing this test has a <10% false positive rate (so 3 failures in a row is at worst case a 0.1% chance)
		TEST_METHOD(V2_LengthSqrIsFasterThanLength)
		{
			constexpr size_t ammount = 10000000;
			{
				Vector2f* vectors = new Vector2f[ammount];
				float* results = new float[ammount];
				float* resultsSqr = new float[ammount];
				for (size_t i = 0; i < ammount; i++)
				{
					vectors[i].x = TestUtility::GetRandomFloat();
					vectors[i].y = TestUtility::GetRandomFloat();
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
				Logger::WriteMessage(" float Vector2 Lengths: ");
				Logger::WriteMessage(std::to_string(LengthDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");
				Logger::WriteMessage("\n");
				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" float Vector2 Squared Lengths: ");
				Logger::WriteMessage(std::to_string(LengthSqrDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");

				Assert::IsTrue(LengthDuration >= LengthSqrDuration, 
					L"LengthSqr is slower than Length. This should not be the case");
			}
			Logger::WriteMessage("\n");
			{
				Vector2d* vectors = new Vector2d[ammount];
				double* results = new double[ammount];
				double* resultsSqr = new double[ammount];
				for (size_t i = 0; i < ammount; i++)
				{
					vectors[i].x = TestUtility::GetRandomDouble();
					vectors[i].y = TestUtility::GetRandomDouble();
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
				Logger::WriteMessage(" double Vector2 Lengths: ");
				Logger::WriteMessage(std::to_string(LengthDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");
				Logger::WriteMessage("\n");
				Logger::WriteMessage("Time to calculate ");
				Logger::WriteMessage(std::to_string(ammount).c_str());
				Logger::WriteMessage(" double Vector2 Squared Lengths: ");
				Logger::WriteMessage(std::to_string(LengthSqrDuration.count()).c_str());
				Logger::WriteMessage(" milliseconds");

				Assert::IsTrue(LengthDuration >= LengthSqrDuration, 
					L"LengthSqr is slower than Length. This should not be the case. Try the test again because the scheduler can affect this measurement");
			}
		}
		TEST_METHOD(V2_Unit_Vector_Length)
		{
			// Test Vector2<float> Length methods on unit vectors
			Vector2f unitXf, unitYf;
			unitXf.x = 1.0f;
			unitYf.y = 1.0f;

			Assert::AreEqual(1.0f, unitXf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector2<float> with values (1.0f, 0.0f).");
			Assert::AreEqual(1.0f, unitXf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector2<float> with values (1.0f, 0.0f).");

			Assert::AreEqual(1.0f, unitYf.Length(), ourToleranceF, L"Length(): Incorrect length returned for Vector2<float> with values (0.0f, 1.0f).");
			Assert::AreEqual(1.0f, unitYf.LengthSqr(), ourToleranceF, L"LengthSqr(): Incorrect squared length returned for Vector2<float> with values (0.0f, 1.0f).");

			// Test Vector2<double> Length methods on unit vectors
			Vector2d unitXd, unitYd;
			unitXd.x = 1.0f;
			unitYd.y = 1.0f;

			Assert::AreEqual(1.0, unitXd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector2<double> with values (1.0, 0.0).");
			Assert::AreEqual(1.0, unitXd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector2<double> with values (1.0, 0.0).");

			Assert::AreEqual(1.0, unitYd.Length(), ourToleranceD, L"Length(): Incorrect length returned for Vector2<double> with values (0.0, 1.0).");
			Assert::AreEqual(1.0, unitYd.LengthSqr(), ourToleranceD, L"LengthSqr(): Incorrect squared length returned for Vector2<double> with values (0.0, 1.0).");

			// Test Vector<int> Length methods on unit vectors
			Vector2i unitXi, unitYi;
			unitXi.x = 1;
			unitYi.y = 1;

			Assert::AreEqual(1, unitXi.Length(), L"Length(): Incorrect length returned for Vector2<int> with values (1, 0).");
			Assert::AreEqual(1, unitXi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector2<int> with values (1, 0).");

			Assert::AreEqual(1, unitYi.Length(), L"Length(): Incorrect length returned for Vector2<int> with values (0, 1).");
			Assert::AreEqual(1, unitYi.LengthSqr(), L"LengthSqr(): Incorrect squared length returned for Vector2<int> with values (0, 1).");
		}

		TEST_METHOD(V2_Normalise)
		{
			// Test Vector2<float> Normalise methods
			for (int i = 0; i < 100; ++i)
			{
				float xRnd = TestUtility::GetRandomFloat();
				float yRnd = TestUtility::GetRandomFloat();

				Vector2f vec2(xRnd, yRnd);
				Vector2f normalised = vec2.GetNormalized();

				float length = std::sqrt((xRnd * xRnd) + (yRnd * yRnd));
				float lengthInv = 1.0f / length;

				float resultX = xRnd * lengthInv;
				float resultY = yRnd * lengthInv;

				Assert::AreEqual(resultX, normalised.x, ourToleranceF, L"GetNormalized(): Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(resultY, normalised.y, ourToleranceF, L"GetNormalized(): Element y of Vector2<float> has an incorrect value.");

				vec2.Normalize();
				Assert::AreEqual(normalised.x, vec2.x, ourToleranceF, L"Normalize(): Element x of Vector2<float> has an incorrect value.");
				Assert::AreEqual(normalised.y, vec2.y, ourToleranceF, L"Normalize(): Element y of Vector2<float> has an incorrect value.");
			}

			// Test Vector2<double> Normalise methods
			for (int i = 0; i < 100; ++i)
			{
				double xRnd = TestUtility::GetRandomDouble();
				double yRnd = TestUtility::GetRandomDouble();

				Vector2d vec2(xRnd, yRnd);
				Vector2d normalised = vec2.GetNormalized();

				double length = std::sqrt((xRnd * xRnd) + (yRnd * yRnd));
				double lengthInv = 1.0 / length;

				double resultX = xRnd * lengthInv;
				double resultY = yRnd * lengthInv;

				Assert::AreEqual(resultX, normalised.x, ourToleranceD, L"GetNormalized(): Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(resultY, normalised.y, ourToleranceD, L"GetNormalized(): Element y of Vector2<double> has an incorrect value.");

				vec2.Normalize();
				Assert::AreEqual(normalised.x, vec2.x, ourToleranceD, L"Normalize(): Element x of Vector2<double> has an incorrect value.");
				Assert::AreEqual(normalised.y, vec2.y, ourToleranceD, L"Normalize(): Element y of Vector2<double> has an incorrect value.");
			}
		}

		TEST_METHOD(V2_Length_Zero_Vector)
		{
			// Test Vector2<float> Length methods for zero vector
			Vector2f vec2f;

			Assert::AreEqual(0.0f, vec2f.Length(), ourToleranceF, L"Length(): Vector2<float> Zero vector doesn't have zero length.");
			Assert::AreEqual(0.0f, vec2f.LengthSqr(), ourToleranceF, L"Length(): Vector2<float> Zero vector doesn't have zero squared length.");

			// Test Vector2<double> Length methods for zero vector
			Vector2d vec2d;

			Assert::AreEqual(0.0, vec2d.Length(), ourToleranceD, L"Length(): Vector2<double> Zero vector doesn't have zero length.");
			Assert::AreEqual(0.0, vec2d.LengthSqr(), ourToleranceD, L"Length(): Vector2<double> Zero vector doesn't have zero squared length.");

			// Test Vector2<int> Length methods for zero vector
			Vector2i vec2i;

			Assert::AreEqual(0, vec2i.Length(), L"Length(): Vector2<int> Zero vector doesn't have zero length.");
			Assert::AreEqual(0, vec2i.LengthSqr(), L"Length(): Vector2<int> Zero vector doesn't have zero squared length.");
		}

		TEST_METHOD(V2_Normalise_Zero_Vector)
		{
			// Test Vector2<float> Normalise methods for zero vector
			Vector2f vec2f;
			Vector2f normalisedF = vec2f.GetNormalized();
			vec2f.Normalize();

			Assert::AreEqual(0.0f, normalisedF.x, ourToleranceF, L"GetNormalized() on zero vector: Element x of Vector2<float> is not 0.0f.");
			Assert::AreEqual(0.0f, normalisedF.y, ourToleranceF, L"GetNormalized() on zero vector: Element y of Vector2<float> is not 0.0f.");

			Assert::AreEqual(0.0f, vec2f.x, ourToleranceF, L"Normalize(): Element x of Vector2<float> is not 0.0f.");
			Assert::AreEqual(0.0f, vec2f.y, ourToleranceF, L"Normalize(): Element y of Vector2<float> is not 0.0f.");

			// Test Vector2<double> Normalise methods for zero vector
			Vector2d vec2d;
			Vector2d normalisedD = vec2d.GetNormalized();
			vec2d.Normalize();

			Assert::AreEqual(0.0, normalisedD.x, ourToleranceD, L"GetNormalized() on zero vector: Element x of Vector2<double> is not 0.0.");
			Assert::AreEqual(0.0, normalisedD.y, ourToleranceD, L"GetNormalized() on zero vector: Element y of Vector2<double> is not 0.0.");

			Assert::AreEqual(0.0, vec2d.x, ourToleranceD, L"Normalize(): Element x of Vector2<double> is not 0.0.");
			Assert::AreEqual(0.0, vec2d.y, ourToleranceD, L"Normalize(): Element y of Vector2<double> is not 0.0.");

			// Test Vector2<int> Normalise methods for zero vector
			Vector2i vec2i;
			Vector2i normalisedI = vec2i.GetNormalized();
			vec2i.Normalize();

			Assert::AreEqual(0, normalisedI.x, L"GetNormalized() on zero vector: Element x of Vector2<int> is not 0.");
			Assert::AreEqual(0, normalisedI.y, L"GetNormalized() on zero vector: Element y of Vector2<int> is not 0.");

			Assert::AreEqual(0, vec2i.x, L"Normalize(): Element x of Vector2<int> is not 0.");
			Assert::AreEqual(0, vec2i.y, L"Normalize(): Element y of Vector2<int> is not 0.");
		}

		TEST_METHOD(V2_Component_Multiplication)
		{
			Vector2i lhs(1, 2);
			Vector2i rhs(5, 6);
			Vector2i product = lhs * rhs;

			Assert::AreEqual(5, product.x, L"The x element is wrong in the component multiplication product.");
			Assert::AreEqual(12, product.y, L"The y element is wrong in the component multiplication product.");

			// Exhastive Test Vector2<float> component product
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();

				Vector2f left(xRnd1, yRnd1);
				Vector2f right(xRnd2, yRnd2);

				Vector2f result = left * right;
				Vector2f resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, ourToleranceF, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, ourToleranceF, L"The component multiplication product should be the same regardless of order.");

				float resultX = xRnd1 * xRnd2;
				float resultY = yRnd1 * yRnd2;

				Assert::AreEqual(resultX, result.x, ourToleranceF, L"The x element is wrong in the component multiplication product for Vector2<float>.");
				Assert::AreEqual(resultY, result.y, ourToleranceF, L"The y element is wrong in the component multiplication product for Vector2<float>.");
			}

			// Exhastive Test Vector2<double> component product
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();

				Vector2d left(xRnd1, yRnd1);
				Vector2d right(xRnd2, yRnd2);

				Vector2d result = left * right;
				Vector2d resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, ourToleranceD, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, ourToleranceD, L"The component multiplication product should be the same regardless of order.");

				double resultX = xRnd1 * xRnd2;
				double resultY = yRnd1 * yRnd2;

				Assert::AreEqual(resultX, result.x, ourToleranceD, L"The x element is wrong in the component multiplication product for Vector2<double>.");
				Assert::AreEqual(resultY, result.y, ourToleranceD, L"The y element is wrong in the component multiplication product for Vector2<double>.");
			}

			// Exhastive Test Vector2<int> component product
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();

				Vector2i left(xRnd1, yRnd1);
				Vector2i right(xRnd2, yRnd2);

				Vector2i result = left * right;
				Vector2i resultRL = left * right;

				Assert::AreEqual(result.x, resultRL.x, L"The component multiplication product should be the same regardless of order.");
				Assert::AreEqual(result.y, resultRL.y, L"The component multiplication product should be the same regardless of order.");

				int resultX = xRnd1 * xRnd2;
				int resultY = yRnd1 * yRnd2;

				Assert::AreEqual(resultX, result.x, L"The x element is wrong in the component multiplication product for Vector2<int>.");
				Assert::AreEqual(resultY, result.y, L"The y element is wrong in the component multiplication product for Vector2<int>.");
			}
		}
		TEST_METHOD(V2_Dot)
		{
			// Test Vector2<float> Dot product
			for (int i = 0; i < 100; ++i)
			{
				float xRnd1 = TestUtility::GetRandomFloat();
				float yRnd1 = TestUtility::GetRandomFloat();

				float xRnd2 = TestUtility::GetRandomFloat();
				float yRnd2 = TestUtility::GetRandomFloat();

				Vector2f left(xRnd1, yRnd1);
				Vector2f right(xRnd2, yRnd2);

				float dotLR = left.Dot(right);
				float dotRL = right.Dot(left);
				float result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2);

				Assert::AreEqual(dotLR, dotRL, ourToleranceF, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector2<float>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector2<float>.");
			}

			// Test Vector2<double> Dot product
			for (int i = 0; i < 100; ++i)
			{
				double xRnd1 = TestUtility::GetRandomDouble();
				double yRnd1 = TestUtility::GetRandomDouble();

				double xRnd2 = TestUtility::GetRandomDouble();
				double yRnd2 = TestUtility::GetRandomDouble();

				Vector2d left(xRnd1, yRnd1);
				Vector2d right(xRnd2, yRnd2);

				double dotLR = left.Dot(right);
				double dotRL = right.Dot(left);
				double result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2);

				Assert::AreEqual(dotLR, dotRL, ourToleranceD, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector2<double>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector2<double>.");
			}

			// Test Vector2<int> Dot product
			for (int i = 0; i < 100; ++i)
			{
				int xRnd1 = TestUtility::GetRandomInt();
				int yRnd1 = TestUtility::GetRandomInt();

				int xRnd2 = TestUtility::GetRandomInt();
				int yRnd2 = TestUtility::GetRandomInt();

				Vector2i left(xRnd1, yRnd1);
				Vector2i right(xRnd2, yRnd2);

				int dotLR = left.Dot(right);
				int dotRL = right.Dot(left);
				int result = (xRnd1 * xRnd2) + (yRnd1 * yRnd2);

				Assert::AreEqual(dotLR, dotRL, L"Dot product: a.Dot(b) should be equal to b.Dot(a) but is not when using two Vector2<int>.");
				Assert::AreEqual(result, dotLR, L"Dot product: Incorrect result when using two Vector2<int>.");
			}
		}

	private:
		static const float ourToleranceF;
		static const double ourToleranceD;
	};

	const float Vector2Test::ourToleranceF = 0.00001f;
	const double Vector2Test::ourToleranceD = 0.00001;
}