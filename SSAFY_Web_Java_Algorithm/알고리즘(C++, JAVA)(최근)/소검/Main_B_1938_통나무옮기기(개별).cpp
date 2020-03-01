/* 1310~1420
	1. 2�� 128MB
	2. ȸ�� ���� : �߽��� ���� �ȹ� 1�� ������ �ȵ�
	3. �ּ� Ƚ���� BBB�� EEE�� �����ϰ� �ϱ�

	Ǯ�� : bfs�� �غ���
	�湮ó���� [][][����/����] �̷������� �ְ�
	�Է��Լ�,
	bfs�Լ�
	ȸ���Լ�
	���� ����� �ɵ��ϴ�. 
	�߽����� �������� �̵��Ѵ�.
	����, ȸ�������� ���μ����϶��� ũ�� ��������� �̵��� ��, ���� ������ �޸� ����Ѵ�.

*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct center {
	int y;
	int x;
	int d; // 0 ����, 1 ����
	center() {}
	center(int Y, int X, int D):y(Y),x(X),d(D){}
};
int N;
int answer;
center tree;
center dest;
char map[51][51];
bool v[51][51][2]; // 0 ����, 1 ����
int dir1[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; // ����
int dir2[4][2] = { {1,1},{-1,-1},{1,-1},{-1,1} }; // �밢��

void input();
void bfs(center treePos);
bool rotatable(center cur);
int main()
{
	input();
	bfs(tree);
	cout << answer;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string temp;
	int bCnt = 0;
	int by, bx, ey, ex;
	int eCnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = temp[j];
			if (temp[j] == 'B')
			{
				bCnt++;
				if (bCnt == 1)
				{
					by = i;
					bx = j;
				}
				else if (bCnt == 2)
				{
					if (by == i)
					{
						tree.y = i;
						tree.x = j;
						tree.d = 0;
					}
					else if (bx == j)
					{
						tree.y = i;
						tree.x = j;
						tree.d = 1;
					}
				}
			}
			else if (temp[j] == 'E')
			{
				eCnt++;
				if (eCnt == 1)
				{
					ey = i;
					ex = j;
				}
				else if (eCnt == 2)
				{
					if (ey == i)
					{
						dest.y = i;
						dest.x = j;
						dest.d = 0;
					}
					else if (ex == j)
					{
						dest.y = i;
						dest.x = j;
						dest.d = 1;
					}
				}
			}
		}
	}
}

void bfs(center treePos)
{
	center cur;
	int curY, curX, curD;
	int nx, ny;
	int cnt = 0;
	bool isFind = false;
	//
	queue<center> que;
	que.push(treePos);
	v[treePos.y][treePos.x][treePos.d] = true;

	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			cur = que.front();
			que.pop();

			curY = cur.y;
			curX = cur.x;
			curD = cur.d;

			if (curY == dest.y && curX == dest.x && curD == dest.d)
			{
				answer = cnt;
				isFind = true;
			}

			if (rotatable(cur)) // ȸ���� �����ϴٸ�
			{
				que.push({ curY, curX, !curD }); // ȸ����Ų �� Ǫ��(�̰͵� 1ȸ�� ó��)
				v[curY][curX][!curD] = true;
			}

			for (int i = 0; i < 4; i++)//�̵�
			{
				ny = curY + dir1[i][0];
				nx = curX + dir1[i][1];

				if (curD == 0) // ������ ��,
				{
					if (ny < 0 || ny >= N ||				// �߽�
						nx - 1 < 0 || nx + 1 >= N ||		// �翷
						map[ny][nx] == '1' || map[ny][nx - 1] == '1' || map[ny][nx + 1] == '1' || // ���� �浹
						v[ny][nx][curD])
					{
						continue;
					}
				}
				else // ������ ��,
				{
					if (nx < 0 || nx >= N ||				// �߽�
						ny - 1 < 0 || ny + 1 >= N ||		// �翷
						map[ny][nx] == '1' || map[ny - 1][nx] == '1' || map[ny + 1][nx] == '1' || // ���� �浹
						v[ny][nx][curD])
					{
						continue;
					}
				}

				que.push({ ny, nx, curD });
				v[ny][nx][curD] = true;
			}
		}
		if (isFind)
			break;
		cnt++;
	}
	if (!isFind)
		answer = 0;

}

bool rotatable(center cur)
{
	bool isRotatable = true;
	int ny, nx;
	int curY, curX;
	curY = cur.y;
	curX = cur.x;

	if (v[curY][curX][!cur.d]) // �̹� �غ��� �ִ� �׼�
		return false;


	for (int i = 0; i < 4; i++)
	{
		ny = curY + dir1[i][0];
		nx = curX + dir1[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '1')
		{
			return false;
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		ny = curY + dir2[i][0];
		nx = curX + dir2[i][1];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '1')
		{
			return false;
		}
	}

	return isRotatable;
}
