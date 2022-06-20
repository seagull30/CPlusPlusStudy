#include "FowardList.h"
#include <utility>

ForwardList::ForwardList()
{
	_head->Next = _end;
}

explicit ForwardList::ForwardList(size_t count) : ForwardList()
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
	if (empty())
	{
		return end();
	}
	Node* where = pos._p;
	Node* removed = where->Next;
	where->Next = removed->Next;
	removed->Next = nullptr;

	return removed;
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

