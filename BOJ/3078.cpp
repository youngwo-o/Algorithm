#include <bits/stdc++.h>

using namespace std;

int N, K;
queue<int> q[21];
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;

		int len = s.length();

		while (!q[len].empty() && i - q[len].front() > K) {
			q[len].pop();
		}

		ans += q[len].size();
		q[len].push(i);
	}

	cout << ans;

	return 0;
}