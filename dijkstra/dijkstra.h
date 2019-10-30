#pragma once
#include <vector>
#include <iostream>
#include "stdlib.h"

struct MGraph
{
	int vertexNum;//�������
	std::vector< std::vector<int> > arcs;//���л��ĳ��ȣ����ɴ���ΪINT_MAX
};

void Dijkstra(int v0, const MGraph& graph, std::vector<int>& shortestPath, std::vector<int>& parentNode)
{	
	//������һЩ�Ϸ��Լ�⣬רעD�㷨�߼�����
	
	//��ʼ��v0������������·��
	shortestPath.clear();
	shortestPath.insert(shortestPath.end(), graph.arcs[v0].begin(), graph.arcs[v0].end());
	shortestPath[v0] = 0;
	//��ʼ�����нڵ�ĸ��ڵ�
	parentNode.clear();
	parentNode.insert(parentNode.end(), graph.vertexNum, -1);
	for(int v = 0; v < graph.vertexNum; ++v)
	{
		if (v != v0 && graph.arcs[v0][v] < INT_MAX)
			parentNode[v] = v0;//�ɴ�v0һ�������򸸽ڵ�Ϊv0������Ϊ-1
	}
	
	//��ʼ�������������
	std::vector<bool> visited(graph.vertexNum, false);
	visited[v0] = true;

	//visitedNum��ʾ�Ѿ����ʹ��Ľڵ������v0�Ѿ����ʹ�������visitedNum��1��ʼ
	for (int visitedNum = 1; visitedNum < graph.vertexNum; ++visitedNum)
	{
		//�ұ��������·���Ͷ�Ӧ�ڵ�
		int vMin = 0, minD = INT_MAX;
		for (int v = 0; v < graph.vertexNum; ++v)
		{
			if (!visited[v] && shortestPath[v] < minD)
			{
				vMin = v;
				minD = shortestPath[v];
			}
		}
		//if (minD == INT_MAX) return;//����ͼӦ������ô��������ͼ��Ҫ������
		visited[vMin] = true;
		//����δ�����ʹ��Ľڵ㣬�жϵ�ǰ���·���Ƿ��ܱ�����vMin���·������
		for (int v = 0; v < graph.vertexNum; ++v)
		{
			if (!visited[v])
			{
				int updateD = (graph.arcs[vMin][v] == INT_MAX ? INT_MAX : minD + graph.arcs[vMin][v]);
				if (updateD < shortestPath[v])
				{
					shortestPath[v] = updateD;//������̾���
					parentNode[v] = vMin;//���¸��ڵ�
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