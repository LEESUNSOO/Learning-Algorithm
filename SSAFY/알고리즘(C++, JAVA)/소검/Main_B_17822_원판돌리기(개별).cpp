/*1610~1700 + 1815~1915 => 50+60 => 1H50M

*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int circle[51][51];
int N, M, T;
int num, dir, dis;
int k;
int adjoin[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
set<pair<int, int>> posCheck;
double sum;
int cnt;
void rotate();
void swap(int row);
void adjoinCheck();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> circle[i][j];
			sum += circle[i][j];
		}
	}
	cnt = N * M;
	for (int t = 0; t < T; t++)
	{
		cin >> num >> dir >> dis;


		rotate();
		adjoinCheck();
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer += circle[i][j];
		}
	}

	cout << answer;

	return 0;
}

void rotate()
{
	// ���� ����ȭ (�� �������� �����ֱ�
	if (dir == 0)
	{
		k = dis;
	}
	else // �ݽð�
	{
		k = M - dis;
	}

	for (int i = 0; i < N; i++)
	{
		if ((i + 1) % num != 0)
			continue;
		swap(i);
	}
}

void swap(int row)
{
	vector<int> temp;
	for (int i = M - k; i < M; i++) // ���� �Ѿ� ���ư��� �ֵ� ��� ������
	{
		temp.push_back(circle[row][i]);
	}

	for (int i = M - 1; i >= k; i--) // �ٸ��ֵ� �̵�
	{
		circle[row][i] = circle[row][i - k];
	}

	for (int i = 0; i < k; i++) // �Ѿ���ֵ� �����ֱ�
	{
		circle[row][i] = temp[i];
	}

	temp.clear();
}

void adjoinCheck()
{
	int ny, nx;
	int base;
	bool isCollect;
	bool isSame = false;
	for (int i = 0; i < N; i++) // ����ó��
	{
		for (int j = 0; j < M; j++)
		{
			if (circle[i][j] == 0)
				continue;
			base = circle[i][j];
			isCollect = false;

			for (int k = 0; k < 4; k++)
			{
				ny = i + adjoin[k][0];
				nx = j + adjoin[k][1];

				if (ny < 0 || ny >= N) // ������ ����� �� ��ŵ
					continue;
				if (nx < 0)
				{
					nx = M - 1;
				}
				else if (nx >= M)
				{
					nx = 0;
				}

				if (circle[ny][nx] == 0) // ���ŵ� ���� ó������ �ʴ´�
					continue;

				if (base == circle[ny][nx])
				{
					posCheck.insert({ ny,nx });
					isCollect = true;
					isSame = true;

				}
			}
			if (isCollect)
			{
				posCheck.insert({ i,j });
			}
		}
	}

	double avg;
	if (!isSame) // �ϳ��� ���� �� ���ٸ�
	{
		avg = sum / cnt;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (circle[i][j] == 0)
					continue;

				if (circle[i][j] < avg)
				{
					circle[i][j]++;
					sum++;
				}
				else if (circle[i][j] > avg)
				{
					circle[i][j]--;
					sum--;
				}
			}
		}
	}
	else // �־��ٸ�,
	{
		for (auto a : posCheck)
		{
			sum -= circle[a.first][a.second];
			cnt--;
			circle[a.first][a.second] = 0;
		}
		posCheck.clear();
	}


}

