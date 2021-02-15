#include <bits/stdc++.h>

using namespace std;

bool cmp(const vector<int> a, const vector<int> b) {
	return a.size() < b.size();
}

vector<int> solution(string s) {
	int idx = 2;

	vector<vector<int>> tuples;
	//string을 튜플 단위로 자르기
	for (int i = 1; i < s.length() - 1; ++i) {
		if (s[i] == '}') {
			string sub = s.substr(idx, i - idx);
			idx = i + 3;

			//','를 기준 string tokenizer
			stringstream ss(sub);
			string token;
			vector<int> res;
			while (getline(ss, token, ',')) {
				res.push_back(stoi(token));
			}

			tuples.push_back(res);
		}
	}

	//튜플의 요소 수가 적은 순으로 정렬
	sort(tuples.begin(), tuples.end(), cmp);

	vector<bool> isSelected(100001, false);
	vector<int> ans;
	//모든 튜플 탐색
	for (auto tup : tuples) {
		for (auto num : tup) {
			if (!isSelected[num]) {
				isSelected[num] = true;
				ans.push_back(num);
			}
		}
	}

	return ans;
}