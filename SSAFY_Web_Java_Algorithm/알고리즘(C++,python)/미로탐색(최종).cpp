//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//int map[100][100];
//int visit[100][100];
//int n, m; // ���� ����
//
//bool check(int x, int y)
//{
//	if (x >= 0 && x < n && y >= 0 && y < m)
//		return true;
//	return false;
//}
//void solution()
//{
//	//������
//	int x, y;
//	x = y = 0;
//
//	//bfs ť
//	queue<pair<int, int>> q;
//
//	//�������� push
//	q.push({ x,y });
//
//	//���� ��ġ
//	pair<int, int> site;
//
//	int direction[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
//
//	int nextX;
//	int nextY;
//
//	while (!q.empty())
//	{
//		site = q.front();
//		q.pop();
//		x = site.first;
//		y = site.second;
//		visit[x][y] = true;
//
//		for (int i = 0; i < 4; i++)
//		{
//			nextX = x + direction[i][0];
//			nextY = y + direction[i][1];
//
//			if (check(nextX, nextY) && map[nextX][nextY] == 1 && !visit[nextX][nextY])
//			{
//				q.push({ nextX, nextY });
//				map[nextX][nextY] = map[x][y] + 1;
//			}
//		}
//	}
//
//	cout << map[n - 1][m - 1];
//}
//int main()
//{
//	cin >> n >> m;
//
//	string temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < m; j++)
//		{
//			map[i][j] = temp[j] - '0';
//		}
//	}
//
//	solution();
//	return 0;
//}
//
///*
//�Ÿ��� ���ؾ� �ϰ� ���������� ��ǥ������ �����Ǿ��ִ�.
//	 -> ������ ���� �ľ�
//��ΰ� ���� �ʿ����� �ʱ⶧���� �θ��忡 ���� ������ �ʿ������
//	 -> ���ʿ��� �޸� �Ҵ�
//���������� ������ �������� ������ �̷������ ������ �߰��� break�� �� �ʿ����.
//	 -> ������ ���� �ľ�
//���� ������ ���̺� �ʿ���� ������ ���̺��� �����ϸ鼭 �����ϸ� �ȴ�.
//	 -> �� �κп��� �޸𸮸� �ּ�ȭ��ų �� �ִ�.
//*/