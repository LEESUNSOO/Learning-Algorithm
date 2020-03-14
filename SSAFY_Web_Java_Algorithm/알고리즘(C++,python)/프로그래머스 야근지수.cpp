//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
///* 
//���� ���Ƽ� ���� 15�и��� Ǭ ���ϴ�.
//������ �����Ǹ� ������ �°� ȿ������ ����ؾ� �ߴ�.
//works �迭�� ��簪�� �����ϸ� �ִ밪�� ���ҽ����ִ� ����� ������ڴ�
//n�� �ִ밪 * works�� �ִ���̸� ������� �� ȿ���� ������ �����ŷ� �ǴܵǾ���
//algorithm�� sort�� ��쿡�� ���귮�� �������� ������.
//����, ȿ������ ���İ� �ִ밪�� ã�� �� �ִ� ����� �����ϱ� �����ϴٰ�
//�켱����ť(max heap)�� ���ö� �����غð� ���� �������� ���!
//
//*/
//using namespace std;
//
//long long solution(int n, vector<int> works) {
//	long long answer = 0;
//	priority_queue<int> que;
//	int num = n;
//	for (int i = 0; i < works.size(); i++)
//	{
//		que.push(works[i]);
//	}
//
//	int temp = 0;
//
//	while (num != 0)
//	{
//		temp = que.top();
//		que.pop();
//		if (temp == 0)
//			return 0;
//		que.push(temp - 1);
//		num--;
//	}
//
//	long long sum = 0;
//	while (!que.empty())
//	{
//		sum += que.top() * que.top();
//		que.pop();
//	}
//
//	answer = sum;
//	return answer;
//}
//
//
//int main()
//{
//	vector<int> works = { 5};
//	int n = 3;
//	cout << solution(n, works) << endl;
//
//	return 0;
//}
