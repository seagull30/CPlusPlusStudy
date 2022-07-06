#include "Set.h"
#include <iostream>
#include <queue>

Set::Node::Node(int data, Node* parent, Node* left, Node* right) :Data(data), Parent(parent), Left(left), Right(right) {}

bool Set::Node::IsLeaf() const
{
	if (Left == nullptr && Right == nullptr)
		return true;
	else
		return false;
}
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
Set::~Set()
{
	clear();
	_head = nullptr;
}

*/

//int Set::height() const
//{
//
//}
//
//int Set::height2() const
//{
//
//}

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

//void Set::clear()
//{
//
//}

bool Set::insert(int value)
{

	// 1. 루트 노드가 없을 경우 루트 노드 설정
	if (_size == 0)
	{
		Node* root = new Node(value);
		_head->Parent = root;
		_head->Left = root;
		_head->Right = root;
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
/*
void Set::erase(int value)
{

}

void Set::erase(Node* pos)
{

}
*/

Set::Node* Set::find(int value) const
{
	Node* result = _head->Parent;
	while (result->Left != nullptr && result->Right != nullptr)
	{
		if (result->Data > value)
		{
			result = result->Left;
		}
		else if (result->Data < value)
		{
			result = result->Right;
		}
		else if (result->Data == value)
		{
			return result;
		}
	}
	return _head->Right;
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

void        Set::traverseByPreorderHelper(Node * node) const
{
	if (node == nullptr)
		return;
	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}

void        Set::traverseByInorderHelper(Node * node) const
{
	if (node == nullptr)
		return;
	traverseByInorderHelper(node->Left);
	std::cout << node->Data << "->";
	traverseByInorderHelper(node->Right);
}

void        Set::traverseByPostorderHelper(Node * node) const
{
	if (node == nullptr)
		return;
	traverseByPostorderHelper(node->Left);
	traverseByPostorderHelper(node->Right);
	std::cout << node->Data << "->";
}