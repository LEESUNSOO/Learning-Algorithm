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
//vector<int> coin;
//int cnt[100001];
//
//int sol()
//{
//	int answer = 0;
//	int min;
//
//	for (int i = 1; i <= target; i++)
//	{
//		if (cnt[i])
//			continue;
//		vector<int> temp;
//		min = 100001;
//		for (int j = 0; j < num; j++)
//		{
//			if (i - coin[j] < 0 || !cnt[i-coin[j]] || !cnt[coin[j]])
//				break;
//			/*
//			3	4
//			3
//			5
//			7
//			*/
//			// i = 4 -> minsum[1] + minsum[3] = 0+1
//			if (min > cnt[i - coin[j]] + cnt[coin[j]])
//				min = cnt[i - coin[j]] + cnt[coin[j]];
//		}
//
//		if(min != 100001)
//			cnt[i] = min;
//	}
//
//	answer = cnt[target];
//	return answer == 0 ? -1 : answer;
//}
//int main()
//{
//	//while (1)
//	{
//		cin >> num >> target;
//		int temp;
//
//		for (int i = 0; i < num; i++)
//		{
//			cin >> temp;
//			coin.push_back(temp);
//			cnt[temp] = 1;
//		}
//		sort(coin.begin(), coin.end());
//		cout << sol();
//	}
//	return 0;
//}
