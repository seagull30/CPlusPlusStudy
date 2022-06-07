#include "Vector.h"
#include <algorithm>

MyVector::MyVector(int capacity) : _object(new MyObject[capacity]), _size(capacity), _capacity(capacity)
{
	for (int i = 0; i < capacity; ++i)
	{
		_object[i] = 0;
	}
}

MyVector::MyVector(const MyVector& other) : _object(other._object), _size(other._size), _capacity(other._capacity)
{
	for (int i = 0; i < other._size; ++i)
	{
		_object[i]=other._object[i]
	}
}

MyVector& MyVector::operator=( MyVector& other)
{
	std::swap(_object, other._object);
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
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

}

// Returns the first occurrence of MyObject instance with the given ID.
// Returns nullptr if not found.
MyObject* MyVector::FindById(int MyObjectId) const
{
	for (size_t i = 0; i < _size; ++i)
	{
		if(MyObjectId==_object[i]._id)
			return
	}
	return nullptr;
}

// Trims the capacity of this vector to current size.
void TrimToSize();

// Returns the MyObject instance at the specified index.
MyObject& operator[](size_t index);

// Returns string representation of the vector.
std::string ToString() const;

// Remove all MyObject instances with the given ID in this vector.
void MyVector::RemoveAll(int MyObjectId)
{

}

// Returns a newly allocated array of MyVector objects,
// each of whose elements have the same "_id" value of the MyObject struct.
// The 'numGroups' is an out parameter, and its value should be set to
// the size of the MyVector array to be returned.
MyVector* GroupById(int* numGroups);




MyVector::FindById(int myobject)




