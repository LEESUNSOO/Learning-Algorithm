/* 2250~
	1. 2�� 256MB
	2. ������ �� ū ���� ���� �������� �̵��� �ϴµ�,
	�ִ� �̵� Ƚ��(�� ��)�� ���ϴ� ������.
	1) ������ �ִ��� ���̰� ���� �������� �̵��� ���ϱ�?
	-> �̰� �ƴϴ�. �ݷʰ� �����.
	
	2) �׷� ������ ������ �� ���캼��?
	-> ���������� �ð����⵵�� ����غ���
	-> ��� ���� Ž��, �ִ밪 500*500
	-> �� �������� Ž�� �ּ� 1, �ִ� 500*500
	-> 500*500 + 500*499 + 500*498 + ... + 500*1 => 500 * ( (500*501) / 2 ) �� n^3
	-> 125000000 �ָ��ϴ� �Ƹ� �޸𸮿������� �����Ŵ�
	
	3) DP ����. ���� �̷� ��, DP��
	�׷���, �������� ���� DP�� ������ ���ΰ�?
	�׷��� �Ѵٸ� ���������� ���� ��ȸ�ؾ��� �Ű� 500*500 Ž���� ��� �ؾ��Ѵ�.
	���� ��ť�� ���� ���
	=> �ᱹ �� ������ ��ȸ�ϵ�, dp���� ���Ͽ� ��Ʈ��ŷ���ִ� ������� ������
	=> �̷� ����, ���귮�� ���� �� �ְ�, ���������� ���� dp���� Ȯ���Ͽ� �ִ밪�� ��
*/
#include <iostream>
#include <string>
#include <queue> // bfs�� �ʿ�
#include <algorithm>

using namespace std;

int N;//�� ũ��
int map[500][500]; // 0~ ����
bool visit[500][500];
int dp[500][500];
int sy, sx;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void input();
void search();
int dfs(int y, int x, int dep);
int maxSearch();

int main()
{
	input();
	search();
	cout << maxSearch();

	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void search()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] > 0)
				continue;
			dp[i][j] = dfs(i, j, 1);
		}
	}
}

int dfs(int y, int x, int dep)
{
	bool isFind = false;
	int ny, nx;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dir[i][0];
		nx = x + dir[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] <= map[y][x])
			continue;
		isFind = true;
		if (dp[ny][nx] == 0)
		{
			int nextDep = dfs(ny, nx, dep);
			if(dp[y][x] < dep + nextDep)
				dp[y][x] = dep + dfs(ny, nx, dep);
		}
		else
		{
			if(dp[y][x] < dep + dp[ny][nx])
				dp[y][x] = dep + dp[ny][nx];
		}
	}

	if (isFind)
		return dp[y][x];
	else
		return dp[y][x] = dep;
}

int maxSearch()
{
	int maxVal = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dp[i][j] > maxVal)
				maxVal = dp[i][j];
		}
	}

	return maxVal;
}


