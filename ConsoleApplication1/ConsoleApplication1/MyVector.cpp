#include "MyVector.h"
#include <algorithm>


MyVector::MyVector(int capacity) : _container(new MyObject[capacity]), _size(0), _capacity(capacity) { }

MyVector::MyVector(const MyVector& other) : _container(other._container), _size(other._size), _capacity(other._capacity)
{
	for (int i = 0; i < other._size; ++i)
	{
		_container[i] = other._container[i];
	}
}

MyVector& MyVector::operator=(const MyVector& other)
{
	if (this == &other)
	{
		return*this;
	}
	MyVector temp(other);
	std::swap(_container, temp._container);
	std::swap(_size, temp._size);
	std::swap(_capacity, temp._capacity);
	return*this;
}

MyVector::~MyVector()
{
	MyVector::clear();
}

// Returns current capacity of this vector.
int MyVector::GetCapacity() const
{
	return _capacity;
}

// Returns current size of this vector.
int MyVector::GetSize() const
{
	return _size;
}

// Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
void MyVector::Add(int id)
{
	if (_capacity == 0)
	{
		reserve(1);
	}
	else if (_size == _capacity)
	{
		reserve(_capacity * 2);
	}
	end()->_id = id;
	++_size;
}

// Returns the first occurrence of MyObject instance with the given ID.
// Returns nullptr if not found.
MyObject* MyVector::FindById(int MyObjectId) const
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (MyObjectId == _container[i]._id)
			return &_container[i];
	}
	return nullptr;
}

// Trims the capacity of this vector to current size.
void MyVector::TrimToSize()
{
	if (_size == _capacity)
	{
		return;
	}

	reallocate(_size);

}

// Returns the MyObject instance at the specified index.
MyObject& MyVector::operator[](size_t index)
{
	return _container[index];
}

// Returns string representation of the vector.
std::string MyVector::ToString() const
{
	std::string str= "[ " + std::to_string(_container[0]._id);
	for (size_t i = 1; i < _size; ++i)
	{
		str += ", ";
		str += std::to_string(_container[i]._id);
	}
	str += "]";
	/*
	#include <sstream>
	
	std::stringstream ss;
	ss << "[";
	for (size_t i = 0; i < _size; ++i)
	{
		ss<< _container[i]._id << ", ";
	}
	ss << "]";
	
	return 
	*/

	return str;
}

// Remove all MyObject instances with the given ID in this vector.
void MyVector::RemoveAll(int MyObjectId)
{
	size_t size = _size;
	for (size_t i = 0; i < size; ++i)
	{
		if (_container[i]._id == MyObjectId)
		{
			erase(&_container[i]);
			--i;
			--size;
		}
	}
}

// Returns a newly allocated array of MyVector objects,
// each of whose elements have the same "_id" value of the MyObject struct.
// The 'numGroups' is an out parameter, and its value should be set to
// the size of the MyVector array to be returned.
MyVector* MyVector::GroupById(int* numGroups)
{
	MyVector ids;
	for (size_t i = 0; i < _size; ++i)
	{
		if (nullptr == ids.FindById(_container[i]._id))
		{
			ids.Add(_container[i]._id);
		}
	}

	int count = ids.GetSize();
	MyVector* result = new MyVector[count];

	for (size_t i = 0; i < _size; ++i)
	{

	}
}