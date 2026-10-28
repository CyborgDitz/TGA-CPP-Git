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
			for (SizeType i = 0; i < CAPACITY; i++)
			{
				myStorage[i] = aFixedVector[i];
			}
		}
		return *this;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::front()
	{
		assert(mySize > 0);
		return myStorage[0];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::front() const
	{
		assert(mySize >= 0);
		return  myStorage[0];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::back()
	{
		(mySize > 0);
		return myStorage[mySize];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::back() const
	{
		(mySize > 0);
		return myStorage[mySize];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::at(SizeType aIndex)
	{
		(aIndex < mySize && aIndex >= 0);
		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::at(SizeType aIndex) const
	{
		(aIndex < mySize && aIndex >= 0);
		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	const Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::operator[](SizeType aIndex) const
	{
		(aIndex < mySize && aIndex >= 0);
		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	Type& CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::operator[](SizeType aIndex)
	{
		(aIndex < mySize && aIndex >= 0);
		return myStorage[aIndex];
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::push_back(const Type& aObject)
	{
		myStorage[mySize] = aObject;
		mySize++;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::insert(iterator aIterator, const Type& aObject)
	{
		assert(aIterator > &myStorage[0] && aIterator < &myStorage[mySize]);
		mySize++;
		for (int i = mySize;  i > 0; i--)
		{
			if (&myStorage[i] == aIterator)
			{
				*aIterator = aObject;
				return;
			}
			myStorage[i] = myStorage[i-1];
			
		}
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::erase(iterator aIterator)
	{
		// assert aIterator > ?myStorage
		myStorage[0];
		
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::pop_back()
	{
		(mySize < CAPACITY);
		mySize = 0;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::iterator CommonUtilities::FixedVector<Type, CAPACITY,
		SizeType>::begin()
	{
		(mySize > 0);
		return myStorage;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::begin() const
	{
		(mySize > 0);
		return myStorage;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::cbegin() const
	{
		(mySize > 0);
		return myStorage;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::iterator CommonUtilities::FixedVector<Type, CAPACITY,
		SizeType>::end()
	{
		(mySize > 0);
		return myStorage;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::end() const
	{
		//TODO redo
		(mySize > 0);
		return myStorage;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	typename CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::const_iterator CommonUtilities::FixedVector<Type,
		CAPACITY, SizeType>::cend() const
	{
		//TODO redo
		(mySize > 0);
		return myStorage;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::clear()
	{
		//TODO redo
		mySize = 0;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::resize(SizeType newSize)
	{
		//TODO redo
		mySize = newSize;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	void CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::resize(SizeType newSize, const Type& value)
	{
		//TODO redo
		int i = 0;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	bool CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::empty() const
	{
		return true;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	SizeType CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::size() const
	{
		return mySize;
	}

	template <typename Type, unsigned int CAPACITY, typename SizeType>
	SizeType CommonUtilities::FixedVector<Type, CAPACITY, SizeType>::capacity() const
	{
		(mySize > 0);
		return CAPACITY;
	}
}

