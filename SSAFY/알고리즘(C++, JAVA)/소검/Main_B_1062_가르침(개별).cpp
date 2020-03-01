	1. 1�� 128MB �����ϴ�
	2. 1 <= N <= 50 , 0 <= K <= 26

	Ǯ��:
	�⺻ antic -> �� �ټ����ڸ� �𸣸� ��� �ܾ �𸥴�
	=> K < 5 => 0��
	=> K == 5 => �ټ����� �ƴ� ���ڰ� �߰��� ������ => 0��
	=> K > 5 => �߰� ���ڵ��� �����ؾ��Ѵ�.
	=> ���ĺ��� �� 26�� �� �� antic �ټ��� �����ϸ� 21��
	������ ��찡 ���� ���� ���� K�� 16�� ��, �� 21���� 10���� �� ��,
	������ ������� ������ 21*20*19...*11 = 14,079,294,028,800 �׳� �ʰ�
	map�� Ȱ���ؼ� �ִ밪�� ���� ���ĺ����� ������� ó���ص� �ɵ�?
	�׷��� ���̸� ���� 15�� �ִ�� 21*20*19*18*17*16*15 => 586,051,200 �̴�.
	�̶�, ������ �����ϱ⿡ �ռ� map�� ���� ���� ū ���ڴ� �����ϴ� ������� ����ġ�⸦ �ϸ�
	���ɼ��� ���� ������? �ϴ� ��԰� ����
  ===...>>> ���� �ɷȴ�..���� ��Ž��
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
char frontEnd[5] = { 'a','n','t','i','c' }; // �⺻������ ��� �� �ֵ�
int answer;
int maxVal;

bool isLearned[26];
vector<string> words;

void input();
void dfs(int wp, int learnCnt);
int main()
{
	input();
	if (K < 0)
	{
		cout << 0;
		return 0;
	}
	else if (K == 21)
	{
		cout << N;
		return 0;
	}

	dfs(0, 0);
	cout << maxVal;
	

	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	string temp;
	for (int i = 0; i < N; i++) // �ܾ� ����
	{
		cin >> temp;
		words.push_back(temp);
	}

	K -= 5; // �⺻�ܾ� ����

	for (int i = 0; i < 5; i++)
	{
		isLearned[frontEnd[i] - 'a'] = true;
	}
}

void dfs(int wp, int learnCnt)
{
	if (learnCnt == K)
	{
		answer = 0;
		string temp;
		int len;
		int cnt;
		bool isFailed;
		for (int i = 0; i < words.size() ; i++)
		{
			
			temp = words[i];
			len = words[i].size();
			isFailed = false;
			for (int j = 0; j < len; j++)
			{
				if (!isLearned[temp[j] - 'a'])
				{
					isFailed = true;
					break;
				}
			}
			if (!isFailed)
				answer++;
		}
		if (maxVal < answer)
			maxVal = answer;

		return;
	}


	for (int i = wp; i < 26; i++)
	{
		if (isLearned[i])
			continue;

		isLearned[i] = true;
		dfs(i, learnCnt + 1);
		isLearned[i] = false;
	}

}


