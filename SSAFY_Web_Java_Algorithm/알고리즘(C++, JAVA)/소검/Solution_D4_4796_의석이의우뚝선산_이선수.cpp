///* 1950~2120
//
//	1. 10�� 1��, 256MB
//	2. ������ ������ ���� ���� ���⼭ �����ϴ� ��� �� ���� '����'�� ������ ���ϴ°��̴�.
//
//	Ǯ�� : 
//	
//	�������� ������ ���� ū �ְ� ��һ��� ã�´�.
//	�׸��� ���� ���� ����� �ε����� ����
//	������ * ���������� ������ �� �� �ִ�.
//
//	����, �� ������ ���ο� �������� �Ǹ�, ��� ���� ã�´�. 
//
//	���ٺ��� �̰� �䰰��
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int height[50001];
//int N;
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> N;
//		for (int i = 1; i <= N; i++)
//			cin >> height[i];
//
//		int startIdx;
//		int endIdx;
//		int highestIdx;
//		startIdx = highestIdx = 1;
//		endIdx = 2;
//		int oldHeight;
//		oldHeight = height[startIdx];
//		bool isClimb = height[startIdx] < height[endIdx];
//		int answer = 0;
//		while (endIdx != N+1)
//		{
//			if (isClimb)
//			{
//				if (oldHeight < height[endIdx])
//				{
//					oldHeight = height[endIdx];
//					endIdx++;
//
//				}
//				else if (oldHeight > height[endIdx])
//				{
//					oldHeight = height[endIdx];
//					highestIdx = endIdx - 1;
//					endIdx++;
//					isClimb = false;
//				}
//			}
//			else
//			{
//				if (oldHeight > height[endIdx])
//				{
//					oldHeight = height[endIdx];
//					endIdx++;
//
//				}
//				else if (oldHeight < height[endIdx])
//				{
//					answer += (highestIdx - startIdx) * (endIdx - 1 - highestIdx);
//					startIdx = endIdx - 1;
//					endIdx = startIdx;
//					endIdx++;
//					isClimb = true;
//				}
//			}
//			if (!isClimb && endIdx == N + 1)
//			{
//				if (endIdx == N + 1)
//				{
//					answer += (highestIdx - startIdx) * (endIdx - 1 - highestIdx);
//				}
//			}
//		}
//		cout << "#" << t << " " << answer << endl;
//	}
//
//
//	return 0;
//}
//
///*
//1
//7
//9 7 2 4 5 3 1
//
//
//*/