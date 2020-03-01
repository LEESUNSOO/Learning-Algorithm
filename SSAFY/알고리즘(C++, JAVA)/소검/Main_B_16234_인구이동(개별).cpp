/*

	1. N*N ������ ������ �� ������ �α� ���̰� L�̻� R�����̸� ���漱�� �����Ѵ�.
	2. ���ǿ� ���� ���漱�� �� �����ٸ� �α��̵��� �����Ѵ�.
	3. ������ �̷�� �ִ� �� ����� (������ �α��� / ���� ���� ) �� �ȴ�. �Ҽ����� ������(int)
	4. �� �̵������� ��� ���漱�� �ݴ´�.
	5. 1������ �ٽ� �����Ͽ� ���漱�� �ϳ��� ���žȵǴ� �� ���� �α��̵� ����?

	1. 1 <= N <= 50  1<= L <= R <= 100
	2. r = y , c = x

	# Ʋ�� Ǯ�� ��� (�ð��ʰ�)
	1. �α��� üũ�� ��� �� ����? => ����, ���� ��� ����
	2. ������ ��� �ľ��� ��? => bfs�� �湮ó���ϸ鼭 ��ǥ ���?
	3. while(true)
		{
			���漱 ���� (bool �迭)

			�α���üũ => ���漱 ��ȭ

			if(���漱üũ(���漱) == ���漱 x) (for bool �迭 ��ȸ)
				break;

			cnt ++;

			�����ľ� ( bfs�� ���պ� vector�� ��� )

			���պ� �α� ���� ( ���տ� �ش��ϴ� ������ �ο��� ����)
		}

	
	# �´� Ǯ�� ���

	1. ���� Ǯ�̹���� �� ��ȸ�� �� �����ߴ�. 50*50�̶�� �����ؼ� ������� ������ �־ ������������� �����ߴ�.
	2. ������, �ִ� 2,000���� �α��̵��� �����ϰ� L, R ���Ǻ�, �Һ��� �ʱ�ȭ �� ���귮�� �� ���Ұ� �ð��ʰ��� ����.
	3. ó�� Ǯ���Ϸ��� ����� �ܰ踦 ����ȭ�ؼ� DFS�� Ȱ���� ���漱�� ã��, BFS�� ���� ���� ������ �ľ��Ϸ��� �ߴ�.
	4. ������, ���������� �ľ��� ������ ���漱 �˻簡 �����Կ��� �ұ��ϰ� ���ʿ��� ��ȸ ������ �ø��� �ƴ�.
	5. ����, BFS�� Ȱ���ؼ� ���������� 2�� while�� ������ ��� ���� ������ �����Ϸ� �ؼ� ���� while������ ���ö����� ���Ӱ� ������ 
	pos�� ã�µ� �� ������ �߰��ƴ�. 
	6. �ᱹ, BFS�� �����ϴ� �ܰ迡�� visit ó���� �ϸ� (1), �� BFS���� ���Ž���� �ϱ⶧���� ���� �������� ����Ǵ� 2�� for���� Ȱ���Ͽ�
		�̹湮 ���¿����� BFS�� ������� newPos�� ���ϴ� ������ �����ߴ�.
	7. ���������� �α��̵��� �Ͼ�� �ʴ� ��� ������ �ܵ������� �� ���¿����� BFS�� �������� ����Ǵ� ���̾���.
	8. �� �κ��� �ؼ��ϱ� ���� ȣ��Ǵ� BFS�� Ƚ���� ���������� ���� Ȯ���ߴ�. BFS�� Ż�� ������ ���̻� ������ ������ ���� ����̹Ƿ�
	 BFS�� ����ȸ�ŭ ������ �������ٰ� ������ �� �ִ�.
	9. ����, ���������� ���� ���� ũ��(N x N)�� ������ ����, �α��̵��� �����ٰ� �ľ��� �� �ִ�.
	  
===============================================================================================
*/

#include <iostream>
#include <string>
#include <vector> // ���� ��ǥ ���
#include <queue> // bfs��

using namespace std;

int N, L, R;

int popul[51][51]; // 0 ~ 49
bool visit[51][51]; // 0 ~ 49
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int localsNum;

void bfs(int y, int x)
{
	localsNum++;
	queue<pair<int, int>> que;
	pair<int, int> tempPos;

	int cy, cx;
	cy = y;
	cx = x;

	int diff;
	int sumPopul;

	vector<pair<int, int>> pos;
	que.push(make_pair(cy, cx));
	sumPopul = 0;

	while (!que.empty())
	{
		tempPos = que.front();
		que.pop();
		cy = tempPos.first;
		cx = tempPos.second;

		if (visit[cy][cx])
			continue;
		visit[cy][cx] = true;

		sumPopul += popul[cy][cx];
		pos.push_back(make_pair(cy, cx));

		int ny, nx;
		for (int i = 0; i < 4; i++)
		{
			ny = cy + dir[i][0];
			nx = cx + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			diff = abs(popul[cy][cx] - popul[ny][nx]);
			if ((diff >= L && diff <= R) && !visit[ny][nx]) // ���� ����
				que.push(make_pair(ny, nx));
		}
	}

	// pos�� ��� ���� ���� �ο� ����
	int ava = sumPopul / pos.size();

	for (int i = 0; i < pos.size(); i++)
	{
		popul[pos[i].first][pos[i].second] = ava;
	}
}

void reset()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> popul[i][j];
		}
	}

	int cnt = 0;

	while (true)
	{
		reset(); // �湮, ���漱 ����

		localsNum = 0;
		for(int i = 0 ; i < N; i++)
			for(int j = 0 ; j < N; j++)
				if(!visit[i][j])
					bfs(i, j);

		if (localsNum == N*N)
		{
			cout << cnt;
			break;
		}
		cnt++;
	}



	return 0;
}
