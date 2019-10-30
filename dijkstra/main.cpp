#include "dijkstra.h"

int main()
{
	//��ʼ��ͼ�������ֱ�ӳ�ʼ��������������Կ��Ǵ��ļ��ж�ȡ
	MGraph g;
	g.vertexNum = 6;
	g.arcs = {//����һ������ͼ
		{ INT_MAX, INT_MAX,      10, INT_MAX,      30,     100 },
		{ INT_MAX, INT_MAX,       5, INT_MAX, INT_MAX, INT_MAX },
		{ INT_MAX, INT_MAX, INT_MAX,      50, INT_MAX, INT_MAX },
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,      10 },
		{ INT_MAX, INT_MAX, INT_MAX,      20, INT_MAX,      60 },
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX }
	};
	//����Դ��
	int v0 = 0;
	//v0������������·��
	std::vector<int> shortestPath;
	//v0������������·���ϵ����һ�����ڵ�
	std::vector<int> parentNode;
	//ͨ��D�㷨�ҵ�Դ�㵽���������·��
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