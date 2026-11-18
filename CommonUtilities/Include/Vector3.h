#pragma once

#include <cmath>

namespace Tga
{
	template <typename T>
	class Vector3;
}
namespace CommonUtilities
{
	template <typename T>
	class Vector3
	{
	public:
		T x; // Note: this variable is explicitly public.
		T y; // Note: this variable is explicitly public.
		T z; // Note: this variable is explicitly public.
		// Creates a zero-vector
		Vector3() :
			x(0),
			y(0),
			z(0) { }
		// Creates a vector (aX, aY, aZ)
		Vector3(const T& aX, const T& aY, const T& aZ) :
			x(aX),
			y(aY),
			z(aZ) { }
		// Copy constructor (compiler generated)
		//Vector3(const Vector3<T>& aVector) = default;
		// Assignment operator (compiler generated)
		//Vector3<T>& operator=(const Vector3<T>& aVector3) = default;
		// Destructor (compiler generated)
		//~Vector3() = default;
		
		// Returns a CommonUtilities::Vector3 copy with another datatype as elements,
		// ex: converts from Vector3<int> to Vector3<float>
		// to explicitly do operations, such as addition, for an explicit type
		template<class TargetType>
		Vector3<TargetType> ToType() const
		{
			return Vector3<TargetType>(static_cast<TargetType>(x), static_cast<TargetType>(y), static_cast<TargetType>(z));
		}
		// Returns a copy of the vector as a Tga vector, use to interface with TGE
		Tga::Vector3<T> ToTga() const
		{
			return { x,y,z };
		}
		// Returns a negated copy of the vector
		Vector3<T> operator-() const
		{
			return Vector3(-x, -y, -z);
		}
		// Returns the squared length of the vector, optimization compared to length
		T LengthSqr() const
		{
			return (x * x) + (y * y) + (z * z);
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
		Vector3<T> GetNormalized() const
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
		T Dot(const Vector3<T>& aVector) const
		{
			return (x * aVector.x) + (y * aVector.y) + (z * aVector.z);
		}
		// Returns the cross product of this and aVector. Only for Vector3
		Vector3<T> Cross(const Vector3<T>& aVector) const
		{
			return Vector3(
				(y * aVector.z) - (z * aVector.y),
				(z * aVector.x) - (x * aVector.z),
				(x * aVector.y) - (y * aVector.x)
			);
		}
	};
	// Returns the resulting vector sum from performing addition:
	// lhs + rhs
	template <typename T>
	inline Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}
	// Returns the resulting vector sum from performing difference:
	// lhs - rhs
	template <typename T>
	inline Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}
	// Returns the resulting vector from performing component wise multiplication:
	// lhs * rhs
	template <typename T>
	inline Vector3<T> operator*(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
	}
	// Returns the resulting scaled vector from performing scalar multiplication:
	// aVector * aScalar
	template <typename T>
	inline Vector3<T> operator*(const Vector3<T>& aVector, const T& aScalar)
	{
		return Vector3<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar);
	}
	// Returns the resulting scaled vector from performing scalar multiplication:
	// aScalar * aVector
	template <typename T>
	inline Vector3<T> operator*(const T& aScalar, const Vector3<T>& aVector)
	{
		return aVector * aScalar;
	}
	// Returns the resulting scaled vector from performing scalar division:
	// aVector / aScalar
	template <typename T>
	inline Vector3<T> operator/(const Vector3<T>& aVector, const T& aScalar)
	{
		return Vector3<T>(aVector.x / aScalar, aVector.y / aScalar, aVector.z / aScalar);
	}
	// Apply and return vector sum from performing addition:
	// lhs += rhs
	// Equivalent to: lhs = lhs+rhs
	template <typename T>
	inline Vector3<T>& operator+=(Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		aVector0 = aVector0 + aVector1;
		return aVector0;
	}
	// Apply and return vector difference from performing subtraction:
	// lhs -= rhs
	// Equivalent to: lhs = lhs-rhs
	template <typename T>
	inline Vector3<T>& operator-=(Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		aVector0 = aVector0 - aVector1;
		return aVector0;
	}
	// Apply and return the scaled vector when performing scalar multiplication:
	// aVector *= aScalar
	// Equivalent to: aVector = aVector * aScalar
	template <typename T>
	inline Vector3<T>& operator*=(Vector3<T>& aVector, const T& aScalar)
	{
		aVector = aVector * aScalar;
		return aVector;
	}
	// Apply and return the scaled vector when performing scalar division:
	// aVector /= aScalar
	// Equivalent to: aVector = aVector / aScalar
	template <typename T>
	inline Vector3<T>& operator/=(Vector3<T>& aVector, const T& aScalar)
	{
		aVector = aVector / aScalar;
		return aVector;
	}
}