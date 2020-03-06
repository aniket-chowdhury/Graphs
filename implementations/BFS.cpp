#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"
#include "print.hpp"

void BreadthFirstSearch(lib::graph<int> g, int s)
{
	int white = 0, gray = 1, black = 2;
	int total_vertices = g.vertices.size();
	for (auto vertex : g.vertices)
	{
		g[vertex].color = white;
		g[vertex].distance = INT32_MAX;
		g[vertex].prev = nullptr;
	}
	g[s].color = gray;
	g[s].distance = 0;

	std::queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();

		q.pop();

		for (auto vertex : g[u].list)
		{
			auto v = g[vertex];

			if (g[vertex].color == white)
			{
				g[vertex].color = gray;
				g[vertex].distance = g[u].distance + 1;
				g[vertex].prev = &g[u];
				q.push(vertex);
			}
		}
		g[u].color = black;
	}
	for (auto vertex : g.vertices)
	{
		std::cout << g[vertex].distance << " ";
	}
}

int main(int argc, char *argv[])
{
	lib::graph g({{10, 1, 2, 4},
				  {1, 10, 2},
				  {2, 10, 1, 3, 4},
				  {3, 2},
				  {4, 10, 2}});
	std::cout << g.v << "\n";
	BreadthFirstSearch(g, 1);
}