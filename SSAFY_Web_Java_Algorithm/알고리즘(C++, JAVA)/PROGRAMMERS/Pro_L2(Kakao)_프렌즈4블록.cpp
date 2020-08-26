/* 22:24~
	1. �ѿ�ѿ��� ����
	2. �ִ������ 30*30�̱⶧���� ������ ��, ��, ������ �˻縦 �����Ѵٰ� ���� ��, ���귮�� ������ ���������� ���δ�. 

	Ǯ��
	1. ��, ��, ������ �˻縦 �ϸ� 4���� �����ϴ� ���, �ٸ� �迭�� trueó���� ���ش�. (�̹� true�� ���� ī������ ���� �ʴ´�.)
	2. �ı� �� �������� �����ϰ� �ռ� ������ �ݺ��Ѵ�.
	3. ������ ī��Ʈ�� ������ �����Ѵ�.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char map[31][31];
bool check[30][30];
int M, N;

void reset() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;
}

void move() {
	for (int i = M-1; i >=0; i--) {
		for (int j = N-1; j >=0; j--){
			if (check[i][j]) {
				vector<char> temp;

				for (int k = i; k >= 0; k--) {
					if (!check[k][j]) {
						temp.push_back(map[k][j]);
					}
					else {
						check[k][j] = false;
					}
					map[k][j] = ' ';
				}

				for (int k = 0; k < temp.size(); k++) {
					map[i - k][j] = temp[k];
				}

			}
		}
	}
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	M = m;
	N = n;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].length(); j++) {
			map[i][j] = board[i][j];
		}
	}

	int total = 0;
	int cnt;
	while (true) {
		cnt = 0;

		// 2*2 ã��
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == ' ') // ����ִ°��,
					continue;
				char curChar = map[i][j];
				if (map[i][j + 1] == curChar && map[i + 1][j] == curChar && map[i + 1][j + 1] == curChar) {
					
					for (int k = i; k < i + 2; k++) {
						for (int l = j; l < j + 2; l++) {
							if (check[k][l])
								continue;
							cnt++;
							check[k][l] = true;
						}
					}

				}

			}
		}
		if (cnt == 0)
			break;
		// �̵�
		move();

		reset();

		total += cnt;

	}
	answer = total;
	return answer;
}
int main()
{
	int m = 4;
	int n = 5;
	vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };

	cout << solution(m, n, board) << endl;
	return 0;
}