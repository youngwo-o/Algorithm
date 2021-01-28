#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> infoMap;

void insert(string* key, int mask, int score) {
	string s = "";
	for (int i = 0; i < 4; ++i) {
		//비트마스크로 사람 정보 저장
		s += (mask & (1 << i)) ? "-" : key[i];
		//비트마스크에 해당하는 벡터에 점수 저장
		infoMap[s].push_back(score);
	}
}

vector<int> solution(vector<string> info, vector<string> query) {
	string key[4], tmp;
	int score;

	for (auto& in : info) {
		istringstream iss(in); //space 또는 tap으로 구분된 문자열 parsing
		iss >> key[0] >> key[1] >> key[2] >> key[3] >> score; // format에 맞게 각 변수에 저장

		//한명의 사람이 총 16개의 쿼리로 검색될 수 있음
		for (int i = 0; i < 16; ++i)
			insert(key, i, score);
	}

	//모든 점수 벡터 오름차순 정렬
	for (auto& m : infoMap)
		sort(m.second.begin(), m.second.end());

	vector<int> ans;
	for (auto& q : query) {
		istringstream iss(q);
		iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >> score;

		string str = key[0] + key[1] + key[2] + key[3];
		vector<int> res = infoMap[str];

		//벡터에 score가 없을 수 있으므로 score보다 크거나 같은 수사가 처음 나타나는 위치 찾기	
		int idx = res.end() - lower_bound(res.begin(), res.end(), score);
		ans.push_back(idx);
	}

	return ans;
}

int main() {
	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100", "python and frontend and - and - and 50" }; // { "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" };

	vector<int> ans = solution(info, query);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}

	return 0;
}