//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <string>
//#include <vector>
//
//using namespace std;
///*
//	�ϴ� stock < k ��, stock ���� ó������ ���ų� ���� dates�� supplies�� �޾ƾ��Ѵ�.
//	stock+= supplies�� �ǰ� �� �ٽ� stock < k ��, stock ���� ���ų� ó������ ���� dates�� supplies�� �޾ƾ��Ѵ�.
//
//	�ٽ��� ó������ �����ΰŰ��� // => �̰� Ʋ�Ⱦ�.. �� ������ �������ڰ� ���׿� ���ܼ� �̸� �޾Ƴ����ϴ� ��Ȳ���ִ�.
//
//	�켱���� ť�� ����? Ư���� ���ϴ� ���� ������� �����͵��� �����Ѵٴ°ž�
//
//	�� �������� ��� Ȱ���� �� ������?
//
//*/
//int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
//	int answer = 0;
//	priority_queue<int> pq;
//	int start = 0;
//
//	while (stock < k)
//	{
//		for (int i = start; i < dates.size(); i++)
//		{
//			if (dates[i] <= stock)
//			{
//				pq.push(supplies[i]);
//			}
//			else
//			{
//				start = i;
//				break;
//			}
//		}
//
//		stock += pq.top();
//		pq.pop();
//		answer++;
//	}
//
//	return answer;
//}
//
//int main()
//{
//	int stock = 4;
//	vector<int> dates =    { 4,5,6,7,8,9,10,11 }; // �̷� ��� 11�� ��� ��
//	vector<int> supplies = { 20,5,10,20,30,60,30,20 }; // ���� 3���ε� 5�����ð�?
//	int k = 100;
//	
//
//	cout << solution(stock, dates, supplies, k) << endl;
//
//	return 0;
//}