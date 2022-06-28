#include <iostream>
#include <vector>
#include <algorithm>
bool isAdjacent(int** graph, int v1, int v2)
{
	if (graph[v1][v2] || graph[v1][v2])
		return true;
	else
		return false;
}

bool isAdjacent(std::vector<int>* graph, int v1, int v2)
{
	if (graph[v1].end() != std::find(graph[v1].begin(), graph[v1].end(), v2))
	{
		return true;
	}
	if (graph[v2].end() != std::find(graph[v2].begin(), graph[v2].end(), v1))
	{
		return true;
	}
	return false;
}

int countIndegree(int** graph, int vertex)
{
	int count = 0;
	for (int i = 0; i < 5; ++i)
		if (graph[i][vertex] == true)
			++count;
	return count;
}

int countIndegree(std::vector<int>* graph, int vertex)
{
	int count = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (graph[i].end() != std::find(graph[i].begin(), graph[i].end(), vertex))
		{
			++count;
			continue;
		}

		return count;
	}
}
int main()
{
	std::cout << "Hello World!\n";
}
