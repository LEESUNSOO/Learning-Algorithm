//#include <string>
//#include <vector>
///*
//������ ��ȿ�������� Ǭ�� ���⵵�ϰ�
//���ٹ���� �¾����� Ǯ�̹��� �����ߴ� �� ����
//*/
//
//using namespace std;
//int N;
//vector<int> recursive(vector<int> v)
//{
//	N--;
//	if (N == 0)
//	{
//		return v;
//	}
//	vector<int> temp;
//	for (int i = 0; i < v.size(); i++)
//		temp.push_back(v[i]);
//
//	temp.push_back(0);
//
//	for (int i = v.size() - 1; i >= 0; i--)
//		temp.push_back(!v[i]);
//
//	return recursive(temp);
//
//}
//
//vector<int> solution(int n) {
//	vector<int> answer;
//	vector<int> first = { 0 };
//	N = n;
//	if (N == 1)
//	{
//		return first;
//	}
//	else
//	{
//		answer = recursive(first);
//	}
//
//	return answer;
//}