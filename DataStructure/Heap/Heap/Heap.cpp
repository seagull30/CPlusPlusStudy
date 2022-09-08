#include "Heap.h"

const int& Heap::top() const
{
	return _container.front();
}

bool Heap::empty() const
{
	return _container.empty();
}

size_t Heap::size() const
{
	return _container.size();
}

void Heap::push(int value)
{
	// 1. ���� �� ���� �����͸� �����Ѵ�.
	_container.push_back(value);

	// 2. ���� �Һ����� ������ ������ �����͸� �ٲ��ش�.
	// HACK : ù ��° ��带 1�� ����
	size_t currentIndex = size();
	while (currentIndex > 1)
	{
		// 2-1. �θ��带 ã�´�.
		size_t parrentInex = currentIndex / 2;
		if (_container[parrentInex - 1] >= _container[currentIndex - 1])
		{
			// 2-1-1. �θ� ������ �� ũ�ٸ� ���� �Һ����� �����ϴ� ���̹Ƿ� ����
			break;
		}
		std::swap(_container[parrentInex - 1], _container[currentIndex - 1]);
		currentIndex = parrentInex;
	}

}

void Heap::pop()
{
	// 1. ������ ��带 ��Ʈ ���� �����´�.
	_container[0]= _container.back();

	// 2. ������ ��带 �����Ѵ� .
	_container.pop_back();

	// 3. ���� �Һ����� ������ ������ �ڽ��̶� �ٲ۴�.
	const size_t currentSize = _container.size();
	size_t currentIndex = 1;

	while (true)
	{
		size_t left = currentIndex * 2;
		size_t right = left + 1;
		// 3-+1. �ڽ��� �����ؾ��Ѵ�.
		if (left > currentSize)
		{
			break;
		}

		// 3-2. ���� �ڽİ� ������ �ڽ� �� �� ū ������ �ٲ۴�.
		size_t child = left;
		if (right <= currentSize && _container[left - 1] < _container[right - 1])
		{
			child = right;
		}

		// 3-3 �ٲ� �ڽ��� ���ٸ� �����Ѵ�.
		if (_container[currentIndex - 1] >= _container[child - 1])
		{
			break;
		}
		std::swap(_container[currentIndex - 1], _container[child - 1]);
		currentIndex = child;		
	}
}


