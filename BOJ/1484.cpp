#include <bits/stdc++.h>

using namespace std;

int main() {
	int G;
	cin >> G;

	vector<int> ans;
	int left = 1, right = 1;
	while ((left == 1 && right == 1) || left < right) { //조건 1 : 처음 while문 들어가야하기 때문
		int res = right * right - left * left;
		if (res == G) 
			ans.push_back(right);

		if (res > G) left++;
		else right++;
	}

	if (ans.empty()) {
		cout << "-1";
		return 0;
	}

	sort(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a << "\n";
	}

	return 0;
}