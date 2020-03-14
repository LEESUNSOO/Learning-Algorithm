///* 0200~0230
//
//	1. 1�� 128MB
//	2. ���μ��ΰ� �ִ� 100�̱⶧���� �ѹ� ��ȸ�ϴµ� 10000���� �����̹Ƿ�
//	�ð������δ� ����ҵ��ϴ�.
//	��ȸ�ϸ� ����� �˻��Ͽ�, ����� ���� 1�� �ƴϸ� false
//	���� 1�̸� true �� ��, true�Ѹ�ŭ�� ���ڸ� ��ȯ�Ѵ�. 
//	����, ��°� Ȯ���� �迭�� �������� ���� �����Ѵ�.
//
//	������ �߸��ľ��ߴ�.
//
//	����� ������ �ƴ� ��ü�� �������� ����� �����ڸ��� �����ϴ°��̾���.
//	ūƲ�� ������, ��� ����� �ٸ��� �ؾ��Ѵ�.
//	bfs�� Ȱ���ؼ� 0�� ����θ� �̵��� �����ϸ�, �����ڸ��� ���� �� �ִ� �ֵ���
//	�����ڸ��̴�.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//struct pos {
//	int y;
//	int x;
//	pos(int Y, int X):y(Y),x(X){}
//};
//int N, M;
//int map[100][100];
//bool melt[100][100];
//bool visit[100][100];
//int oldNum;
//int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//
//void input();
//bool melting(int y, int x);
//void fixMap();
//void visitInit();
//int main()
//{
//	input();
//	int time = 0;
//	while (true)
//	{
//		int num = 0;
//		for (int i = 1; i < N - 1; i++)
//		{
//			for (int j = 1; j < M - 1; j++)
//			{
//				if (map[i][j] == 0)
//					continue;
//
//				if (melting(i, j))
//				{
//					melt[i][j] = true;
//					num++;
//				}
//				visitInit();
//			}
//		}
//
//		if (num == 0)
//			break;
//		fixMap();
//		oldNum = num;
//		time++;
//	}
//	cout << time << endl;
//	cout << oldNum << endl;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	int temp;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//			if (temp == 1)
//				oldNum++;
//		}
//	}
//}
//
//bool melting(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	visit[y][x] = true;
//	int curY, curX, ny, nx;
//	while (!que.empty())
//	{
//		pos cur = que.front();
//		que.pop();
//		curY = cur.y;
//		curX = cur.x;
//		for (int k = 0; k < 4; k++)
//		{
//			ny = curY + dir[k][0];
//			nx = curX + dir[k][1];
//
//			if (map[ny][nx] == 1 || visit[ny][nx])
//				continue;
//
//			if (ny == 0 || nx == 0 || ny == N - 1 || nx == M - 1)
//				return true;
//			else
//			{
//				que.push({ ny,nx });
//				visit[ny][nx] = true;
//			}
//		}
//	}
//
//	return false;
//}
//
//void fixMap()
//{
//	for (int i = 1; i < N - 1; i++)
//	{
//		for (int j = 1; j < M - 1; j++)
//		{
//			if (melt[i][j])
//			{
//				map[i][j] = 0;
//				melt[i][j] = false;
//			}
//		}
//	}
//}
//
//void visitInit()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//}
