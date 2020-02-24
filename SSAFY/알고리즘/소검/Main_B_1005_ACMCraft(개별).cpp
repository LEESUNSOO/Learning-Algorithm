///*2045~2230
//	1. 1�� 512MB
//	2. ù ��° ���Ӱ� �� ��° ������ �ǹ��� ���� ������ �ٸ� ���� �ִ�
//
//	Ǯ�� :
//	���� ��忡�� ������ ���� �����ϸ� �ִ밪�� �������� ������ �����ָ�
//	�湮ó���� ������. ���������� que�� ���� ��尡 ��������
//	ù �ǹ��� �����Ǹ� ������.
//	-> ���ٽ��� �̸� ���� �ذ�� ������ �ƴϿ���.. ����^^
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int T;
//int N, K, D;
//int W;
//vector<int> graph[1001];
//int delay[1001] = { -1, };
//int dp[1001] = { -1, };
//vector<long> answer;
//void input();
//void build(int w);
//void reset(); // visit, graph, time �ʱ�ȭ (delay�� ���� ���ص� �� ��)
//int main()
//{
//	cin >> T;
//	for (int t = 0; t < T; t++)
//	{
//		input();
//		build(W);
//		cout << *max_element(answer.begin(), answer.end()) << endl;
//		reset();
//	}
//
//
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> K;
//	for (int n = 1; n <= N; n++)
//		cin >> delay[n];
//	int from, to;
//	for (int k = 0; k < K; k++)
//	{
//		cin >> to >> from;
//		graph[from].push_back(to); // 1 2 �� ��, �׷���[2]�� 1�� �־����. �� �ǹ̴� �׷���[2]�� ��� 1���� �����ž� �Ǽ� �� �� �ִ��� �ǹ�
//	}
//	cin >> W; // ���� �ǹ�
//	for (int i = 1; i <= N; i++)
//		dp[i] = -1;
//
//}
//
//void build(int w)
//{
//	queue<pair<int, int>> que;
//	que.push({ delay[w], w });
//	int cur;
//	int t;
//	int next;
//	int nextTime;
//	while (!que.empty())
//	{
//		pair<int, int> curInfo = que.front();
//		que.pop();
//		cur = curInfo.second;
//		t = curInfo.first;
//
//		if (graph[cur].size() == 0)
//		{
//			answer.push_back(t);
//		}
//		for (int i = 0; i < graph[cur].size(); i++)
//		{
//			next = graph[cur][i];
//			nextTime = delay[next] + t;
//
//			if (dp[next] < nextTime)
//			{
//				dp[next] = nextTime;
//				que.push({ nextTime, next });
//			}
//			
//		}
//	}
//}
//
//void reset()
//{
//	for (int i = 1; i <= N; i++)
//	{
//		dp[i] = -1;
//		delay[i] = -1;
//		graph[i].clear();
//		answer.clear();
//	}
//}
//
///*
//�ݷ� �����ϱ�
//< �������� �ϳ��� �ǹ��� ����µ� �ʿ������� ���>
//1
//4 3
//10 10 30 20
//2 1
//3 1
//4 1
//1
//
//< �����̰� 0�� ��� >
//1
//2 1
//0 0
//2 1
//1
//
//=> dp�� �ʱⰪ�� -1�� ���������� ������ 0�̶�� ���� que�� ���Ե��� �ʾ� answer vector�� empty�� ���°� �ǰ�, max_elements �Լ����� ������.
//
//*/