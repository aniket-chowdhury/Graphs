#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"
#include "print.hpp"

template <typename T>
void printpath(lib::graph<T> g, T s, T d);

template <typename T>
void BreadthFirstSearch(lib::graph<T> g, T s)
{
	int white = 0, gray = 1, black = 2;
	int total_vertices = g.vertices.size();
	for (auto vertex : g.vertices)
	{
		g[vertex].color = white;
		g[vertex].distance = INT16_MAX;
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
	std::cout << '\n';
	printpath(g, s, 'e');
}

template <typename T>
void printpath(lib::graph<T> g, T s, T d)
{
	if (s == d)
		std::cout << s << ":";
	else if (g[d].prev == nullptr)
	{
		std::cout << "No path exists";
	}
	else
		printpath(g, s, g[d].prev->val);
	std::cout << d << " ";
}

int main(int argc, char *argv[])
{
	lib::graph g({{'a', 'b', 'c'},
				  {'b', 'a'},
				  {'c', 'a', 'b', 'd'},
				  {'d', 'c', 'e'},
				  {'e'}});
	std::cout << g.v << "\n";
	BreadthFirstSearch(g, 'b');
}