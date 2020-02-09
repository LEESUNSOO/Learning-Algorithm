/* 1630~1800 + 1900~1950
	1. ���̷��� �� ������ ������ŭ�� ��� Ȯ������ ��, ���� ���̷����� ���� ����� �ּҽð��� ���ض�
	2. �׷��� ������ �ӵ������� 0.25�̴�.
	3. ���嶰������ ����� ���� ���̷����� �� 3���� ���� ���,
	bfs�� ���� �� �ʸ��� Ȯ�� ��, ����¸� �����ϴ� ����� �����Ͽ� �ð��� �ľ��ϴ°��̴�.
	����, ���̻� Ȯ���� �ȵǴ� ��Ȳ���� �� üũ ��, ���� ������ �ʾ����� -1�� ����Ѵ�.
	��üũ�� ���� ó������ �����Ѵ�.
	��Ȱ�� ���̷����� ���̷����� ��
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int y;
	int x;
	pos(int i, int j) :y(i), x(j) {}
};

int map[50][50];
int temp[50][50];
//int visit[50][50];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int N, M;
int virusNum;
vector<pos> virusPos;
vector<int> posCombi;
queue<pos> que;
bool visit[101][101];
void input();
int spoil();
void copy();
bool check();
int minVal = 9999999;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	int minute;
	input();

	do {
		copy(); // Ȯ�� ���� �����غ� ������ �� ����
		while (!que.empty())
			que.pop();
		for (int i = 0; i < virusNum; i++)
			if (posCombi[i] == 1)
			{
				int vy, vx;
				vy = virusPos[i].y;
				vx = virusPos[i].x;
				que.push({ vy, vx }); // ���̷��� M���� ���� �����ߴ��� 
				temp[vy][vx] = 3;
			}
		// Ȯ�� (�� �ʸ��� üũ)
		
		minute = spoil();

		// bool ���� true�� �ּҰ� �� , false�� ��ŵ
		if (minute == -1)
			continue;
		else
		{
			if (minute == 0)
			{
				minVal = 0;
				break;
			}
			else if (minVal > minute)
				minVal = minute;
		}

	} while (next_permutation(posCombi.begin(), posCombi.end()));

	// �ѹ��� �ּҰ��� ������ �����ٸ�, ���� �ȵ� ���ϱ� -1���
	if (minVal == 9999999)
		cout << -1;
	else
		cout << minVal;

	return 0;
}

void input()
{
	cin >> N >> M;
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			map[i][j] = temp;
			if (temp == 2)
			{
				virusPos.push_back(pos(i, j));
				virusNum++;
			}
		}
	}
	posCombi = vector<int>(virusPos.size() - M, 0);
	for (int i = 0; i < M; i++)
		posCombi.push_back(1);
}

int spoil()
{
	bool isFull = false;
	int time = 0;
	int ny, nx;
	while (!que.empty())
	{
		if(check())
		{
			isFull = true;
			break;
		}
		time++;

		int size = que.size();
		while (size-- > 0)
		{
			pos vpos = que.front();
			que.pop();
			for (int d = 0; d < 4; d++)
			{
				ny = vpos.y + dir[d][0];
				nx = vpos.x + dir[d][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N || temp[ny][nx] == 1 || temp[ny][nx] == 3 )
					continue;
				que.push(pos(ny, nx));
				temp[ny][nx] = 3;
			}
		}
	}

	if (isFull)
		return time;
	return -1;
}

void copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = map[i][j];
		}
	}
}

bool check()
{
	bool isFull = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp[i][j] == 0)
			{
				isFull = false;
				break;
			}
		}
		if (!isFull)
			break;
	}

	return isFull;
}
