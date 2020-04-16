/* 1930~2005

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct oper {
	int r;
	int c;
	int s;
};
int N, M, K;
int map[101][101]; // (1,1) ����
int baseMap[101][101];
int r, c, s;
vector<oper> v; // ȸ������ ��¿�
vector<int> np; // ���ۿ�(����)
int minVal = 999999999;

void minCheck(); // �ణ�� ���հ� �ּҰ� ��
void rotate(); // �������� ���ڰ��� Ȱ���� ȸ��
void copyMap();
void input();
int main()
{
	input();

	do {
		copyMap();
		//����� ȸ��
		rotate();
		//�ּҰ� Ȯ��
		minCheck();
	} while (next_permutation(np.begin(), np.end()));

	cout << minVal;


	return 0;
}

void rotate()
{
	int r, c, s;
	int sy, sx, ey, ex;

	for (int i = 0; i < K; i++)
	{
		r = v[np[i]].r;
		c = v[np[i]].c;
		s = v[np[i]].s;

		sy = r - s;
		sx = c - s;
		ey = r + s;
		ex = c + s;

		while ((ey - sy != 0) && (ex - sx != 0)) // �ּ� 2*2�� �����ϴ� ���¿����� ȸ��
		{
			int startPos = map[sy][sx]; // �ϳ� ������
			for (int y = sy + 1; y <= ey; y++) // ����ó��
			{
				map[y - 1][sx] = map[y][sx];
			}

			for (int x = sx + 1; x <= ex; x++) // �Ʒ�ó��
			{
				map[ey][x - 1] = map[ey][x];
			}

			for (int y = ey - 1; y >= sy; y--) // ������ó��
			{
				map[y + 1][ex] = map[y][ex];
			}

			for (int x = ex - 1; x > sx; x--) // ������ó��
			{
				map[sy][x + 1] = map[sy][x];
			}

			map[sy][sx + 1] = startPos;

			sx++;
			sy++;
			ex--;
			ey--;
		}
	}
}

void copyMap()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = baseMap[i][j];
		}
	}
}

void minCheck()
{
	int row;

	for (int i = 1; i <= N; i++)
	{
		row = 0;
		for (int j = 1; j <= M; j++)
		{
			row += map[i][j];
		}
		if (minVal > row)
			minVal = row;
	}
	
}


void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> baseMap[i][j];
		}
	}


	int r, c, s;
	for (int k = 0; k < K; k++)
	{
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}

	for (int i = 0; i < K; i++)
	{
		np.push_back(i);
	}
}
