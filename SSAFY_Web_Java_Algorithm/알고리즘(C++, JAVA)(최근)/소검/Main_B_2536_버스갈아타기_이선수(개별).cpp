/* 0300~0405
	1. 1�� 256MB
	2. xy �ݴ���
	3. (1 �� m,n �� 100,000)
	4. ������ �� k (1 �� k �� 5,000)
	5. ��� �Է¿� ���Ͽ�, ������� �������� �ٸ��� �־����� ��������� ��������
		���� ����� �� ���� �̻� �����Ѵ�.

	Ǯ�� :
	�ϴ� ���� ��ġ���� Ż �� �ִ� ������ üũ�ϰ�
	�̵� �߿� ������ ���� üũ�ϰ� 
	�̷������δ� ���� ���� �� ����.

	�ϴ� �ּ� ȯ�� Ƚ���ϱ� bfs�� ������ �غ���.
	��ĭ�� �̵��Ѵ�ġ�� �ִ� 100����̴�. �̰� �ƴϴ�.

	ȯ�� Ƚ���� �� �����̴�, �Ÿ��� ũ�� ����� ����.
	�׷��ٸ�, �������� �������踦 �ľ��ϰ�,
	���ͽ�Ʈ��� �����غ��°� ���?

	�׷��� Ȯ���غ��� �������踸 graph���·� ��Ÿ���� bfs�� �ص� �ݹ� ���� ���´�.

	������, �������� ������ �������� ǥ���ϴ� ���̳Ĵ�. 
	�ִ� 5000���� ���� ��� �� ������,
	5,000*5,000 �� 25,000,000 �̰�,
	����, bfs�� �Ѵ��ؼ� �ִ� ������ 5000���̴ϱ�, 1�ʾȿ� ���� ������?
	�ٵ� �׷����� ��Ž�������� �߰� ������ �׹��� �̷����� 1����̴�.
	������, ������ 5����� �� ��, 
	1 �� - 2,3,4,5 �� �˻縦 �ϸ�
	2 ���� 3,4,5�ϰ� �˻縦 �ϸ� �ȴ�.
	���� N*N���ٴ� ���� (N*N)/2�� �ǰ� �� 12,500,000 �����̱� ������ ������ �� ����.
	�ѹ� �غ���



*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
struct pos {
	int x;
	int y;
};
struct Bus {
	int x1;
	int y1;
	int x2;
	int y2;
};
int N, M;
int B;
queue<int> que;
Bus bus[5001];
bool visit[5001];
vector<int> graph[5001];
vector<int> endV;
pos startP;
pos endP;
void input();
void adjCheck(int idx);
int bfs();
int main()
{
	input();

	for (int i = 1; i <= B; i++)
	{
		adjCheck(i);
	}

	cout << bfs();

	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	cin >> B;
	int num, x1, y1, x2, y2;
	for (int i = 1; i <= B; i++)
	{
		cin >> num >> x1 >> y1 >> x2 >> y2;

		if (x1 == x2)
		{
			if (y1 < y2)
			{
				bus[num].x1 = x1;
				bus[num].y1 = y1;
				bus[num].x2 = x2;
				bus[num].y2 = y2;
			}
			else
			{
				bus[num].x1 = x1;
				bus[num].y1 = y2;
				bus[num].x2 = x2;
				bus[num].y2 = y1;
			}
		}
		else
		{
			if (x1 < x2)
			{
				bus[num].x1 = x1;
				bus[num].y1 = y1;
				bus[num].x2 = x2;
				bus[num].y2 = y2;
			}
			else
			{
				bus[num].x1 = x2;
				bus[num].y1 = y1;
				bus[num].x2 = x1;
				bus[num].y2 = y2;
			}
		}
	}

	cin >> startP.x;
	cin >> startP.y;
	cin >> endP.x;
	cin >> endP.y;
}

void adjCheck(int idx)
{
	int x1, y1, x2, y2;
	x1 = bus[idx].x1;
	y1 = bus[idx].y1;
	x2 = bus[idx].x2;
	y2 = bus[idx].y2;

	if (x1 <= startP.x && startP.x <= x2 && y1 <= startP.y && startP.y <= y2)
	{
		que.push(idx);
		visit[idx] = true;
	}

	if (x1 <= endP.x && endP.x <= x2 && y1 <= endP.y && endP.y <= y2)
	{
		endV.push_back(idx);
	}

	int nx1, ny1, nx2, ny2;
	for (int i = idx + 1; i <= B; i++)
	{
		nx1 = bus[i].x1;
		ny1 = bus[i].y1;
		nx2 = bus[i].x2;
		ny2 = bus[i].y2;

		if ((x1 <= nx1 && nx1 <= x2 && ny1 <= y1 && y1 <= ny2) || (nx1 <= x1 && x1 <= nx2 && y1 <= ny1 && ny1 <= y2))
		{
			graph[idx].push_back(i);
			graph[i].push_back(idx);
		}
	}
}

int bfs()
{
	int dis = 1;
	int cur;
	int next;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			cur = que.front();
			que.pop();

			for (int i = 0; i < endV.size(); i++)
			{
				if (cur == endV[i])
				{
					return dis;
				}
			}
			for (int i = 0; i < graph[cur].size(); i++)
			{
				if (visit[graph[cur][i]])
					continue;
				que.push(graph[cur][i]);
				visit[graph[cur][i]] = true;
			}
		}
		dis++;

	}


	return dis;
}
