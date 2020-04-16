#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999
int V, E;
int start;
int dis[20001]; // 1���� 1~20000������ �Ÿ��� ������ �迭
vector<pair<int, int>> graph[20001];
void input();
void disInit();
void dijkstra(int startIdx);

int main()
{
	input();
	disInit(); // ��� �Ÿ��� �ִ�ġ�� ���� (�ּҰ��� ���� �� �ֵ���)
	dijkstra(start);
	for (int v = 1; v <= V; v++)
	{
		if (dis[v] == INF)
			cout << "INF" << endl;
		else
			cout << dis[v] << endl;
	}
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start;
	int from, to, w;

	for (int e = 0; e < E; e++) // �ּұ��� ������ �����ϵ��� ����
	{
		cin >> from >> to >> w;
		if(graph[from].size() == 0)
			graph[from].push_back({ to, w });
		else
		{
			bool isCollet = false;
			for (int i = 0; i < graph[from].size(); i++)
			{
				if (graph[from][i].first == to)
				{
					if (graph[from][i].second > w)
						graph[from][i].second = w;
					isCollet = true;
				}
			}
			if(!isCollet)
				graph[from].push_back({ to, w });
		}	
	}
	
}

void disInit()
{
	for (int i = 1; i <= V; i++)
	{
		dis[i] = INF;
	}
}

void dijkstra(int startIdx)
{
	int nextDis;
	int nextVer;
	dis[startIdx] = 0; // �����δϱ� 0
	priority_queue<pair<int, int>> pq; // �ּ� �Ÿ� ������ ���� ���� ���� pq Ȱ��
	pq.push({ -0, startIdx }); // 0�� ����� ������, pq�� greater�� �ٲٴ��� �������� Ȱ���ϴ����ؼ� �ּҰ��� ��ܿ� ��ġ�ϵ��� ����

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();
		int weight = cur.first * -1;
		int curVertex = cur.second; // ������ ���ȭ
		if (dis[curVertex] < weight)
			continue;
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			if (curVertex == graph[curVertex][i].first) // �ٽ� ���ƿ��� ���,
				continue;
			nextVer = graph[curVertex][i].first;
			nextDis = graph[curVertex][i].second + weight;

			if (dis[nextVer] > nextDis)
			{
				dis[nextVer] = nextDis;
				pq.push({ nextDis*-1 , nextVer});
			}
		}
	}
}
