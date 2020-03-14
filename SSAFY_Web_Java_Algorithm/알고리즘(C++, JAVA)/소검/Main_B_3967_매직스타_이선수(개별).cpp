///* 0305~0415 1H15M
//	1. 1�� 256MB
//
//	Ǯ�� :
//	�Ϻθ� ä���� ������Ÿ��� ������, �ּ� 1���� �־����װ�,
//	�׷� �ִ� 11! �� ����� ���� �˻��غ��� �ȴ�.
//
//	������ 12���ϱ�, ������ �������൵ �� �� �ϴ�.
//	5*9
//	������ ¥�������� ��, 26�� �Ѵ� ��Ȳ�� �߻��Ǹ� ��Ʈ��ŷ�� �������ش�.
//
//	�� ������ ������ ��Ÿ�� ���� 6��
//	�� ��ġ�� ���� ������ �˷��� �Լ�,
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//struct pos {
//	int y;
//	int x;
//	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
//};
//
//char map[5][9]; // ������ ��� ������ ���̴�.
//int line[7]; // 1~6�� ����
//vector<pos> totalPos = { {0,4},{1,1},{1,3},{1,5},{1,7},{2,2},{2,6},{3,1},{3,3},{3,5},{3,7},{4,4} };
//bool numCheck[13];
//bool isFind;
//
//void input();
//vector<int> searchLine(pos cur);
//void combi(int idx);
//int main()
//{
//	input();
//	combi(0);
//
//	return 0;
//}
//
//void input()
//{
//	string temp;
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < 9; j++)
//		{
//			map[i][j] = temp[j];
//			if (temp[j] != '.' && temp[j] != 'x') // ���ĺ�
//			{
//				vector<int> nums = searchLine({ i,j });
//				for (int k = 0; k < nums.size(); k++)
//				{
//					line[nums[k]] += temp[j] - 'A' + 1;
//				}
//				numCheck[temp[j] - 'A' + 1] = true; // �̹� ���� ���ڵ�
//			}
//		}
//	}
//}
//
//
//void combi(int idx)
//{
//	if (idx == 12) // ��� ��ġ�� �����ϴ� ���,
//	{
//		bool isSuccess = true;
//
//		for (int i = 1; i <= 6; i++)
//		{
//			if (line[i] != 26)
//			{
//				isSuccess = false;
//				break;
//			}
//		}
//
//		if (!isSuccess)
//			return;
//
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				cout << map[i][j];
//			}
//			cout << endl;
//		}
//
//		isFind = true;
//		return;
//	}
//
//	int y = totalPos[idx].y;
//	int x = totalPos[idx].x;
//
//	if (map[y][x] != 'x')
//	{
//		combi(idx + 1);
//		if (isFind)
//			return;
//	}
//	else // x��,
//	{
//		vector<int> lines = searchLine({ y,x });
//		bool isOver;
//		for (int i = 1; i <= 12; i++)
//		{
//			if (numCheck[i])
//				continue;
//			isOver = false;
//			for (int j = 0; j < lines.size(); j++)
//			{
//				if (line[lines[j]] + i > 26) // ���� ���ο� ���� 26�� �Ѵ´�,
//				{
//					isOver = true;
//					break;
//				}
//			}
//			if (isOver) // �Ѿ�� ������ �����ϱ� �� ���� �Ѿ
//				break;
//
//			map[y][x] = (char)('A' + i - 1); // �ش� ���ڷ� �ٲ��ְ�
//			for (int j = 0; j < lines.size(); j++)
//			{
//				line[lines[j]] += i; // �� �����ְ�,
//			}
//			numCheck[i] = true;
//			combi(idx + 1); // ���� �ܰ� �Ѱ��ְ�,
//			if (isFind)
//				return;
//			numCheck[i] = false; // �ش� ���ڰ� ���������� �ٽ� false�����ְ�,
//			for (int j = 0; j < lines.size(); j++)
//			{
//				line[lines[j]] -= i; // �� ���ְ�,
//			}
//			map[y][x] = 'x';
//		}
//	}
//
//
//}
//
//vector<int> searchLine(pos cur)
//{
//	int y = cur.y;
//	int x = cur.x;
//
//	if (y == 0 && x == 4)
//	{
//		return { 1,3 };
//	}
//	else if (y == 1)
//	{
//		if (x == 1)
//		{
//			return { 4,5 };
//		}
//		else if (x == 3)
//		{
//			return { 1,4 };
//		}
//		else if (x == 5)
//		{
//			return { 3,4 };
//		}
//		else
//		{
//			return { 4,6 };
//		}
//	}
//	else if (y == 2)
//	{
//		if (x == 2)
//		{
//			return { 1,5 };
//		}
//		else
//		{
//			return { 3,6 };
//		}
//	}
//	else if (y == 3)
//	{
//		if (x == 1)
//		{
//			return { 1,2 };
//		}
//		else if (x == 3)
//		{
//			return { 2,5 };
//		}
//		else if (x == 5)
//		{
//			return { 2,6 };
//		}
//		else
//		{
//			return { 2,3 };
//		}
//	}
//	else
//	{
//		return { 5,6 };
//	}
//
//	return { 0 };
//}
