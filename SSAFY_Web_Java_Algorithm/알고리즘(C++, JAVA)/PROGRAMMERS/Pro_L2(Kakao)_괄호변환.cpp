///* 15:23
//
//1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�. 
//2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�. ��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�. 
//3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�. 
//  3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�. 
//4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�. 
//  4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�. 
//  4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�. 
//  4-3. ')'�� �ٽ� ���Դϴ�. 
//  4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�. 
//  4-5. ������ ���ڿ��� ��ȯ�մϴ�.
//
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//string divide(string str) {
//
//	if (str.length() == 0)
//		return "";
//
//	string result = "";
//
//	int cnt = 0;
//	string pre, post;
//	int i;
//	bool isCorrect = true;
//
//	for (i = 0; i < str.length(); i++) {
//		if (str[i] == '(')
//			cnt++;
//		else
//			cnt--;
//		if (cnt == 0) {
//			pre = str.substr(0, i + 1);
//			break;
//		}
//		else if (cnt < 0)
//			isCorrect = false;
//	}
//
//	post = str.substr(i+1, -1);
//
//	if (isCorrect) {
//		return pre + divide(post);
//	}
//	else {
//		result += "(";
//		result += divide(post);
//		result += ")";
//		int len = pre.length();
//		pre = pre.substr(1, len - 2);
//		for (int i = 0; i < pre.length(); i++)
//		{
//			if (pre[i] == '(')
//				result += ')';
//			else
//				result += '(';
//		}
//	}
//
//	return result;
//}
//string solution(string p) {
//	string answer = "";
//
//	if (p.length() == 0)
//		return answer;
//
//	answer = divide(p);
//
//	return answer;
//}
//int main()
//{
//	string p = "()))((()";
//	cout << solution(p) << endl;
//	
//	return 0;
//}