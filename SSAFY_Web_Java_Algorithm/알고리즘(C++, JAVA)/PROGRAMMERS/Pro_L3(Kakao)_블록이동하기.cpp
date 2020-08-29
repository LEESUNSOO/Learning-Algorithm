//
///* 14:05~14:40 - 1�� ����
//
//
//	Ǯ��
//	1. bfs�� ��������
//
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int map[101][101];
//bool visit[101][101][2];
//int minVal = 987654321;
//int N;
//int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//struct pos {
//	int y;
//	int x;
//	int state;
//
//};
//int bfs(int y, int x, int state) {
//
//	queue<pos> que;
//	visit[y][x][state] = true;
//	que.push({ y,x,state });
//
//	int curY, curX, curState;
//	int ny, nx;
//	int move = 0;
//	while (!que.empty()) {
//
//		int size = que.size();
//
//		while (size-- > 0)
//		{
//			curY = que.front().y;
//			curX = que.front().x;
//			curState = que.front().state;
//			que.pop();
//
//			if (curState == 0) {
//				if ((curY == N && curX == N) || (curY == N && curX + 1 == N))
//				{
//					return move;
//				}
//			}
//			else {
//				if ((curY == N && curX == N) || (curY+1 == N && curX == N))
//				{
//					return move;
//				}
//			}
//
//			if (curState == 0) { // ������ ��,
//
//					// ��
//				if (curX + 2 <= N && map[curY][curX + 2] == 0 && !visit[curY][curX + 1][0])
//				{
//					visit[curY][curX + 1][0] = true;
//					que.push({ curY,curX + 1, 0 });
//				}
//				// ��
//				if (curY + 1 <= N && map[curY + 1][curX] == 0 && map[curY + 1][curX + 1] == 0 && !visit[curY + 1][curX][0])
//				{
//					visit[curY + 1][curX][0] = true;
//					que.push({ curY + 1,curX, 0 });
//				}
//				// ��
//				if (curX - 1 > 0 && map[curY][curX - 1] == 0 && !visit[curY][curX - 1][0])
//				{
//					visit[curY][curX - 1][0] = true;
//					que.push({ curY,curX - 1, 0 });
//				}
//				// ��
//				if (curY - 1 > 0 && map[curY - 1][curX] == 0 && map[curY - 1][curX + 1] == 0 && !visit[curY - 1][curX][0])
//				{
//					visit[curY - 1][curX][0] = true;
//					que.push({ curY - 1,curX, 0 });
//				}
//
//				// ������ ����
//				// ���� ȸ��
//				if (curY - 1 > 0 && map[curY - 1][curX] == 0 && map[curY - 1][curX + 1] == 0 && !visit[curY - 1][curX + 1][1])
//				{
//					visit[curY - 1][curX + 1][1] = true;
//					que.push({ curY - 1,curX + 1, 1 });
//				}
//				// �Ʒ��� ȸ��
//				if (curY + 1 <= N && map[curY + 1][curX] == 0 && map[curY + 1][curX + 1] == 0 && !visit[curY][curX + 1][1])
//				{
//					visit[curY][curX + 1][1] = true;
//					que.push({ curY,curX + 1, 1 });
//				}
//
//				// ���� ����
//				// ���� ȸ��
//				if (curY - 1 > 0 && map[curY - 1][curX + 1] == 0 && map[curY - 1][curX] == 0 && !visit[curY - 1][curX][1])
//				{
//					visit[curY - 1][curX][1] = true;
//					que.push({ curY - 1,curX, 1 });
//				}
//				// �Ʒ��� ȸ��
//				if (curY + 1 <= N && map[curY + 1][curX + 1] == 0 && map[curY + 1][curX] == 0 && !visit[curY][curX][1])
//				{
//					visit[curY][curX][1] = true;
//					que.push({ curY,curX, 1 });
//				}
//
//			}
//			else { // ������ ��,
//				// ��
//				if (curX + 1 <= N && map[curY][curX + 1] == 0 && map[curY + 1][curX + 1] == 0 && !visit[curY][curX + 1][1])
//				{
//					visit[curY][curX + 1][1] = true;
//					que.push({ curY,curX + 1, 1 });
//				}
//				// ��
//				if (curY + 2 <= N && map[curY + 2][curX] == 0 && !visit[curY + 1][curX][1])
//				{
//					visit[curY + 1][curX][1] = true;
//					que.push({ curY + 1,curX, 1 });
//				}
//				// ��
//				if (curX - 1 > 0 && map[curY][curX - 1] == 0 && map[curY + 1][curX - 1] == 0 && !visit[curY][curX - 1][1])
//				{
//					visit[curY][curX - 1][1] = true;
//					que.push({ curY,curX - 1, 1 });
//				}
//				// ��
//				if (curY - 1 > 0 && map[curY - 1][curX] == 0 && !visit[curY - 1][curX][1])
//				{
//					visit[curY - 1][curX][1] = true;
//					que.push({ curY - 1,curX, 1 });
//				}
//
//				// ��� ����
//				// �·� ȸ��
//				if (curX - 1 > 0 && map[curY + 1][curX - 1] == 0 && map[curY][curX - 1] == 0 && !visit[curY][curX - 1][0])
//				{
//					visit[curY][curX - 1][0] = true;
//					que.push({ curY,curX - 1, 0 });
//				}
//				// ��� ȸ��
//				if (curX + 1 <= N && map[curY + 1][curX + 1] == 0 && map[curY][curX + 1] == 0 && !visit[curY][curX][0])
//				{
//					visit[curY][curX][0] = true;
//					que.push({ curY,curX, 0 });
//				}
//
//
//				// �ϴ� ����
//				// �·� ȸ��
//				if (curX - 1 > 0 && map[curY][curX - 1] == 0 && map[curY + 1][curX - 1] == 0 && !visit[curY + 1][curX - 1][0])
//				{
//					visit[curY + 1][curX - 1][0] = true;
//					que.push({ curY + 1,curX - 1, 0 });
//				}
//				// ��� ȸ��
//				if (curX + 1 <= N && map[curY][curX + 1] == 0 && map[curY + 1][curX + 1] == 0 && !visit[curY + 1][curX][0])
//				{
//					visit[curY + 1][curX][0] = true;
//					que.push({ curY + 1,curX, 0 });
//				}
//			}
//		}
//		
//		move++;
//
//	}
//	return move;
//
//}
//
//int solution(vector<vector<int>> board) {
//	int answer = 0;
//
//	N = board.size();
//
//	for (int i = 0; i < board.size(); i++) {
//		for (int j = 0; j < board[i].size(); j++)
//			map[i + 1][j + 1] = board[i][j];
//	}
//
//
//	answer = bfs(1,1,0);
//
//	return answer;
//}
//
//int main() {
//
//	vector < vector<int >> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0 } };
//	cout << solution(board) << endl;
//
//	return 0;
//}