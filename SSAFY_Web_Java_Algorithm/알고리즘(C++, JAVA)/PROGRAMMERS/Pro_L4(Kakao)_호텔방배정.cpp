//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//map<long long, long long> parent;
//
//long long getParent(long long findRoom)
//{
//	if (parent[findRoom] == 0)
//		return findRoom;
//	
//	return parent[findRoom] = getParent(parent[findRoom]);
//}
//
//vector<long long> solution(long long k, vector<long long> room_number) {
//	vector<long long> answer;
//	int len = room_number.size();
//	for (int i = 0; i < len; i++)
//	{
//		if (parent.find(room_number[i]) == parent.end()) // �θ� ���� �ȵ� ��, �� ����ִ� �� 
//		{
//			parent[room_number[i]] = room_number[i] + 1;
//			if(parent.find(room_number[i]+1) == parent.end())
//				parent[room_number[i] + 1] = 0;
//			answer.push_back(room_number[i]);
//		}
//		else // �θ� �ִ� ��
//		{
//			long long findRoom = getParent(room_number[i]);
//			parent[findRoom] = findRoom + 1;
//			if(parent.find(findRoom+1) == parent.end())
//				parent[findRoom + 1] = 0;
//			answer.push_back(findRoom);
//		}
//	}
//
//	return answer;
//}
//int main()
//{
//	long long k = 10;
//	vector<long long> room_number = { 1,3,4,1,3,1 };
//
//	vector<long long> result = solution(k, room_number);
//
//	for (auto a : result)
//	{
//		cout << a << " ";
//	}
//
//	return 0;
//}