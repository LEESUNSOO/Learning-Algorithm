///*
//	1. �����
//	2. �ڱ���̳� ���ε����� ���
//	3. ��ó�� ������
//	4. �̵���� : ���� �÷� �Ӹ��� ��ĭ�� ��ġ��Ű�� ����� ������ ����� �������� �þ��� ��������
//	4-1, ���ٸ�, ������ �Ӹ���ġ�� �̵�
//
//	Q. �� �� ���⿡ ��ĭ�� �����µ�, �־��� ����(ȸ��) ������ �޾� ������ ���� �������� �����
//
//	Ǯ�̹��, 
//	���� ������ ������ �������� ���ʵ��� ���� ���ϰ� �����ϰ�, ��ȸ�� ��, +1, ��ȸ���� +3�ؼ� ������ �������ش�
//	��ͷ� Ǯ���̴�.
//	���� �ε����� ���� ����������, �� ���� �ε����� ��츦 ����ϱ� ���� ���� �� ���� �ִ� ��ġ�� ǥ���ؾ��Ѵ�.
//	�ϴ� visit������ �������µ�, ��.
//	���� ���̸� ����� ���� ���� �κ��� false ������� �Ѵ�.
//	Ư�� �������� ȸ���� �ϱ� ������ ���� ����;��ϴµ� �װ� ��� ���� �������.
//	1. ȸ�������� �������, Ư�� ���̿� �����ϸ� visit�� �ٽ� false �����ִ� �͵� �ٲ�����~?!?
//
//	���� ��ȯ Ƚ���� 100 �����̴ϱ�, ��ͷ� �ص� ũ�� ���� ���� �� ���δ�.
//
//*/
//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//struct command {
//	int second;
//	string rotate;
//};
//
//struct Pos {
//	int y;
//	int x;
//	int d;
//};
//
//int curBody[101][101];
//int apples[101][101];
//int N;
//int K; // ��� ����
//int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//bool isOver;
//int answer;
//int C; // command
//command cd[100];
//int cdSec;
//int cdIdx;
//bool isRotate;
//Pos tailPos;
//queue<Pos> curve;
//
//void input();
//void move(int y, int x, int d);
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	input();
//
//	tailPos.y = 1;
//	tailPos.x = 1;
//	tailPos.d = 0;
//	cdSec = cd[0].second;
//	answer = 0;
//	move(1, 1, 0); // 0,0 ��ġ���� ���������� 0 �ʷ� ����
//
//	cout << answer;
//	return 0;
//}
//void input()
//{
//	cin >> N >> K;
//	int y;
//	int x;
//
//	for (int i = 0; i < K; i++)
//	{
//		cin >> y >> x;
//		apples[y][x] = 1;
//	}
//
//	cin >> C;
//	for (int i = 0; i < C; i++)
//	{
//		cin >> cd[i].second;
//		cin >> cd[i].rotate;
//	}
//
//}
//void move(int y, int x, int d)
//{
//	if (isOver) // ��������
//		return;
//	
//	curBody[y][x] = true;
//	int _d = d;
//
//	if (answer == cdSec) // �����Ͽ� ȸ���ǵ���
//	{
//		if (cd[cdIdx].rotate == "D")
//		{
//			_d += 1;
//		}
//		else
//		{
//			_d += 3;
//		}
//		curve.push({ y,x,_d % 4 });
//		cdIdx += 1;
//		cdSec = cd[cdIdx].second;
//	}
//
//	_d %= 4;
//
//	int ny, nx;
//	ny = y + dir[_d][0];
//	nx = x + dir[_d][1];
//
//	if (curBody[ny][nx] || ny <= 0 || nx <= 0 || ny > N || nx > N)
//	{
//		isOver = true;
//		answer++;
//		return;
//	}
//	else if (apples[ny][nx] == 1)
//	{
//		apples[ny][nx] = 0;
//		answer++; // 1�� ����
//		move(ny, nx, _d);
//		if (isOver)
//			return;
//	}
//	else
//	{
//		int ey, ex;
//		int cy, cx;
//		ey = tailPos.y;
//		ex = tailPos.x;
//
//		curBody[ey][ex] = false;
//
//		if (!curve.empty())
//		{
//			cy = curve.front().y;
//			cx = curve.front().x;
//
//			//curBody[ey][ex] = false;
//
//			if (cy == ey && cx == ex) // Ŀ�������̸�
//			{
//				tailPos.y = ey + dir[curve.front().d][0];
//				tailPos.x = ex + dir[curve.front().d][1];
//				tailPos.d = curve.front().d;
//				curve.pop();
//			}
//			else
//			{
//				tailPos.y = ey + dir[tailPos.d][0];
//				tailPos.x = ex + dir[tailPos.d][1];
//			}
//		}
//		else
//		{
//			tailPos.y = ey + dir[tailPos.d][0];
//			tailPos.x = ex + dir[tailPos.d][1];
//		}
//		answer++; // 1�� ����
//		move(ny, nx, _d);
//		if (isOver)
//			return;
//	}
//	
//}