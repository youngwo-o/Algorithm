#include <bits/stdc++.h>

using namespace std;

vector<string> res[8]; //�� �ҷ� ����ڿ� ���εǴ� ���̵� ����
set<set<string>> idList; //��� ���̵� ��� �ߺ� ����
set<string> isSelected; //user_id ���� �ߺ� ����
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

				if (check) //�ҷ� ����ڿ� ���εǴ� ���
					res[idx].push_back(uid);
			}
		}
		idx++;
	}

	dfs(0, {}, banned_id.size());

	return ans;
}