/*1730~1750
	1. 2�� 256MB
	2. ����� ���� ��ֹ��� �پ���� �� �ִ�.
	3. �����̴� �ɷ��� �����ؼ� �� K���� ���� ���� ������ �� �ְ�,
	�� �ܿ��� �׳� ������ ĭ���θ� ������ �� �ִ�.
	�밢�� ������ ������ ĭ�� ���Ե��� �ʴ´�.
	4. �������� �� ���� ������ �����ؼ� �� ������ �Ʒ����� �����Ѵ�.
	5. ������ �� �������� �� �� �����̴� ��, ���� ���������� �� �� �����̴� ��,
	��� �� ���� �������� ģ��.
	6. ��� : �����̰� �ּ����� �������� ������������ ������������ �� �� �ִ� ���
	�ּ�Ƚ���� ����ض�

	Ǯ�� :
	���μ���ó��  ���ٱ� ���� ��, ������ �÷� �����ؼ� bfs�� �����ϸ� �� ���ϴ�.

*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct pos{
	int y;
	int x;
	int cnt;
};

int K, N, M;

int visit[200][200][31];
int map[200][200];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int horseDir[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{1,2},{2,1} };

void input();
int bfs(int y, int x);

int main()
{
	input();
	int answer = bfs(0, 0);
	cout << answer;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

int bfs(int y, int x)
{
	queue<pos> que;
	que.push({ y,x,0 });
	visit[y][x][0] = true;
	int curY, curX, ny, nx;
	int curCnt;
	int move = 0;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			pos cur = que.front();
			que.pop();
			curY = cur.y;
			curX = cur.x;
			curCnt = cur.cnt;
			if (curY == N - 1 && curX == M - 1)
			{
				return move;
			}
			if (curCnt < K)
			{
				for (int i = 0; i < 8; i++)
				{
					ny = curY + horseDir[i][0];
					nx = curX + horseDir[i][1];

					if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 1 || visit[ny][nx][curCnt+1])
						continue;
					que.push({ ny, nx, curCnt + 1 });
					visit[ny][nx][curCnt+1] = true;
				}
			}
			
			for (int i = 0; i < 4; i++)
			{
				ny = curY + dir[i][0];
				nx = curX + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == 1 || visit[ny][nx][curCnt])
					continue;
				que.push({ ny, nx, curCnt});
				visit[ny][nx][curCnt] = true;
			}
		}
		move++;
	}

	return -1;
}
