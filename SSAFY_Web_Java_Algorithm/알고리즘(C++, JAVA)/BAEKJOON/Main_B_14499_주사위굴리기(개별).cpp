/*
	1. 0���� �ʱ�ȭ �Ǿ��ִ� �ֻ����� ������ �ٴ��� 0�϶� �ٴڿ� ���ڸ� ����, 
	�����϶�, �ֻ����� ����ǰ� �ٴڸ��� 0���� �ٲ�
	2. ������ ����� ����� �����ϰ� ��µ� �ϸ� �ȵ�
	3. ���������� �ֻ��� ���鿡 ���ִ� ���ڸ� ���

	Ǯ�̹��
	U, D, L, R, F, B �� �����ϰ�,
	ȸ�� ���⿡ ���� ���� �������ش�.

*/
#include <iostream>
#include <string>
using namespace std;
int N, M;
int map[20][20];
int square[7]; // �ֻ���
int y, x;
bool isAble;

//enum dir {
//	U = 1,
//	F = 5,
//	D = 6,
//	B = 2,
//	R = 3,
//	L = 4
//};

void copy()
{
	if (map[y][x] == 0)
	{
		map[y][x] = square[6];
	}
	else
	{
		square[6] = map[y][x];
		map[y][x] = 0;
	}
}

void rotate(int num)
{
	switch (num)
	{
		int temp;
	case 1: //��
		if (x + 1 >= M)
		{
			isAble = false;
			break;
		}
		x += 1;
		
		temp = square[1];
		square[1] = square[4];
		square[4] = square[6];
		square[6] = square[3];
		square[3] = temp;
		break;
	case 2: //��
		if (x - 1 < 0)
		{
			isAble = false;
			break;
		}
		x -= 1;
		temp = square[1];
		square[1] = square[3];
		square[3] = square[6];
		square[6] = square[4];
		square[4] = temp;
		break;

	case 3: //��
		if (y - 1 < 0)
		{
			isAble = false;
			break;
		}
		y -= 1;
		temp = square[1];
		square[1] = square[5];
		square[5] = square[6];
		square[6] = square[2];
		square[2] = temp;
		
		break;
	case 4: //��
		if (y + 1 >= N)
		{
			isAble = false;
			break;
		}
		y += 1;
		temp = square[1];
		square[1] = square[2];
		square[2] = square[6];
		square[6] = square[5];
		square[5] = temp;
		break;
	}
	if(isAble)
		copy();
}


int main()
{

	int linesNum;
	cin >> N >> M >> y >> x >> linesNum;

	for (int i = 0; i < N; i++) // �� �ʱ�ȭ
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= linesNum; i++)
	{
		int temp;
		cin >> temp;

		isAble = true;
		rotate(temp);
		if (!isAble)
			continue;

		if(i == linesNum)
			cout << square[1];
		else
			cout << square[1] << endl;
	}


	return 0;
}

