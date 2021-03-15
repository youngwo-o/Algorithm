#include <bits/stdc++.h>

using namespace std;

int compress(int n, string s) {
	string new_s = "";

	string sub1 = s.substr(0, n);
	int cnt = 1;
	for (int i = n; i < s.size(); i += n) {
		string sub2 = s.substr(i, n);
		if (sub1 == sub2) cnt++;
		else {
			if (cnt > 1) new_s += (to_string(cnt) + sub1);
			else new_s += sub1;
			sub1 = sub2;
			cnt = 1;
		}
	}
	if (cnt > 1) new_s += (to_string(cnt) + sub1);
	else new_s += sub1;

	return new_s.size();
}

int solution(string s) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = s.size();
	for (int i = 1; i <= s.size() / 2; ++i) {
		ans = min(compress(i, s), ans);
	}

	return ans;
}