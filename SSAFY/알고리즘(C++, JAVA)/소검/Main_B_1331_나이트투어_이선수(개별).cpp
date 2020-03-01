/* 0055~0115
	1. 2�� 128MB
	2. ü���� ���� �̵� (8����)���� ��� ������ �ѹ����� �湮�ϰ�,
	������ �������� �ٽ� ���������� ���ƿ��� ��ΰ� ������ �Ǵ��ϴ� ����

	Ǯ�� :
	������ ���̱� ����, 
	���� ó���� �������� ���ؼ� �ȵǸ� Invalid ���
	�Ǹ� �̵��� �����غ���.
	y�̵����� x�̵����� ���밪�� 1�� 2�� �̷���������� �����Ű��
	������ ���������� visit�� true���� true�� ��湮�ϸ� false ��Ų��.
	���� ������ ������ ���� �ݴ�� �Ǿ��ִ°� �����Ѵ�.

	�ٸ�Ǯ�� : �̰� �����غ���.
	map�� Ȱ���� �ߺ�üũ,
	���޾� ���� ��ǲ������ üũ

*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> m;
	bool isFalse = false;
	string startPos;
	string oldPos;
	string newPos;
	cin >> oldPos;
	startPos = oldPos;
	m[startPos] = 1;
	for (int i = 1; i < 36; i++)
	{
		cin >> newPos;

		if (m.find(newPos) != m.end())
		{
			isFalse = true;
			break;
		}
		m[newPos] = 1;
		int diffY = abs(oldPos[0] - newPos[0]);
		int diffX = abs(oldPos[1] - newPos[1]);

		if (diffY * diffX != 2)
		{
			isFalse = true;
			break;
		}
		oldPos = newPos;
	}
	if (isFalse)
	{
		cout << "Invalid";
		return 0;
	}
	int diffY = abs(oldPos[0] - startPos[0]);
	int diffX = abs(oldPos[1] - startPos[1]);

	if (diffY * diffX != 2)
	{
		cout << "Invalid";
		return 0;
	}

	cout << "Valid";

	return 0;
}
