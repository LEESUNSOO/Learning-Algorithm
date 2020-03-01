///* 1415~1430 + 1450~1630 + 2030~2100 = 15M+1H40M+30M = 2H25M
//	1. 0.5��, 512MB
//	2.	���ο� ������ ũ�Ⱑ N��N�� ü���ǿ��� ����ǰ�, ����ϴ� ���� ������ K���̴�.
//		���� ���Ǹ���̰�, �ϳ��� �� ���� �ٸ� ���� �ø� �� �ִ�.
//		ü������ �� ĭ�� ���, ������, �Ķ��� �� �ϳ��� ��ĥ�Ǿ��ִ�.
//	3. �� �� ���� 1�� ������ K�� ������ ������� �̵���Ű�� ���̴�.
//	4. ���� ����Ǵ� �߿� ���� 4�� �̻� ���̴� ���� ������ ����ȴ�.
//	5. ���� �̵� ���⿡ �ִ� ĭ�� ���� ���� �̵��� �ٸ��� �Ʒ��� ����.
//	 => ������ġ�� �ƴ� �̵��Ϸ��� ĭ�� ���� ���� �ٸ�
//
//	1) ���� ������ ��� ǥ������?
//	2) ���� ������ ������ �� ��� �� ������?
//	3) ���������� ����ؾ� �ð� ������ ����ұ�?
//	4) ���� �ִ� 10������ �Ѽ�Ʈ�� 4���̻�Ǹ� ������.
//
//	���� ����ü�� �����ϰ�, ����ü ���� deque�� ����
//	�Ϲ����� ���⿡���� push_back(pop_front)�� ���ְ�
//	������ ���⿡���� push_back(pop_back)
//	��ĭ ������ push_back(pop_back) // ������ que�� deque����
//
//*/
//#include <iostream>
//#include <string>
//#include <deque>
//#include <vector>
//
//using namespace std;
//struct unit {
//	deque<pair<int, int>> Ndir;
//	int y;
//	int x;
//	bool isActive;
//	unit() {}
//};
//
//int N, K;
//int map[13][13]; // (1,1)�� ����
//int curNum[13][13];
//int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} }; // ��, ��, ��, ��
//unit units[11];
//int turn;
//int answer;
//bool isFour;
//void input();
//void move();
//int dirChange(int d);
//int main()
//{
//	input();
//
//	while (true)
//	{
//		turn++;
//		if (turn > 1000)
//		{
//			answer = -1;
//			break;
//		}
//		move();
//		if (isFour)
//		{
//			answer = turn;
//			break;
//		}
//	}
//	cout << answer;
//	return 0;
//}
//
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	int d;
//	int y, x;
//	for (int k = 1; k <= K; k++)
//	{
//		cin >> y >> x;
//		units[k].y = y;
//		units[k].x = x;
//		cin >> d;
//		units[k].Ndir.push_back({ k,dirChange(d) });
//		curNum[y][x] = k;
//		units[k].isActive = true;
//	}
//}
//
//void move()
//{
//	int ny, nx;
//	int curY, curX;
//	int d;
//	for (int k = 1; k <= K; k++)
//	{
//		if (!units[k].isActive)
//			continue;
//		d = units[k].Ndir.front().second;
//		curY = units[k].y;
//		curX = units[k].x;
//
//		ny = curY + dir[d][0];
//		nx = curX + dir[d][1];
//
//		if (ny < 1 || nx < 1 || ny > N || nx > N || map[ny][nx] == 2) // ����ų� �Ķ����� ��,
//		{
//			ny = curY + dir[(d + 2) % 4][0];
//			nx = curX + dir[(d + 2) % 4][1];
//
//			if (ny < 1 || nx < 1 || ny > N || nx > N || map[ny][nx] == 2) // �Ǳ׷���
//			{
//				//int _dir = units[k].dir.front(); // ���⸸ ��ȯ
//				units[k].Ndir.pop_front();
//				units[k].Ndir.push_front({ k,(d + 2) % 4 });
//			}
//			else
//			{
//				//int _dir = units[k].dir.front(); // ���⸸ ��ȯ
//				units[k].Ndir.pop_front();
//				units[k].Ndir.push_front({ k,(d + 2) % 4 });
//				d = units[k].Ndir.front().second;
//
//				if (map[ny][nx] == 0)
//				{
//					if (curNum[ny][nx] == 0) //�ϰ͵� ���� ��
//					{
//						curNum[ny][nx] = k; // ��ȣ�̵�
//						curNum[curY][curX] = 0; // ������ġ ����
//						units[k].y = ny;
//						units[k].x = nx;
//					}
//					else // �ٸ� ����� ���� ��,
//					{
//						int old = curNum[ny][nx];
//						while (!units[k].Ndir.empty()) // ���̴� ��
//						{
//							int newDir = units[k].Ndir.front().second;
//							int newK = units[k].Ndir.front().first;
//							units[old].Ndir.push_back({ newK,newDir });
//							units[k].Ndir.pop_front();
//						}
//						curNum[curY][curX] = 0; // ������ġ ����
//						units[k].isActive = false;
//
//						if (units[old].Ndir.size() >= 4)
//							isFour = true;
//					}
//				}
//				else if (map[ny][nx] == 1)
//				{
//					if (curNum[ny][nx] == 0) //�ϰ͵� ���� ��
//					{
//						//curNum[ny][nx] = k; // ��ȣ�̵�
//						curNum[curY][curX] = 0; // ������ġ ����
//						units[k].y = ny;
//						units[k].x = nx;
//
//						deque<pair<int,int>> temp; //���� ������
//						while (!units[k].Ndir.empty())
//						{
//							int newDir = units[k].Ndir.back().second;
//							int newK = units[k].Ndir.back().first;
//							temp.push_back({ newK,newDir });
//							units[k].Ndir.pop_back();
//						}
//						units[k].Ndir = temp;
//
//						int curBottom = units[k].Ndir.front().first;
//						units[curBottom].Ndir = units[k].Ndir;
//						units[curBottom].y = units[k].y;
//						units[curBottom].x = units[k].x;
//						units[curBottom].isActive = true;
//						if(curBottom != k)
//							units[k].isActive = false;
//						curNum[ny][nx] = curBottom;
//					}
//					else // �ٸ� ����� ���� ��,
//					{
//						int old = curNum[ny][nx];
//						while (!units[k].Ndir.empty()) // ����� ���̴� ��
//						{
//							int newDir = units[k].Ndir.back().second;
//							int newK = units[k].Ndir.back().first;
//							units[old].Ndir.push_back({ newK,newDir });
//							units[k].Ndir.pop_back();
//						}
//						curNum[curY][curX] = 0; // ������ġ ����
//						units[k].isActive = false;
//
//						if (units[old].Ndir.size() >= 4)
//							isFour = true;
//					}
//				}
//			}
//		}
//		else
//		{
//			switch (map[ny][nx])
//			{
//			case 0: // ���
//				if (curNum[ny][nx] == 0) //�ϰ͵� ���� ��
//				{
//					curNum[ny][nx] = k; // ��ȣ�̵�
//					curNum[curY][curX] = 0; // ������ġ ����
//					units[k].y = ny;
//					units[k].x = nx;
//				}
//				else // �ٸ� ����� ���� ��,
//				{
//					int old = curNum[ny][nx];
//					while (!units[k].Ndir.empty()) // ���̴� ��
//					{
//						int newDir = units[k].Ndir.front().second;
//						int newK = units[k].Ndir.front().first;
//						units[old].Ndir.push_back({ newK,newDir });
//						units[k].Ndir.pop_front();
//					}
//					curNum[curY][curX] = 0; // ������ġ ����
//					units[k].isActive = false;
//
//					if (units[old].Ndir.size() >= 4)
//						isFour = true;
//				}
//				break;
//			case 1: // ������
//				if (curNum[ny][nx] == 0) //�ϰ͵� ���� ��
//				{
//					//curNum[ny][nx] = k; // ��ȣ�̵�
//					curNum[curY][curX] = 0; // ������ġ ����
//					units[k].y = ny;
//					units[k].x = nx;
//
//					deque<pair<int, int>> temp; //���� ������
//					while (!units[k].Ndir.empty())
//					{
//						int newDir = units[k].Ndir.back().second;
//						int newK = units[k].Ndir.back().first;
//						temp.push_back({ newK,newDir });
//						units[k].Ndir.pop_back();
//					}
//					units[k].Ndir = temp;
//
//					int curBottom = units[k].Ndir.front().first;
//					units[curBottom].Ndir = units[k].Ndir;
//					units[curBottom].y = units[k].y;
//					units[curBottom].x = units[k].x;
//					units[curBottom].isActive = true;
//					if (curBottom != k)
//						units[k].isActive = false;
//					curNum[ny][nx] = curBottom;
//				}
//				else // �ٸ� ����� ���� ��,
//				{
//					int old = curNum[ny][nx];
//					while (!units[k].Ndir.empty()) // ����� ���̴� ��
//					{
//						int newDir = units[k].Ndir.back().second;
//						int newK = units[k].Ndir.back().first;
//						units[old].Ndir.push_back({ newK,newDir });
//						units[k].Ndir.pop_back();
//					}
//					curNum[curY][curX] = 0; // ������ġ ����
//					units[k].isActive = false;
//
//					if (units[old].Ndir.size() >= 4)
//						isFour = true;
//				}
//				break;
//			}
//			if (isFour)
//				return;
//		}
//	}
//}
//
//int dirChange(int d)
//{
//	int dir;
//	switch (d)
//	{
//	case 1:
//		dir = 0;
//		break;
//	case 2:
//		dir = 2;
//		break;
//	case 3:
//		dir = 1;
//		break;
//	case 4:
//		dir = 3;
//		break;
//	}
//	return dir;
//}
//
///*
//4 1
//0 0 0 0
//0 2 1 2
//0 0 0 0
//0 0 0 0
//2 2 1
//
//4 1
//0 0 0 0
//0 0 1 2
//0 0 0 0
//0 0 0 0
//2 2 1
//
//4 4
//0 0 2 0
//0 0 1 0
//0 0 1 2
//0 2 0 0
//2 1 1
//3 2 3
//2 2 1
//4 1 2
//*/