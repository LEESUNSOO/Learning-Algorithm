///* 1640~1730
//	Ǯ�� :
//	1) ���� 1~N-2���� ���� ��� �� ��ȸ�� �Ѵ�.
//	2) ��ȸ�� �� ������ visitó���� �ٽ� ���ش�.
//	3) ������ġ �Ű������� ������ ����ϰ� �ش� ��ġ�� ���ƿ��� �Ÿ��� �ִ밪�� �����ش�.
//	4) ������ ��� ���� skip�Ѵ�.
//	5) �ִ밪 ���̱� ������ ����ġ�Ⱑ �Ұ���������,
//	DP�� ����غ���.
//	DP�� �Ƚᵵ 20*20 �̱� ������, ����� �� �ϴ� ..����^^;
//	6) ���������� ���⿡ ���� ������ �־�� �� �� �ϴ�. �ݷʷ� ��Ʈ���?����� ����Ŭ�� ������ ���� �ִ�.
//	7) ���� ���� ������ ���ϸ� ���϶� ���ϸ� ����ϰ�,
//		���ϸ� ���Ͽ� �»� ����ϴ� �̷� ������ ������ �� ����.
//		������ �ð�������� �����ϴ°��� ������ �ɱ� �ͱ⵵ ������ 
//		�� �������� �������� ��, �ݴ��� ����� ���� �� ��Ƹ� �� ���� �ŷ� �����ȴ�.
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//};
//
//int N;
//int maxNum;
//int map[20][20];
//bool visit[20][20];
//bool numCheck[101];
//int dir[4][2] = { {1,1},{1,-1},{-1,-1},{-1,1} };
//
//int maxVal = 0;
//
//void input();
//void boolInit();
//void dfs(pos start, pos cur, int d, int dis);
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		maxVal = 0;
//		for (int i = 0; i < N-2; i++)
//		{
//			for (int j = 1; j < N - 1; j++)
//			{
//				dfs({ i,j }, { i,j }, 0, 0);
//				//boolInit();
//			}
//		}
//
//		if (maxVal == 0)
//			cout << "#" << t << " " << -1 << endl;
//		else
//			cout << "#" << t << " " << maxVal << endl;
//	}
//
//
//	return 0;
//}
//
//void input()
//{
//	cin >> N;
//	int temp;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//			if (temp > maxNum)
//				maxNum = temp;
//		}
//	}
//}
//
//void boolInit()
//{
//	//for (int i = 1; i <= maxNum; i++)
//	//	numCheck[i] = false;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//
//}
//
//void dfs(pos start, pos cur, int d, int dis)
//{
//	if (cur.y == start.y && cur.x == start.x && visit[cur.y][cur.x])
//	{
//		// ����Ŭ ����
//		if (maxVal < dis)
//			maxVal = dis;
//		return;
//	}
//
//	if (visit[cur.y][cur.x] || numCheck[map[cur.y][cur.x]] || cur.y < start.y)
//		return;
//
//
//	int ny, nx;
//	int curY, curX;
//	curY = cur.y;
//	curX = cur.x;
//
//	visit[curY][curX] = true;
//	numCheck[map[curY][curX]] = true;
//
//	for (int i = 0; i < 2; i++)
//	{
//		ny = curY + dir[(d + i) % 4][0];
//		nx = curX + dir[(d + i) % 4][1];
//
//		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
//			continue;
//		dfs(start, { ny,nx }, (d + i) % 4, dis + 1);
//	}
//
//	visit[curY][curX] = false;
//	numCheck[map[curY][curX]] = false;
//}
//
///*
//1
//4
//9 8 9 8
//4 6 9 4
//8 7 7 8
//4 5 3 5
//
//1 8 18 18 7 16 15 3 5 6 3 6 8 3 15 13 15 2 4 1 11 17 3 4 3 17 16 2 18 10 2 3 11 12 11 17 16 2 9 16 5 4 17 7 6 16 16 11 15 8 2 1 7 18 12 11 6 2 13 12 12 15 9 11 12 18 
//*/