#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <initializer_list>

typedef std::vector<char> list;
typedef std::map<char, list> graph;

void printpath(graph g, char s, char d, std::map<char, char> prev);

void dfs(graph g, char s, char d = ' ')
{
	int white = 0, gray = 1, black = -1;
	std::map<char, int> color, distance;
	std::map<char, char> prev;
	for (auto elem : g)
	{
		auto c = elem.first;
		color[c] = white;
		distance[c] = -1;
		prev[c] = ' ';
	}
	color[s] = gray;
	distance[s] = 0;
	std::queue<char> q;
	q.push(s);
	while (!q.empty())
	{
		auto u = q.front();
		q.pop();
		for (auto vertex : g[u])
		{
			if (color[vertex] == white)
			{
				color[vertex] = gray;
				distance[vertex] = distance[u] + 1;
				prev[vertex] = u;
				q.push(vertex);
			}
		}
		color[u] = black;
	}

	for (auto elem : distance)
	{
		std::cout << elem.second << " ";
	}
	std::cout<<'\n';
	if (d == ' ')
		return;
	printpath(g, s,d, prev);
}

void printpath(graph g, char s, char d, std::map<char, char> prev)
{
	if (s == d)
		std::cout << s << ":";
	else if (prev[d] == ' ')
		return;
	else printpath(g, s, prev[d], prev);
	std::cout << d << ' ';
}

main(int argc, char const *argv[])
{
	graph g;
	g['a'] = list({'b', 'c'});
	g['b'] = list({'a'});
	g['c'] = list({'a', 'b', 'd'});
	g['d'] = list({'c', 'e'});
	g['e'] = list();

	dfs(g, 'b', 'e');
	return 0;
}
