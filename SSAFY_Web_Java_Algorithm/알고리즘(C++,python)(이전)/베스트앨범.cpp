#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, string>> mapToVec(map<string, int> BG)
{
	vector<pair<int, string>> VbestGenres;
	for (auto elem : BG)
	{
		VbestGenres.push_back(make_pair(elem.second, elem.first));
	}

	return VbestGenres;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> bestGenres;
	vector<pair<int, string>> VbestGenres;
	map<string, vector<pair<int, int>>> idxNplayOfGenres;
	vector<pair<int, int>> playsNIdx;

	for (int i = 0; i < genres.size(); i++)
	{
		if (bestGenres.find(genres[i]) != bestGenres.end())
		{
			bestGenres[genres[i]] += plays[i];
		}
		else
		{
			bestGenres.insert(make_pair(genres[i], plays[i]));
		}

		idxNplayOfGenres[genres[i]].push_back(make_pair(plays[i], i));
	}

	// ������� �帣�� �� �÷��� ���� �� �� �ִ�.
	// �̶� bestGenres�� sort�ϸ� key���� �������� ������ �Ǳ⶧���� value���� �������� �ϴ� sort�� �ʿ��ϴ�
	// ������ map�� vector�� �ű�� �۾��� ���ش�.

	VbestGenres = mapToVec(bestGenres);
	sort(VbestGenres.rbegin(), VbestGenres.rend());
	// ����Ʈ '�帣' ������ Ȯ���ƴ�.
	// �帣�� �ε����� �÷���Ƚ���� �ʿ��ѵ� �� �߿����� �÷��� Ƚ���� ���� ������ �־��� ���ڴ�

	for (auto elem : VbestGenres)
	{
		playsNIdx = idxNplayOfGenres[elem.second];
		sort(playsNIdx.rbegin(), playsNIdx.rend());
		
		for (int i = 0; i < playsNIdx.size(); i++)
		{
			if (i == 2)
				break;
			answer.push_back(playsNIdx[i].second);
		}

		if (playsNIdx[0].first == playsNIdx[1].first)
		{
			int temp = answer[answer.size() - 2];
			answer[answer.size() - 2] = answer[answer.size() - 1];
			answer[answer.size() - 1] = temp;
		}
	}
	return answer;
}

int main()
{
	vector<string> genres;
	vector<int> plays;
	
	genres.push_back("classic");   
	genres.push_back("pop");	
	genres.push_back("classic");
	genres.push_back("classic");
	genres.push_back("pop");	
	
	plays.push_back(800);          
	plays.push_back(600);		
	plays.push_back(150);		
	plays.push_back(800);		
	plays.push_back(2500);		

	vector<int> answer = solution(genres, plays);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

}