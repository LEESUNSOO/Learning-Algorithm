/* 1615~1715 + 2120~2230 = 1H + 1H 10M
	1. 2��, 256MB
	2. �ټ��̰� 7���� �ٷ��� �ϴµ� �׻� �ټ��� > �����İ� �����ؾ��Ѵ�.
	3. ��� ����� ���� ���ض� �ε�

	Ǯ�� :
	bfs�� dfs�� ��� ���� ���������� ���� Ǯ�̹��
	dfs�� �� ��� ���� �� ����� ������ �ϳ��ϳ� ����������ϴµ� ��Ʈ�ι̳�� �̿��� ������
	4������ �����ߴ�. ������ �̰Ŵ�.. 12+8+4 = �� 24���� ����������ϴµ� �ڵ��� �ǹ̰� �ֳ��𸣰ڴ�.
	bfs�� �� ���, �翷���� ���� ��츦 �Ѱ��� �������ڴ� �ٸ� �������� ����ص� ���� ������ ���ö��� �־ �����ߴ�.

	����, 25�� �����̴� ������ ����
	
	�̶�, np�� ����ϰ� �Ǹ� ��Ʈ��ŷ�� �ȵȴ�. �Ϻΰ��������� 
	dfs���� ȿ���� ��������.
	���� ���, np�� ��쿡�� ����üũ�� �ϱ��� �ټس׶� �����׼��� ���� ���� ������ ��Ʈ��ŷ�� �� �ִ�.
	������ ���ʿ� 1234xxx��� ���ڰ� ���� ��, 1234���� ������ ���� 4�� �������ʹ� 1234xxx�� �� ���ϸ� �Ǵµ�
	np�� �װ� �Ұ����ϴ�. �׷��� dfs�� ���� �ȵǴ� ��찡 ���� �� �� �ڿ� �� �͵鵵 �ϴ� ���������µ� �־
	���귮�� Ȯ�پ� 25C7�ӿ��� �ұ��ϰ� �����ϴ�.

	�׷��⶧���� dfs�� �������� üũ�� �ϸ� ���������� 3���� �Ѿ�� �����ְ�
	�������������� visit�� üũ���ش�. 
	���� 7�� ���������� visit�� �ֵ��� bfs�� ���� �����ߴ��� Ȯ�����ְ�
	���� �÷��ش�.


*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;
struct pos {
	int y;
	int x;
	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
};

char map[5][5];
int visit[5][5];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int answer;
void input();
void dfs(int n, int numS, int numY);
bool adjoin();
bool bfs(int y, int x);
int main()
{
	input();

	dfs(0, 0, 0);

	cout << answer;

	return 0;
}

void input()
{
	string temp;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = temp[j];
		}
	}
}

void dfs(int n, int numS, int numY)
{
	if (numY > 3)
		return;
	if (numY + numS > 7)
		return;
	else if (numY + numS == 7)
	{
		if (adjoin())
		{
			answer++;
		}
		return;
	}

	int y;
	int x;

	for (int i = n; i < 25; i++) // 0�� �ƴ� n�� �ߺ��� �������� ���
	{
		y = i / 5;
		x = i % 5;
		if (visit[y][x])
			continue;
		visit[y][x] = true;
		if (map[y][x] == 'S')
			dfs(i, numS + 1, numY);
		else
			dfs(i, numS, numY + 1);
		visit[y][x] = false;
	}
}

bool adjoin()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (visit[i][j])
			{
				return bfs(i, j);
			}
		}
	}

	return false;
}

bool bfs(int y, int x)
{
	bool team[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			team[i][j] = false;
		}
	}

	queue<pos> que;
	que.push({ y,x });
	team[y][x] = true;
	pos cur;
	int curY, curX;
	int ny, nx;
	int cnt = 0;
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		curY = cur.y;
		curX = cur.x;
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || team[ny][nx] || !visit[ny][nx])
				continue;
			que.push({ ny,nx });
			team[ny][nx] = true;
		}
	}

	if (cnt == 7)
		return true;
	else
		return false;
}

