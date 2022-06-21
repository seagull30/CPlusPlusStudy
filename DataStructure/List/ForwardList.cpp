#include "FowardList.h"
#include <utility>

ForwardList::Node::Node(int data, Node* next) : Data(data), Next(next)
{

}

ForwardList::Node::~Node()
{
	Next = nullptr;
}

ForwardList::const_iterator::const_iterator(Node* p) :_p(p)
{

}

ForwardList::const_iterator::~const_iterator()
{
	_p = nullptr;
}



const int& ForwardList::const_iterator::operator*() const
{
	return _p->Data;
}

const int* ForwardList::const_iterator::operator->() const
{
	return &(_p->Data);
}

ForwardList::const_iterator& ForwardList::const_iterator::operator++()
{
	_p = _p->Next;
	return *this;
}
ForwardList::const_iterator ForwardList::const_iterator::operator++(int)
{
	const_iterator temp = *this;
	_p = _p->Next;

	return temp;
}

bool ForwardList::const_iterator::operator==(const const_iterator& rhs) const
{
	if (_p == rhs._p)
		return true;
	else
		return false;
}

bool ForwardList::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool ForwardList::const_iterator::operator==(nullptr_t p) const
{
	if (_p == nullptr)
		return true;
	else
		return false;
}
bool ForwardList::const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == nullptr);
}

ForwardList::iterator::iterator(Node* p) : const_iterator(p)
{
	
}

int& ForwardList::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

int* ForwardList::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
}

ForwardList::iterator& ForwardList::iterator::operator++()
{
		const_iterator::operator++();
		return *this;
}

ForwardList::iterator ForwardList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	return  temp;
}

ForwardList::ForwardList()
{
	_head->Next = _end;
}

ForwardList::ForwardList(size_t count) : ForwardList()
{
	
	for (size_t i = 0; i < count; ++i)
	{
		push_front(0);
	}
}

ForwardList::ForwardList(const ForwardList& other) : ForwardList()
{
	iterator inserted = before_begin();
	for (const_iterator iter = other.begin(); iter != other.end(); ++iter)
	{
		inserted = insert_after(inserted, *iter);
	}
}
ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
	}
	return *this;
}


ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;

	delete _end;
	_end = nullptr;

}


int& ForwardList::front()
{
	return *begin();
}

const int& ForwardList::front() const
{
	return *begin();
}

ForwardList::iterator ForwardList::before_begin()
{
	return _head;
}

ForwardList::const_iterator ForwardList::before_begin() const
{
	return _head;
}

ForwardList::iterator ForwardList::begin()
{
	return _head->Next;
}
ForwardList::const_iterator ForwardList::begin() const
{
	return _head->Next;
}

ForwardList::iterator ForwardList::end()
{
	return _end;
}
ForwardList::const_iterator ForwardList::end() const
{
	return _end;
}

ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{
	Node* newNode = new Node();
	Node* where = pos._p;

	newNode->Data = value;
	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	Node* where = pos._p;
	Node* removed = where->Next;
	where->Next = removed->Next;
	
	delete removed;

	return where->Next;
}

void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void ForwardList::pop_front()
{
	erase_after(before_begin());
}

bool ForwardList::empty() const
{
	if (_head->Next == _end)
		return true;
	else
		return false;
}

void ForwardList::clear()
{
	while (empty()==false)
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}
	return false;
}

