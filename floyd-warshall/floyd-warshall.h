#pragma once
#include <vector>
#include <iostream>

struct MGraph
{
	int vertexNum;//�������
	std::vector< std::vector<int> > arcs;//���л��ĳ��ȣ����ɴ���ΪINT_MAX
};

void Floyd(const MGraph& g, std::vector< std::vector<int> > &A, std::vector< std::vector<int> > &Path)
{
	//time O(n^3), space O(n^2)
	//������һЩ�Ϸ��Լ�⣬רעF�㷨�߼�����

	//��ʼ��n�׾���A��Path
	A.clear(), Path.clear();
	std::vector<int> row(g.vertexNum, -1);
	A.resize(g.vertexNum, row);
	Path.resize(g.vertexNum, row);
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			if(i == j)
				A[i][j] = 0;
			else
				A[i][j] = g.arcs[i][j];
		}
	}
	//�������·������A�͸��ڵ����Path
	for (int k = 0; k < g.vertexNum; ++k)
	{
		for (int i = 0; i < g.vertexNum; ++i)
		{
			for (int j = 0; j < g.vertexNum; ++j)
			{
				if (A[i][k] != INT_MAX && A[k][j] != INT_MAX)
				{
					if (A[i][j] > A[i][k] + A[k][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						Path[i][j] = k;
					}
				}
			}
		}
	}
	return;
}