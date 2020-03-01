#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(int comNum, vector<bool>& check, vector<vector<int>> temp)
{
	if (check[comNum])
		return;
	check[comNum] = true;
	for (int i = 0; i < temp[comNum].size(); i++)
	{
		int NextComNum = temp[comNum][i];
		DFS(NextComNum, check, temp);
	}
}


int solution(int n, vector<vector<int>> computers) {
	
	int answer = 0;
	
	vector<vector<int>> temp;
	vector<int> miniTemp;

	vector<bool> check;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (computers[i][j] == 1)
				miniTemp.push_back(j);
		}
		temp.push_back(miniTemp);
		miniTemp.clear();
		check.push_back(false);
	}

	for (int i = 0; i < check.size(); i++)
	{
		if (!check[i])
		{
			DFS(i, check, temp);
			count++;
		}
	}

	answer = count;
	return answer;
}


int main()
{
	//Ǯ�� ����� ������ ���� �׷��������� �� �ʿ�������Ű���
	//�׸��� ������ 0,1�� �̷���� ��� true ,false �������ε� ��밡������ �������! �ڵ带 ���ϼ��ִ�.
	int n = 3;
	//vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };
	vector<vector<int>> computers = { {1,1,0},{1,1,1},{0,1,1} };

	cout << solution(n, computers) << endl;

	return 0;
}