#pragma once
//-------------------------------------------------------------------------------------------------
// ���� (vector) Ŭ���� �����ϱ�
//
// �� header ���Ͽ�����, ���� �Ի��������� ����������, ������ ���͸� �����ϱ� ����,
// MyVector ��� Ŭ������ �����ϰ� �ֽ��ϴ�.
//
// �ҽ��� �ּ��� �����Ͽ�, �ʿ��� ��ɵ��� �����Ͽ�,
// MyVector.h ���ϰ� MyVector.cpp, 2���� ������ �������ֽø� �˴ϴ�.
// (�����Ͻô� ���ϵ��� ���ڵ��� utf-8 �� �����ֽø� �����ϰڽ��ϴ�.)
//
// ����: std::vector �� ����, �̹� ������ ���͸� ���δ½����� �������� ���ð�,
//    ���� �ڽ��� �ڵ�� ����� ���� ��Ź�帳�ϴ�.
//
// ����: ����� �ۼ��� �κ��� ���� �Ϳ� ���� ������ �帮�ڸ�,
//    ���� �Ƿ��� �߿��ϰ� ����ٱ� ���ٴ�, �����⸦ ������ ���� �ѱ� ������ ã��,
//    ��� �ؼ��� ������ ������, ����/�н��ϴ� �ɷ��� �߿��ϱ� �����Դϴ�.
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
// ���Ͷ�? (http://www.cplusplus.com/reference/vector/vector/)
//
// Vectors are sequence containers representing arrays that can change in size.
// Just like arrays, vectors use contiguous storage locations for their elements,
// which means that their elements can also be accessed using offsets on regular pointers
// to its elements, and just as efficiently as in arrays. But unlike arrays,
// their size can change dynamically, with their storage being handled automatically
// by the container.
//
// Internally, vectors use a dynamically allocated array to store their elements.
// This array may need to be reallocated in order to grow in size when new elements are inserted,
// which implies allocating a new array and moving all elements to it.
// This is a relatively expensive task in terms of processing time, and thus,
// vectors do not reallocate each time an element is added to the container.
//
// Instead, vector containers may allocate some extra storage to accommodate for possible growth,
// and thus the container may have an actual capacity greater than the storage strictly needed to
// contain its elements (i.e., its size). Libraries can implement different strategies for growth
// to balance between memory usage and reallocations, but in any case,
// reallocations should only happen at logarithmically growing intervals of size
// so that the insertion of individual elements at the end of the vector can be provided with
// amortized constant time complexity.
//-------------------------------------------------------------------------------------------------

#include <string>

//-------------------------------------------------------------------------------------------------
// MyVector �� �����ϴ� ������Ʈ
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector Ŭ����.
//-------------------------------------------------------------------------------------------------
class MyVector
{
private:

    MyObject* _object;
    //int* _container;
    size_t  _size;
    size_t  _capacity;
    // ������ �ʿ��� ��� �߰� �Լ�/�������� �����Ӱ� �Ʒ��� ���� �մϴ�.

    // ��.1) ����� �����ϴ� ��������� �Ʒ�ó�� �߰��ϸ� �˴ϴ�.
    // int _vectorSize;

    // ��.2) ��������� �ø��� �Լ��� �Ʒ�ó�� �߰��ϸ� �˴ϴ�.
    // void Grow();
    void clear()
    {
        delete[] _object;
    }

    void reserve(size_t newCapacity)
    {
        
    }


public: // ������, ���������, �Ҵ翬����, �Ҹ��ڸ� .cpp ���Ͽ� �����մϴ�.

	// Constructor.
	MyVector(int capacity);

	// Copy constructor.
	MyVector(const MyVector& other);

	// Assignment operator.
	MyVector& operator=( MyVector& other);

	// Destructor.
    ~MyVector();

public: // �Ʒ� ��� �Լ����� .cpp ���Ͽ� �����մϴ�.

    // Returns current capacity of this vector.
    int GetCapacity() const;

    // Returns current size of this vector.
    int GetSize() const;

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id);

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const;

    // Trims the capacity of this vector to current size.
    void TrimToSize();

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index);

    // Returns string representation of the vector.
    std::string ToString() const;

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId);

    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    MyVector* GroupById(int* numGroups);
};
