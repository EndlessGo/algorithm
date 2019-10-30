#include "dijkstra.h"

int main()
{
	//初始化图，简单起见直接初始化，复杂情况可以考虑从文件中读取
	MGraph g;
	g.vertexNum = 6;
	g.arcs = {//这是一个有向图
		{ INT_MAX, INT_MAX,      10, INT_MAX,      30,     100 },
		{ INT_MAX, INT_MAX,       5, INT_MAX, INT_MAX, INT_MAX },
		{ INT_MAX, INT_MAX, INT_MAX,      50, INT_MAX, INT_MAX },
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,      10 },
		{ INT_MAX, INT_MAX, INT_MAX,      20, INT_MAX,      60 },
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX }
	};
	//设置源点
	int v0 = 0;
	//v0到其他点的最短路径
	std::vector<int> shortestPath;
	//v0到其他点的最短路径上的最后一个父节点
	std::vector<int> parentNode;
	//通过D算法找到源点到其他点最短路径
	Dijkstra(v0, g, shortestPath, parentNode);
	for (auto i : shortestPath)
		std::cout << i << " ";
	std::cout << std::endl;

	for (int v = 0; v < g.vertexNum; ++v)
	{
		PrintPath(v, parentNode);
	}
	return 0;
}