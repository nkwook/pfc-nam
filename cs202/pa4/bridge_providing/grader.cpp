#include "bridge.h"
#include <iostream>
#include <cassert>

namespace
{
	int N, M;
	std::vector<int> X, Y;
	std::vector<int> A, B;
	int num_queries = 0;
}
int count_crosses(int a, int b)
{
	if (!(1 <= a && a <= N && 1 <= b && b <= N))
	{
		std::cout << "Wrong Answer: count_crosses parameter out of range.\n";
		exit(0);
	}
	num_queries += 1;
	int num_crosses = 0;
	for (int i = 0; i < M; i++)
	{
		if (X[i] == a && Y[i] == b)
			return -1;
		if (X[i] < a && Y[i] > b)
			num_crosses += 1;
		if (X[i] > a && Y[i] < b)
			num_crosses += 1;
	}
	return num_crosses;
}

void report_bridge(int a, int b)
{
	if (!(1 <= a && a <= N && 1 <= b && b <= N))
	{
		std::cout << "Wrong Answer: report_bridge parameter out of range.\n";
		exit(0);
	}
	A.push_back(a);
	B.push_back(b);
}

int main()
{
	assert(std::cin >> N >> M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		assert(std::cin >> a >> b);
		X.push_back(a);
		Y.push_back(b);
	}

	find_bridges(N);

	if (A.size() != M)
	{
		std::cout << "Wrong Answer: bridges does not match.\n";
		return 0;
	}
	for (int i = 0; i < M; i++)
	{
		bool hasEqual = false;
		for (int j = 0; j < M; j++)
			if (X[i] == A[j] && Y[i] == B[j])
			{
				hasEqual = true;
			}
		if (hasEqual == false)
		{
			std::cout << "Wrong Answer: bridges does not match.\n";
			return 0;
		}
	}
	std::cout << "Correct! " << num_queries << " queries used.\n";
	return 0;
}