///* 0050~0250
//	1. 1�� 128MB
//	2.
//	�� Ÿ���� �ڿ��� �ϳ��� �����ϰ� �ִ�. 
//	�ڿ��� �� �ټ� ���� ������ ������, ����, ���, ���, �, �����̴�.
//	�� �ڿ��� 1���� 5���� ������ ��Ÿ�� �� �ִ�.
//	- ���ο� Ÿ���� '�̹�' ä���� ������ Ÿ�Ͽ� ����ִ� �ڿ��� �ٸ� �ڿ��̾�� �Ѵ�.
//	- ������ �ڿ��� ���� ������ ��쿡��, ���忡 ���� ���� ��Ÿ�� �ڿ��� �����Ѵ�.
//	- �׷��� ��쵵 ���� �������, ��ȣ�� ���� ���� �����Ѵ�.
//	�׽�Ʈ ���̽��� ���� c (1 �� c �� 200)
//	���� n�� �־�����. (1 �� n �� 10000)
//
//	n�� 10000�̸� �����ص� �� �� ������,
//	�������� �ϼ��Ǵ� ������ ������ ���� 3���̰�,
//	��ҿ��� 2���̴�.
//	����,
//	1, 1+6, 1+6+12 �� ���� ������, ���� ������ ����, ó��, �������� ������ ��ȣ�� �˻��ϸ� �ȴ�.
//	�Ӹ� �ƴ϶�, ������? ���� �κ��� �ƴ� �κе鵵 ���������� ��������.
//
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int catan[10001];
//int c;
//int cmd[200];
//int largeNum;
//int cnt[6]; // 1~5 Ƚ��,
//
//void input();
//int findNum(vector<int> van);
//int edge(int lineNum, int num);
//int main()
//{
//	input();
//	catan[1] = 1;	catan[2] = 2;	catan[3] = 3;	
//	catan[4] = 4;	catan[5] = 5;
//	catan[6] = 2;	catan[7] = 3;
//	// ������� �� �ζ���,
//	
//	// cnt ����
//	for (int i = 1; i <= 7; i++)
//	{
//		cnt[catan[i]]++;
//	}
//
//	int line = 2; // 1�� 0����,
//	int edgeNum = 1;
//	int curEdge = edge(line, edgeNum);
//	int back, oldCompare, oldCompareNext;
//	int oldLineFirst;
//	oldLineFirst = 2;
//	bool isNewLine = true;
//	for (int i = 8; i <= largeNum; i++) // 6���� �ִ� ��ȣ���� �ϼ��� ��,
//	{
//		if (isNewLine) // ó�� ���ο� ���� ��, ���� ��ȣ��, �� ���� ù ��ȣ ��
//		{
//			back = i-1;
//			oldCompare = oldLineFirst;
//			oldCompareNext = oldLineFirst;
//			catan[i] = findNum({ catan[back], catan[oldLineFirst] });
//			isNewLine = false;
//			oldLineFirst = i; // ���� ���� ���ο� �� �ʱ�ȭ
//		}
//		else
//		{
//			if (i == curEdge) // ���� �񱳹�ȣ, �� ��ȣ
//			{
//				if (edgeNum == 6)
//				{
//					back = i - 1;
//					oldCompare = oldCompareNext;
//					oldCompareNext = oldLineFirst;
//					catan[i] = findNum({ catan[back], catan[oldCompare], catan[oldCompareNext] });
//					line++;
//					edgeNum = 1;
//					curEdge = edge(line, edgeNum);
//					isNewLine = true;
//				}
//				else
//				{
//					back = i - 1;
//					oldCompare = oldCompareNext;
//					catan[i] = findNum({ catan[back], catan[oldCompare] });
//					edgeNum++;
//					curEdge = edge(line, edgeNum);
//				}
//			}
//			else // edge�� �ƴҶ�, 1) ���� ��ȣ, ���� �� ��ȣ, ���� �� ��ȣ ����
//			{
//				back = i - 1;
//				oldCompare = oldCompareNext;
//				oldCompareNext = oldCompare + 1;
//				catan[i] = findNum({ catan[back], catan[oldCompare], catan[oldCompareNext] });
//			}
//		}
//	}
//
//	for (int i = 0; i < c; i++) // �������,
//	{
//		cout << catan[cmd[i]] << endl;
//	}
//
//	return 0;
//}
//
//void input()
//{
//	cin >> c;
//	for (int i = 0; i < c; i++)
//	{
//		cin >> cmd[i];
//		if (cmd[i] > largeNum)
//			largeNum = cmd[i];
//	}
//}
//
//int findNum(vector<int> van)
//{
//	int minIdx;
//	int minVal = 999999999;
//
//	bool isAble;
//	for (int i = 1; i <= 5; i++)
//	{
//		isAble = true;
//
//		for (int j = 0; j < van.size(); j++)
//		{
//			if (i == van[j])
//			{
//				isAble = false;
//				break;
//			}
//		}
//		if (!isAble)
//			continue;
//		if (minVal > cnt[i])
//		{
//			minVal = cnt[i];
//			minIdx = i;
//		}
//	}
//
//	cnt[minIdx]++;
//	return minIdx;
//}
//
//int edge(int lineNum, int num)
//{
//	return 1 + 3* lineNum*(lineNum +1) - (6-num)*lineNum; // ��������
//}
