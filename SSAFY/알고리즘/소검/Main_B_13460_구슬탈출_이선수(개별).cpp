#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pos
{
	int y;
	int x;
	pos(int _y, int _x): y(_y), x(_x) {};
};

int Y;
int X;
char map[10][10];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }; // �� �� �� �� (+2 % 4 �ϸ� �ݴ���� ����)
pos red = { 0,0 };
pos blue = { 0,0 };
pos hole = { 0,0 };
int answer = 999999999;
bool dropRed;
bool dropBlue;
void input();
void move(int d, int cnt, pos red, pos blue);
#define Min(a,b)(a<b?a:b)

int main()
{
	input();
	move(-11, 1, red, blue); // ù ���� �ſ� �۰� ���� ( ������ �����̵��� )
	
	if (answer == 999999999)
		cout << -1;
	else
		cout << answer;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Y >> X;

	string temp;
	char c;
	for (int y = 0; y < Y; y++)
	{
		cin >> temp;
		for (int x = 0; x < X; x++)
		{
			c = temp[x];
			map[y][x] = c;
			if (c == 'R')
			{
				red.y = y;
				red.x = x;
			}
			else if (c == 'B')
			{
				blue.y = y;
				blue.x = x;
			}
			else if (c == 'O')
			{
				hole.y = y;
				hole.x = x;
			}
		}
	}


}

void move(int d, int cnt, pos red, pos blue)
{


	if (cnt > 10)
		return;
	if (red.x == hole.x && red.y == hole.y)
	{
		answer = Min(cnt, answer);
		return;
	}

	int _d = d % 4; // �Ⱦ���?
	int notD = (_d + 2) % 4; // �ݴ���� (�ȱ׷��� ��� �Դٰ���)

	for (int i = 0; i < 4; i++)
	{
		dropRed = false;
		dropBlue = false;
		if (i == notD)
			continue;
		// ����
		int rny = red.y;
		int rnx = red.x;
		
		while (true) // ���� �������� ��� �̵�
		{
			rny += dir[i][0]; // ���°� ���ٸ� ��� ������
			rnx += dir[i][1];

			if (map[rny][rnx] == '#')
			{
				rny -= dir[i][0];
				rnx -= dir[i][1];
				break;
			}
			if (map[rny][rnx] == 'O')
			{
				dropRed = true;
				break;
			}
		}

		// �Ķ�
		int bny = blue.y;
		int bnx = blue.x;
		
		while (true) // ���� �������� ��� �̵�
		{
			bny += dir[i][0]; // ���°� ���ٸ� ��� ������
			bnx += dir[i][1];
			if (map[bny][bnx] == '#')
			{
				bny -= dir[i][0];
				bnx -= dir[i][1];
				break;
			}
			if (map[bny][bnx] == 'O')
			{
				dropBlue = true;
				break;
			}
		}

		if (dropRed && !dropBlue)
		{
			answer = Min(cnt, answer);
			continue;
		}
		else if((!dropRed && dropBlue) || (dropRed && dropBlue))
		{
			continue;
		}

		if (rny == red.y && rnx == red.x && bny == blue.y && bnx == blue.x)
			continue;

		// �� ��������,
		if (rny == bny && rnx == bnx) // �̵��غ��� ���� ���̶��
		{
			switch (i)
			{
			case 0: // ��
				if (red.y > blue.y) // ���尡 �Ʒ��� �־��ٸ�
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny - 1, bnx)); // ��� ��ĭ ����
				}
				else // ��簡 �Ʒ��־��ٸ�
				{
					move(i, cnt + 1, pos(rny - 1, rnx), pos(bny, bnx)); // ���� ��ĭ ����
				}

				break;
			case 1: // ��
				if (red.x > blue.x) // ���尡 �����ʿ� �־��ٸ�
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny, bnx - 1)); // ��� ��ĭ ��������
				}
				else // ��簡 �����ʿ� �־��ٸ�
				{
					move(i, cnt + 1, pos(rny, rnx - 1), pos(bny, bnx)); // ���� ��ĭ ����
				}
				break;
			case 2: // ��
				if (red.y > blue.y) // ���尡 �Ʒ��� �־��ٸ�
				{
					move(i, cnt + 1, pos(rny + 1, rnx), pos(bny, bnx)); // ��� ��ĭ ����
				}
				else // ��簡 �Ʒ��� �־��ٸ�
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny + 1, bnx)); // ���� ��ĭ ����
				}
				break;
			case 3: // ��
				if (red.x > blue.x) // ���尡 �����ʿ� �־��ٸ�
				{
					move(i, cnt + 1, pos(rny, rnx + 1), pos(bny, bnx)); // ��� ��ĭ ��������
				}
				else // ��簡 �����ʿ� �־��ٸ�
				{
					move(i, cnt + 1, pos(rny, rnx), pos(bny, bnx + 1)); // ���� ��ĭ ����
				}
				break;
			}
		}
		else
		{
			move(i, cnt + 1, pos(rny, rnx), pos(bny, bnx));
		}

		

	}
}
