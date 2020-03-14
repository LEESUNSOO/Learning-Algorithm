//#include <string>
//#include <vector>
//#include <iostream>
//#include <stack>
//
//
//using namespace std;
//
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//	vector<int> answer;
//	vector<int> prio;
//	stack<int> priStack;
//	float x;
//	for (int i = 0; i < progresses.size(); i++)
//	{
//		x = float(100 - progresses[i]) / speeds[i];
//		prio.push_back(x > (int)x ? x + 1 : x);
//	}
//
//	int temp = 0;
//	int count = 0;
//	for (int i = 1; i < prio.size(); i++)
//	{
//		count++;
//		if (prio[temp] < prio[i])
//		{
//			answer.push_back(count);
//			count = 0;
//			temp = i;
//		}
//	}
//
//	answer.push_back(++count);
//	return answer;
//}
//
//
//int main()
//{
//	/*	progresses	 speeds	    return
//		[93, 30, 55] [1, 30, 5] [2, 1]
//
//		����� �� ����
//		ù ��° ����� 93 % �Ϸ�Ǿ� �ְ� �Ϸ翡 1 % �� �۾��� �����ϹǷ� 7�ϰ� �۾� �� ������ �����մϴ�.
//		�� ��° ����� 30 % �� �Ϸ�Ǿ� �ְ� �Ϸ翡 30 % �� �۾��� �����ϹǷ� 3�ϰ� �۾� �� ������ �����մϴ�.������ ���� ù ��° ����� ���� �ϼ��� ���°� �ƴϱ� ������ ù ��° ����� �����Ǵ� 7��° �����˴ϴ�.
//		�� ��° ����� 55 % �� �Ϸ�Ǿ� �ְ� �Ϸ翡 5 % �� �۾��� �����ϹǷ� 9�ϰ� �۾� �� ������ �����մϴ�.
//
//		���� 7��°�� 2���� ���, 9��°�� 1���� ����� �����˴ϴ�.
//	*/
//
//	//	vector<int> progresses = { 93,30,55,40,80,10,60 };
//		//vector<int> speeds = { 1,30,5,40,2,60,4 };
//	vector<int> progresses = { 15, 1, 14, 9, 29, 25, 17, 24, 4, 27, 7, 19, 29, 14, 23, 4, 21, 3, 8, 14 };
//	vector<int> speeds = { 9, 11, 21, 16, 11, 21, 7, 5, 6, 30, 11, 24, 26, 18, 20, 18, 15, 30, 7, 18 };
//
//	for(int i = 0 ; i < solution(progresses, speeds).size() ;++i)
//		cout << solution(progresses, speeds)[i] << endl;
//
//	//solution(progresses, speeds);
//	return 0;
//
//}