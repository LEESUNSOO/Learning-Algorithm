///* 0110~0250
//	1. 1�� 128MB => ���Ǹ� ���� ���� �����غ��� ����, �ܼ� ��ȸ�� �ƴϴ�
//	2. ���� �̳׶��� ���� Ŭ������,
//	3. ���밡 ���ư��ٰ� �̳׶��� ������, �� ĭ�� �ִ� �̳׶��� ��� �ı��ǰ� ����� �� �ڸ����� �̵��� �����.
//	4. �̳׶��� �ı��� ���Ŀ� ���� Ŭ�����Ͱ� �и��� ���� �ִ�.
//	5. ���Ӱ� ������ Ŭ�����Ͱ� �� �ִ� ��쿡�� �߷¿� ���ؼ� �ٴ����� �������� �ȴ�.
//	6. �������� ���� Ŭ�������� ����� ������ �ʴ´�.
//	7. Ŭ�����ʹ� �ٸ� Ŭ�����ͳ� ���� ������ ������ �Լ��ؼ� ��������.
//	8. Ŭ�����ʹ� �ٸ� Ŭ������ ���� ������ �� �ְ�, �� ���Ŀ��� �������� �ȴ�.
//
//	 (1 �� R,C �� 100)
//	  ���� 1�� ����� ���� �ٴ�, R�� ���� ���� �ǹ��Ѵ�.
//	  ù ��° ����� ���ʿ��� ���������� ��������,
//	  �� ��°�� �����ʿ��� ��������,
//	  �̿� ���� ������ �����ư��� ������.
//	  ���߿� �� �ִ� �̳׶� Ŭ�����ʹ� ������,
//	  �� �� �Ǵ� �� �̻��� Ŭ�����Ͱ� ���ÿ� �������� ��쵵 ����.
//
//	  Ǯ�� :
//	  ����ϴ� �� ������ ������ ������,
//	  Ŭ�����Ͱ� ���߿� ���ִ� ��츦 �ľ��ϱ� ����
//	  �ٴ��� �̳׶����� �������θ� �ľ��Ͽ� ���߿� ���ִ� �̳׶��� üũ�Ѵ�.
//
//	  �׷��ٸ� �и��� Ŭ�������� �߶���?
//	  => ������ Ŭ�����ͷ� �Ǵ��� ��, visit�� true�� �� �κ��� �����ٵ�,
//	  ���� �ɷ� �ǴܵǸ�, �� visit�� ��������
//	  ���ϴ��� ��ǥ�� ���
//	  y���� �ϳ��� ����(����)��Ű�� �ٴ��̳�, �ٸ� �̳׶��� �߰ߵǸ�
//	  �� �������� �� �����ش�.
//	  '�� Ŭ�������� �� �Ʒ� �κ��� �ٴ� �Ǵ� �̳׶� ���� �������� �Է¸� �־�����.'
//	  �� ���ǿ��� ������ �ٴ��� �ƴ� �ٸ� �κ��� �ٸ� �̳׶��� �������� ���� �����ص� �Ǵ�
//	  ����� �κ��� �پ���.
//
//	  ������ 1�ʶ� �ð� ���� �����ұ�?
//	  �뷫������ 100*(100*100 + 100*100) ������ �ð� ���⵵�� ������ ������ �ʹ�.
//
//	  ������
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = -1, int X = -1) :y(Y), x(X) {}
//};
//
//int Y, X;
//char map[100][100]; //�ϴ��� 1���� ��������
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; // bfs��ȸ, �����̳׶� Ȯ�ο�
//int cmdNum;
//int cmd[100]; // ������ ���� �򰥸��� �ʰ� �Է¹��� �� ���� R-x�� ����
//int visit[100][100];
//
//void input();
//void roundCluster(pos adjoin);
//pos destroy(int idx); // idx % 2 == 0 ? 1 ?
//void moveCluster(); // �� visit�� ���� ����,
//void visitInit(); // ����Ȯ���� ��ĥ������ ������Ѵ�. �ֳĸ� ���ߺ��ص� Ŭ�����Ͱ� �ΰ� �� ���� �ִ�.
//
//int main()
//{
//	input();
//	
//	for (int i = 0; i < cmdNum; i++)
//	{
//		pos dpos = destroy(i);
//		if (dpos.y == -1) // �ƹ��͵� �ȸ���
//			continue;
//
//		for (int j = 0; j < X; j++)
//		{
//			if (visit[Y - 1][j] || map[Y-1][j] != 'x')
//				continue;
//			roundCluster({ Y-1,j });
//		}
//		moveCluster();
//		visitInit();
//	}
//	for (int i = 0; i < Y; i++)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> Y >> X;
//	string temp;
//	for (int i = 0; i < Y; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < X; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//
//	cin >> cmdNum;
//	int height;
//	for (int i = 0; i < cmdNum; i++)
//	{
//		cin >> height;
//		cmd[i] = Y - height;
//	}
//}
//
//void roundCluster(pos adjoin)
//{
//	queue<pos> que;
//	que.push({ adjoin.y, adjoin.x });
//	visit[adjoin.y][adjoin.x] = 1;
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
//			if (ny < 0 || nx < 0 || ny >= Y || nx >= X || visit[ny][nx] == 1 || map[ny][nx] != 'x')
//				continue;
//			visit[ny][nx] = 1;
//			que.push({ ny,nx });
//		}
//	}
//}
//
//pos destroy(int idx)
//{
//	pos dpos;
//	int height = cmd[idx];
//	if (idx % 2 == 0) // ��->��
//	{
//		for (int x = 0; x < X; x++)
//		{
//			if (map[height][x] == 'x')
//			{
//				dpos.y = height;
//				dpos.x = x;
//				map[height][x] = '.';
//				break;
//			}
//		}
//	}
//	else // �� -> ��
//	{
//		for (int x = X - 1; x >= 0; x--)
//		{
//			if (map[height][x] == 'x')
//			{
//				dpos.y = height;
//				dpos.x = x;
//				map[height][x] = '.';
//				break;
//			}
//		}
//	}
//	return dpos;
//}
//
//void moveCluster()
//{
//	// ���� �� ���� ��ǥ Ȯ��
//	int maxDis = Y;
//	int y, x;
//	for (int i = Y-1 ; i >=0; i--)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			if (visit[i][j] == 0 && map[i][j] == 'x') // ���ϰ� ����ȵƴµ� �̳׶��ξֵ�
//			{
//				y = i;
//				x = j;
//				int fallDis = 0;
//				while (true) // ��ĭ�� ������ �ٴ� �� �̳׶� ���� ���� ã��
//				{
//					y++;
//					if ((map[y][x] == 'x' && visit[y][x]) || y == Y)
//						break;
//					fallDis++;
//				}
//				if (maxDis > fallDis)
//					maxDis = fallDis;
//			}
//		}
//	}
//
//	// fallDis�� �������� map�� ����
//	for (int i = Y - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			if (visit[i][j] == 0 && map[i][j] == 'x')
//			{
//				map[i + maxDis][j] = 'x';
//				map[i][j] = '.';
//			}
//		}
//	}
//}
//
//void visitInit()
//{
//	for (int i = 0; i < Y; i++)
//	{
//		for (int j = 0; j < X; j++)
//		{
//			visit[i][j] = 0;
//		}
//	}
//}
//
///*
//
//�ݷ� �����
//
//6 6
//xxxxxx
//x.xx.x
//x.xx.x
//x.xx.x
//..xx..
//..xx..
//6
//4 4 6 6 2 2
//
//6 6
//.....x
//.....x
//.....x
//xxxxxx
//.....x
//.....x
//2
//3 3
//
//
//
//*/