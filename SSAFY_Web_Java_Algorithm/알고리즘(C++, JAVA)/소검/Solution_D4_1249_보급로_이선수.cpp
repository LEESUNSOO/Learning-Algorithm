///* 1520~1605
//	�ܼ�
//	1. ���ΰ� �Ŀ��� ���̿� ����ؼ� ���� �ð��� �����Ѵ�
//	2. ��������� ���������� ���� ��� �߿� ���� �ð��� ���� ª�� ��ο� ���� �� ���� �ð��� ���Ͻÿ�.
//	3. ���̰� 1�̶�� ������ ��� �ð��� 1�̶�� �����Ѵ�.
//
//	Ǯ��
//	1. bfs�� Ȱ���� dp�� Ǯ���
//	2. dfs�� Ȱ���� ��Ʈ��ŷ�� ����̴�. => �������� �ð��ʰ��� ����.
//	 => �Ƹ� ó���� �ּҰ��� ����� ���� ������ ����ġ�Ⱑ ���� �ǰ�����,
//	 �־��� ��� ��ü Ž���� �ϰ� �ȴ�.
//
//	�׷� �ϴ� ���� dfs���� �غ���,
//	�׷� dp�� �ٽ� ����
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
//	pos(int Y = 0, int X = 0):y(Y),x(X){}
//};
//
//int map[100][100];
//int dp[100][100];
//int N;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//void input();
//void bfsDP(int y, int x);
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		bfsDP(0, 0);
//		cout << "#" << t << " " << dp[N-1][N-1] << endl;
//	}
//}
//
//void input()
//{
//	cin >> N;
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < N; j++)
//		{
//			map[i][j] = temp[j]-'0';
//			dp[i][j] = -1;
//		}
//	}
//}
//
//void bfsDP(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	dp[y][x] = map[y][x];
//	
//	int curY, curX;
//	int ny, nx;
//	while (!que.empty())
//	{
//		curY = que.front().y;
//		curX = que.front().x;
//		que.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
//				continue;
//
//			if (dp[ny][nx] != -1) // �湮�� ���� �ִٸ�,
//			{
//				if (dp[ny][nx] > dp[curY][curX] + map[ny][nx])
//				{
//					dp[ny][nx] = dp[curY][curX] + map[ny][nx];
//					que.push({ ny,nx });
//				}
//			}
//			else
//			{
//				dp[ny][nx] = dp[curY][curX] + map[ny][nx];
//				que.push({ ny,nx });
//			}
//		}
//
//	}
//}
//
