#include "floyd-warshall.h"

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

	//���·������
	std::vector< std::vector<int> > A;
	//���·���ϵ����һ�����ڵ�
	std::vector< std::vector<int> > path;
	//ͨ��D�㷨�ҵ�Դ�㵽���������·��
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