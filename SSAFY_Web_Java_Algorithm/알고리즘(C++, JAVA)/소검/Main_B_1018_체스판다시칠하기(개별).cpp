///*1950~2010
//
//	1. 2�� 128MB
//	2. 50������ ũ�⿡�� 8*8 ��ŭ �߶� ü���� ó�� ����� ���� ��ĥ�ؾ��ϴ� �ּҰ�?
//
//	Ǯ�� :
//	��Ž 
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//char map[50][50];
//int minVal = 999999999;
//int N, M;
//
//void input();
//void wbSearch();
//
//int main()
//{
//	input();
//	wbSearch();
//	cout << minVal;
//
//	return 0;
//}
//
//void input()
//{
//	cin >> N >> M;
//	string temp;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = temp[j];
//		}
//	}
//}
//
//void wbSearch()
//{
//	int cnt;
//	// �»��� W�̶��� ��,
//	for (int i = 0; i <= N - 8; i++)
//	{
//		for (int j = 0; j <= M - 8; j++)
//		{
//			cnt = 0;
//			for (int a = i; a < i + 8; a++)
//			{
//				for (int b = j; b < j + 8; b++)
//				{
//					if (a % 2 == 0)
//					{
//						if (b % 2 == 0)
//						{
//							if (map[a][b] != 'W')
//								cnt++;
//						}
//						else
//						{
//							if (map[a][b] != 'B')
//								cnt++;
//						}
//					}
//					else
//					{
//						if (b % 2 == 0)
//						{
//							if (map[a][b] != 'B')
//								cnt++;
//						}
//						else
//						{
//							if (map[a][b] != 'W')
//								cnt++;
//						}
//					}
//				}
//			}
//			if (minVal > cnt)
//				minVal = cnt;
//		}
//	}
//
//	// �»��� B�̶� �� ��,
//	for (int i = 0; i <= N - 8; i++)
//	{
//		for (int j = 0; j <= M - 8; j++)
//		{
//			cnt = 0;
//			for (int a = i; a < i + 8; a++)
//			{
//				for (int b = j; b < j + 8; b++)
//				{
//					if (a % 2 == 0)
//					{
//						if (b % 2 == 0)
//						{
//							if (map[a][b] != 'B')
//								cnt++;
//						}
//						else
//						{
//							if (map[a][b] != 'W')
//								cnt++;
//						}
//					}
//					else
//					{
//						if (b % 2 == 0)
//						{
//							if (map[a][b] != 'W')
//								cnt++;
//						}
//						else
//						{
//							if (map[a][b] != 'B')
//								cnt++;
//						}
//					}
//				}
//			}
//			if (minVal > cnt)
//				minVal = cnt;
//		}
//	}
//}
