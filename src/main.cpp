#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "graph.hpp"
#include "print.hpp"


int white = 0, gray = 1, black = 2;
std::map<char,std::pair<int,int>> times;
int time_count=0;
std::map<char,char> before;

template <typename T>
void dfs_visit(lib::graph<T> g,T u);

template <typename T>
void DephFirstSearch(lib::graph<T> g)
{
	for (auto vertex : g.vertices)
	{
		g[vertex].color = white;
		g[vertex].prev = nullptr;
	}

	for(auto vertex : g.vertices)
	{
		if(g[vertex].color==white)
			dfs_visit(g,vertex);
	}

	for(auto v : before)
	{
		std::cout  << v.first << " " << v.second << "\n";
	}
}


template <typename T>
void dfs_visit(lib::graph<T> g,T u){
	time_count+=1;
	g[u].color=gray;
	times[u].first=time_count;
	for(auto v : g[u].list)
	{
		if(g[v].color==white){
			g[v].prev=&g[u];
			before[v]=u;
			dfs_visit(g,v);
		}
	}
	g[u].color=black;
}

int main(int argc, char *argv[])
{
	lib::graph g({{'a', 'b', 'c'},
				  {'b', 'a'},
				  {'c', 'a', 'b', 'd'},
				  {'d', 'c', 'e'},
				  {'e'}});
	std::cout << g.v << "\n";
	DephFirstSearch(g);
}