#pragma once

#include <cmath>

//namespace Tga
//{
//	template <typename T>
//	class Vector2;
//	//class Vector2
//	//{
//	//	Vector2() :
//	//		x(0),
//	//		y(0)
//	//	{
//	//	}
//	//	// Creates a vector (aX, aY, aZ)
//	//	Vector2(const T& aX, const T& aY) :
//	//		x(aX),
//	//		y(aY)
//	//	{
//	//	}
//	//};
//
//}
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
namespace CommonUtilities
{
	template <typename T>
	class Vector2
	{
	public:
		T x; // Note: this variable is explicitly public.
		T y; // Note: this variable is explicitly public.
		// Creates a zero-vector
		Vector2() :
			x(0),
			y(0)
		{
		}
		// Creates a vector (aX, aY, aZ)
		Vector2(const T& aX, const T& aY) :
			x(aX),
			y(aY)
		{
		}
		// Copy constructor (compiler generated)
		//Vector2(const Vector2<T>& aVector) = default;
		// Assignment operator (compiler generated)
		//Vector2<T>& operator=(const Vector2<T>& aVector2) = default;
		// Destructor (compiler generated)
		//~Vector2() = default;

		// Returns a CommonUtilities::Vector2 copy with another datatype as elements,
		// ex: converts from Vector2<int> to Vector2<float>
		// to explicitly do operations, such as addition, for an explicit type
		template<class TargetType>
		Vector2<TargetType> ToType() const
		{
			return Vector2<TargetType>(static_cast<TargetType>(x), static_cast<TargetType>(y));
		}
		// Returns a copy of the vector as a Tga vector, use to interface with TGE
		Tga::Vector2<T> ToTga() const
		{
			return Tga::Vector2<T>(x, y);
		}
		// Returns a negated copy of the vector
		Vector2<T> operator-() const
		{
			return Vector2<T>(-x, -y);
		}
		// Returns the squared length of the vector, optimization compared to length
		T LengthSqr() const
		{
			return (x * x) + (y * y);
		}
		// Returns the length of a vector, int vector is not required to work
		T Length() const
		{
			return static_cast<T>(std::sqrt(LengthSqr()));
		}
		// Returns a normalized copy of this vector
		// For int vectors, expected is integer division
		// example (1,2,3)/5 = (0, 0, 0) should be expected
		// Handle normalization of zero-vector by returning the zero vector
		Vector2<T> GetNormalized() const
		{
			const T length = Length();
			if (length != 0)
			{
				return *this / length;
			}
			return *this;
		}
		// Normalizes the vector
		// For int vectors, expected is integer division
		// example (1,2,3)/5 = (0, 0, 0) should be expected
		// Handle normalization of zero-vector by not modifying the vector
		void Normalize()
		{
			*this = GetNormalized();
		}
		// Returns the dot product of this and aVector
		T Dot(const Vector2<T>& aVector) const
		{
			return (x * aVector.x) + (y * aVector.y);
		}
		// Returns the cross product of this and aVector. Only for Vector2

	};
	// Returns the resulting vector sum from performing addition:
	// lhs + rhs
	template <typename T>
	inline Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
	}
	// Returns the resulting vector sum from performing difference:
	// lhs - rhs
	template <typename T>
	inline Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
	}
	// Returns the resulting vector from performing component wise multiplication:
	// lhs * rhs
	template <typename T>
	inline Vector2<T> operator*(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
	}
	// Returns the resulting scaled vector from performing scalar multiplication:
	// aVector * aScalar
	template <typename T>
	inline Vector2<T> operator*(const Vector2<T>& aVector, const T& aScalar)
	{
		return Vector2<T>(aVector.x * aScalar, aVector.y * aScalar);
	}
	// Returns the resulting scaled vector from performing scalar multiplication:
	// aScalar * aVector
	template <typename T>
	inline Vector2<T> operator*(const T& aScalar, const Vector2<T>& aVector)
	{
		return aVector * aScalar;
	}
	// Returns the resulting scaled vector from performing scalar division:
	// aVector / aScalar
	template <typename T>
	inline Vector2<T> operator/(const Vector2<T>& aVector, const T& aScalar)
	{
		return Vector2<T>(aVector.x / aScalar, aVector.y / aScalar);
	}
	// Apply and return vector sum from performing addition:
	// lhs += rhs
	// Equivalent to: lhs = lhs+rhs
	template <typename T>
	inline Vector2<T>& operator+=(Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		aVector0 = aVector0 + aVector1;
		return aVector0;
	}
	// Apply and return vector difference from performing subtraction:
	// lhs -= rhs
	// Equivalent to: lhs = lhs-rhs
	template <typename T>
	inline Vector2<T>& operator-=(Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		aVector0 = aVector0 - aVector1;
		return aVector0;
	}
	// Apply and return the scaled vector when performing scalar multiplication:
	// aVector *= aScalar
	// Equivalent to: aVector = aVector * aScalar
	template <typename T>
	inline Vector2<T>& operator*=(Vector2<T>& aVector, const T& aScalar)
	{
		aVector = aVector * aScalar;
		return aVector;
	}
	// Apply and return the scaled vector when performing scalar division:
	// aVector /= aScalar
	// Equivalent to: aVector = aVector / aScalar
	template <typename T>
	inline Vector2<T>& operator/=(Vector2<T>& aVector, const T& aScalar)
	{
		aVector = aVector / aScalar;
		return aVector;
	}
}