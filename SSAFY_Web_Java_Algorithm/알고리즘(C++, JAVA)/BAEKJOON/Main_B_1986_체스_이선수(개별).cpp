///* 1630~1700
//	1. 2�� 128MB
//	2. �׸��� Pawn�� ������� ���� ���� �� ���ٰ� ����
//	(��, ��ֹ��� ���Ҹ� �Ѵٴ� ���̴�).
//	3. 1<= n,m <= 1000
//	4. Knight, Queen, Pawn�� ������ ���� 100�� ���� �ʴ´�.
//
//	Ǯ�� : 
//	��� ���� ���ؼ� ���� �̵� ��θ��� -1�� ���ְ� N*M�� �����ϸ� �� �� �ϴ�.
//	�׷��� ������ ������ ����غ���.
//	pawn�� ���, �Էº��� true��Ű�� ���� ������ ��Ű��,
//	���� 100�� ���, �¿���� �˻縦 �ϸ� 2000*100�̴�. 
//	����Ʈ�� ��� 100���϶�, 4*100
//	�ð��� ũ�� ������ �������ϴ�.
//
//	��� ���� ��ġ�� true�� �ǰ�, ���۵ȴ�.
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//struct unit {
//	int y;
//	int x;
//};
//
//int N, M;
//int total;
//unit units[3][100]; // 0: Q, 1:K, 2:P
//int unitsNum[3];
//int map[1001][1001];
//bool visit[1001][1001];
//int qdir[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1, -1} };
//int kdir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
//
//void input();
//void routeCheck();
//
//int main()
//{
//	input();
//	routeCheck();
//	cout << total;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//	total = N * M;
//	int nums;
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> nums;
//		unitsNum[i] = nums;
//		int y, x;
//		for (int j = 0; j < nums; j++)
//		{
//			cin >> y >> x;
//			units[i][j].y = y;
//			units[i][j].x = x;
//			map[y][x] = 1;
//			visit[y][x] = 1;
//			total--;
//		}
//	}
//}
//
//void routeCheck()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < unitsNum[i]; j++)
//		{
//			if (i == 0) // ��
//			{
//				int y, x;
//
//				for (int k = 0; k < 8; k++)
//				{
//					y = units[i][j].y;
//					x = units[i][j].x;
//
//					while (true)
//					{
//						y += qdir[k][0];
//						x += qdir[k][1];
//
//						if (y < 1 || x < 1 || y > N || x > M || map[y][x] == 1)
//							break;
//						if (visit[y][x])
//							continue;
//						visit[y][x] = true;
//						total--;
//					}
//				}
//			}
//			else // ����Ʈ
//			{
//				int ny, nx;
//				for (int k = 0; k < 8; k++)
//				{
//					ny = units[i][j].y + kdir[k][0];
//					nx = units[i][j].x + kdir[k][1];
//
//					if (ny < 1 || nx < 1 || ny > N || nx > M || map[ny][nx] == 1)
//						continue;
//					if (visit[ny][nx])
//						continue;
//					visit[ny][nx] = true;
//					total--;
//				}
//			}
//		}
//	}
//}
