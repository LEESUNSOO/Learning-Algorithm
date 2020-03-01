///* 1545~1605 20M
//	1. 1�� 128MB
//	2. ������ ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� 
//	���� �� �ð��� �ɸ��� ���� �� ���� ������ �����ִ�
//	3. ����, ������ ũ��� ���� 50����
//	4. ������ ��Ÿ���� �� �� ���̸� �ִ� �Ÿ��� �̵��Ϸ��� 
//	���� ���� �� �� �̻� �������ų�, �ָ� ���ư����� �� �ȴ�.
//	Ǯ�� :
//	���� �� ���� bfs�� �����Ͽ� que�� ���������� �Ÿ��� ����ϸ� �� ���ϴ�.
//	��� ������ �˻��ϰ� �ִ밪�� ����ϸ� �ɵ��ϰ�
//	bfs�� �˻��Ҷ����� visit�� �ʱ�ȭ �����ش�.
//	���� ����� ���� ��� ������ �������� �ְ�����, ���� �������� ������ �ϴ� ���� ��
//
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
//};
//
//bool visit[50][50];
//char map[50][50];
//int maxVal;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//int N, M;
//
//void input();
//void bfs(int y, int x);
//void visitInit();
//
//int main()
//{
//	input();
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (map[i][j] == 'W')
//				continue;
//			bfs(i, j);
//			visitInit();
//		}
//	}
//	cout << maxVal;
//
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
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//}
//
//void bfs(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	visit[y][x] = true;
//
//	pos cur;
//	int curY, curX;
//	int ny, nx;
//	int size, dis;
//	dis = 0;
//	while (!que.empty())
//	{
//		size = que.size();
//		while (size-- > 0)
//		{
//			cur = que.front();
//			que.pop();
//			curY = cur.y;
//			curX = cur.x;
//
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == 'W')
//					continue;
//
//				que.push({ ny,nx });
//				visit[ny][nx] = true;
//			}
//		}
//		dis++;
//	}
//	if (maxVal < dis - 1)
//		maxVal = dis - 1;
//
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
