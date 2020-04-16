///* 2100~2125
//	1. 1�� 256MB
//	2. ����ġ ������ �Ȱ���.
//	�ٸ�, �ִ� ���̰� 1000�ε�,
//	100���� ���ɰ� 1�ʴ�.
//	�� 1000*1000 ¥���� 100tc���´� �������� ��,
//	�Ұ� ����̰� ���� �ָ� ���ÿ� ���� �߽ɿ��� �ⱸ�� ���� 
//	�ִٰ� �����ϸ� �뷫 50��*4 => 200�� ���� ���귮�� ���õ��ϴ�.
//	�׷�, �־��� ��� �� 2���� �����̹Ƿ� �ָ������� ���迡 ���ϸ� �����ҵ��ϴ�.
//	(�� 1����� 1�ʴ� �ƴϴ���)
//
//	Ǯ��:
//	����� ��ġ�� ���� ��ġ�� ť�� ��´�,
//	���� �̵� -> ����� �̵��� �ݺ��ϸ�, ����̰� ���̻� �̵��� ���� ���� ��,
//	impossible!
//	���� ������ ������ ��, �Ÿ��� ���ش�.
//	���ڿ� ���� �̵��� ������ ���̱� ������ ������� �̵� visit������ ������ �� ���ϴ�.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//struct pos {
//	int y;
//	int x;
//};
//
//queue<pos> sang;
//queue<pos> fire;
//char map[1000][1000];
//bool visit[1000][1000];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int N, M;
//
//void input();
//int bfs();
//void reset();
//
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 0; t < T; t++)
//	{
//		input();
//		int answer = bfs();
//		if (answer == -1)
//			cout << "IMPOSSIBLE" << endl;
//		else
//			cout << answer << endl;
//		reset();
//	}
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> M >> N;
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin	>> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = temp[j];
//			if (temp[j] == '*')
//			{
//				fire.push({ i,j });
//			}
//			else if (temp[j] == '@')
//			{
//				sang.push({ i,j });
//				visit[i][j] = true;
//			}
//		}
//	}
//}
//
//int bfs()
//{
//	int dis = 0;
//	int curY, curX, ny, nx;
//	while (!sang.empty())
//	{
//		int size = fire.size();
//		while (size-- > 0)
//		{
//			curY = fire.front().y;
//			curX = fire.front().x;
//			fire.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '*' || map[ny][nx] == '#')
//					continue;
//				map[ny][nx] = '*';
//				fire.push({ ny,nx });
//			}
//		}
//
//		size = sang.size();
//		while (size-- > 0)
//		{
//			curY = sang.front().y;
//			curX = sang.front().x;
//			sang.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M)
//					return dis+1;
//				if(visit[ny][nx] || map[ny][nx] == '*' || map[ny][nx] == '#')
//					continue;
//				visit[ny][nx] = true;
//				sang.push({ ny,nx });
//			}
//		}
//		dis++;
//	}
//	return -1;
//}
//
//void reset()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//	while (!sang.empty())
//		sang.pop();
//	while (!fire.empty())
//		fire.pop();
//
//}
