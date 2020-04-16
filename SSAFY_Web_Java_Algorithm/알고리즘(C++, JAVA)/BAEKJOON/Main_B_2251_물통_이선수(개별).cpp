///* 1830~1900 + 2040~2055 => 30 + 15 = 45M
//	1. 2�� 128MB
//	2. ���ǰ� A, B, C(1��A, B, C��200) ������ �� ���� ����
//	3. �� �뷮�� ������������ �����Ѵ�.
//	4. �̶����� �� ������ ��ų�, �ٸ� �� ������ ���� �� ������ ���� ���� �� �ִ�.
//*/
//#include <iostream>
//#include <string>
//#include <set>
//
//using namespace std;
//
//int A, B, C;
//set<int> s;
//bool visit[201][201][201];
//
//void dfs(int a, int b, int c);
//int main()
//{
//	cin >> A >> B >> C;
//	dfs(0, 0, C);
//
//	set<int>::iterator it;
//	it = s.begin();
//	for (it; it != s.end(); it++)
//		cout << *it << " ";
//
//	return 0;
//}
//
//void dfs(int a, int b, int c)
//{
//	if (visit[a][b][c])
//		return;
//	visit[a][b][c] = true;
//	if (a == 0)
//		s.insert(c);
//
//	if (a != 0)
//	{
//		// a->b
//		if (a > B - b)
//			dfs(a - (B - b), B, c);
//		else
//			dfs(0, b + a, c);
//		// a->c
//		if (a > C - c)
//			dfs(a - (C - c), b, C);
//		else
//			dfs(0, b, c + a);
//	}
//	if (b != 0)
//	{
//		// b->a
//		if (b > A - a)
//			dfs(A, b - (A - a), c);
//		else
//			dfs(a + b, 0, c);
//		// b->c
//		if (b > C - c)
//			dfs(a, b - (C - c), C);
//		else
//			dfs(a, 0, c + b);
//	}
//	if (c != 0)
//	{
//		// c->a
//		if (c > A - a)
//			dfs(A, b, c - (A - a));
//		else
//			dfs(a + c, b, 0);
//		// c->b
//		if (c > B - b)
//			dfs(a, B, c - (B - b));
//		else
//			dfs(a, b + c, 0);
//	}
//}
