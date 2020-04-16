///* 2120~2030
//	1. 50�� 5�� 1���� 0.1�� 10,000,000����
//	2. struct�� �̻��� ������ ��� �̵���Ű��,
//	3. vector<int>[][] �� ������ ��´�.
//	�غ���~
//	������ �ݴ� ��� ������ �����Ƿ� dir �Ű�Ἥ ����
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//struct microbe {
//	int y;
//	int x;
//	int num;
//	int dir;
//	bool isActive;
//};
//
//int N, M, K;
//vector<int> map[100][100];
//int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
//microbe mc[1000];
//
//int dirChange(int dir)
//{
//	switch (dir)
//	{
//	case 1:
//		return 0;
//	case 2:
//		return 2;
//	case 3:
//		return 1;
//	case 4:
//		return 3;
//	}
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M >> K;
//	int y, x, n, d;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> y >> x >> n >> d;
//		mc[i].y = y;
//		mc[i].x = x;
//		mc[i].num = n;
//		mc[i].dir = dirChange(d);
//		mc[i].isActive = true;
//	}
//
//}
//
//void move()
//{
//	int ny, nx;
//	for (int i = 0; i < K; i++)
//	{
//		if (!mc[i].isActive)
//			continue;
//		ny = mc[i].y + dir[mc[i].dir][0];
//		nx = mc[i].x + dir[mc[i].dir][1];
//
//		if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) // ����������
//		{
//			mc[i].num /= 2;
//			mc[i].dir = (mc[i].dir + 2) % 4;
//		}
//		if (mc[i].num == 0)
//		{
//			mc[i].isActive = false;
//		}
//		else
//		{
//			mc[i].y = ny;
//			mc[i].x = nx;
//			map[ny][nx].push_back(i);
//		}
//	}
//}
//
//void sameCheck()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (map[i][j].size() > 1) // ������ 2���̻��ִٸ�,
//			{
//				int max = 0;
//				int maxIdx = 0;
//				for (int k = 0; k < map[i][j].size(); k++)
//				{
//					if (mc[map[i][j][k]].num > max)
//					{
//						max = mc[map[i][j][k]].num;
//						maxIdx = map[i][j][k];
//					}
//				}
//
//				for (int k = 0; k < map[i][j].size(); k++)
//				{
//					if (maxIdx == map[i][j][k])
//						continue;
//					mc[maxIdx].num += mc[map[i][j][k]].num;
//					mc[map[i][j][k]].isActive = false;
//				}
//			}
//			map[i][j].clear();
//		}
//	}
//}
//
//int sumCheck()
//{
//	int sum = 0;
//	for (int i = 0; i < K; i++)
//	{
//		if (!mc[i].isActive)
//			continue;
//		sum += mc[i].num;
//	}
//	return sum;
//}
//
//int main(int argc, char** argv)
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		//map �ʱ�ȭ
//		cout << N << endl;
//		int hour = M;
//		while (hour-- > 0)
//		{
//			move();
//			sameCheck();
//		}
//		cout << "#" << t << " " << sumCheck() << endl;
//	}
//
//	return 0;
//}
//
//
