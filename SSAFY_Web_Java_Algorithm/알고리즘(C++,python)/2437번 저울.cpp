//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int chu[1001];
//int check[1001];
//
//int main()
//{
//	int num;
//	cin >> num;
//	int temp;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> temp;
//		chu[i] = temp;
//	}
//
//	sort(chu, chu + num);
//
//	int start = 1;
//	/*
//	 5 4 2 1
//	 8  
//	*/
//	int idx;
//	int tempstart;
//	while (1)
//	{
//		if (start == 4)
//		{
//			cout << "��";
//		}
//		tempstart = start;
//		while (1)
//		{
//			for (idx = 0; idx < num; idx++)
//			{
//				if (check[idx])
//					continue;
//				if (chu[idx] >= tempstart)
//				{
//					/*
//						���� ���� start���� �ϳ��� �ø��鼭 �迭���� �� ���ų� �������ڸ�
//						������ ���� ó���� ���ִµ� ���� ���ڸ� Ȱ���� �� �����ϱ�
//						check�� �־� ��µ� �׷����� 1 1 6 ���� ���,
//						6 ���� ���� ���� ��� 1�� ��� �����ڳ� check�� �������
//						�̰� ����
//					
//					*/
//					break;
//				}
//			}
//			tempstart -= chu[idx];
//			check[idx] = true;
//			if (tempstart < 0)
//			{
//				cout << start;
//				return 0;
//			}
//			if (tempstart == 0)
//				break;
//		}
//
//		start++;
//		for (int i = 0; i < num; i++)
//		{
//			check[i] = false;
//		}
//	}
//	
//	
//
//	return 0;
//}
