/*2010~2100
	1. ������ �������� ȸ��,
	2. ����� �ִ� 10
	3. 100*100 ��ǥ
	4. ������ �ݽð�������� �س��� ������ �־���(�ٽ�)

	Ǯ�̹��

	(�ٽ�)��������� �Ѿ�� ���������� ������ǥ�� ������ �ݽð�������� �̵��� �ϸ�ȴ�.
	���븦 �ŵ��� �� ����, vector�� ���������� ����
	ex1) 
	3
	3 3 0 1
	4 2 1 3
	4 2 2 1
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int dc[101][101];
int dir[4][2] = { {0,1},{-1, 0}, {0,-1},{1,0} }; // 90�� ȸ���� +3%4; -90���� +1%4;
int g;
void dragon(int y, int x, int cur, vector<int>& list)
{
	dc[y][x] = true;
	int len;
	int ny, nx;
	int i;
	ny = y + dir[list[0]][0];
	nx = x + dir[list[0]][1];
	dc[ny][nx] = true;  // 1ó�� �ߺ��ǵ� �������.(���ĵ� �ȴٴ� ����)
	int cnt = cur;
	while (cnt < g)
	{
		len = list.size() - 1;

		for (i = len; i >= 0; i--)
		{
			int rotate = (list[i] + 1) % 4;

			while (rotate > 4)
				rotate %= 4;

			ny += dir[rotate][0];
			nx += dir[rotate][1];

			dc[ny][nx] = true;
			list.push_back(rotate);
		}
		cnt++;
	}
}

int searchSquare()
{
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (dc[i][j] == 1 &&
				dc[i][j + 1] == 1 &&
				dc[i + 1][j] == 1 &&
				dc[i + 1][j + 1] == 1)
				cnt++;
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, d;
		cin >> x >> y >> d >> g;
		vector<int> dirList;
		dirList.push_back(d);
		dragon(y, x, 0, dirList);
	}

	//Ŀ��Ȯ�� �Լ�
	cout << searchSquare();
	return 0;
}
