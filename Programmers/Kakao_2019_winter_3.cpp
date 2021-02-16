#include <bits/stdc++.h>

using namespace std;

vector<string> res[8]; //각 불량 사용자에 매핑되는 아이디 저장
set<set<string>> idList; //결과 아이디 목록 중복 방지
set<string> isSelected; //user_id 선택 중복 방지
int ans = 0;

void dfs(int idx, set<string> strs, int n) {
	if (idx == n) {
		if (idList.count(strs) == 0) {
			ans++;
			idList.insert(strs);
		}
		return;
	}
	for (int i = 0; i < res[idx].size(); ++i) {
		if (isSelected.count(res[idx][i]) == 0) {
			isSelected.insert(res[idx][i]);
			strs.insert(res[idx][i]);

			dfs(idx + 1, strs, n);

			isSelected.erase(res[idx][i]);
			strs.erase(res[idx][i]);
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int idx = 0;
	for (auto bid : banned_id) {
		for (auto uid : user_id) {
			if (bid.length() == uid.length()) {
				bool check = true;
				for (int i = 0; i < bid.length(); ++i) {
					if (bid[i] == '*')
						continue;
					if (bid[i] != uid[i]) {
						check = false;
						break;
					}
				}

				if (check) //불량 사용자에 매핑되는 경우
					res[idx].push_back(uid);
			}
		}
		idx++;
	}

	dfs(0, {}, banned_id.size());

	return ans;
}