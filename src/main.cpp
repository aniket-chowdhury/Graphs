#include <iostream>
#include <vector>
#include "graph.hpp"

int main(int argc, char *argv[])
{
	lib::graph g({{1, 2, 3, 5},
				  {2, 1, 3, 4},
				  {3, 1, 2, 4, 5},
				  {4, 2, 3},
				  {5, 1, 3}});
	g[1];
}