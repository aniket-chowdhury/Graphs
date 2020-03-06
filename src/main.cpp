#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"
#include "print.hpp"

void BreadhFirstSearch(lib::graph<int> g, int s){
	int white=0,gray=1,black=2;
	int total_vertices=g.vertices.size();
	std::vector<int> color(total_vertices,white);
	std::vector<int> distance(total_vertices,INT32_MAX);
	std::vector<int> prev(total_vertices,-1);
	color[s]=gray;
	distance[s]=0;
	prev[s]=-1;

	std::queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v : g[u])
		{
			if(color[v]==white){
				color[v]=gray;
				distance[v]=distance[u]+1;
				prev[v]=u;
				q.push(v);
			}
		}
		color[u]=black;
	}
	std::cout << distance;
}

int main(int argc, char *argv[])
{
	lib::graph g({{0, 1, 2, 4},
				  {1, 0, 2},
				  {2, 0, 1, 3, 4},
				  {3, 2},
				  {4, 0, 2}});
	std::cout << g.v << "\n";
	BreadhFirstSearch(g,1);
}