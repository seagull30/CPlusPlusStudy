#pragma once
#include <algorithm>

class MyVector
{
public:
	// �⺻ ������
	MyVector()=default;

	// count��ŭ ������ �Ҵ�� ������
	explicit MyVector(size_t count) : _container(new int[count]), _size(count), _capacity(count)
	{
		for (size_t i = 0; i < count; ++i)
		{
			_container[i] = 0;
		}
	}

	// ���� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
	MyVector(const MyVector& other) : _container(new int[other._capacity]), _size(other._size), _capacity(other._capacity)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			_container[i] = other._container[i];
		}
	}

	// �Ҵ� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
	MyVector& operator=( MyVector& rhs)
	{
		std::swap(_container, rhs._container);
		std::swap(_size, rhs._size);
		std::swap(_capacity, rhs._capacity);

		return*this;
	}

	// �Ҹ���
	~MyVector()
	{
		clear();
	}

	// ù ��° ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	int* begin()
	{
		//���Ͱ� ����ִٸ� end()�� ��ȯ
		if (empty())
		{
			return end();
		}

		//���Ͱ� ������� �ʴٸ� ù ��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
		return _container;
	}
	const int* begin() const
	{
		//���Ͱ� ����ִٸ� end()�� ��ȯ
		if (empty())
		{
			return end();
		}

		//���Ͱ� ������� �ʴٸ� ù ��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
		return _container;
	}

	// ������ ����� ���� ��°�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	int* end()
	{
		// _container : �����̳��� �ּ�
		// _size : ���� ������ �ִ� ������ ����
		// _capacity : �ִ� ������ ����
		return _container + _size;
	}
	const int* end() const { return _container + _size; }

	// �����̳ʰ� ������� �˻��Ѵ�.
	bool                empty() const
	{
		if (0 == _size)
		{
			return true;
		}
		else
			return false;

	}

	// ������ ������ ��ȯ�Ѵ�.
	size_t              size() const { return _size; }

	// ���� �Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�.
	size_t              capacity() const { return _capacity; }

	// pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�. ���� pos�� �������� ����� std::out_of_range ���ܰ� ��������.
	int& at(size_t pos);
	const int& at(size_t pos) const;

	// pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�.
	int& operator[](size_t pos) { return _container[pos]; }
	const int& operator[](size_t pos) const { return _container[pos]; }

	// �����̳��� ù ��° ������ ������ ��ȯ�Ѵ�.
	int& front() { return *begin(); }
	const int& front() const { return *begin(); }

	// �����̳��� ������ ������ ������ ��ȯ�Ѵ�.
	int& back() { return *(end() - 1); }
	const int& back() const { return *(end() - 1); }

	// �����̳ʸ� ����.
	void                clear()
	{
		delete[] _container;

	}

	// pos ���� ��ġ�� value�� �����Ѵ�.
	// value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ�Ѵ�.
	int* insert(int* pos, int value)
	{
		// 1. ��ŭ �������ִ��� Ȯ���Ѵ�.
		int dist = pos - begin();

		// 2. �뷮�� Ȯ���Ѵ�.
		if (_capacity == 0)
		{
			reserve(1);

			pos = begin() + dist;
		}
		else if (_size == _capacity)
		{
			reserve(_capacity * 2);

			pos = begin() + dist;
		}

		// 3. ����
		for (int* iter = end(); iter != pos; --iter)
		{
			*iter = *(iter - 1);
		}
		*pos = value;

		// 4. �ʵ� ������ �ֽ�ȭ
		++_size;
		return pos;
	}

	// pos�� ��ġ�� ���Ҹ� �����.
	// ������ ����� ���� �����͸� ��ȯ�Ѵ�.
	int* erase(int* pos)
	{
		if (_size == 0)
		{
			return end();
		}

		int* last = end() - 1;
		if (pos == last)
		{
			--_size;
			return end();
		}

		for (int* iter = pos; iter != last; ++iter)
		{
			*iter = *(iter + 1);
		}

		--_size;
		return pos;
	}

	// �����̳��� �� ���� ���Ҹ� �߰��Ѵ�.
	void                push_back(int value) { insert(end(), value); }

	// �����̳��� ������ ���Ҹ� �����Ѵ�.
	void                pop_back() { erase(end() - 1); }

	// value�� �����ϴ��� �˻��Ѵ�.
	bool                contains(int value)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (value == _container[i])
				return true;
		}
		return false;
	}

	// �����̳��� �뷮�� newCapacity���� ���ų� ũ�� �ø���.
	// newCapacity > _capacity��� ���ο� �޸𸮸� �Ҵ��ϰ�,
	// �׷��� �ʴٸ� �ƹ� ���۵� �������� �ʴ´�.
	void                reserve(size_t newCapacity)
	{
		// 1. newCapacity, _capacity ũ�� ��
		if (newCapacity <= _capacity)
			return;
		// 2. ���ο� �޸𸮸� �Ҵ�
		int* newcontainer = new int[newCapacity];
		// 3. ���� �޸��� �����͸� ����
		for (size_t i = 0; i < _size; ++i)
		{
			newcontainer[i] = _container[i];
		}
		// 4. ���� �޸� ����
		delete[] _container;
		// 5. �ʵ� ������ ���� _capacity = newCapacity
		_container = newcontainer;
		_capacity = newCapacity;
	}
private:
	int*				_container = nullptr;
	size_t              _size = 0;
	size_t              _capacity = 0;
};