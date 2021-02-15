#include <bits/stdc++.h>

using namespace std;

bool cmp(const vector<int> a, const vector<int> b) {
	return a.size() < b.size();
}

vector<int> solution(string s) {
	int idx = 2;

	vector<vector<int>> tuples;
	//string�� Ʃ�� ������ �ڸ���
	for (int i = 1; i < s.length() - 1; ++i) {
		if (s[i] == '}') {
			string sub = s.substr(idx, i - idx);
			idx = i + 3;

			//','�� ���� string tokenizer
			stringstream ss(sub);
			string token;
			vector<int> res;
			while (getline(ss, token, ',')) {
				res.push_back(stoi(token));
			}

			tuples.push_back(res);
		}
	}

	//Ʃ���� ��� ���� ���� ������ ����
	sort(tuples.begin(), tuples.end(), cmp);

	vector<bool> isSelected(100001, false);
	vector<int> ans;
	//��� Ʃ�� Ž��
	for (int i = 0; i < tuples.size(); ++i) {
		for (int j = 0; j < tuples[i].size(); ++j) {
			//������ ���õ��� ���� ��� ��� �迭�� �ֱ�
			if (!isSelected[tuples[i][j]]) {
				isSelected[tuples[i][j]] = true;
				ans.push_back(tuples[i][j]);
			}
		}
	}

	return ans;
}