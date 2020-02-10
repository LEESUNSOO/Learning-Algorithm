/* 1633~1652 + 1700~
	1. rc �峭 ��ħ
	2. ��û�� �׻� 0��° ���� ��ġ
	3. ũ��� �� �� ����
	4. ��ġ �ȵ� ���� �̸�����
	5. ��û�� �ְų� �������̸� Ȯ�� ��
	6. Ȯ��� n/5  (Ȯ���� �����ΰ� ����Ʈ)
	7. Ȯ��ǰ� ���� �� n-(n/5)*(Ȯ����� ����)

	1. ����û���� �۵� ��, �ٶ� ������ ������ �ݽð���� ��ȯ
		�Ʒ����� �ð���� ��ȯ
	2. �ٶ��� �Ҹ� �ٶ� ������ ��� ��ĭ�� �̵��Ѵ�.
	3.

	6  30   7   // ��ȸ�ϸ� �� // Ȯ�귮 ���� �����ִ·� ���� ����
	*  10   0
	*   0  20

*/
#include <iostream>
#include <string>
using namespace std;

int R, C, T;
int rest[50][50];
int spoil[50][50];
int airPos[2][2]; // 0 : up, 1: down
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
// up�� �ٷ� ���� ������� �� ���� �� ��ġ�� ��->������->�Ʒ�->����(������)
int airDirUp[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int airDirDown[4][2] = { {1,0}, {0,1},{-1,0},{0,-1} };
bool isUp;
bool isDown;
void input()
{
	int temp;
	int cnt = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> temp;
			rest[i][j] = temp;
			if (temp == -1)
			{
				airPos[cnt][0] = i;
				airPos[cnt][1] = j;
				cnt++;
			}
		}
	}
}

void SP() // Ȯ��
{
	int ny, nx;
	int spoil_mimun;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (rest[i][j] == -1 || rest[i][j] == 0) // ����û������ ��� �� �۾��� �������� �ʴ´�.
				continue;
			spoil_mimun = rest[i][j] / 5;
			for (int k = 0; k < 4; k++)
			{
				ny = i + dir[k][0];
				nx = j + dir[k][1];
				if (rest[ny][nx] == -1 || ny < 0 || nx < 0 || ny >= R || nx >= C)
					continue;
				spoil[ny][nx] += spoil_mimun;
				rest[i][j] -= spoil_mimun; // ������ �����ߴµ� �ִ� 4�����̰� /5�� �ϱ⶧���� �׷��� ������
			}
		}
	}
}
void curRest()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (spoil[i][j] == 0)
				continue;
			rest[i][j] += spoil[i][j];
			spoil[i][j] = 0;
		}
	}
}
void up(int y, int x, int d)
{
	int ny = y + airDirUp[d][0];
	int nx = x + airDirUp[d][1];

	if (ny == airPos[0][0] && nx == airPos[0][1])
	{
		rest[y][x] = 0;
		isUp = true;
		return;
	}
	if (ny < 0 || nx < 0 || (ny > airPos[0][0] && d !=3) || nx >= C)
	{
		int newY = y + airDirUp[d + 1][0];
		int newX = x + airDirUp[d + 1][1];
		rest[y][x] = rest[newY][newX]; // �޾ƿ���
		up(newY, newX, (d + 1) % 4);
		if (isUp)
			return;
	}
	else
	{
		rest[y][x] = rest[ny][nx]; // �޾ƿ���
		up(ny, nx, d % 4);
		if (isUp)
			return;
	}
}
void down(int y, int x, int d)
{
	int ny = y + airDirDown[d][0];
	int nx = x + airDirDown[d][1];

	if (ny == airPos[1][0] && nx == airPos[1][1])
	{
		rest[y][x] = 0;
		isDown = true;
		return;
	}
	if (ny >= R || nx < 0 || (ny < airPos[1][0] && d != 3) || nx >= C)
	{
		int newY = y + airDirDown[d + 1][0];
		int newX = x + airDirDown[d + 1][1];
		rest[y][x] = rest[newY][newX]; // �޾ƿ���
		down(newY, newX, d + 1);
		if (isDown)
			return;
	}
	else
	{
		rest[y][x] = rest[ny][nx]; // �޾ƿ���
		down(ny, nx, d);
		if (isDown)
			return;
	}
}
void air()
{
	//up
	/*
		up�� �ٷ� ���� ������� �� ���� �� ��ġ�� ��->������->�Ʒ�->����(������)
	*/
	rest[airPos[0][0] - 1][airPos[0][1]] = 0; // �����
	isUp = false;
	up(airPos[0][0] - 1, airPos[0][1], 0); // û���� �� ���� ����, ���� ���� ��������

	//down
	/*
		down�� �ٷ� �Ʒ��� ������� �� �Ʒ��� �� ��ġ�� �Ʒ�->������->��->����(������)
	*/
	rest[airPos[1][0] + 1][airPos[1][1]] = 0; // �����
	isDown = false;
	down(airPos[1][0] + 1, airPos[1][1], 0);// û���� �Ʒ� ���� ����, �Ʒ��� ���� ��������

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	input();
	while (T-- > 0)
	{
		SP();
		curRest();
		air();
	}

	int Sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			Sum += rest[i][j];
		}
	}
	cout << Sum+2;

	return 0;
}
