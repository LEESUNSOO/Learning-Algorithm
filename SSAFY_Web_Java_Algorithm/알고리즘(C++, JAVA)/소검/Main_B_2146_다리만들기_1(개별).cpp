/* 2255~2330 = 35M
	1. 2�� 192MB
	2. ���� ������ �ƴϴ� �ΰ� �̻��̴�.
	3. �ٸ��� ������ �ƴϴ� ���ڵ� �ȴ� -> ������ ������ ª�� �������ߴµ� �ݷʰ� �ִ�.
	 ex )
	 1 1 0 0 0 0 0 1 => ������ ���� ��, ������ �ƴ� ���� 3�̶� �»� - �� �� �ٸ��� �ִµ�
	 1 1 0 0 0 0 0 1	������ �ϴ� ���� ���� 5 (�»�-���) ���� ���ð��̴�.
	 0 0 0 0 0 0 0 0
	 0 0 0 0 0 0 0 0
	 0 0 1 1 0 0 0 0
	
	Ǯ�� :
	1) ������ 1,2,... n ���� ������.
	2) ������ �������� �ѹ��� ���� bfs�� ���� �ִ� �ٸ� �ѹ��� ���� ���� �������� �� ���� vector�� ��´�
	3) vector�� �ּҰ��� ����Ѵ�.
	4) �ƽ��� �κ��� 1-2�� ����ϰ� 2-1�� ����� ���̴�. �ϴ� ������ ������ �˻縦 ���� �ʾƵ� ������
	�ð��ʰ��� ���ٸ� �� �κ��� �����ϴ°ŵ� ����ϵ� �ϴ�.
	�ð����⵵?
	��.. ���������� 100*100
				+
	������ �ּҰŸ� ã�� �ִ� 100
	5) DP�� Ȱ���Ͽ� �ּҰŸ��� ������Ʈ�ϴ� �� �����غ�����, ���� 2�� �ʰ��� ��, �ָ�������
	������ �����͸� ������ �������ϸ� ���� �ٲ��ִ°� ��ȿ������ �� ����.

*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int y;
	int x;
	pos(int Y = 0, int X = 0):y(Y), x(X) {}
};
int N;
int numbering = 1;
int map[100][100];
bool devideV[100][100]; 
bool minDisV[100][100];
vector<int> disV;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int startNum;

void input();
void devide(int y, int x); // ���������� ���� numbering ������ �������� ��
void minDis(int y, int x);
void visitInit();

int main()
{
	input();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (devideV[i][j])
				continue;
			if (map[i][j] == 1)
			{
				devide(i, j);
				numbering++;
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (minDisV[i][j])
				continue;
			if (map[i][j] != 0)
			{
				startNum = map[i][j];
				minDis(i, j);
				visitInit();
			}
		}
	}
	
	cout << *min_element(disV.begin(), disV.end());


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

void devide(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	devideV[y][x] = true;
	map[y][x] = numbering;
	
	pos cur;
	int curY, curX;
	int ny, nx;
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		curY = cur.y;
		curX = cur.x;

		for (int i = 0; i < 4; i++)
		{
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || devideV[ny][nx] || map[ny][nx] != 1)
				continue;
			que.push({ ny,nx });
			devideV[ny][nx] = true;
			map[ny][nx] = numbering;
		}
	}
}

void minDis(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	minDisV[y][x] = true;

	pos cur;
	int curY, curX;
	int ny, nx;

	int dis = 0;
	bool isFind = false;

	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			cur = que.front();
			que.pop();
			curY = cur.y;
			curX = cur.x;

			if (map[curY][curX] != 0 && map[curY][curX] != startNum)
			{
				disV.push_back(dis-1);
				isFind = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				ny = curY + dir[i][0];
				nx = curX + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N || minDisV[ny][nx] || map[ny][nx] == startNum)
					continue;

				que.push({ ny,nx });
				minDisV[ny][nx] = true;

			}
		}
		if (isFind)
			break;
		dis++;

	}
}

void visitInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			minDisV[i][j] = false;
		}
	}
}
