//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int LR(string s, int& cur)
//{
//	int length = s.length();
//	int nextIdx = 0;
//	int tempCur = cur;
//	for (int i = tempCur + 1; i < length; i++)
//	{
//		if (s[i] != 'A')
//		{
//			nextIdx = i;
//			break;
//		}
//	}
//	cur = nextIdx;
//
//	if (nextIdx - tempCur < length - nextIdx + tempCur)
//	{
//		return nextIdx - tempCur ;
//	}
//	return length - nextIdx + tempCur ;
//}
//int UD(string s, int cur)
//{
//	if ((int)(s[cur] - 'A') <= 13)
//		return (int)(s[cur] - 'A'); //��
//	return (int)('Z' - s[cur]) + 1; //�ٿ�
//}
//
//int solution(string name) {
//	//���� ������������ �����͸� �ΰ� ���� ���ڱ����� �Ÿ��� ����ؼ� ����������� �����ϴ°� �����Ű���
//	//�Լ��� �ΰ��� �����ؼ� �Ұž�
//	int answer = 0;
//
//	int curIdx = 0;
//	int length = name.length();
//
//	int count = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if (name[i] != 'A')
//			count++;
//	}
//
//
//	while (count-- != 0)
//	{
//		answer += LR(name, curIdx);
//		answer += UD(name, curIdx);
//	}
//
//
//
//	return answer;
//}
//
//int main()
//{
//	string  s = "JEROEN";
//
//	cout << solution(s) << endl;
//}