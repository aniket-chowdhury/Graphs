#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <initializer_list>

typedef std::vector<char> list;
typedef std::map<char, list> graph;

int white = 0, gray = 1, black = 2;

void dfs_visit(graph g, char u);

int time_count;
std::map<char, int> color;
std::map<char, char> prev;
std::map<char, std::pair<int, int>> times;

void dfs(graph g)
{
	for (auto elem : g)
	{
		auto c = elem.first;
		color[c] = white;
		prev[c] = ' ';
		times[c] = std::make_pair(0, 0);
	}
	time_count = 0;
	for (auto elem : g)
	{
		auto c = elem.first;
		if (color[c] == white)
		{
			dfs_visit(g, c);
		}
	}
}

void dfs_visit(graph g, char u)
{
	time_count += 1;
	times[u].first = time_count;
	color[u] = gray;
	for (auto v : g[u])
	{
		if (color[v] == white)
		{
			prev[v] = u;
			dfs_visit(g, v);
		}
	}
	color[u] = black;
	time_count += 1;
	times[u].second = time_count;
}

main(int argc, char const *argv[])
{
	graph g;
	g['a'] = list({'b', 'c'});
	g['b'] = list({'a'});
	g['c'] = list({'a', 'b', 'd'});
	g['d'] = list({'c', 'e'});
	g['e'] = list();
	dfs(g);

	for (auto &&i : times)
	{
		std::cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
	}
	

	return 0;
}
