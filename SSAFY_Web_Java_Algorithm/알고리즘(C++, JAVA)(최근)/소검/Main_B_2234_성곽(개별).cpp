/* 0010~0050
	1. 2�� 128MB
	2. ��Ʈ ������ ���� ������ �ľ�
	3. ���� �۵� ������ ���
	-> ���˻� -> ���� �˻� (�μ� ��)
	Ǯ�� :
	1. �� ���� �ִ� ���� ����
	 : visitó���ϸ鼭 ������ ���鼭 bfs ���ư� Ƚ�� ����
	2. ���� ���� ���� ����
	 : 1 �������� ���Ḷ�� ī��Ʈ vector�� ���� max_element ����
	3. ���μ��� �̵��ϱ� ���� ���� visit[n][m][2] (�μ�/����) ���� ī���� �ִ밪 ����
	=> �� �κ��� �߸��ƴ�. �μ��� ���� �˻��ϸ� �̵��ϴ� ���� ���� ������������ �ּҰ��� �϶���
	bfs�� �����ϸ鼭 ���������� �� ������ ���� ũ�⸦ ã�ƾ��ϱ⶧���� �� �� �μ��� ���� �� �� �μ��� ����
	���������� ���� �� ��� ũ���� �ִ밪�� ã�� �� ������.
	����, ���պ񽺹����ϰ� ���� �㹰�� �����ְ� �ݺ����ָ� 2������ ����� �Լ��� ��Ȱ���ߴ�.
	����, 2���� �ѹ��� �������� ���� ��ġ�� ���̾��� ����Ǳ� ������ visit�迭�� �ʱ�ȭ �� �ʿ������
	�� ���������� �� ���� �� ���� �㹰���� ��, ��ġ�� ���� ������ ���̹Ƿ� visit�� �� �˻縶�� �ʱ�ȭ�����.

	2,3 �� ���ÿ� �� �� �ִ°�?
	: �������� �ʴ´�.

*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct pos {
	int y;
	int x;
	pos(int Y = 0, int X = 0) :y(Y), x(X) {}
};
vector<int> roomSize;
vector<int> destroyRoomSize;

int bitMask[4] = { 1,2,4,8 }; // ��, ��, ��, ��
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
bool visitRoomCheck[50][50];
int map[50][50];
int M, N;

void input();
int roomCheck(int y, int x);
void destroyBfs();
void visitInit();
int main()
{
	input();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visitRoomCheck[i][j])
				continue;
			roomSize.push_back(roomCheck(i, j));
		}
	}
	destroyBfs();
	cout << roomSize.size() << endl;
	cout << *max_element(roomSize.begin(), roomSize.end()) << endl;
	cout << *max_element(destroyRoomSize.begin(), destroyRoomSize.end()) << endl;
	
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

int roomCheck(int y, int x)
{
	queue<pos> que;
	que.push({ y,x });
	visitRoomCheck[y][x] = true;

	pos cur;
	int curY, curX;
	int ny, nx;
	int cnt = 0;
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		curY = cur.y;
		curX = cur.x;
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			if (bitMask[i] & map[curY][curX])
				continue;
			ny = curY + dir[i][0];
			nx = curX + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visitRoomCheck[ny][nx])
				continue;
			que.push({ ny,nx });
			visitRoomCheck[ny][nx] = true;
		}
	}
	return cnt;
}

void destroyBfs()
{
	int ny, nx;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
				continue;
			for (int k = 0; k < 4; k++)
			{
				if (bitMask[k] & map[i][j])
				{
					ny = i + dir[k][0];
					nx = j + dir[k][1];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M)
						continue;
					visitInit();
					map[i][j] -= bitMask[k];
					destroyRoomSize.push_back(roomCheck(i, j));
					map[i][j] += bitMask[k];
				}
			}
		}
	}
}

void visitInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visitRoomCheck[i][j] = false;
		}
	}
}
