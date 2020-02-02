/*
	1. r = y, c = x (row, column?)
	2. ġŲ�� �� M�� ����� ��, ġŲ �Ÿ� �ּڰ� ���ϱ�

	Ǯ�̹��
	���۷� ġŲ�� ����¥��
	���ۿ� �ش��ϴ� �ε����� �Ÿ� ���ϱ�
	min���� �־� ���ϱ�
	���� ��

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int map[51][51];
int chickenPos[13][2]; // ġŲ�� ��ġ
int homePos[101][2];
int homeCnt;
int chickenCnt;
int disSum[101];

#define disCalc(A, B, C, D) (abs(C-A) + abs(D - B))
#define Min(A,B) (A<B?A:B)
void distance(vector<int> pos)
{
	for (int i = 0; i < homeCnt; i++)
		disSum[i] = 0;

	for (int i = 0; i < homeCnt; i++)
	{
		int minVal = 99999999999;
		for (int j = 0; j < pos.size(); j++)
		{
			if (pos[j] == 0)
				continue;
			int dis = disCalc(homePos[i][0], homePos[i][1], chickenPos[j][0], chickenPos[j][1]);
			minVal = Min(minVal, dis);
		}
		disSum[i] += minVal;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int pos;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> pos;
			map[i][j] = pos;
			if (pos == 1) // home
			{
				homePos[homeCnt][0] = i;
				homePos[homeCnt][1] = j;
				homeCnt++;
			}
			else if (pos == 2) // home
			{
				chickenPos[chickenCnt][0] = i;
				chickenPos[chickenCnt][1] = j;
				chickenCnt++;
			}
		}
	}

	vector<int> v(chickenCnt - M);
	for (int i = 0; i < M; i++)
		v.push_back(1); // ���տ� ���ͻ���
	
	int minSum = 99999999999;
	do {
		distance(v);

		int sum = 0;
		for (int i = 0; i < homeCnt; i++)
			sum += disSum[i];
		if (minSum > sum)
			minSum = sum;
	} while (next_permutation(v.begin(), v.end()));



	cout << minSum;

	return 0;
}
