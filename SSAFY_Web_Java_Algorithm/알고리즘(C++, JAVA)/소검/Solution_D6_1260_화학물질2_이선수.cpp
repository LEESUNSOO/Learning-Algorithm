///* 1545~1700 + 2020~2135 = 1H15M+1H+15M = 2H30M
//
//	[��ȭ��]
//
//	dp[s][e] = dp[s][k] + dp[k+1][e] + l[i-1]*l[k]*l[j]; (s<= k <= j)
//
//	���ظ� ���� ���� ����,
//
//	ABCD
//	A <= K <= C
//	dp[A][C] = dp[A][A] + dp[B][C] + l[A-0]*l[A]*l[C];
//						...
//						...
//						...
//
//	���� �����ϱ� ����� �κ��� ����° �� ���� ���� �������� �κ��̴�.
//	�̿� ���� �����̴�. �� ���� ����� �ΰ� �����ϸ� �ָ�������, ���� �ټ����� �����غ���
//	ABCF
//
//	�̶� �ּ� ���� ������ ���� ��, �پ��� ����� ���� �������̴�.
//
//	(AB)CF �� ���۵� ���� �ְ�, AB(CF)�� �� ���� �ִ�.
//
//	���� ������ �ǹ��ϴ� �ٴ� ���� �̹� ����(Ƚ���� �ľ���)�� ����(dp��) �κ��� ���ϰ�,
//	���� ��� A(BC)F �̿� ���� BC�� Ƚ���� �ľǵ� ���¿��� ,
//	�츮�� AC�� CF���� ����Ƚ���� �ľ��ϰ� ���� ���̴�. 
//	���� ACF�� ���� �����ְ� �Ǵ°��̴�.
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <deque>
//#include <algorithm>
//
//using namespace std;
//
//struct matrix {
//
//	int row;
//	int col;
//	matrix(int r = 0, int c = 0) : row(r), col(c) {}
//
//};
//
//int map[100][100];
//int N;
//vector<matrix> v;
//int dp[21][21];
//deque<matrix> dq;
//int m[21];
//
//void input();
//void check_matrix(int y, int x);
//void connectMatrix();
//void dpMethod();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		v.clear();
//		dq.clear();
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (map[i][j] == 0)
//					continue;
//				check_matrix(i, j);
//			}
//		}
//
//		connectMatrix();
//
//		dpMethod();
//
//
//		cout << "#" << t << " " << dp[1][v.size()] << endl;
//
//		for (int i = 0; i < 21; i++)
//		{
//			for (int j = 0; j < 21; j++)
//			{
//				dp[i][j] = 0;
//			}
//			m[i] = 0;
//		}
//	}
//}
//
//void input()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//}
//
//void check_matrix(int y, int x)
//{
//	// ���� �˻�
//	int sx, ex;
//	sx = ex = x;
//	while (map[y][ex] != 0 && ex < N)
//	{
//		ex++;
//	}
//
//	// ���� �˻�
//	int sy, ey;
//	sy = ey = y;
//	while (map[ey][x] != 0 && ey < N)
//	{
//		ey++;
//	}
//
//	int row, col;
//	row = ey - sy;
//	col = ex - sx;
//
//	v.push_back({ row, col });
//
//	for (int i = sy; i < ey; i++)
//	{
//		for (int j = sx; j < ex; j++)
//		{
//			map[i][j] = 0;
//		}
//	}
//}
//
//void connectMatrix()
//{
//	dq.push_back({ v[0].row, v[0].col });
//
//	while (dq.size() != v.size())
//	{
//		for (int i = 1; i < v.size(); i++)
//		{
//			if (v[i].col == dq.front().row)
//			{
//				dq.push_front(v[i]);
//			}
//			else if (dq.back().col == v[i].row)
//			{
//				dq.push_back(v[i]);
//			}
//		}
//	}
//
//	for (int i = 0; i <= v.size(); i++)
//	{
//		if (i == v.size())
//		{
//			m[i] = dq[i - 1].col;
//		}
//		else
//		{
//			m[i] = dq[i].row;
//		}
//	}
//
//}
//
//void dpMethod()
//{
//	int limit = v.size();
//	for (int l = 0; l < limit; l++)
//	{
//		for (int i = 1; i <= limit - l; i++)
//		{
//			int kLimit = i + l;
//			if (i == kLimit)
//			{
//				dp[i][kLimit] = 0;
//				continue;
//			}
//			dp[i][kLimit] = 999999999;
//			for (int k = i; k <= kLimit-1; k++)
//			{
//				dp[i][kLimit] = min(dp[i][kLimit], dp[i][k] + dp[k + 1][kLimit] + m[i - 1] * m[k] * m[kLimit]);
//			}
//		}
//	}
//}
