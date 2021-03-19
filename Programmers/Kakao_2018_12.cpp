#include <bits/stdc++.h>

using namespace std;

int stringToTime(string s) {
	int h = stoi(s.substr(0, 2)) * 60;
	int m = stoi(s.substr(3, 2));
	return h + m;
}

string solution(string m, vector<string> musicinfos) {
	int maxPlayTime = 0;
	string ans = "";
	for (auto& info : musicinfos) {
		vector<string> res;
		stringstream ss(info);
		string token;
		while (getline(ss, token, ',')) { //','을 구분자로 string 나누기
			res.push_back(token);
		}

		int playTime = stringToTime(res[1]) - stringToTime(res[0]); //초단위로 바꿔서 재생시간 도출
		string melody = res[3], tmp = res[3];
		int cnt = 0;
		for (int i = 0; i < melody.size(); ++i) {
			if (melody[i] == '#') cnt++;
		}
		int melodyLen = melody.length() - cnt; //실제 음의 수

		string newMelody = "";
		if (playTime <= melodyLen) { //재생시간보다 멜로디 길이가 크거나 같은 경우
			cnt = 0;
			for (int i = 0; i < melody.length(); ++i) {
				if (cnt == playTime) break; //새로운 멜로디길이가 재생시간과 같아진 경우 끝내기
				if (i  + 1 != melody.size() && melody[i + 1] == '#') { //#이 붙은 음인 경우
					newMelody += melody.substr(i, 2); //하나의 음으로 처리
					i++;
				}
				else newMelody += melody[i];
				cnt++;
			}
		}
		else { //재생시간보다 멜로디 길이가 작은 경우
			int idx = 0;
			newMelody = melody; //현재 멜로디에 덧붙여야함
			while (melodyLen < playTime) { //새로운 멜로디 길이가 재생시간과 같아질때까지
				if (idx  + 1 != melody.size() && melody[idx + 1] == '#') { //#이 붙은 음인 경우
					newMelody += melody.substr(idx, 2); //하나의 음으로 처리
					idx++;
				}
				else newMelody += melody[idx];
				idx++;
				melodyLen++;
				if (idx >= melody.length()) idx = 0;
			}
		}

		int found = -1;
		while (1) { //새로운 멜로디에서 기억한 멜로디 찾기
			found = newMelody.find(m, found + 1);
			if (found == string::npos) break; //더 이상 기억한 멜로디와 같은 문자열이 없는 경우 끝내기
			else {
				if (newMelody[found + m.length()] != '#') { //조건 일치 (뒤에 #이 붙지 않은 경우)
					if (maxPlayTime < playTime) {
						maxPlayTime = playTime;
						ans = res[2];
					}
				}
			}
		}
	}

	if (ans.empty()) ans = "(None)";

	return ans;
}