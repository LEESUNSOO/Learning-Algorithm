/*2350~2440
	1. A ȸ���� �´��� B�� ���� �ٸ��� A�� ȸ���� �ݴ�������� ȸ��
	2. ���� ������ ȸ�� ����

	���� ��Ϲ����� ���¸� ���ض�
	���(Ȩ)�� 8���� ���� 12�� ���� �ð���� ������ �� �־���
	��Ϲ����� 4���� ����
	1<= ȸ��Ƚ�� <= 100
	��� ��ȣ / ����
	1 = �ð����, -1 = �ݽð����
	�ִ� ȸ���� ���, 
	�ϳ��� ���� ȸ���� ���� �¿�� 99���� ������ �˻��ϰ�
	ȸ���� 100���̸�
	100*100
	
	=> �ùķ� ��
	
	1. ��Ϲ����� 2�� (������ 0���� ������ ��)�� 6���� �˻��ؾ��Ѵ�
	1-1. ���۰� ���� 6���� 2�� ����
	2. �ش� ��Ϲ����� �������� ���� ���� ������ �˻��ϰ�
	3. ��Ʈ�����ڸ� Ȱ���ϸ� ������ �� �ϴ�. (���� insert, remove�� 8���̱⶧���� ������ ������ �ϴ�.)

	�ð��� �ʾ����� ���ͷ� �غ���, �޸������� ȿ������ ����ؼ� ������ ��Ʈ���غ���


*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
vector<vector<int>> v;
int rot;
int rotList[100];

void vector_change(int idx, int dir)
{
	int val;
	if (dir == 1)
	{
		val = v[idx][7];
		v[idx].pop_back();
		v[idx].insert(v[idx].begin(), val);
	}
	else
	{
		val = v[idx][0];
		v[idx].erase(v[idx].begin());
		v[idx].push_back(val);
	}
}

void rot_recursive_R(int cur, int dir)
{
	if (cur >= 4) // ���� ����
		return;

	if (v[cur - 1][2+dir] == v[cur][6])
		return;
	else
	{
		vector_change(cur, dir*-1);
		rot_recursive_R(cur + 1, dir*-1);
	}
}
void rot_recursive_L(int cur, int dir)
{
	if (cur < 0) // ���� ����
		return;

	if (v[cur][2] == v[cur+1][6+dir])
		return;
	else
	{
		vector_change(cur, dir*-1);
		rot_recursive_L(cur - 1, dir*-1);
	}
}
void rot_recursive(int idx, int dir)
{
	vector_change(idx, dir); // ���� ��Ϲ����� ȸ���� �������� ��

	rot_recursive_R(idx+1, dir);
	rot_recursive_L(idx-1, dir);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	v = vector<vector<int>>(4, vector<int>(8, 0));
	string s;
	for (int i = 0; i < 4; i++)
	{
		cin >> s;
		for (int j = 0; j < 8; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}

	cin >> rot;
	int index;
	int direction;
	for (int i = 0; i < rot; i++)
	{
		cin >> index >> direction;
		rot_recursive(index-1, direction);
	}

	int sum = 0;
	int mul = 1;
	for (int i = 0; i < 4; i++)
	{
		if (v[i][0])
		{
			sum += pow(2, i);
		}
	}
	cout << sum;
	


	return 0;
}
