#include "stones.h"

#include <algorithm>
#include <cassert>
#include <iostream>

namespace
{
	const int MAXN = 900;
	int A[MAXN + 5];
	int correct_cnt;
	int q_cnt;
	bool called, correct;
	int num_tests;
	int N;
}

int compare(int x, int y)
{
	if (!(1 <= x && x <= N && 1 <= y && y <= N))
	{
		std::cout << "Compare x, y out of range" << std::endl;
		exit(-1);
	}
	q_cnt++;
	if (A[x] == A[y])
		return 0;
	else if (A[x] < A[y])
		return -1;
	else
		return +1;
}

void answer(std::vector<int> v1, std::vector<int> v2)
{
	if (called)
	{
		std::cout << "multiple answer call in min_max!" << std::endl;
		exit(-1);
	}
	called = true;

	int n1 = v1.size(), n2 = v2.size();

	if (n1 < 1 || n2 < 1 || n1 > N || n2 > N)
		return;

	int min_v = A[1], max_v = A[1];
	for (int i = 1; i <= N; i++)
	{
		min_v = min_v > A[i] ? A[i] : min_v;
		max_v = max_v < A[i] ? A[i] : max_v;
	}

	std::vector<int> a1, a2;
	for (int i = 1; i <= N; i++)
	{
		if (min_v == A[i])
			a1.push_back(i);
		if (max_v == A[i])
			a2.push_back(i);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	if (a1 == v1 && a2 == v2)
	{
		correct_cnt++;
		correct = true;
	}
}

int main()
{
	assert(std::cin >> num_tests);

	for (int t = 1; t <= num_tests; t++)
	{
		assert(std::cin >> N);
		for (int i = 1; i <= N; i++)
			assert(std::cin >> A[i]);

		called = false;
		q_cnt = 0;
		correct = false;
		stones(N);

		if (correct)
			std::cout << "Case #" << t << ": CORRECT" << std::endl;
		else
			std::cout << "Case #" << t << ": WRONG" << std::endl;

		std::cout << "number of compare() calls: " << q_cnt << std::endl;
	}
	std::cout << "correct calls: " << correct_cnt << std::endl;
}