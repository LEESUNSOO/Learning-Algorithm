	1. 2�� 128MB
	2. ������ ȸ�� +1, +3 ���� ������ȯ�ϴ� ����
	3. M, N <= 100 // ������ 1,1
	���� ���� : ������ ������ 1, ������ 2, ������ 3, ������ 4�� �־�����.

	Ǯ�� : bfs�� ���� ���
	�̵��� ������ 3->2->1> ������
	������ �̵������� �������� ȸ���ϴ� ��츦 �� �������°ɷ�
	������ ���ڴ�� ���ϰ� �������ش�.
	������ ������ ���� �̵� + 1
	ȸ�� �̵��� ���, �̵� + 2
	�湮ó���� ��.. ���ְ� ��������� �������� ��������
	�湮ó���� �����ָ� 3 + 1 �̵��� 2 + 2 �� �ι� �����ϰ� �ȴ�
	���� ������ ó���� �����ָ� + 3 -> -3 -> +3 �� �ݺ��� �� �ִ�.

	=> ���� ù ��ȹ�� �׻� Ʋ���±� ����


*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
	int y;
	int x;
	int d;
	pos(int _y = 0, int _x = 0, int _d = 0) :y(_y), x(_x), d(_d) {}
};

int M, N;
int map[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // �� �� �� �� 
bool r[101][101][4]; // ���ڸ� ȸ�� üũ
pos robot;
pos dest;
int minVal = 999999999;
void input();
int changeDir(int d);
void bfs(int y, int x, int d);
int main()
{
	input();
	bfs(robot.y, robot.x, robot.d);
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	int y, x, d;
	cin >> y >> x >> d;
	robot.y = y;
	robot.x = x;
	robot.d = changeDir(d);

	cin >> y >> x >> d;
	dest.y = y;
	dest.x = x;
	dest.d = changeDir(d);
}

int changeDir(int d)
{
	int dir = 0;
	switch (d)
	{
	case 1:
		dir = 0;
		break;
	case 2:
		dir = 2;
		break;
	case 3:
		dir = 1;
		break;
	case 4:
		dir = 3;
		break;
	}
	return dir;
}

void bfs(int y, int x, int d)
{
	queue<pos> que;
	que.push({ y,x,d });
	bool isFind = false;
	int curCnt;
	pos cur;
	int curY, curX, curD;
	int ny, nx;
	int cnt = 0;
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

			r[curY][curX][curD] = true;
			if (curY == dest.y && curX == dest.x && curD == dest.d)
			{
				cout << cnt;
				isFind = true;
				break;
			}
			
			for (int j = 1; j <= 3; j++) // �Ÿ��� ���ִ���, ���� �ʰ����� Ȯ��
			{
				ny = curY + dir[curD][0]*j; // ����������� ����
				nx = curX + dir[curD][1]*j;

				if (r[ny][nx][curD])
					continue;
				if (ny < 1 || nx < 1 || ny > M || nx > N || map[ny][nx] == 1 ) // ���� �ʰ�, �� 
				{
					break;
				}
				else
				{
					que.push({ ny,nx,curD });
					r[ny][nx][curD] = true;
				}
			}

			if (!r[curY][curX][(curD + 1) % 4]) // �ð����
			{
				que.push({ curY, curX, (curD + 1) % 4 });
				r[curY][curX][(curD + 1) % 4] = true;
			}
			if (!r[curY][curX][(curD + 3) % 4]) //�ݽð����
			{
				que.push({ curY, curX, (curD + 3) % 4 });
				r[curY][curX][(curD + 3) % 4] = true;
			}
		}
		if (isFind)
			break;
		cnt++;
	}

}



