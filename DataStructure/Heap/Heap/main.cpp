#include "Heap.h"
#include <iostream>
#include <queue>
int main()
{
	Heap heap;
	for (int num : {7, 10, 56, 8, 4, 2, 9, 85, 15})
	{
		heap.push(num);
	}
	
	while (false == heap.empty())
	{
		std::cout << heap.top() << ' ';
		heap.pop();
	}


	std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
}