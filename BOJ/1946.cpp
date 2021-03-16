#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N; cin >> N;
		vector<pair<int, int>> score;
		for (int i = 0; i < N; ++i) {
			int a, b; cin >> a >> b;
			score.push_back({ a, b });
		}
		sort(score.begin(), score.end());

		int ans = 0, maxS = INT_MAX;
		for (int i = 0; i < N; ++i) {
			if (maxS > score[i].second) {
				maxS = score[i].second;
				ans++;
			}
		}

		cout << ans << "\n";
	}
}