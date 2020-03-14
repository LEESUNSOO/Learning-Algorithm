/*1930~2000 + (drx vs grf) + 0015~0045 = 1H
	1. 2��, 128MB
	2. ���� �׽� ��, => �ʿ��� �� �˾Ҵµ� �ʿ����~!
	3. ���� Ÿ���� ���谡 ���� �� ���� �� �ְ�, ���� ���������̴�.
	4. �����̰� ���踦 ���ܳ��� �ٸ� ���� �����ϴ� ���谡 ���� ���� �ִ�.
	5. ����� ���� �� ����� �� �ִ�.
	6. ���� �ν��̰� �̷θ� Ż�� �� �� ������, -1�� ����Ѵ�.
	7. �ּ��̵� �� ���

	Ǯ�� :
	�ϴ� �̰� visit�迭�� ����غ����Ѵ�.
	���������θ� �������� ��, 
	visit �迭�� ����� ���踦 �ݰ� �ٽ� �Դ����� �ǵ��ư����� ���ٵ�
	�ִ�뷮�� 128�ΰɷ� ���� �װ� �ȵɵ�ʹ�.
	����, �� ���� ���� 3���� �迭 visit ������ �ʿ��� ���ϴ�.
	���, n,m�� �ִ� 50�̱⶧����
	visit[50][50][26] < 26�� ���ĺ� ����
	���踦 ���� �ִ� ���¿��� ���������� �ִ����� �ľ��ϴ� ���̴�.
	�׷��ٸ� ���� ���� ���θ� �ľ��ؾ��ϴµ�,
	�ν��̰� �� ���� �ִ��� �ٷ� �˻��ϴµ� �־ ���귮�� ���̷���
	map�� �����ҵ� �ϴ�.
	�׸��� 

	....1
	#A###
	0a..#
	.a...
	...#.
	�̷� ��츦 �����غ���.
	a�� �̹� �����ִµ� a�� ���°��� �ǹ̰� ������?
	���� ��Ȳ�� �����ϴ°��� �´�.

	#A###
	0a..#
	.a...
	#.###
	....1

	�̷� ��Ȳ�̶��, �������� ���, �ⱸ�� ã�� ���Ѵ�.
	���� �̵����ǿ��� ���� ����� ���Խ�Ű�� �ʴ´�.

	���� 1)
	f0.F..1
	�̷� ��Ȳ�� ���� ��ȹ�� �ɸ�����,
	����, ���谡 ��������� visitó���� ��� �� ���ΰ�?
	���� �ִ� ���� ���� ��� visit�� Ʈ���̸� �̵��Ұ�?
	��Ʈ����ŷ�� �Ẹ�°� ���? => X ȿ������ �� ������ ��Ʈ���굵 �ʿ�� �ȴ�. ����, �޸𸮺����� �߻��ϸ� �����غ����� ����

	int���� 32��Ʈ, 26���� ����ϸ�
	���� �ִ� ���� ��ȣ�� 1�� �����ִٰ�

	=> �ϴ� ��������ϰ� ����ͼ� ����!!

	������ �ٽú��� ����� ���� a~f�̱� ������ �ִ� ���� ��찡 64�����̴�.
	�׷��ٸ� visit[50][50][64]�� �����Ͽ�, 
	���� ������ ������ �����ص� �ɵ��ϴ�.
	a 1
	b 2
	c 4
	d 8
	e 16
	f 32

	ū Ʋ :
	- bfs�� �̵�
	- visit�� player�� ���� ���� ������ Ȯ���Ѵ�.
	- ���� �������� ��, 'C' - 'A' ���� �迭 �� {1,2,4,8,16,32}�� �����Ͽ�
	���� &������ ���� 1�� ������ ��� 0�̸� ����
	- key, door �� islower, isDigit���� �Ǻ�

*/


#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct pos {
	int y;
	int x;
	int key; // ������ ���� ���� ����
};

char map[50][50];
bool visit[50][50][64]; // 1~63
int bitNum[7] = { 1,2,4,8,16,32 };
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
pos player;

int N, M;

void input();
int bfs(pos p);

int main()
{
	input();
	cout << bfs(player);
	
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = temp[j];
			if (temp[j] == '0')
			{
				map[i][j] = '.';
				player.y = i;
				player.x = j;
				player.key = 0;
			}
		}
	}
}

int bfs(pos p)
{
	int dis = 0;
	queue<pos> que;
	que.push(p);
	visit[p.y][p.x][p.key] = true;
	int curY, curX, curKey;
	int ny, nx;
	while (!que.empty())
	{
		int size = que.size();

		while (size-- > 0)
		{
			pos cur = que.front();
			que.pop();
			curY = cur.y;
			curX = cur.x;
			curKey = cur.key;

			if (islower(map[curY][curX]))
			{
				if((curKey & bitNum[map[curY][curX] - 'a']) == 0)
					curKey += bitNum[map[curY][curX] - 'a'];
			}

			if (isdigit(map[curY][curX])) // 1 �߰�
			{
				return dis;
			}

			for (int i = 0; i < 4; i++)
			{
				ny = curY + dir[i][0];
				nx = curX + dir[i][1];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '#' || visit[ny][nx][curKey])
					continue;

				if (isupper(map[ny][nx]))
				{
					int keyNum = bitNum[map[ny][nx] - 'A'];
					if ((curKey&keyNum) != 0) // �����ϰ�������
					{
						que.push({ ny,nx,curKey });
						visit[ny][nx][curKey] = true;
					}
				}
				else
				{
					que.push({ ny,nx,curKey });
					visit[ny][nx][curKey] = true;
				}
			}
		}
		dis++;
	}
	return -1;
}
