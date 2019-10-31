#pragma once
#include <vector>
#include <iostream>

struct MGraph
{
	int vertexNum;//顶点个数
	std::vector< std::vector<int> > arcs;//所有弧的长度，不可达则为INT_MAX
};

void Dijkstra(int v0, const MGraph& graph, std::vector<int>& shortestPath, std::vector<int>& parentNode)
{	
	//time O(n^2), space O(n)
	//忽略了一些合法性检测，专注D算法逻辑本身
	
	//初始化v0到其他点的最短路径
	shortestPath.clear();
	shortestPath.insert(shortestPath.end(), graph.arcs[v0].begin(), graph.arcs[v0].end());
	shortestPath[v0] = 0;
	//初始化所有节点的父节点
	parentNode.clear();
	parentNode.insert(parentNode.end(), graph.vertexNum, -1);
	for(int v = 0; v < graph.vertexNum; ++v)
	{
		if (v != v0 && graph.arcs[v0][v] < INT_MAX)
			parentNode[v] = v0;//可从v0一步到达则父节点为v0，否则为-1
	}
	
	//初始化顶点访问数组
	std::vector<bool> visited(graph.vertexNum, false);
	visited[v0] = true;

	//visitedNum表示已经访问过的节点个数，v0已经访问过，所以visitedNum从1开始
	for (int visitedNum = 1; visitedNum < graph.vertexNum; ++visitedNum)
	{
		//找本轮中最短路径和对应节点
		int vMin = -1, minD = INT_MAX;
		for (int v = 0; v < graph.vertexNum; ++v)
		{
			if (!visited[v] && shortestPath[v] < minD)
			{
				vMin = v;
				minD = shortestPath[v];
			}
		}
		//if (minD == INT_MAX) continue;//当前节点无法被访问到
		if (vMin == -1) continue;//当前节点无法被访问到，这两种判断都可以
		visited[vMin] = true;
		//对于未被访问过的节点，判断当前最短路径是否能被经过vMin后的路径更新
		for (int v = 0; v < graph.vertexNum; ++v)
		{
			if (!visited[v])
			{
				int updateD = (graph.arcs[vMin][v] == INT_MAX ? INT_MAX : minD + graph.arcs[vMin][v]);
				if (updateD < shortestPath[v])
				{
					shortestPath[v] = updateD;//更新最短距离
					parentNode[v] = vMin;//更新父节点
				}
			}
		}
	}
	return;
}

void PrintPath(int v, const std::vector<int>& parentNode)
{	
	int node = v;
	std::vector<int> path;
	while (v != -1)
	{
		path.push_back(v);
		v = parentNode[v];
	}
	std::cout << path[path.size() - 1];
	for (int i = path.size() - 2; i >= 0; --i)
		std::cout << "->" << path[i];
	std::cout << std::endl;
}
