//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//
//bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& temp, vector<string>& answer, int cnt) {
//
//	temp.push_back(from);
//
//	if (cnt == tickets.size())
//	{
//		answer = temp;
//		return true;
//	}
//
//	for (int i = 0; i < tickets.size(); i++)
//	{
//		if (tickets[i][0] == from && visit[i] == false)
//		{
//			visit[i] = true;
//
//			bool success = dfs(tickets[i][1], tickets, visit, temp, answer, cnt + 1);
//			if (success)
//				return true;
//			visit[i] = false;
//		}
//	}
//	temp.pop_back();
//	return false;
//}
//
//vector<string> solution(vector<vector<string>> tickets)
//{
//	vector<string> answer, temp;
//	vector<bool> visit(tickets.size(), false);
//
//	sort(tickets.begin(), tickets.end());
//	dfs("ICN", tickets, visit, temp, answer, 0);
//
//	return answer;
//}
//
//int main()
//{
//	/*
//	1->2
//	1->3
//	3->1
//	�̷� ��찡 �־����� 1->2�� ���� ���װ� 
//	������ �Ҵ´�.
//
//	*/
//	vector<vector<string>> tickets = { {"ICN","SFO"}, {"ICN","ATL"}, {"SFO","ATL"}, {"ATL", "ICN"}, {"ATL","SFO"} };
//
//	for (int i = 0; i < solution(tickets).size(); i++)
//		cout << solution(tickets)[i] << endl;
//
//	return 0;
//}