///*1635~
//	1. N��, M��, H��
//	2. ���μ��� ������ �� ����.
//	3. i�� ���μ��� ����� i���� �����Բ��ϴ� ���μ� �ּ� ����
//	4. b�� ���μ��� b+1�� ���μ��� a�� ���� ��ġ���� �����ߴٴ� �ǹ�
//
//	Ǯ�̹��
//
//	��ȸ) int ladder[21][31], ladder[s][e], ladder[e][s] ������ ������ �ǹ��� �� �ִ� 1, -1�� �Է��Ѵ�.
//	���������� ��ȸ�ϸ� 0�� �ƴ� ���� �������� ��, ���� ���� �̵��ϵ���
//
//	�߰�) �ִ밡 ������ �����Ǿ� �ֱ⶧���� ��ġ�� 1,2,3������ �����غ��� �ȵɽÿ� �����ϸ� �ȴ�.
//	�׷��ٸ�, �ð����⵵�� ������� ��, �ִ�� �����ϰ�
//	1�� ���, 9*30 = 270
//	2�� ���, 270*269 = 72000
//	3�� ���, 270*269*268 = 19460000
//
//		�ٽ�) ������ ¦���� �������� �����ؾ� �Ѵ�. �׷� ��������� �ڱ����� ���ƿ��� ���ִ�.
//	�ʿ� ����
//	int[][] ���� (���� ����)
//
//	��ȸ�ϸ� 1)������ ���, 2) ���� ����, 3) ���� ������ ������ ��ġ�� ���, Ȯ��
//
//	������ 3���� ũ�� -1, �Ұ����ص� -1
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm> // ���ۻ��
//
//using namespace std;
//int X, lines, Y;
//int ladder[32][11]; // X�� 0~10(11��) Y�� 0~1~30~31 (32��) 
//bool isSuccess;
//int minimum = 5;
//
//bool searchLadder()
//{
//	//�������� 0,lineNum ���� �Ʒ��� Y�� �������� ��, lineNum, destNum ��
//	isSuccess = true;
//	bool isHorMove = false;
//	int curX;
//	for (int i = 1; i <= X; i++)
//	{
//		curX = i;
//		for (int j = 1; j <= Y; j++)
//		{
//			if (ladder[j][curX])
//				curX += 1;
//			else if (ladder[j][curX - 1])
//				curX -= 1;
//		}
//
//		if (curX != i)
//			return false;
//	}
//
//	return true;
//}
//void search(int cnt, int y) // �ִ밳���� �Ѵ��� Ȯ���� cnt, �������� �ľ��� y,x
//{
//	//��������
//	if (cnt > 3) // 3���� ���� �ʴ´� ������,
//		return;
//
//	if (searchLadder()) // ��ȸ // ���� ó���� ���μ� ���� ���¿����� ����
//	{
//		if (minimum > cnt)
//			minimum = cnt;
//		return;
//	}
//
//
//	for (int i = y; i <= Y; i++)
//	{
//		for (int j = 1; j <= X; j++)
//		{
//			if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j-1]) // ��ġ���� �ľ�
//				continue;
//			ladder[i][j] = true;
//			search(cnt + 1, i);
//			ladder[i][j] = false;
//		}
//	}
//
//}
//int main()
//{
//	cin >> X >> lines >> Y; // X ���� ���� ��
//	int a, b;
//	for (int i = 0; i < lines; i++)
//	{
//		cin >> a >> b;
//		ladder[a][b] = true;
//	}
//
//	search(0, 1);
//
//	if (minimum == 5)
//		cout << -1;
//	else
//		cout << minimum;
//
//	return 0;
//}
