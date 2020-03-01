#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
	int y;
	int x;
	int speed;
	int dir;
	int size;
	bool isActive;
};


int Y, X, M;
vector<int> spotNum[101][101];
Shark shark[10002];
int total;

bool compare(int a, int b)
{
	if (shark[a].size > shark[b].size)
		return true;
	return false;
}

//�Լ�
void input();
void deleteShark(int time);
void moveShark();
void posChange(int idx);
void fight();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	
	int time = 0;

	while (++time <= X) // X�� ����ġ�� �� ( ���ÿ� �̵� )
	{
		deleteShark(time); // �ʸ��� �ش� ��ũ ���̱� ( ���� )
		moveShark();
		fight();
	}
	cout << total;

	return 0;
}

void input()
{
	cin >> Y >> X >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> shark[i].y;
		cin >> shark[i].x;
		cin >> shark[i].speed;
		cin >> shark[i].dir;
		cin >> shark[i].size;
		shark[i].isActive = true;
		spotNum[shark[i].y][shark[i].x].push_back(i);
	}
}

void deleteShark(int time)
{
	int near = 102; // ���� �� ���� ��
	int idx = 0;
	for (int i = 0; i < M; i++)
	{
		if (!shark[i].isActive) // �����ֵ��� ��ŵ
			continue;
		if (shark[i].x == time)
		{
			if (near > shark[i].y)
			{
				near = shark[i].y;
				idx = i;
			}
		}
	}
	if (near != 102) // ��ã������ �����̱�
	{
		shark[idx].isActive = false; // ���̱�
		total += shark[idx].size;
		spotNum[shark[idx].y][shark[idx].x].clear();
	}
}

void moveShark()
{
	for (int i = 0; i < M; i++)
	{
		if (!shark[i].isActive)
			continue;
		spotNum[shark[i].y][shark[i].x].clear();
	}

	for (int i = 0; i < M; i++)
	{
		if (!shark[i].isActive)
			continue;
		posChange(i);
	}
}

void posChange(int idx)
{
	int sy = shark[idx].y;
	int sx = shark[idx].x;
	int dir = shark[idx].dir;
	int speed = shark[idx].speed;
	int diff;
	int repeat; // ���� ȸ��
	int rest; // ���� ����
	int ny, nx; // �̵� �� ��ġ
	ny = sy;
	nx = sx;
	switch (dir)
	{
	case 1: // ��
		diff = speed - (sy - 1); // ������ ���� ���� ���ǵ� (�̵��Ÿ��� ���ϴ� ��)
		if (diff <= 0) // �������� ���� �����ϸ�
			ny = sy - speed; // ���ǵ������ ���� ���⺯ȭ�� ��������
		else // ���´ٸ�
		{
			repeat = diff / (Y - 1);
			rest = diff % (Y - 1);
			if (repeat % 2 == 0)
			{
				ny = 1 + rest;
				shark[idx].dir = 2;
			}
			else
			{
				ny = Y - rest;
			}
		}
		break;

	case 2: // �Ʒ�
		diff = speed - (Y - sy); // �������� ���� ���� ���ǵ� (�̵��Ÿ��� ���ϴ� ��)
		if (diff <= 0) // ���������� ���� �����ϸ�
			ny = sy + speed; // ���ǵ������ ���� ���⺯ȭ�� ��������
		else // ���´ٸ�
		{
			repeat = diff / (Y - 1);
			rest = diff % (Y - 1);
			if (repeat % 2 == 0)
			{
				ny = Y - rest;
				shark[idx].dir = 1;
			}
			else
			{
				ny = 1 + rest;
			}
		}
		break;

	case 3: // ������
		diff = speed - (X - sx); // �������� ���� ���� ���ǵ� (�̵��Ÿ��� ���ϴ� ��)
		if (diff <= 0) // ���������� ���� �����ϸ�
			nx = sx + speed; // ���ǵ������ ���� ���⺯ȭ�� ��������
		else // ���´ٸ�
		{
			repeat = diff / (X - 1);
			rest = diff % (X - 1);
			if (repeat % 2 == 0)
			{
				nx = X - rest;
				shark[idx].dir = 4;
			}
			else
			{
				nx = 1 + rest;
			}
		}
		break;

	case 4: // ����
		diff = speed - (sx - 1); // �������� ���� ���� ���ǵ� (�̵��Ÿ��� ���ϴ� ��)
		if (diff <= 0) // ���������� ���� �����ϸ�
			nx = sx - speed; // ���ǵ������ ���� ���⺯ȭ�� ��������
		else // ���´ٸ�
		{
			repeat = diff / (X - 1);
			rest = diff % (X - 1);
			if (repeat % 2 == 0)
			{
				nx = 1 + rest;
				shark[idx].dir = 3;
			}
			else
			{
				nx = X - rest;
			}
		}
		break;
	}

	// ��ġ�� ���������� �̵� �����������ְ� ī��Ʈ�� ���ش�.
	spotNum[ny][nx].push_back(idx);
	shark[idx].y = ny;
	shark[idx].x = nx;
}

void fight()
{
	int max;
	int idx;
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			idx = 10001;
			max = 0;
			if (spotNum[i][j].size() > 1)
			{
				sort(spotNum[i][j].begin(), spotNum[i][j].end(), compare);
				int live = spotNum[i][j][0];
				for (int k = 1; k < spotNum[i][j].size(); k++)
				{
					shark[spotNum[i][j][k]].isActive = false;
				}
				spotNum[i][j].clear();
				spotNum[i][j].push_back(live);
			}
		}
	}
}
