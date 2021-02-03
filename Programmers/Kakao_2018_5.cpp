#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringToTime(string s) {
	int res = 0;

	int h1 = (s[0] - '0') * 10;
	int h2 = s[1] - '0';
	res += (h1 + h2) * 60;

	int m1 = (s[3] - '0') * 10;
	int m2 = s[4] - '0';
	res += (m1 + m2);

	return res;
}

string timeToString(int t) {
	string res = "";

	int h = t / 60;
	int m = t % 60;

	res += ((h / 10) + '0');
	res += ((h % 10) + '0');
	res += ':';
	res += ((m / 10) + '0');
	res += ((m % 10) + '0');

	return res;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	vector<int> time;
	for (auto s : timetable) {
		//문자열을 분으로 변경
		//ex. "09:00" -> 540분
		int minute = stringToTime(s);

		time.push_back(minute);
	}
	//시간을 오름차순으로 정렬
	sort(time.begin(), time.end());

	int startTime = stringToTime("09:00");
	int endTime = startTime + ((n - 1) * t);

	int check, lastTime;
	//셔틀 운행 시간마다 탈 수 있는 사람의 수 탐색
	for (int i = startTime; i <= endTime; i += t) {
		//upper_bound val을 처음 초과하는 인덱스 리턴
		//현재 셔틀 운행 시간에 탈 수 있는 사람의 수
		int waitNum = upper_bound(time.begin(), time.end(), i) - time.begin();

		//현재 탈 사람의 수가 한 셔틀에 탈 수 있는 최대 크루 수보다 적은 경우
		//자리가 남는 경우
		if (waitNum < m) {
			check = 1;
			lastTime = i; //가장 마지막 셔틀 시간 저장
			time.erase(time.begin(), time.begin() + waitNum);
		}
		//현재 탈 사람의 수가 한 셔틀에 탈 수 있는 최대 크루 수와 같거나 더 큰 경우
		//자리가 남지 않는 경우
		else {
			check = 2;
			lastTime = time[m - 1]; //셔틀을 탄 마지막 사람의 시간 저장
			time.erase(time.begin(), time.begin() + m);
		}
	}

	int res;
	//자리가 남는 경우 -> 가장 마지막 셔틀 시간
	if (check == 1)
		res = lastTime;
	//자리가 남지 않는 경우 -> 셔틀을 탄 마지막 사람의 시간보다 1분 적은 시간
	else if (check == 2)
		res = lastTime - 1;

	answer = timeToString(res);

	return answer;
}