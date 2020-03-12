///*2015~2035 20M
//	������� �� N�� 4�̻� 16������ ¦���̴�.
//	�������� ���� N / 2���� ������ �� ���� �丮
//	1) ����� 1�� ����� 2�� ���� �丮���� �� �߻��ϴ� �ó��� S12�� 5�̴�.
//	2) ����� 2�� ����� 1�� ���� �丮���� �� �߻��ϴ� �ó��� S21�� 4�̴�.
//
//	���� ������ 6���� 3��/3���� ������ 1,2,3/4,5,6 �̶�� �����ϸ�
//	12, 21, 13, 31, 23, 32 ��츦 ���ؾ� �Ѵ�.
//	Ǯ�� :
//	���۸� Ȱ���Ͽ� ���� ������ ���� ������ ����� ���� Ȯ���� ��,
//	������ ���ո��� ��� ����� ���� ���� ���� ���Ѵ�.
//	����, �ּҰ� �񱳸� ���� ����� ����.
//
//*/
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int N;
//vector<int> np;
//vector<int> A, B;
//int table[16][16];
//int minVal;
//void input();
//int foodSum(vector<int> food);
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//		minVal = 999999999;
//
//		do {
//			for (int i = 0; i < N; i++) // ���� ������,
//			{
//				if (np[i] == 0)
//					A.push_back(i);
//				else
//					B.push_back(i);
//			}
//			int a = foodSum(A);
//			int b = foodSum(B);
//
//			if (abs(a - b) < minVal)
//				minVal = abs(a - b);
//
//			A.clear();
//			B.clear();
//		} while (next_permutation(np.begin(), np.end()));
//
//		cout << "#" << t << " " << minVal << endl;
//		np.clear();
//	}
//	return 0;
//}
//
//void input()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> table[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (i < N / 2)
//			np.push_back(0);
//		else
//			np.push_back(1);
//	}
//}
//
//int foodSum(vector<int> food)
//{
//	int sum = 0;
//	for (int i = 0; i < N / 2; i++)
//	{
//		for (int j = 0; j < N / 2; j++)
//		{
//			if (i == j)
//				continue;
//			sum += table[food[i]][food[j]];
//		}
//	}
//	return sum;
//}
