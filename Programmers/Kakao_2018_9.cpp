#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;

	map<string, int> dic;
	int cnt = 1, idx = 1;

	for (char alpha = 'A'; alpha <= 'Z'; ++alpha) {
		string tmp = "";
		tmp = alpha;
		dic[tmp] = idx++;
	}

	for (int i = 0; i < msg.length();) {
		string w;
		int j;

		for (j = cnt; j > 0; --j) {
			w = msg.substr(i, j);

			if (dic[w] != 0) {
				answer.push_back(dic[w]);
				break;
			}
		}

		if (i + j <= msg.length()) {
			string wc = w + msg[i + j];
			cnt = max(cnt, (int)wc.length());
			dic[wc] = idx++;
		}

		i += j;
	}

	return answer;
}