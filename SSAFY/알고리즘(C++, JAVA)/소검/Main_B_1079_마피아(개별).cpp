/* 2205~2250 45M
	1. 2�� 128MB
	2. N�� 16���� �۰ų� ���� �ڿ���
	
	Ǯ�� :
	������� �״� ��� ��츦 ���Ǹ�, �����̰� ���� �������� ���� ����Ѵ�.
	�������� ������ ���� return ���Ѽ� ��Ʈ��ŷ�� �� �� �ִ�.
	���� ���ÿ��� �����̴� ������ �������� �ʰ� �����Ѵ�.

	������ ������ ���� ��ȣ�� ���� ���ؼ��� 
	max �񱳿��� ��ȣ�� ���ܽ��� ���� ��ȣ���� ��ȸ��Ų��.

*/
#include <iostream>
#include <string>

using namespace std;
int N;
int R[16][16]; // �÷��̾� ��ȣ 0���� ����
int guiltyScore[16];
bool isDead[16]; // ������ ���ʿ��� ���� ����
int maxDay; // �ִ�� ��ƾ ��
bool EJDead; // ������ ���� Ȯ��
int mafiaNum;
int alivePerson;

void input();
void game(int days);

int main()
{
	input();
	alivePerson = N;
	game(0);
	cout << maxDay;
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> guiltyScore[n];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> R[i][j];
		}
	}

	cin >> mafiaNum;
}

void game(int days)
{
	if (alivePerson % 2 == 0) // ��
	{
		for (int i = 0; i < N; i++)
		{
			if (i == mafiaNum || isDead[i])
				continue;

			isDead[i] = true;
			for (int j = 0; j < N; j++)
			{
				if (isDead[j])
					continue;
				guiltyScore[j] += R[i][j];
			}

			alivePerson--;

			game(days + 1);

			alivePerson++;

			for (int j = 0; j < N; j++)
			{
				if (isDead[j])
					continue;
				guiltyScore[j] -= R[i][j];
			}
			isDead[i] = false;
		}
	}
	else // ��
	{
		int maxScore = 0;
		int idx = 0;
		for (int i = 0; i < N; i++)
		{
			if (isDead[i])
				continue;
			if (maxScore < guiltyScore[i])
			{
				maxScore = guiltyScore[i];
				idx = i;
			}
		}

		if (idx == mafiaNum) // �����̰� �ɷ����� ��
		{
			if (maxDay < days)
				maxDay = days;
			return;
		}

		isDead[idx] = true;
		alivePerson--;
		game(days);
		alivePerson++;
		isDead[idx] = false;
	}
}


