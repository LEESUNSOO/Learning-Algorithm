///* 1320~1400
//	1. 1�� 512MB
//	2. ���� �غ� ���Ӱ� �����
//	
//	Ǯ�� :
//	������ DFSó���ϰ�
//	���⿡ ���� �� ������ ������ϴµ� ��
//	deque�� �Ẹ����
//	0�϶�, �ڷ� �ְ�
//	0�� �ƴҶ�, front�� ���ؼ� 
//	������, front pop�ϰ� ���簪 * 2�ϰ� deque �ڿ� 0 �ϳ� �־��ְ�
//	�ٸ���, front pop�� �� ���� �ְ�, ���� �� �ְ�
//	���⼭ �ְ�� ������ index�� �ּ� ��(���⿡ ����)���� ���� ä����
//	���Ŀ�, deque�� ��� 0�� index���� ������ ä���ְ��ϸ� �ɵ�ʹ�.
//
//*/
//#include <iostream>
//#include <string>
//#include <deque>
//
//using namespace std;
//int N;
//int map[20][20];
//int maxVal;
//
//void input();
//void dfsDir(int dir, int cnt, int arr[][20]);
//void move(int dir, int src[][20], int des[][20]);
//int main()
//{
//	input();
//	for (int i = 0; i < 4; i++)
//	{
//		dfsDir(i, 1, map);
//	}
//
//	cout << maxVal;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//}
//
//void dfsDir(int dir, int cnt, int arr[][20])
//{
//	int temp[20][20];
//
//	move(dir, arr, temp);
//
//	if (cnt == 5)
//	{
//		int maxNum = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (temp[i][j] > maxNum)
//					maxNum = temp[i][j];
//			}
//		}
//		if (maxNum > maxVal)
//			maxVal = maxNum;
//		return;
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		dfsDir(i, cnt + 1, temp);
//	}
//}
//
//void move(int dir, int src[][20], int des[][20])
//{
//	deque<int> dq;
//	int emptyY;
//	int emptyX;
//	int curNum;
//	int frontNum;
//	switch (dir)
//	{
//	case 0: // ��
//
//		for (int x = 0; x < N; x++)
//		{
//			emptyY = 0;
//			for (int y = 0; y < N; y++)
//			{
//				curNum = src[y][x];
//				if (curNum == 0)
//				{
//					dq.push_back(curNum);
//				}
//				else
//				{
//					if (dq.empty())
//					{
//						dq.push_front(curNum);
//					}
//					else
//					{
//						frontNum = dq.front();
//						if (frontNum == 0)
//						{
//							dq.push_front(curNum);
//						}
//						else if (frontNum == curNum)
//						{
//							des[emptyY][x] = curNum * 2;
//							dq.pop_front();
//							dq.push_back(0);
//							emptyY++;
//						}
//						else
//						{
//							des[emptyY][x] = frontNum;
//							dq.pop_front();
//							emptyY++;
//							dq.push_front(curNum);
//						}
//					}
//				}
//			}
//			while (!dq.empty())
//			{
//				frontNum = dq.front();
//				des[emptyY][x] = frontNum;
//				dq.pop_front();
//				emptyY++;
//			}
//		}
//		break;
//	case 1: // ��
//
//		for (int x = 0; x < N; x++)
//		{
//			emptyY = N-1;
//			for (int y = N - 1; y>=0; y--)
//			{
//				curNum = src[y][x];
//				if (curNum == 0)
//				{
//					dq.push_back(curNum);
//				}
//				else
//				{
//					if (dq.empty())
//					{
//						dq.push_front(curNum);
//					}
//					else
//					{
//						frontNum = dq.front();
//						if (frontNum == 0)
//						{
//							dq.push_front(curNum);
//						}
//						else if (frontNum == curNum)
//						{
//							des[emptyY][x] = curNum * 2;
//							dq.pop_front();
//							dq.push_back(0);
//							emptyY--;
//						}
//						else
//						{
//							des[emptyY][x] = frontNum;
//							dq.pop_front();
//							emptyY--;
//							dq.push_front(curNum);
//						}
//					}
//				}
//			}
//			while (!dq.empty())
//			{
//				frontNum = dq.front();
//				des[emptyY][x] = frontNum;
//				dq.pop_front();
//				emptyY--;
//			}
//		}
//		break;
//	case 2: // ��
//
//		for (int y = 0; y < N; y++)
//		{
//			emptyX = 0;
//			for (int x = 0; x < N; x++)
//			{
//				curNum = src[y][x];
//				if (curNum == 0)
//				{
//					dq.push_back(curNum);
//				}
//				else
//				{
//					if (dq.empty())
//					{
//						dq.push_front(curNum);
//					}
//					else
//					{
//						frontNum = dq.front();
//						if (frontNum == 0)
//						{
//							dq.push_front(curNum);
//						}
//						else if (frontNum == curNum)
//						{
//							des[y][emptyX] = curNum * 2;
//							dq.pop_front();
//							dq.push_back(0);
//							emptyX++;
//						}
//						else
//						{
//							des[y][emptyX] = frontNum;
//							dq.pop_front();
//							emptyX++;
//							dq.push_front(curNum);
//						}
//					}
//				}
//			}
//			while (!dq.empty())
//			{
//				frontNum = dq.front();
//				des[y][emptyX] = frontNum;
//				dq.pop_front();
//				emptyX++;
//			}
//		}
//		break;
//	case 3: // ��
//
//		for (int y = 0; y < N; y++)
//		{
//			emptyX = N-1;
//			for (int x = N - 1; x >= 0; x--)
//			{
//				curNum = src[y][x];
//				if (curNum == 0)
//				{
//					dq.push_back(curNum);
//				}
//				else
//				{
//					if (dq.empty())
//					{
//						dq.push_front(curNum);
//					}
//					else
//					{
//						frontNum = dq.front();
//						if (frontNum == 0)
//						{
//							dq.push_front(curNum);
//						}
//						else if (frontNum == curNum)
//						{
//							des[y][emptyX] = curNum * 2;
//							dq.pop_front();
//							dq.push_back(0);
//							emptyX--;
//						}
//						else
//						{
//							des[y][emptyX] = frontNum;
//							dq.pop_front();
//							emptyX--;
//							dq.push_front(curNum);
//						}
//					}
//				}
//			}
//			while (!dq.empty())
//			{
//				frontNum = dq.front();
//				des[y][emptyX] = frontNum;
//				dq.pop_front();
//				emptyX--;
//			}
//		}
//		break;
//	}
//}
//
///*
//5
//2 2 2 4 32
//4 0 0 2 16
//0 2 2 2 8
//0 4 8 4 0
//4 0 0 8 8
//
//*/