///* 0920~1000
//	Ǯ�� :
//	������ �� �ڸ��� ���� ����� ���� ���Ѵ�.
//	�ִ� W�� 12�̱� ������, 12*12*12*12 (N�� �ִ� 4��) �� �ǰڴ�. 
//	�� ��츶�� �߻� ����, �浹�� ���� �������⸦ ��������� �����Ѵ�.
//	������ ������ ��, ��ܿ� 0�� �ƴ� ���� �ִٸ� �Ʒ��� ��ĭ�� �̵� �����ش�.
//	������ ����� Ȱ���Ͽ� ���� ���� �� �ִ밪�� ���Ͽ� ���� ��´�.
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int N, W, H;
//int minVal;
//int map[15][12];
//int copyMap[15][12];
//bool visit[15][12];
//int cmd[4];
//int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
//int total;
//
//void input()
//{
//	cin >> N >> W >> H;
//
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			cin >> map[i][j];
//			if (map[i][j] != 0)
//				total++;
//		}
//	}
//
//}
//
//void mapCopy()
//{
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			copyMap[i][j] = map[i][j];
//		}
//	}
//}
//void visitInit()
//{
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			visit[i][j] = false;
//		}
//	}
//}
//void fall()
//{
//	for (int i = 0; i < W; i++)
//	{
//		vector<int> temp;
//		for (int j = H - 1; j >= 0; j--)
//		{
//			if (!visit[j][i] && copyMap[j][i] != 0)
//				temp.push_back(copyMap[j][i]);
//		}
//		for (int j = 0; j < temp.size(); j++)
//		{
//			copyMap[H - 1 - j][i] = temp[j];
//		}
//		for (int j = temp.size(); j < H; j++)
//		{
//			copyMap[H - 1 - j][i] = 0;
//		}
//	}	
//
//}
//void destroy(int y, int x, int dis)
//{
//
//	int ny, nx;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 1; j <= dis; j++)
//		{
//			ny = y + dir[i][0] * j;
//			nx = x + dir[i][1] * j;
//
//			if (ny < 0 || nx < 0 || ny >= H || nx >= W || visit[ny][nx] || copyMap[ny][nx] == 0)
//				continue;
//
//			visit[ny][nx] = true;
//			destroy(ny, nx, copyMap[ny][nx] - 1);
//		}
//	}
//
//}
//
//void shoot(int x)
//{
//	int curY = 0;
//
//	while (copyMap[curY][x] == 0)
//	{
//		curY++;
//		if (curY == H)
//			return;
//	}
//	visit[curY][x] = true;
//	destroy(curY, x, copyMap[curY][x] - 1);
//}
//void posDfs(int cnt)
//{
//	if (cnt == N) // 0~N-1 ��ġ���õ�
//	{
//		mapCopy();
//
//		for (int i = 0; i < N; i++)
//		{
//			shoot(cmd[i]);
//			fall();
//			visitInit();
//		}
//		if (minVal == 0)
//			return;
//
//		int cnt = 0;
//
//		for (int i = 0; i < H; i++)
//		{
//			for (int j = 0; j < W; j++)
//			{
//				if (copyMap[i][j] != 0)
//					cnt++;
//			}
//		}
//
//		if (minVal > cnt)
//			minVal = cnt;
//		return;
//	}
//
//	for (int i = 0; i < W; i++)
//	{
//		cmd[cnt] = i;
//		posDfs(cnt + 1);
//		if (minVal == 0)
//			return;
//	}
//}
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		minVal = 9999;
//		posDfs(0);
//		cout << "#" << t << " " << minVal << endl;
//	}
//
//
//	return 0;
//}
