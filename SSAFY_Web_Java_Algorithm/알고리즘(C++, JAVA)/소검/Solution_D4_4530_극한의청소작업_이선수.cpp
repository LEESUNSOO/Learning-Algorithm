///*
//	Ǯ��)
//	9������ȯ -> 10���� ��ȯ
//	�Ǽ��� ���Ҵ� �κ��� ������ ���� ���? �޶����� ������? ��ȣ? ���� ��������.
//
//	å������ ����ó�� Ǯ������ϴµ� ..ũ��..
//
//*/
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//long long from;
//long long to;
//long long change10to9to10(long long num);
//
//int main()
//{
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> from >> to;
//		
//		bool isSame = true;
//		if (from < 0 && to > 0)
//			isSame = false;
//	
//		from = abs(from);
//		to = abs(to);
//
//		from = change10to9to10(from);
//		to = change10to9to10(to);
//
//		if(isSame)
//			cout << "#" << t << " " << abs(to - from) << endl;
//		else
//			cout << "#" << t << " " << to + from - 1 << endl;
//
//	}
//
//}
//
//long long change10to9to10(long long num)
//{
//	long long n = num;
//	long long newNum = 0;
//	long long nineNum = 0;
//	while (n != 0)
//	{
//		int rest = n % 10;
//		n /= 10;
//		if (rest >= 4)
//			rest--;
//		newNum += rest * pow(9, nineNum);
//		nineNum++;
//	}
//
//	return newNum;
//}
