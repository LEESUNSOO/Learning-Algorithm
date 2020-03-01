///* 1450~1535 45M �� ť
//	1. 1�� 256MB
//	2. �ϳ⸶�� �� ĭ�� �������� �� �������� �پ��ִ� 0�� ����� ĭ�� ������ŭ �پ���.
//	3. 0���� �� ���� �ʴ´�.
//	4. ��� ������ ������ 0�� ���� ��, �� ���� ���꿡 ������ �ش�.
//	5. ������ �ΰ��� �������� �ּ� ����� ���ϴµ� �� ���������� �ε��̷� �ȳ����� 0�� ���
//	6. N�� M�� 3 <= <= 300
//	7. ������ 10000�� ����
//
//	Ǯ�� :
//	ũ�� ���� ��,
//	while{
//	���̱�
//	��ȹ�˻� ( 1���� ��, 2���̻��� ��, 0���� �� ����)
//	} �ε�, 
//	������ ���̱⿡���̴�. 
//	'�迭���� ������ �� �κп� �ش�Ǵ� ĭ�� �ִ� ���̴� �ϳ⸶�� 
//	�� ĭ�� �������� �� �������� �پ��ִ� 0�� ����� ĭ�� ������ŭ �پ���.' �� ������ ����
//	��°������� 0�� �Ǿ��ٰ� ���� ���꿡 ������ �ִ°� �ƴѰ� ����.
//
//	������ ����ü�� ���, �ֺ� 0�� ������ �����Ѵ�.
//	�ظ��� 0�� ������ŭ ���ҽ�Ű�� 0���� �۾����� 0���� �����ϰ� ���� ������ �ִٸ� 0�� ++���ش�.
//	ũ�� ��, �湮ó��(�ٴٿ���)�� ������ �����Ѵ�.
//	��ȹ�˻翡�� visit�迭�� �� �ϳ� �ʿ��ϰ� �˻縶�� �ʱ�ȭ�� �ʿ��ϴ�.
//	�̶�, ����ü�� �� ȿ�����ϱ ����غ���.
//	����ü�� ������������� �ִ� 300*300 (90000)�� ��ȸ�ϸ� ������ ���, ���� �ױ����� Ȯ���ϰ� ���ҽ�Ų��.
//	�׷��� �̷��� �ϸ� 0�� �� ���, ���� ���꿡 ������ �ֱ⶧���� ����ü�� �����غ���
//	���� ����ü�� ����� ��쵵, �ﰢ���� 0�� ���� �� ++ �� �ƴ� ������ add�迭�� ��Ƶ״ٰ� ��������Ѵ�.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct Iceburg {
//	int y;
//	int x;
//	int o;
//	Iceburg(int Y = 0, int X = 0, int O = 0):y(Y),x(X),o(O){}
//};
//
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0) :y(Y), x(X){}
//};
//
//int map[300][300];
//int add[300][300]; // ��Ƽ� 0�� �� ���, ���� ���꿡 ������ �� �Ͻ� ���� ( �� ���� �ʱ�ȭ �ʿ� )
//bool isIceburg[300][300]; // ��ȹ Ȯ�ο��� �ʿ� ( �ʱ�ȭ �ʿ� ) 
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
//int N, M;
//int iceburgNum;
//Iceburg iceburg[10000];
//int answer;
//
//void input();
//void adjoinOcean();
//void melt(); // ����ü ����
//void addOcean();
//void devide(int y, int x); // ��ȹ Ȯ��
//void add_iceburg_init();
//
//int main()
//{
//	input();
//	adjoinOcean();
//	int years = 0;
//	bool isOver = false;
//	int curY, curX;
//
//	while (true)
//	{
//		int parts = 0;
//		for (int i = 0; i < iceburgNum; i++)
//		{
//			if (map[iceburg[i].y][iceburg[i].x] == 0 || isIceburg[iceburg[i].y][iceburg[i].x])
//				continue;
//			
//			devide(iceburg[i].y, iceburg[i].x);
//			parts++;
//			if (parts >= 2)
//			{
//				isOver = true;
//				answer = years;
//				break;
//			}
//		}
//		if (isOver)
//			break;
//		if (parts == 0)
//		{
//			answer = 0;
//			break;
//		}
//
//		melt();
//		addOcean();
//		add_iceburg_init();
//
//		years++;
//	}
//
//	cout << answer;
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
//	int temp;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> temp;
//			map[i][j] = temp;
//			if (temp != 0)
//			{
//				iceburg[iceburgNum].y = i;
//				iceburg[iceburgNum].x = j;
//				iceburgNum++;
//			}
//		}
//	}
//}
//
//void adjoinOcean()
//{
//	int ny, nx;
//	int curY, curX;
//	for (int i = 0; i < iceburgNum; i++)
//	{
//		curY = iceburg[i].y;
//		curX = iceburg[i].x;
//
//		for (int j = 0; j < 4; j++)
//		{
//			ny = curY + dir[j][0];
//			nx = curX + dir[j][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] != 0)
//				continue;
//			iceburg[i].o++;
//		}
//	}
//}
//
//void melt()
//{
//	int ny, nx;
//	int curY, curX;
//
//	for (int i = 0; i < iceburgNum; i++)
//	{
//		if (map[iceburg[i].y][iceburg[i].x] == 0)
//			continue;
//		curY = iceburg[i].y;
//		curX = iceburg[i].x;
//
//		map[curY][curX] -= iceburg[i].o;
//		if (map[curY][curX] <= 0)
//		{
//			map[curY][curX] = 0;
//			for (int j = 0; j < 4; j++)
//			{
//				ny = curY + dir[j][0];
//				nx = curX + dir[j][1];
//
//				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 0)
//					continue;
//				add[ny][nx]++;
//			}
//		}
//	}
//}
//
//void addOcean()
//{
//	int curY, curX;
//
//	for (int i = 0; i < iceburgNum; i++)
//	{
//		if (map[iceburg[i].y][iceburg[i].x] == 0)
//			continue;
//		curY = iceburg[i].y;
//		curX = iceburg[i].x;
//
//		iceburg[i].o += add[curY][curX];
//		add[curY][curX] = 0;
//	}
//}
//
//void devide(int y, int x)
//{
//	queue<pos> que;
//	que.push({ y,x });
//	isIceburg[y][x] = true;
//	
//	pos cur;
//	int curY, curX;
//	int ny, nx;
//
//	while (!que.empty())
//	{
//		cur = que.front();
//		que.pop();
//		curY = cur.y;
//		curX = cur.x;
//
//		for (int i = 0; i < 4; i++)
//		{
//			ny = curY + dir[i][0];
//			nx = curX + dir[i][1];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M || isIceburg[ny][nx] || map[ny][nx] == 0)
//				continue;
//			que.push({ ny,nx });
//			isIceburg[ny][nx] = true;
//		}
//	}
//
//}
//
//void add_iceburg_init()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			isIceburg[i][j] = false;
//			add[i][j] = 0;
//		}
//	}
//}
