//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int c[50001];
//
//int solution(vector<int> people, int limit) {
//	int answer = 0;
//	int size = people.size();
//	sort(people.rbegin(), people.rend());
//	
//	int max = 0;
//	int idx = 0;
//	int temp = limit;
//	for (int i = 0; i < size; i++)
//	{
//		if (c[i]) continue;
//
//		temp -= people[i];
//		idx = i;
//		for (int j = size - 1; j > i; j--)
//		{
//			if (temp - people[j] >= 0 && !c[j])
//			{
//				max = people[j];
//				idx = j;
//			}
//			else if (temp - people[j] < 0)
//				break;
//		}
//
//		c[i] = true;
//		c[idx] = true;
//		answer++;
//		temp = limit;
//	}
//
//	return answer;
//}
//
//int main()
//{
//	vector<int> people = { 10,90,20,80};
//	// {30,30,30,40,70,100}
//	// 1, 2, 3��� �Ǵµ�
//	// 30���� �¿�� 
//	// 4�밡 �ʿ��ϴ�
//	// ���ſ�ֵ���� ó���ϴ°� �����ϴ�
//	int limit = 100;
//	//85879
//
//	cout << solution(people, limit) ;
//
//
//	//cout << solution(s) << endl;
//}