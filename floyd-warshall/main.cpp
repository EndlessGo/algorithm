#include "floyd-warshall.h"

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

	//最短路径矩阵
	std::vector< std::vector<int> > A;
	//最短路径上的最后一个父节点
	std::vector< std::vector<int> > path;
	//通过D算法找到源点到其他点最短路径
	Floyd(g, A, path);

	std::cout << " ";
	for (size_t i = 0; i < A.size(); ++i)
	{
		std::cout << "\t" << i;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < A.size(); ++i)
	{
		std::cout << i;
		for (size_t j = 0; j < A.size(); ++j)
		{
			if(A[i][j] == INT_MAX)
				std::cout << "\t" << "-";
			else
				std::cout << "\t" << A[i][j];
		}
		std::cout << std::endl;
	}
	while(1){}
	return 0;
}