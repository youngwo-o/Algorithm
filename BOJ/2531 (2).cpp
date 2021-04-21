#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;
vector<int> belt;

int solution() {
	int left = 0, right = 0, cnt = 0, ans = 0;
	map<int,int> m;
	while (left <= right && right < N + k - 1) {
		if (cnt == k) {
			m[belt[left]]--;
			if (m[belt[left]] == 0) m.erase(belt[left]);
			left++;
			cnt--;
		}
		else if (cnt < k) {
			m[belt[right++]]++;
			cnt++;

			if (cnt == k) {
				int res = m.size();
				if (!m.count(c)) res++;
				ans = max(ans, res);
			}
		}
	}

	return ans;
}

int main() {
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; ++i) {
		int n; cin >> n;
		belt.push_back(n);
	}
	for (int i = 0; i < k - 1; ++i) {
		belt.push_back(belt[i]);
	}

	cout << solution();

	return 0;
}