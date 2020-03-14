//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int MOD = 20170805;
//int M;
//int N;
////int check[501][501];
//int cmap[501][501];
//pair<int,int> p[501][501];
//int cnt;
//
//// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
//// DFS ������ �����ȴ�
//bool areacheck(int x, int y)
//{
//	if (x >= N || y >= M) // �����ʰ��� ���,
//		return true;
//	return false;
//}
//
//void dfs(int x, int y)
//{
//	if (areacheck(x, y)) // ���� �ʰ��� ���,
//		return;
//
//	//if (check[y][x]) // �湮�� ���,
//		//return;
//
//	if (cmap[y][x] == 1) // ��������� ���,
//		return;
//
//	else if (x == N-1 && y == M-1) // ���������� ���,
//	{
//		cnt++;
//		if (cnt > MOD)
//			cnt %= MOD;
//		return;
//	}
//	
//	else if (cmap[y][x] == 0) // 0�� ������ ���,
//	{
//		p[y][x + 1] = { y,x }; // ����
//		dfs(x + 1, y);
//
//		p[y + 1][x] = { y,x }; // �ϴ�
//		dfs(x, y + 1);
//	}
//
//	else if (cmap[y][x] == 2) // 2�� ������ ���,
//	{
//		if (p[y][x].first == y)
//		{
//			//if (areacheck(x + 1, y))
//				//return;
//			p[y][x + 1] = { y,x };
//			dfs(x + 1, y);
//		}
//		else
//		{
//			//if (areacheck(x, y+1))
//				//return;
//			p[y + 1][x] = { y,x };
//			dfs(x, y + 1);
//		}
//	}	
//}
//int solution(int m, int n, vector<vector<int>> city_map) {
//
//	int answer = 0;
//	M = m; N = n;
//	cnt = 0;
//
//	for (int i = 0; i < 501; i++)
//	{
//		for (int j = 0; j < 501; j++)
//		{
//			//check[i][j] = 0;
//			p[i][j] = { 0,0 };
//		}
//	}
//
//	for (int i = 0; i < city_map.size(); i++)
//	{
//		for (int j = 0; j < city_map[i].size(); j++)
//		{
//			cmap[i][j] = city_map[i][j];
//		}
//	}
//
//	dfs(0, 0);
//	answer = cnt;
//	return answer;
//}
//
//int main()
//{
//	int m, n;
//	m = 3;
//	n = 6;
//	vector<vector<int>> v = { {0,2,0,0,0,2},{0,0,2,0,1,0},{1,0,0,2,2,0} };
//	cout << solution(m, n, v) << endl;
//	
//
//
//	return 0;
//}
