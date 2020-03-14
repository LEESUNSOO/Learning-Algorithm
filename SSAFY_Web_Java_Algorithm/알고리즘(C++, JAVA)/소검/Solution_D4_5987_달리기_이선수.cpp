#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

bool isChoiced[17]; // �� ���� ���迡 ���ؼ� �������� �� �ֳ�?
int position[17][17]; // [y][x] ����, y�� x���� �տ� �ִ� ���, 1 / �ݴ� ��� -1 / �𸣴� ��� 0
bool visit[17]; // dfs �������� ���õǾ�����?
ll dp[1 << 17]; // ����? ��ġ?�� �Ǿ��ִ� ��� ��츦 ���
int N, M;

void input();
void interPosition(int fix, int val); // ������ �־��� position ���� Ȱ���ؼ� �������� ���赵 �ľ��س���
ll dfs(int curPos, ll bitmask); // cur : 1~N��° ��, ��� ��ġ�� ��ġ �� ��, bitmask ��ġ ��� ���,
void reset();
int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		input();// ������� ����Ǹ� �־��� ���ǿ� ���ؼ��� ������ ������, 
				// ���� ��� 1->2 , 2->5 �� ���, 1->5 �� �����ϱ� ������
				// �� ���踦 ���� �Լ����� �������ش�.
		for (int i = 1; i <= N; i++)
		{
			interPosition(i, i); // ��� ��ȣ�� ���ؼ� �����غ��� ��, other�� �ϴ� ������� ���ڸ� �ְ�,
		}

		dfs(0, 0); //  ���� ä���� �ڸ��� ���⶧���� bitmask�� 0���� ����,

		cout << "#" << t << " " << dp[0] << endl;
		reset();
	}
}

void input()
{
	cin >> N >> M;
	int front, end;

	for (int i = 0; i < M; i++)
	{
		cin >> front >> end;
		position[front][end] = 1;  // �ռ��ٴ� ����
		position[end][front] = -1; // �������ٴ� ����
		isChoiced[front] = true;   // ���谡 �־����� ������ ���ǿ� �´� ��츸 ��ġ �� �� �ְ�,
		isChoiced[end] = true;	   // ���� ����
	}

	for (ll i = 0; i <= 1 << N; i++)
	{
		dp[i] = -1; // dp�� �湮�� ���� �ִ��� �ľ��ϱ� ���� 
	}
}

void interPosition(int fix, int val) // ó������ ������ �Ķ���ʹ� fix�� val�� ����. fix�� �� �Լ��� ȣ�� ������ fix�� ������ ���� ã�°��̰�,
{									 // val�� fix�� �����ִ� ���� ���� val���� �ֱ� ���ؼ��̴�. ���� ���, 1->2��� ���踦 ã������,									 // ����, 2�� ���踦 ���� ���� ã���� �ϱ� ������, fix�� ����, val�� �������̴�.
	for (int i = 1; i <= N; i++) // 1������ N������ ���踦 ���캸��
	{
		if (position[val][i] == 1) // fix(���� �˾ƺ����� ������)�� ���谡 �յ��� i�� ã�Ƽ�,
		{
			position[fix][i] = 1;  // ùȣ�⿡���� �̹� �ִ� ���� �������ϴ� ��������,
			position[i][fix] = -1; // ��Ͱ� ���������� ���ο� ���ǰ� �̷������.
			interPosition(fix, i);
		}
	}
}

ll dfs(int curPos, ll bitmask)
{
	// dp �� ���� üũ
	if (dp[bitmask] != -1)
		return dp[bitmask];

	// �������� üũ
	if (curPos == N && bitmask == (1 << N) - 1) // ��� ��ġ�� ���� Ž���� ������ && bitmask�� �� ä���� ���, 
	{										  // ���� ��� N�� 5��, bitmask�� 00011111 �� ��, ��� �ڸ��� ä������ ���̻� ���캼 �� ����.
		dp[bitmask] = 1;					  // �̶�, �� ������ ����� ���� �ϳ��̱⶧���� 1�ְ� ��ȯ�Ѵ�.
		return dp[bitmask];					  // DP�� ������ �����̶�� �� �� �ִ�.
	}

	// ������ ��� ���ǿ��� �ش����� �ʴ´ٸ�, ���ݺ��� �� ��ġ�� dp���� ���Ұ��̱� ������ ���� -1���� 0���� �ٲ��ش�.
	dp[bitmask] = 0;

	// �� ��ġ�� ��ġ�� �� ã��
	for (int i = 1; i <= N; i++)
	{
		if (visit[i]) // �̹� ��ġ�� ���Ե� ���¶�� ��ŵ
			continue;

		// ���� ������ ���� ���ڶ��, ���迩�θ� �ľ��غ���.

		if (isChoiced[i]) // ���谡 �ִ� ���ڶ��
		{
			bool isAble = true;
			for (int j = 1; j <= N; j++) // ��� ��ȣ�� ���踦 ���캸��.
			{
				if (visit[j]) // ��ġ�� �̹� �ִ� ���,
					continue;

				 // ���� ��ġ�� �ȵ� ��ȣ�� ���,
				if (position[j][i] == 1) // ���� ��ġ�� �ȵ� �ĺ� ��ȣ�� ���� ������ �տ� �ִ� ���谡 �ִٸ�,
				{
					isAble = false; // ���� ��ġ �� �� ����.
				}
			}

			if (isAble) // ���� ��ȣ�� ���Ͽ� ���ڸ��� �־ �Ǵ� �����,
			{

				visit[i] = true; // ��뵵 �ߴ�.										// ù ����Ŭ�̶�� �����Ѵٸ�, bitmask�� 0, �ʱ�����̰�
				dp[bitmask] += dfs(curPos + 1, bitmask | (1 << (i - 1)));			// �� ���¿��� (ù ��ġ�� 1�� �� ���) ���� ��ġ�� ���Ƿ� ��͸� ���°Ŵ�.
				visit[i] = false;													// ���� ���� ��ġ�� ������ curPos�� +1�� �����, 
																					// ������ ��Ʈ����ũ�� ��ȣ�� ���� ǥ�ø� ���ֱ� ���� | ������ ���ش�.																																				
			}
		}
		else // ���谡 ���� ���ڶ�� => ��𿡵� ��ġ�� �� �� �ִ�.
		{
			visit[i] = true; // �ռ� �˻縦 �� �ʿ���� �ٷ� �������ش�.
			dp[bitmask] += dfs(curPos + 1, bitmask | (1 << (i - 1)));
			visit[i] = false;
		}
	}

	return dp[bitmask];
}

void reset()
{
	for (int i = 0; i <= N; i++)
	{
		isChoiced[i] = false;
		visit[i] = false;
		for (int j = 0; j <= N; j++)
		{
			position[i][j] = 0;
		}
	}
}
