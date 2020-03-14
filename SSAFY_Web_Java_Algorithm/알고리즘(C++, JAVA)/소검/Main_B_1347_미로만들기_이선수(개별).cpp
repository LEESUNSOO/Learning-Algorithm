/* 0125~0145
	1. 2�� 128MB
	2. ��F���� ������ �� ĭ ������ ���̰�,
	��L'�� ��R'�� ������ ���� �Ǵ� ���������� ��ȯ�� ���̴�.
	��, 90���� ȸ���ϸ鼭, ��ġ�� �״���� ���̴�.

	Ǯ�� :
	�������� �� �� ������ �˳��� ���� �߾ӿ� ���� ������ �Ѵ�.
	���� �̵���δ� �湮ó���� ���ְ�,
	�湮ó�� �� ������ �ּ��ִ� y,x���� �ľ����ش�.
	����, ���������� false�� # true�� . �� ������ش�.

	�ִ� ������ 50���� ������ �� 101?�̸� �ǰ�����,
	�����ϰ�~ 120���� �ش�.


*/
#include <iostream>
#include <string>

using namespace std;
struct pos {
	int y;
	int x;
};

int map[120][120];
bool visit[120][120];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
string cmd;
int N;
void dfs(int y, int x, int d, int cmdNum);
int main()
{
	cin >> N;
	cin >> cmd;

	dfs(60, 60, 2, 0);

	int minY, minX, maxY, maxX;
	maxY = maxX = 0;
	minY = minX = 500;

	for (int i = 0; i < 120; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			if (visit[i][j])
			{
				if (minY > i)
					minY = i;

				if (minX > j)
					minX = j;

				if (maxY < i)
					maxY = i;

				if (maxX < j)
					maxX = j;
			}
		}
	}

	for (int i = minY; i <= maxY; i++)
	{
		for (int j = minX; j <= maxX; j++)
		{
			if (visit[i][j])
				cout << '.';
			else
				cout << '#';
		}
		cout << endl;
	}

	return 0;
}

void dfs(int y, int x, int d, int cmdNum)
{
	visit[y][x] = true;
	if (cmdNum == N)
	{
		return;
	}
	switch (cmd[cmdNum])
	{
	case 'L':
		dfs(y, x, (d + 3) % 4, cmdNum + 1);
		break;
	case 'R':
		dfs(y, x, (d + 1) % 4, cmdNum + 1);
		break;
	case 'F':
		int ny, nx;
		ny = y + dir[d][0];
		nx = x + dir[d][1];
		dfs(ny, nx, (d), cmdNum + 1);
		break;
	}
}
