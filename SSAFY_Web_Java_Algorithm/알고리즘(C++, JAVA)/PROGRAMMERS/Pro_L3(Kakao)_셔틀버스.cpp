///* 20:12~
//
//	1. ��Ʋ�� 09:00���� �� nȸ t�� �������� ���� �����ϸ�, �ϳ��� ��Ʋ���� �ִ� m���� �°��� Ż �� �ִ�.
//	2. ��Ʋ�� �������� �� ������ ������ ��⿭�� �� ũ����� �����ؼ� ��� ������� �¿�� �ٷ� ����Ѵ�. 
//		���� ��� 09:00�� ������ ��Ʋ�� �ڸ��� �ִٸ� 09:00�� ���� �� ũ�絵 Ż �� �ִ�.
//
//		  
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int convertToNum(string time) {
//	int t = 0;
//
//	string h = time.substr(0, 2);
//	string m = time.substr(3);
//
//	int hour = stoi(h);
//	int min = stoi(m);
//
//	t = min + hour * 60;
//
//	return t;
//}
//string solution(int n, int t, int m, vector<string> timetable) {
//	string answer = "";
//
//	int cnt = 1;
//
//	vector<int> convertToInt;
//	for (auto t : timetable) {
//		convertToInt.push_back(convertToNum(t));
//	}
//
//	sort(convertToInt.begin(), convertToInt.end());
//	int result = 0;
//	int curTime = 60 * 9;
//	int restIdx = 0;
//	while (true) {
//		int rest = m;
//		if (cnt == n) {
//			if (convertToInt.size() - restIdx < m) {
//				result = curTime;
//				break;
//			}
//			for (int i = restIdx; i < convertToInt.size(); i++) {
//				if (curTime >= convertToInt[i]) // ����ð����� ���� �ֵ��̶��
//				{
//					restIdx++; // �¿�ɷ� �ϰ� �ε��� ����
//					rest--;
//					if (rest == 0) {
//						result = convertToInt[i] - 1;
//						break;
//					}
//				}
//				else {
//					result = curTime;
//					break;
//				}
//			}
//			break;
//		}
//		else {
//			for (int i = restIdx; i < convertToInt.size(); i++) {
//				if (curTime >= convertToInt[i]) // ����ð����� ���� �ֵ��̶��
//				{
//					restIdx++; // �¿�ɷ� �ϰ� �ε��� ����
//					rest--;
//					if (rest == 0) {
//						break;
//					}
//				}
//				else {
//					break;
//				}
//			}
//		}
//
//		curTime += t;
//		cnt++;
//	}
//	
//	int hour = result / 60;
//	int min = result % 60;
//
//	if (hour / 10 != 0) {
//		answer += to_string(hour);
//	}
//	else {
//		answer += "0"+ to_string(hour);
//	}
//	answer += ":";
//
//	if (min / 10 != 0) {
//		answer += to_string(min);
//	}
//	else {
//		answer += "0" + to_string(min);
//	}
//
//	return answer;
//}
//int main()
//{
//	int n = 1;
//	int t = 1;
//	int m = 5;
//
//	vector<string> timetable = { "08:00", "08:01","08:02","08:03" };
//	//vector<string> timetable = { "09:10", "09:09","08:00" };
//	//vector<string> timetable = { "09:00", "09:00","09:00","09:00"};
//	//vector<string> timetable = { "00:01",  "00:01",  "00:01",  "00:01",  "00:01"};
//	//vector<string> timetable = { "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59",  "23:59"};
//	
//	cout << solution(n, t, m, timetable);
//
//	return 0;
//}