//#include <string>
//#include <vector>
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int solution(string arrangement) {
//	int answer = 0;
//	int temp = 0;
//	bool open = false;
//	queue<char> que;
//	for (int i = 0; i < arrangement.length(); i++)
//	{
//		que.push(arrangement[i]);
//	}
//	while (!que.empty())
//	{
//		switch (que.front())
//		{
//			case '(':
//				open = true;
//				temp += 1;
//				break;
//			case ')':
//				if (open)
//				{
//					temp -= 1;
//					answer += temp;
//				}
//				else
//				{
//					answer += 1;
//					temp -= 1;
//				}
//				open = false;
//				break;		
//		}
//		que.pop();
//	}
//	return answer;
//}
//
//int main()
//{
//	//Ʋ���� �ʾ����� ���� ť�� �� �ǹ̰� ������?
//	//������ Ȱ���ϸ� ������ ������ ��������� Ȱ���� �� �ִ�.
//	//�� �κ����� ��������!
//
//	string Q = "()(((()())(())()))(())";
//	cout << solution(Q) << endl;
//
//	return 0;
//
//}