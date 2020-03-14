/*
	1. �־��� �ʿ��� ���� ���� ���� (�ִ��� �ʿ䰡 ���°� ������� �ּ� 3���� �ִٰ� �Ѵ�.)
	  ���̷���Ȯ�꿡 ������ ������ �ִ밪�� ���ϴ� ����

	Ǯ�̹��
	1. ��� �ȿ� for���� Ȱ���Ͽ� �湮ó���� Ű�� ���ָ� 3���� ���� ���ﶧ����
	-> ���̷��� Ȯ���� ��Ű�� -> �������� (0)�� ��Ҹ� ����.
	��
*/

#include <iostream>
#include <string>
using namespace std;

int Y, X;
int map[8][8]; // ��ǥ������ ���� �����Ƿ� 9�� �������� �ʾƵ� �򰥸��� �ʴ´�.
bool visit[8][8]; //���̷����� ������ ���� ���� �� ������ �ʿ���� �� ����.
int tempmap[8][8]; // Ȯ��üũ�� �� �� ���� ������Ű�� ����Ƿ� �����Ѵ�.
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // ���̷��� ���Ȯ���
int maxVal;

#define MAX(A, B)(A > B ? A : B)

void visitReset()
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			visit[i][j] = false;
		}
	}

}
void virus(int y, int x)
{
	visit[y][x] = true;
	tempmap[y][x] = 2;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny < 0 || nx < 0 || ny >= Y || nx >= X || visit[ny][nx])
			continue;
		if (map[ny][nx] == 1)
			continue;
		virus(ny, nx);
	}
}

void dfs(int y, int x, int cnt)
{
	if (cnt == 3)
	{
		int sum = 0;
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				tempmap[i][j] = map[i][j];
			}
		}

		// Ȯ��
		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				if (!visit[i][j] && map[i][j] == 2){
					virus(i, j);
				}
			}
		}
		// ���� ���� Ȯ��
		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				if (tempmap[i][j] == 0)
					sum++;
			}
		}

		maxVal = MAX(maxVal, sum);
		visitReset();
		return;
	}


	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			if (map[i][j] != 0)
				continue;
			map[i][j] = 1;
			dfs(i, j, cnt+1);
			map[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Y >> X;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> map[y][x];
		}
	}

	dfs(0, 0, 0);
	
	cout << maxVal;

	return 0;
}
