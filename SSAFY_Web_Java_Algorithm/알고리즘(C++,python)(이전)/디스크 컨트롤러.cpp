//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <string>
//#include <vector>
//#include <stack>
//#include <functional>
//
//using namespace std;
//
//
//
////struct pred
////{
////
////};
//
//bool operator<(vector<int> a, vector<int> b)
//{
//	return a[1] > b[1];
//}
//
//int solution(vector<vector<int>> jobs) {
//	int answer = 0;
//	int stayPoint = 0;
//	int vectorIdx = 0;
//	int restWork = 0;
//	int totalWork = 0;
//
//	sort(jobs.begin(), jobs.end());// , less<vector<int>>());
//	priority_queue <  vector<int>, vector<vector<int>> > pq;
//	
//
//	while (true)
//	{
//		while (vectorIdx != jobs.size())
//		{
//			if (jobs[vectorIdx][0] == stayPoint)
//			{
//				pq.push(jobs[vectorIdx]);
//				vectorIdx++;
//			}
//			else
//				break;
//		}
//
//		if (!pq.empty() && restWork <= 0)
//		{
//			restWork = pq.top()[1];
//			totalWork += pq.top()[1];
//			pq.pop();
//		}
//
//		restWork--;
//		totalWork += pq.size();
//		stayPoint++;
//		
//		if (restWork <= 0 && vectorIdx == jobs.size() && pq.empty())
//			break;
//	}
//
//	answer = totalWork / jobs.size();
//
//	return answer;
//}
//
//int main()
//{
//	/*
//		�������� ���� �۾����� �����ϰ� ������ ��ÿ� ���ԵǴ� �������� �۾����� ���� �۾�����
//		�����Ѵ�!
//		�ϴ� �׷��ٸ� ���߹��͸� ������������ �����Ѵ�. (������ �տ������� �˻��Ǿ��ϱ� ������!)
//		������, sort �� Ȱ���ϰ� ���������̱⶧���� less (�⺻��)���� �����Ѵ�.
//		less�� ������ a, b ���� a < b ��� bool ���� true�� ��ȯ�Ͽ� a�� ���� ���ڸ��� ��ġ�ϰ� �ϴ� ����̴�
//
//		���Ŀ� �������� �� ����Ŭ���� 1�������ϸ鼭 �ش� �������� ������ ������������ �������
//		�켱���� ť�� ����ش�
//		�Ҵ�� �۾����� ���������� �켱���� ť�� �˻��Ͽ� top�� �۾����� �ο��޴´�
//
//		���������� ���߹����� �˻��� ������, �ܿ� �۾����� 0�̰�, �켱���� ť�� empty�� ��� �ݺ��� ��ģ��
//
//
//
//	*/
//
//	vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };
//
//	cout << solution(jobs) << endl;
//
//	return 0;
//}