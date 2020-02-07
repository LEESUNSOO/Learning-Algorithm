/*
	1. N+1�Ͽ� ���
	2. �ִ��� ���� ���, �Ϸ翡 �ϳ��� ���� �ٸ� ����� ���
	3. �ɸ��� �Ⱓ�� �ݾ�
	4. �ܹ��ſ� ���������� idx �̵��� �ٸ���

	Ǯ�̹��
	dfs�� ���ڿ� �����Ͽ� �ݾ��� �����Ͽ� �ִ밪�� ���Ѵ�.
	�̶�, �ش� ������ �ҿ�Ⱓ ��ŭ�� idx ������ �ʿ��ϴ�.

*/
#include <iostream>
#include <string>
using namespace std;

int N;
int term[16]; // ���ڶ� �򰥸� �� ������ +1
int price[16];
#define MAX(A,B)(A>B?A:B)
int maxVal;

void dfs(int date, int sum)
{
	if (date + term[date] - 1 > N)
		return;

	maxVal = MAX(maxVal, sum + price[date]);

	for (int i = date + term[date]; i <= N; i++)
	{
		dfs(i, sum + price[date]);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> term[i];
		cin >> price[i];
	}

	for(int i = 1; i <= N; i++) // ���� ��¥���� üũ ( 0~7 )
		dfs(i, 0);

	cout << maxVal;

	return 0;
}
