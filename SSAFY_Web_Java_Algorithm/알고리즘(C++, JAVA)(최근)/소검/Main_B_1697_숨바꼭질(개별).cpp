///* 1830~1945
//	1. �ȴ� ���, +1�� �ȴٸ� �Ѿ�� ��츦 ����ؾ߰����� -1�� �����ϱ� ������ ����Ÿ��� �����
//	��츦 ���ϸ� �ɵ��ϴ�.
//	2. �ȱ�� �����̵��� ���Ͽ� ����Ÿ��� ª�� ��츦 �����ϴ� ������� �����ϸ� �� �� ����.
//	-> ���ߴ�.
//	3. bfs�� �絵��
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//
//int sister;
//int bfs(int subin);
//int minVal = 99999999;
//bool visit[100001];
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int sb;
//
//	cin >> sb >> sister;
//
//	cout << bfs(sb);
//
//	return 0;
//}
//
//int bfs(int subin)
//{
//	queue<int> que;
//	que.push(subin);
//	int size;
//	int time = 0;
//	while (!que.empty())
//	{
//		size = que.size();
//		bool isOk = false;
//		while (size-- > 0)
//		{
//			int curX = que.front();
//			que.pop();
//			visit[curX] = true;
//
//			if (curX == sister)
//			{
//				isOk = true;
//				if (minVal > time)
//					minVal = time;
//			}
//			else if (curX > sister)
//			{
//				if (minVal > time + curX - sister)
//					minVal = time + curX - sister;
//			}
//
//			if (curX - 1 >= 0 && !visit[curX - 1])
//				que.push(curX - 1);
//			if (curX + 1 <= 100000 && !visit[curX + 1])
//				que.push(curX + 1);
//			if (curX * 2 <= 100000 && curX*2 != 0 && !visit[curX*2])
//				que.push(curX * 2);
//		}
//
//		if (isOk)
//			break;
//		time++;
//	}
//	return time;
//}
