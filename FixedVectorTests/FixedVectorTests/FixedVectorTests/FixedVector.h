#pragma once
#include <cassert>
namespace CommonUtilities
{
	/// <summary>
	/// Implements a class with similar interface to std::vector, but stores data inlined in the class with a fixed
	///storage capacity.
	 //</summary>
	// <typeparam name="Type"></typeparam>
	// <typeparam name="SizeType"></typeparam>
	// <typeparam name="CAPACITY"></typeparam>
	///// 
	template <typename Type, unsigned int CAPACITY, typename SizeType = unsigned int>
	class FixedVector
	{
	public:
		typedef Type* iterator;
		typedef const Type* const_iterator;

		FixedVector();
		FixedVector(const FixedVector& aFixedVector);
		~FixedVector();
		FixedVector& operator=(const FixedVector& aFixedVector);

		Type& front();
		const Type& front() const;
		Type& back();
		const Type& back() const;

		Type& at(SizeType aIndex);
		const Type& at(SizeType aIndex) const;

		const Type& operator[](SizeType aIndex) const;
		Type& operator[](SizeType aIndex);

		void push_back(const Type& aObject);
		void insert(iterator aIterator, const Type& aObject);
		void erase(iterator aIterator);
		void pop_back();

		iterator begin();
		const_iterator begin() const;
		const_iterator cbegin() const;

		iterator end();
		const_iterator end() const;
		const_iterator cend() const;

		void clear();
		void resize(SizeType newSize);
		void resize(SizeType newSize, const Type& value);

		bool empty() const;
		SizeType size() const;
		SizeType capacity() const;

	private:
		SizeType mySize = 0;
		bool myIsAsserted = false;
		Type myStorage[CAPACITY]; //<- for G
		//alignas(Type) char myStorage[sizeof(Type) * CAPACITY]; // <- needed for VG
	};
}

namespace CommonUtilities
{
	template<typename Type, unsigned int CAPACITY, typename SizeType>

	FixedVector<Type, CAPACITY, SizeType>::FixedVector()
	{}
	template<typename Type, unsigned int CAPACITY, typename SizeType>

	FixedVector<Type, CAPACITY, SizeType>::FixedVector(const FixedVector& aFixedVector)
	{
		for (SizeType i = 0; i < CAPACITY; i++)
		{
			myStorage[i] = aFixedVector[i];
		}
		*this = aFixedVector;
	}
	template<typename Type, unsigned int CAPACITY, typename SizeType>

	FixedVector<Type, CAPACITY, SizeType>::~FixedVector()
	{}
	template <typename Type, unsigned int CAPACITY, typename SizeType>
	CommonUtilities::FixedVector<Type, CAPACITY, SizeType>& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::operator
		=(const FixedVector& aFixedVector)
	{

		if (this != &aFixedVector)
		{
			mySize = CAPACITY;
			for (SizeType i = 0; i < mySize; i++)
			{
				myStorage[i] = aFixedVector[i];
			}
		}
		return *this;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::front()
	{
		myIsAsserted = (mySize > 0);

		if (!myIsAsserted)
		{
			throw "Front failed";
		}
		assert(myIsAsserted);
		return myStorage[0];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::front() const
	{
		myIsAsserted = (mySize >= 0);
		if (!myIsAsserted)
		{
			throw "Front failed";
		}
		assert(myIsAsserted);
		return  myStorage[0];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::back()
	{
		myIsAsserted = (mySize > 0);

		if (!myIsAsserted)
		{
			throw "Back Failed";
		}
		assert(myIsAsserted);

		return myStorage[mySize - 1];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::back() const
	{
		myIsAsserted = (mySize > 0);
		if (!myIsAsserted)
		{
			throw "Back Failed";
		}
		assert(myIsAsserted);

		return myStorage[mySize - 1];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::at(SizeType aIndex)
	{
		myIsAsserted = (aIndex < CAPACITY);
		if (!myIsAsserted)
		{
			throw "At Failed";
		}
		assert(myIsAsserted);
		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::at(SizeType aIndex) const
	{
		myIsAsserted = (aIndex < mySize && aIndex >= 0);

		if (!myIsAsserted)
		{
			throw "At failed";
		}
		assert(myIsAsserted);
		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::operator[](SizeType aIndex) const
	{

		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::operator[](SizeType aIndex)
	{
		myIsAsserted = (aIndex < mySize && aIndex >= 0);

		if (!myIsAsserted)
		{
			throw "Operator failed";
		}
		assert(myIsAsserted);

		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::push_back(const Type& aObject)
	{
		myIsAsserted = (mySize < CAPACITY);
		if (mySize >= CAPACITY)
		{
			throw "PushBack failed";
		}
		assert(myIsAsserted);

		myStorage[mySize] = aObject;
		mySize++;

	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::insert(iterator aIterator, const Type& aObject)
	{
		myIsAsserted = (mySize < CAPACITY && aIterator >= &myStorage[0] && aIterator <= &myStorage[mySize]);

		if (!myIsAsserted)
		{
			throw "Insert failed";
		}
		assert(myIsAsserted);
		if (mySize == 0)
		{
			push_back(aObject);
			return;
		}

		for (iterator i = end(); i > aIterator; i--)
		{
			*i = *(i - 1);
		}
		*aIterator = aObject;
		++mySize;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::erase(iterator aIterator)
	{
		myIsAsserted = (mySize > 0 && aIterator >= &myStorage[0] && aIterator < &myStorage[mySize]);
		if (!myIsAsserted)
		{
			throw "Erase failed";
		}
		assert(myIsAsserted);

		for (iterator i = aIterator; i < end() - 1; i++)
		{

			*i = *(i + 1);
		}

		pop_back();

	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::pop_back()
	{

		--mySize;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::iterator CommonUtilities::FixedVector<Type, CAPACITY,
		SizeType>::begin()
	{
		return &myStorage[0];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::begin() const
	{

		return &myStorage[0];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::cbegin() const
	{
		return &myStorage[0];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::iterator CommonUtilities::FixedVector<Type, CAPACITY,
		SizeType>::end()
	{
		return &myStorage[mySize];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::end() const
	{
		return &myStorage[mySize];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::cend() const
	{
		return &myStorage[mySize];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::clear()
	{

		mySize = 0;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::resize(SizeType newSize)
	{
		if (newSize > CAPACITY)
		{
			throw "resize failed";
		}
		assert(newSize < CAPACITY);
		mySize = newSize;

	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::resize(SizeType newSize, const Type& value)
	{
		if (newSize > CAPACITY)
		{
			throw "resize failed";
		}
		assert(newSize < CAPACITY);

		SizeType a = mySize;
		mySize = newSize;
		for (SizeType i = newSize; i > a; i--)
		{
			myStorage[i - 1] = value;
		}
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	bool CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::empty() const
	{
		if (mySize == 0)
		{
			return true;
		}
		return false;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	SizeType CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::size() const
	{
		return mySize;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	SizeType CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::capacity() const
	{
		return CAPACITY;
	}

}

