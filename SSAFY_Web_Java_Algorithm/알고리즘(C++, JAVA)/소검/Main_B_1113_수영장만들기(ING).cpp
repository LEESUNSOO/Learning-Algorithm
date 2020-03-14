/*1510~
	1. 2�� 128MB
	2. 1<= N,M <= 50 => 1�϶� 0
	3. ���̴� 1<= <=9
	4. �¿���Ϸ� ���� ���� �ָ� ã�´� (�������� �������� ������ �߰ߵǸ� �극��ũ)
	5. �� ���� ���� �¿���� �� �ּҰ��� ���簪�� ���� ���Ѵ�.
	6. DP�� ������� �ʰ� ����Ѵ� �������� ��,
	�־��� ���, 50*50 �� ��,
	�����ڸ��� 2�̰� ���ΰ� 1�� ��,
	50*50[��ȸ]*(50+50)[�¿���� ��ȸ]

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct pos {
	int y;
	int x;
	pos(int Y = 0,int X = 0):y(Y),x(X){}
};

int N, M;
int map[50][50];
int dp[50][50][4]; // ����� ���� �ִ밪(����)�� ���� //���� 0 �϶�, ��ȸ // 0�� �ƴ� ��,����
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // ��, ��, ��, ��
int parent[50][50][2];
int visit[50][50];
int hole[50][50];
// 50*50*8 = 400*50 = 20000*4byte = 80000byte�� ������ �� �ϴ�.
int total;
vector<int> mVec;

void input();
int heightCheck(int y, int x);
void holeCheck(int y, int x);
void visitInit();
int main()
{
	input();

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (hole[i][j])
				continue;
			holeCheck(i, j);
		}
	}


	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (hole[i][j])
				continue;
			total += heightCheck(i, j);
		}
	}

	cout << total;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				parent[i][j][k] = -1;
			}
		}
	}
}

int heightCheck(int y, int x)
{
	int depth = 0;
	int d[4];
	int curY, curX, curH;
	int idxY, idxX;
	curH = map[y][x];
	int maxH;

	for (int i = 0; i < 4; i++)
	{
		curY = idxY = y;
		curX = idxX = x;
maxH = curH;
if (dp[y][x][i] != -1)
{
	d[i] = dp[y][x][i];
}
else
{
	do {
		if (map[curY][curX] >= maxH) // �����ϴ��� ������ ã��, ������ ���� �����, ������ 0ó��������
		{
			maxH = map[curY][curX];
			idxY = curY;
			idxX = curX;
		}
		curY += dir[i][0];
		curX += dir[i][1];
	} while (curY >= 0 && curX >= 0 && curY < N && curX < M);

	if (idxY == y && idxX == x) // ����� �ϳ��� ������ ������ ���ٸ�,
		return 0;

	switch (i)
	{
	case 0: // ��
		for (int Y = y; Y > idxY; Y--)
		{
			dp[Y][x][i] = maxH;
		}
		break;
	case 1: // ��
		for (int Y = y; Y < idxY; Y++)
		{
			dp[Y][x][i] = maxH;
		}
		break; // ��
	case 2:
		for (int X = x; X > idxX; X--)
		{
			dp[y][X][i] = maxH;
		}
		break;
	case 3:
		for (int X = x; X < idxX; X++)
		{
			dp[y][X][i] = maxH;
		}
		break;
	}

	d[i] = dp[y][x][i];
}
	}

	mVec.clear();

	for (int i = 0; i < 4; i++)
	{
		mVec.push_back(d[i]);
	}

	depth = *min_element(mVec.begin(), mVec.end()) - curH;

	if (depth < 0)
		return 0;
	else
		return depth;
}

void holeCheck(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	visit[y][x] = true;
	int curY, curX, ny, nx;
	int curH;
	bool hasHole = false;
	while (!que.empty())
	{
		pos cur = que.front();
		que.pop();
		curY = cur.y;
		curX = cur.x;
		curH = map[curY][curX];

		for (int i = 0; i < 4; i++)
		{
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (map[curY][curX] < map[ny][nx]) // ������
				continue;

			if (ny <= 0 || nx <= 0 || ny >= N - 1 || nx >= M - 1)
			{
				parent[ny][nx][0] = curY;
				parent[ny][nx][1] = curX;
				hasHole = true;
				break;
			}
			else if (hole[ny][nx])
			{
				hasHole = true;
				ny = y;
				nx = x;
				break;
			}
			if (visit[ny][nx])
				continue;



			que.push({ ny,nx });
			parent[ny][nx][0] = curY;
			parent[ny][nx][1] = curX;
			visit[ny][nx] = true;
		}
		if (hasHole)
			break;
	}

	if (hasHole)
	{
		hole[ny][nx] = true;
		int py, px;
		py = parent[ny][nx][0];
		px = parent[ny][nx][1];
		while (!(py == -1 && px == -1))
		{
			hole[py][px] = true;
			ny = py;
			nx = px;
			py = parent[ny][nx][0];
			px = parent[ny][nx][1];
		}
	}

	visitInit();

}

void visitInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = false;
		}
	}
}

/*
1630~
�ݷ� ������
5 7
6666666
6616166
6111116
6616166
6666166

����üũ�� �ؾ��ϴµ�
bfs�� �����鼭 �θ� ��带 ����� ������ ���� ��,
�θ�鿡�� ���� ������ �ִ� ������ ǥ�����ش�.

���������� �ƴ� �ֵ��� bfs�� �����ϰ� �Ǵµ� 
�̶�, ���������� ������ �ֵ鵵 ���� ������ �ִ°ɷ� ó���Ѵ�.
�׷� 
6666666
6616166
6211116
6616166
6666166
�̷� ���, (2,1)�� 2�� ��쿡�� (1,2)�� bfs���� �ش���� �ʾ����� ������ bfs�� �����ϸ鼭
(2,2)�� ���� hole�� ������ �� �� �ִ�.

����, hole�� ���� ������ ���� üũ�� �ϸ�
5 7
6666666
6616166
6211516
6611166
6666166
�̿� ���� ��� (1,4)�� (2,5)���� ���� ä������.

�����پ˾����� ���ο� �ݷ� �߰� ~1715
5 5
16666
63636
66146
13236
66666

out = 14
ans = 6

*/