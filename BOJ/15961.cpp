#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;
vector<int> belt;
int num[3001];

int solution() {
	deque<int> dq;
	int cnt = 0, ans = 0;
	for (int i = 0; i < k; ++i) {
		dq.push_back(belt[i]);
		if (num[belt[i]] == 0) cnt++;
		num[belt[i]]++;
	}
	if (num[c] == 0) ans = max(ans, cnt + 1);
	else ans = max(ans, cnt);

	int left = 0, right = k;
	while (right < N + k - 1) {
		dq.pop_front();
		num[belt[left]]--;
		if (num[belt[left]] == 0) cnt--;
		left++;

		dq.push_back(belt[right]);
		if (num[belt[right]] == 0) cnt++;
		num[belt[right++]]++;
	
		if (num[c] == 0) ans = max(ans, cnt + 1);
		else ans = max(ans, cnt);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; ++i) {
		int b;
		cin >> b;
		belt.push_back(b);
	}
	for (int i = 0; i < k - 1; ++i) {
		belt.push_back(belt[i]);
	}

	cout << solution();

	return 0;
}