///* 2250~2350 + 0100~0150 = 1H 50M
//	1. ��, �� �������θ� ��ȸ�ϸ� 0,0 ���� N-1,M-1�� �����ϴ� ��ο� �ִ�
//	���ĺ����� ���� �̸��� ���ϴµ�,
//	���������� ���� �ָ� ����ϴ� �Ŵ�.
//	2. ���� ������ �۾Ҵٸ� ��� ��츦 ��Ƽ� ���Ľ������� �ǰ�����
//	������ �ִ� 2000�̴�. 
//	3. ������ �� ��� �ۿ� ������, �� ���� ���ĺ��� ���� �������� �̵��� �ϴ� ������ §�ٸ�,
//	���� 1) ���� ���, ������ a�� ������ �� ���ĺ��� �����ϴ�.
//	bfs�� Ȱ���ϴµ�, ���ӵ� string���� �������� �����ϴ� �ּ�����
//	����Ѵ�.
//	�׸��� �տ��� ���� ������ ���� ���� ��츸 ����� �����ϴ� ������� �غ��� ��� �ʹ�.
//	����, ���� ��ġ string�� ���� ��ġ�� ���� ��쵵 ���ܽ�Ų��.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct name {
//	int y;
//	int x;
//};
//
//int N, M;
//char map[2000][2000];
//bool visit[2000][2000];
//int dir[2][2] = { {0,1},{1,0} };
//string answer;
//
//void input();
//string bfs();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		answer = "";
//		string str(1, map[0][0]);
//		answer += str;
//		bfs();
//		cout <<"#"<< t <<" "<< answer << endl;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				visit[i][j] = false;
//			}
//		}
//	}
//
//
//	return 0;
//}
//
//void input()
//{
//	cin >> N >> M;
//
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//}
//
//string bfs()
//{
//	queue<name> que;
//	que.push({ 0,0 });
//	visit[0][0] = true;
//	int curY, curX;
//	int ny, nx;
//	char nextChar;
//	while (!que.empty())
//	{
//		int size = que.size();
//		queue<name> que2;
//		char minWord = '}';
//		while (size-- > 0)
//		{
//			name cur = que.front();
//			que.pop();
//			curY = cur.y;
//			curX = cur.x;
//
//			if (curY == N - 1 && curX == M - 1)
//				return answer;
//
//			for (int i = 0; i < 2; i++)
//			{
//				ny = curY + dir[i][0];
//				nx = curX + dir[i][1];
//				if (ny >= N || nx >= M || visit[ny][nx])
//					continue;
//				nextChar = map[ny][nx];
//				if (minWord > nextChar)
//				{
//					while (!que2.empty())
//						que2.pop();
//					que2.push({ ny,nx });
//					minWord = nextChar;
//				}
//				else if (minWord == nextChar)
//				{
//					que2.push({ ny,nx });
//				}
//				visit[ny][nx] = true;
//			}
//		}
//		answer += minWord;
//		que = que2;
//	}
//
//	return answer;
//}
