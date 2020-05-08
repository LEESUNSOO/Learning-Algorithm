///* 1655~
//	1. 1�� 128MB
//	2. ���� ����, ���� �������� ������ ���� �پ�Ѿ �� ���� ���� ĭ���� �̵��ϴ� �͸� ���ȴ�. 
//	 ������ ���� ���� ĭ�� ����־�� �ϰ� �� ������ ���� ���ŵȴ�.
//	 ���� �����ǿ� �����ִ� ���� ���°� �־�����. �̶�, ���� ������ �������� �����ǿ� �����ִ�
//	 ���� ������ �ּҷ� �Ϸ��� �Ѵ�. ��, �׷��� ����� ���� �ʿ��� �ּ� �̵�Ƚ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//	3. 1 <= N <= 100 (���� ��)
//	4.  '.'�� �� ĭ, 'o'�� ���� �����ִ� ĭ, '#'�� ������ ���� ĭ�̴�.
//	���� ������ �ִ� 8�̸�, �� �׽�Ʈ ���̽��� �� �ٷ� ���еǾ��� �ִ�.
//
//	Ǯ��
//	1. ���� ������ �ִ� 8���ϱ�, ��ǥ�� Ȱ��ȭ���¸� ���� ����ü�� Ŭ������ Ȱ���ؼ� ���Ϳ� ��´�.
//	2. ���� dfs
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int oCnt;
//char map[5][9];
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int minPin = 10;
//void input();
//void dfs(int p);
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		oCnt = 0;
//		minPin = 10;
//		input();
//		dfs(oCnt);
//
//		if (oCnt == 0)
//		{
//			cout << 0 << " " << 0 << endl;
//		}
//		else
//		{
//			cout << minPin << " " << oCnt-minPin << endl;
//		}
//	}
//
//
//
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string s;
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> s;
//		for (int j = 0; j < 9; j++)
//		{
//			map[i][j] = s[j];
//			if (s[j] == 'o')
//				oCnt++;
//		}
//	}
//
//}
//
//void dfs(int p)
//{
//	int ny, nx;
//	int nny, nnx;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (map[i][j] != 'o')
//				continue;
//
//			for (int k = 0; k < 4; k++)
//			{
//				ny = i + dir[k][0];
//				nx = j + dir[k][1];
//
//				if (ny < 0 || nx < 0 || ny >= 5 || nx >= 9 || map[ny][nx] == '.' || map[ny][nx] == '#')
//					continue;
//
//				nny = ny + dir[k][0];
//				nnx = nx + dir[k][1];
//
//				if (nny < 0 || nnx < 0 || nny >= 5 || nnx >= 9)
//					continue;
//
//				if (map[nny][nnx] == '.')
//				{
//					map[nny][nnx] = 'o';
//					map[i][j] = '.';
//					map[ny][nx] = '.';
//					dfs(p - 1);
//					map[ny][nx] = 'o';
//					map[i][j] = 'o';
//					map[nny][nnx] = '.';
//				}
//			}
//		}
//	}
//
//	if (minPin > p)
//	{
//		minPin = p;
//	}
//}
