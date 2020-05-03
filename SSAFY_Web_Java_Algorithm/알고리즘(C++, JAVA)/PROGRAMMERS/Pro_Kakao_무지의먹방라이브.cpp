///*
//	1. ���� �� �����ؾ� �� ������ ���ٸ� -1�� ��ȯ�ϸ� �ȴ�.
//
//	ȿ���� �׽�Ʈ ���� ����
//	food_times �� ���̴� 1 �̻� 200,000 �����̴�.
//	food_times �� ���Ҵ� 1 �̻� 100,000,000 ������ �ڿ����̴�.
//	k�� 1 �̻� 2 x 10^13 ������ �ڿ����̴�.
//
//	�� ������ ��Ȯ���׽�Ʈ �����ؼ� �� ����Ѵ�. ȿ���� �׽�Ʈ�� �����̴�.
//
//	Ǯ��
//	1. struct ���µ� ���ķ��� �ε����� ���ο� ���Ϳ� ��´�.
//	2. �������� ������ �Ѵ�.
//	3. ������� �ּҰ��� ����� ���ؼ� �ð��� 1�ʾ��� �ƴ� �� ����Ŭ ������ ���ҽ�Ų��.
//	4. 3�� ������ �ش���� �ʾ��� ��, ���� ������ ������ ���Ϳ� ��� �ε��� ������ ���Ľ�Ų��.
//	5. ����, ���� �ð���ŭ ��ȸ�ϸ� ���� ���´�.
//
//	����, �ε��� ������� �������� �Լ��� �ʿ��ϴ�.
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Food {
//	int food;
//	int idx;
//
//	bool operator<(const Food &o) {
//		return food < o.food;
//	}
//};
//
//bool cmp(const Food &a, const Food &b)
//{
//	return a.idx < b.idx;
//}
//
//int solution(vector<int> food_times, long long k) {
//	int answer = 0;
//
//	vector<Food> foodIdxV;
//
//	int foodSize = food_times.size();
//	
//	for (int i = 0; i < foodSize; i++)
//	{
//		foodIdxV.push_back({ food_times[i], i });
//	}
//
//	sort(foodIdxV.begin(), foodIdxV.end()); // ���� ���ķ� ���� ����
//
//	long long totalMinus = 0;
//	long long time = k;
//	int i = 0;
//
//	for (; i < foodIdxV.size(); i++)
//	{
//		if ((foodIdxV[i].food-totalMinus) * foodSize <= time)
//		{
//			time -= (foodIdxV[i].food - totalMinus) * foodSize;
//			foodSize--;
//			totalMinus += foodIdxV[i].food - totalMinus;
//
//			if (foodSize == 0)
//				return -1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	vector<Food> idxFoodV;
//	for (int j = i; j < foodIdxV.size(); j++)
//	{
//		idxFoodV.push_back({ foodIdxV[j].food, foodIdxV[j].idx });
//	}
//
//	sort(idxFoodV.begin(), idxFoodV.end(), cmp);
//
//	int restSize = idxFoodV.size();
//
//	return idxFoodV[time % restSize].idx+1;
//
//}
//int main()
//{
//	vector<int> foodList = { 4, 3, 5, 6, 2 };
//	int k = 7;
//
//	cout << solution(foodList, k);
//
//	return 0;
//}