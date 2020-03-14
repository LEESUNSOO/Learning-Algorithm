///* 2100~2220
//	1. 1�� 256MB
//	2. 1 �� R, C �� 1500 => �Ϲ����� BFS�� Ǯ�� �ȵɵ�.
//
//	Ǯ�� : 
//	1. �𷡼��ױ�������� �������� ���� ���ϸ� ���� que�� �����.
//	2. �����ϳ��� �ִ� �̵���θ� ���� ť�� �ϳ������, ��θ� Ž���� ť�� �ϳ� �����.
//	3. ���ϴ� �������ִ� ���� X�� ������ ������, ������ ���, ���ϰ� �μ����� ������ ���ϰ� �ƴ�
//	 �ٴٸ� ���� ���ϸ� ���������� ��ȸ�� �ؾ� �Ѵ�.
//	4. ����ť�� ��ȸ�߿� �ٸ� ������ ������ �����Ѵ�.
//
//	�湮ó���� ������ �����, ���ϴ� �ʿ� ��ȭ�� ���� �����ϵ��� ����.
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
//	pos(int Y = 0 , int X = 0):y(Y), x(X){}
//};
//int N, M;
//char map[1500][1500];
//bool visitL[1500][1500]; // ������
//pos L1, L2;
//queue<pos> W, L;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//void input();
//bool melt();
//int main()
//{
//	input();
//
//	int days = 0;
//	while (!melt())
//	{
//		days++;
//	}
//	cout << days;
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
//	string temp;
//	int cnt = 0;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j ++)
//		{
//			map[i][j] = temp[j];
//			if (temp[j] == 'L')
//			{
//				if (cnt == 0)
//				{
//					L1.y = i;
//					L1.x = j;
//					cnt++;
//				}
//				else
//				{
//					L2.y = i;
//					L2.x = j;
//				}
//				W.push({ i,j });
//			}
//			else if (temp[j] == '.')
//			{
//				W.push({ i,j });
//			}
//		}
//	}
//}
//
//bool melt()
//{
//	int curY, curX, ny, nx;
//	queue<pos> NL;
//	L.push({ L1.y, L1.x });
//	visitL[L1.y][L1.x] = true;
//	// ���� �̵���Ű��,
//	while (!L.empty())
//	{
//		curY = L.front().y;
//		curX = L.front().x;
//		L.pop();
//
//		if (curY == L2.y && curX == L2.x) // ���忡 ���� ������ �ִ� ���, ���ǿ� �׷��� ���ٴ°� �Ⱥ��δ�. '�׷����� �� ������ ȣ���� ���� �ִ� �������� ������ ���Ѵ�.' �̰ǰ�? Ȥ�ø𸣴� ��
//		{
//			return true;
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visitL[ny][nx])
//				continue;
//			if (map[ny][nx] == 'X')
//			{
//				NL.push({ ny,nx });
//				visitL[ny][nx] = true;
//			}
//			else
//			{
//				L.push({ ny,nx });
//				visitL[ny][nx] = true;
//			}
//		}
//	}
//
//	// ���� ���̰�,
//	int size = W.size();
//	while (size-- > 0) 
//	{
//		curY = W.front().y;
//		curX = W.front().x;
//		W.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '.' || map[ny][nx] == 'L')
//				continue;
//
//			W.push({ ny,nx });
//			map[ny][nx] = '.';
//		}
//	}
//
//
//	L = NL;
//
//	return false;
//}
