//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
///*
//������ ������ ���� �� �ִ�.
//������ Ƚ���� ���Ѿ���
//�ּ�ȸ���� �����ϴ� �� ã�ƶ�
//�ȵɽÿ� -1 ���
//����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.
//*/
//int num;
//int target;
//int coin[101];
//int cnt[100001];
//
//int sol()
//{
//	int answer = 0;
//
//	for (int i = 1; i <= target; i++)
//		cnt[i] = 100001;
//	cnt[0] = 0;
//
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = coin[i]; j <= target; j++)
//		{
//			cnt[j] = min(cnt[j], cnt[j - coin[i]] + 1);
//		}
//	}
//	if (cnt[target] == 100001) cnt[target] = -1;
//
//	return cnt[target];
//}
//int main()
//{
//	//while (1)
//	{
//		cin >> num >> target;
//		int temp;
//
//		for (int i = 1; i <= num; i++)
//		{
//			cin >> temp;
//			coin[i] = temp;
//		}
//		cout << sol();
//	}
//	return 0;
//}
