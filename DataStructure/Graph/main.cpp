#include <iostream>
#include <vector>

struct Edge
{
	int Vertex;
	int Weight;

	Edge(int v, int w) : Vertex(v), Weight(w) {}
};



int main()
{

	std::vector<Edge> graph[7];

	graph[0].push_back({ 1,1 });
	graph[1].push_back({ 0,1 });
	graph[1].push_back({ 2,2 });
	graph[1].push_back({ 3,2 });
	graph[2].push_back({ 1,2 });
	graph[2].push_back({ 5,6 });
	graph[2].push_back({ 6,3 });
	graph[3].push_back({ 1,2 });
	graph[3].push_back({ 4,1 });
	graph[3].push_back({ 5,4 });
	graph[4].push_back({ 3,1 });
	graph[5].push_back({ 2,6 });
	graph[5].push_back({ 3,4 });
	graph[6].push_back({ 2,3 });

	return 0;
}