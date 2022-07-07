#include "Set.h"
#include <iostream>
#include <queue>

Set::Node::Node(int data, Node* parent, Node* left, Node* right) :Data(data), Parent(parent), Left(left), Right(right) {}
/*
bool Set::Node::IsLeaf() const
{
	if (Left == nullptr && Right == nullptr)
		return true;
	else
		return false;
}
*/
Set::Node::~Node()
{
	Parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}
/*
Set::Set()
{
}
Set::Set(const Set&)
{

}
Set& Set::operator=(const Set&)
{

}
*/
Set::~Set()
{
	clear();
	delete _head;
	_head = nullptr;
}

int Set::height() const
{
	std::queue<Node*>q;
	if (_head->Parent)
	{
		q.push(_head->Parent);
	}

	int height = -1;
	while (q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			Node* node = q.front();
			q.pop();

			if (node->Left)
				q.push(node->Left);
			if (node->Right)
				q.push(node->Right);
		}
		++height;
	}
	return height;
}

int Set::height2() const
{
	if (_head->Parent == nullptr)
		return -1;
	return heightHelper(_head->Parent);
}

int Set::heightHelper(Node* node) const
{
	int height = 0;
	if (node->Left)
	{
		height = 1 + heightHelper(node->Left);
	}

	if (node->Right)
	{
		height = std::max(height, 1 + heightHelper(node->Right));
	}
	return height;
}

bool Set::empty() const
{
	if (_size == 0)
		return true;
	else
		return false;
}

size_t Set::size() const
{
	return _size;
}

void Set::clear()
{
	while (!empty())
	{
		erase(_head->Parent);
	}
}

bool Set::insert(int value)
{

	// 1. 루트 노드가 없을 경우 루트 노드 설정
	if (_size == 0)
	{
		Node* root = new Node(value);
		_head->Parent = root;
		++_size;
		return true;
	}

	// 2. 삽입할 위치의 부모노드 찾기
	Node* parent = nullptr;
	Node* p = _head->Parent;
	while (p)
	{
		parent = p;
		if (p->Data == value)
			return false;
		else if (value < p->Data)
			p = p->Left;
		else
			p = p->Right;
	}
	// 3. 새로운 노드 삽입
	Node* newNode = new Node(value);
	if (value < parent->Data)
		parent->Left = newNode;
	else
		parent->Right = newNode;

	newNode->Parent = parent;

	++_size;

	return true;
}

void Set::erase(int value)
{
	// 1. value가 위치한 노드를 찾음
	Node* removedNode = find(value);
	if (removedNode == nullptr)
		return;
	// 2. erase (pos)
	erase(removedNode);
}

void Set::erase(Node* pos)
{
	// 1. 자식이 둘다 있을 떄
	if (pos->Left && pos->Right)
	{
		// 1-1. 후속 노드를 지정한다.
		Node* successor = pos->Right;
		while (successor->Left)
		{
			successor = successor->Left;
		}
		// 1.2 후속 노드의 데이터와 스왑한다.
		//std::swap(pos->Data, successor->Data);
		pos->Data = successor->Data;

		// 1.3 후속 노드를 지운다.
		erase(successor);

		return;
	}

	// 2. 자식이 한쪽만 있을 때 or 둘 다 없을 때
	//	2-1. pos가 부모의 어느쪽에 자식인지 파악한다.
	Node** child = nullptr;
	// 2-1-1. 지우고자 하는 노드가 루트 노드인 경우
	if (pos == _head->Parent)
		child = &_head->Parent;
	// 2-2-2. 지우고자 하는 노드가 루트 노드의 자식인 경우 or 내가 오른쪽에 위치한 경우
	else if (pos->Data < pos->Parent->Data)
		child = &pos->Parent->Left;
	// 2-2-3. 내가 왼쪽에 위치한 경우
	else
		child = &pos->Parent->Right;

	//	2-2. 부모에 pos의 자식을 연결한다.
	*child = nullptr;

	if (pos->Left)
	{
		*child = pos->Left;
		pos->Left->Parent = pos->Parent;
	}
	else if (pos->Right)
	{
		*child = pos->Right;
		pos->Right->Parent = pos->Parent;
	}

	delete pos;
	--_size;


	// 4. pos가 루트 노드일 때

}

Set::Node* Set::find(int value) const
{
	Node* result = _head->Parent;
	while (result)
	{
		if (result->Data == value)
		{
			break;
		}
		else if (result->Data < value)
		{
			result = result->Right;
		}
		else
		{
			result = result->Left;
		}
	}
	return result;
}

void        Set::traverseByPreorder() const
{
	traverseByPreorderHelper(_head->Parent);
}
void        Set::traverseByInorder() const
{
	traverseByInorderHelper(_head->Parent);
}
void        Set::traverseByPostorder() const
{
	traverseByPostorderHelper(_head->Parent);
}

void        Set::traverseByLevelorder() const
{
	std::queue<Node*> q;
	if (_head->Parent)
		q.push(_head->Parent);

	while (!q.empty())
	{
		Node* node = q.front();
		q.pop();

		std::cout << node->Data << "->";

		if (node->Left != nullptr)
			q.push(node->Left);

		if (node->Right != nullptr)
			q.push(node->Right);
	}
}

void        Set::traverseByPreorderHelper(Node* node) const
{
	if (node == nullptr)
		return;
	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}

void        Set::traverseByInorderHelper(Node* node) const
{
	if (node == nullptr)
		return;
	traverseByInorderHelper(node->Left);
	std::cout << node->Data << "->";
	traverseByInorderHelper(node->Right);
}

void        Set::traverseByPostorderHelper(Node* node) const
{
	if (node == nullptr)
		return;
	traverseByPostorderHelper(node->Left);
	traverseByPostorderHelper(node->Right);
	std::cout << node->Data << "->";
}