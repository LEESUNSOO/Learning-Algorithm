/*1400~1530 
	1. cctv�� ������ ���� �˻� ����� �ٸ�
		1) �ѹ���
		2) �����
		3) ��������
		4) ������
		5) �� ����
	2. ���⿡ �ִ� ĭ ��ü�� ������ �� �ִ� (�� �� �ָ���)
	3. ���� �������
	4. ���� ���ϴ� �κ��� �簢����� ��
	5. ȸ���� �����ѵ� �׻� 90�� �����̿��� �Ѵ�. ���� ���δ� ȸ���ϸ鼭�� ���ø��Ѵٴ� �� ����.
	6. cctv�� ���� ��� ���ص� cctv�� ����Ѵ�.
	0�� �� ĭ, 6�� ��, 1~5�� cctv ��ȣ

	������ �� ���ؼ�~ �簢���븦 �ּ�ȭ�ϴ� �ּ� ũ�⸦ ���ض�.

	�繫�� �ִ� ũ�� 8
	�ټ����� cctv�� ȸ���� ������� �� ����� ����,
	1) 4����
	2) 2����
	3) 4����
	4) 4����
	5) 1����

	�ִ��� ���, 8x8ũ�⿡ cctv(1)�� 8���� ���,
	4^8(����� ��) * 8*8(�繫�� ��ȸ)
	2^22 => 2^10^2 => 1,000,000 ����
	�Ҹ���

	Ǯ�̹��
	1. �繫���� ��ȸ�ϸ� 0, 6�� �ƴ� ���ڸ� �߰��ϸ� ��ǥ�� ��� �� ���ڿ� �´� �Լ�ȣ��
	2. ��� ��츦 ��ͷ� Ž���ϸ�, ��ü ������ �������� ������ bool�迭�� ��ȭ���� ����
	   �ּҰ��� ��
	3. �Ź� bool �迭�� �ʱ�ȭ ���ش�. (���� �̶� ������� �ʰ� ������ ��°����� ���ش�)

	12���� 0�� 0, 90�� 1, 180�� 2, 270�� 3
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int room[8][8];
int Y, X;
int numbering;
int pos[8][3];
int kind;
int minVal; // �� �ִ밳�� �̻� ����
int delta[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<vector<int>> angle = { {0},{0,2},{0,1},{3,0,1},{0,1,2,3} }; //�ʱ� 12345�� �ý�Ƽ�� ����

void monitor(int kind, int index, int dir, vector<vector<bool>>& v)
{

	for (int i = 0; i < angle[kind-1].size(); i++)
	{
		int y = pos[index][1];
		int x = pos[index][2];

		while (true)
		{
			int ny = y + delta[(angle[kind-1][i] + dir) % 4][0];
			int nx = x + delta[(angle[kind-1][i] + dir) % 4][1];
			
			if (ny >= Y || ny < 0 || nx >= X || nx < 0) //�����ʰ�
				break;
			if (room[ny][nx] == 6) //��
				break;
			y = ny;
			x = nx;
			if (room[ny][nx] != 0)
				continue;
			v[ny][nx] = true;

		}
	}
	
}
int sumCheck(vector<vector<bool>> v)
{
	int sum = 0;
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
		{
			if (!v[i][j])
				sum++;
		}
	return sum;
}

void check(int index, int dir, vector<vector<bool>> v)
{
	if (index >= numbering)
	{
		// �ּҰ� ��,
		int cursum = sumCheck(v);
		if (minVal > cursum)
			minVal = cursum;
		return;
	}

	monitor(pos[index][0], index, dir, v);

	check(index + 1, 0, v); // 0��
	check(index + 1, 1, v); // 90��
	check(index + 1, 2, v); // 180��
	check(index + 1, 3, v); // 270��
}

void initCheck(vector<vector<bool>> v)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			v[i][j] = false;
}

int main()
{
	int wall_camera = 0;
	cin >> Y >> X;
	int temp;
	minVal = 65;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> temp;
			room[i][j] = temp;
			if (temp == 0 || temp == 6)
			{
				if (temp == 6)
					wall_camera++;
				continue;
			}
			pos[numbering][0] = temp; // ����
			pos[numbering][1] = i; // y ��ǥ
			pos[numbering][2] = j; // x ��ǥ
			numbering++;
			wall_camera++;
		}
	}
	vector<vector<bool>> isChecked(8, vector<bool>(8, false));

	for (int i = 0; i < 4; i++)
	{
		initCheck(isChecked);
		check(0, i, isChecked); // ������ �װ��� ����
	}

	cout << minVal - wall_camera;
	return 0;
}
