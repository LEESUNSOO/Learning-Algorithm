//#include <iostream>
//#include <string>
//
//using namespace std;
//int recurse( int n, int* memo)
//{
//	if (n < 0)
//		return 0;
//	else if (n == 0)
//		return 1;
//	else if (memo[n] > -1)
//	{
//		return memo[n];
//	}
//	else
//	{
//		memo[n] = recurse(n - 1, memo) + recurse(n - 2, memo) + recurse(n - 3, memo);
//		return memo[n];
//	}
//}
//
//int solution(int n)
//{
//	int answer;
//	
//	int* memo = new int[n + 1];
//	memset(memo, -1, sizeof(memo));
//
//	//for (int i = 0; i < n + 1; i++)
//		//memo[i] = -1;
//
//	answer = recurse(n, memo);
//
//	return answer;
//}
//
//
//int main()
//{
//	//� ���̰� n���� ����� ������, 1,2,3 ��ܾ� ������ �ִٸ� ����� ������ ����� ���������?
//
//	int n = 60;
//
//	cout << solution(n) << endl;
//
//
//
//
//	return 0;
//
//}