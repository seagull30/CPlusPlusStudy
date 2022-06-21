#include "List.h"
#include <utility>

List::Node::Node(int data, Node* prev, Node* next) : Data(data), Next(next), Prev(prev)
{

}

List::Node::~Node()
{
	Next = nullptr;
	Prev = nullptr;
}

List::const_iterator::const_iterator(Node* p) : _p(p)
{

}

List::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& List::const_iterator::operator*() const
{
	return _p->Data;
}

const int* List::const_iterator::operator->() const
{
	return &(_p->Data);
}

List::const_iterator& List::const_iterator::operator++()
{
	_p = _p->Next;
	return *this;
}

List::const_iterator List::const_iterator::operator++(int)
{
	const_iterator temp;
	_p = _p->Next;
	return temp;
}

List::const_iterator& List::const_iterator::operator--()
{
	_p = _p->Prev;
	return *this;
}

List::const_iterator List::const_iterator::operator--(int)
{
	const_iterator temp;
	_p = _p->Prev;
	return temp;
}

bool List::const_iterator::operator==(const const_iterator& rhs) const
{
	if (_p == rhs._p)
		return true;
	else
		return false;
}

bool List::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool List::const_iterator::operator==(nullptr_t p) const
{
	if (_p == nullptr)
		return true;
	else
		return false;
}

bool List::const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == nullptr);
}

List::iterator::iterator(Node* p) : const_iterator(p)
{

}

int& List::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

int* List::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
}

List::iterator& List::iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

List::iterator List::iterator::operator++(int)
{
	iterator temp = _p;
	const_iterator::operator++();
	return temp;
}

List::iterator& List::iterator::operator--()
{
	const_iterator::operator--();
	return *this;
}

List::iterator List::iterator::operator--(int)
{
	iterator temp = *this;
	const_iterator::operator--();
	return temp;
}

List::List()
{
	_end->Next = _end;
	_end->Prev = _end;
}

List::List(size_t count) : List()
{
	for (size_t i = 0; i < count; ++i)
	{
		push_front(0);
	}
}

List::List(const List& other) : List()
{
	iterator inserted = begin();
	for (const_iterator iter = other.begin(); iter != other.end(); ++iter)
	{
		inserted = insert(inserted, *iter);
	}
}

// 할당 연산자
List& List::operator=(const List& rhs)
{
	if (&rhs != this)
	{
		List temp = rhs;
		
		std::swap(_end, temp._end);
		std::swap(_size, temp._size);
	}
	return *this;
}

List::~List()
{
	clear();
	delete _end;
	_end = nullptr;
}

int& List::front()
{
	return *begin();
}

const int& List::front() const
{
	return *begin();
}
int& List::back()
{
	return *(--end());
}

const int& List::back() const
{
	return *(--end());
}

List::iterator List::begin()
{
	return iterator(_end->Next);
}
List::const_iterator List::begin() const
{
	return const_iterator(_end->Next);
}

List::iterator List::end()
{
	return _end;
}

List::const_iterator List::end() const
{
	return _end;
}

List::iterator List::insert(iterator pos, int value)
{
	Node* newNode = new Node();
	Node* prev = pos._p->Prev;
	Node* next = pos._p;

	prev->Next = newNode;
	next->Prev = newNode;

	newNode->Prev = prev;
	newNode->Next = next;
	newNode->Data = value;
	++_size;

	return newNode;
}

List::iterator List::erase(iterator pos)
{
	Node* removed = pos._p;
	Node* prev = removed->Prev;
	Node* next = removed->Next;

	prev->Next = next;
	next->Prev = prev;
	delete removed;

	--_size;
	return next;
}

void List::push_front(int value)
{
	insert(begin(), value);
}

void List::push_back(int value)
{
	insert(end(), value);
}

void List::pop_front()
{
	erase(begin());
}

void List::pop_back()
{
	erase(_end->Prev);
}

bool List::empty() const
{
	if (_size == 0)
		return true;
	else
		return false;
}

size_t List::size() const
{
	return _size;
}

void List::clear()
{
	while (empty() == false)
	{
		pop_front();
	}
}

bool List::contains(int value) const
{
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
			return true;
	}
	return false;
}