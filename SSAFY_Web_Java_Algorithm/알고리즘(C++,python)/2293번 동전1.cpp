///* 
//
//	��ȭ�� ������ ���� ������ �ȳ��� ��Ÿ�Ϲ�����
//
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
///*
//���� k�� �ǵ��ϸ� ������
//Ƚ������ ����
//������ �ٸ����� ���� ���� ���
//�� ����� ����?
//*/
//
//int num, target;
//int coin[101];
//int cnt[100001];
//
//int sol()
//{
//	cnt[0] = 1;
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = coin[i]; j <= target; j++)
//		{
//			cnt[j] += cnt[j - coin[i]];
//		}
//	}
//
//	return cnt[target];
//}
//int main()
//{
//	//while(1)
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
