/*
	1. ���� ���� 2<= <=11
	2. ����		1<= <=100
	3. ���� ����, ���� ����, ���� ����, ������ ����
	��� = �ִ�, �ּڰ� // int�� ���� (�߰����������� 10�� ���϶� int ����)
*/
/*
	1. ���� �迭 �ϼ��ϰ�
	2. ������ �� ������ �� �ְ�
	3. ��ͷ� ������ ī��Ʈ �ٿ����� N�� �������� �� �� ���Ϳ� ����
	4. �Լ� ���� ��, vector�� �ִ밪 �ּҰ� ���
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[11];
vector<int> v;

void calcu(int cnt, int total, int s, int mi, int mu, int di)
{
	if (cnt == n)
	{
		v.push_back(total);
		return;
	}

	int cur = num[cnt];

	if(s != 0)
		calcu(cnt + 1, total + cur , s-1, mi, mu, di);
	if (mi != 0)
		calcu(cnt + 1, total - cur, s, mi-1, mu, di);
	if (mu != 0)
		calcu(cnt + 1, total * cur, s, mi, mu-1, di);
	if (di != 0)
		calcu(cnt + 1, total / cur, s, mi, mu, di-1);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sum;
	int minus;
	int multi;
	int divide;

	int total = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	cin >> sum;
	cin >> minus;
	cin >> multi;
	cin >> divide;

	calcu(1, num[0], sum, minus, multi, divide);

	cout << *max_element(v.begin(), v.end()) << endl;
	cout << *min_element(v.begin(), v.end()) << endl;

}
