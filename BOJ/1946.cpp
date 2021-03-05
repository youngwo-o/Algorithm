#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N;
vector<pair<int, int>> score(MAX);

void solution() {
	sort(score.begin(), score.begin() + N);
	int ans = 0, sMin = INT_MAX;
	for (int i = 0; i < N; ++i) {
		if (score[i].second < sMin) {
			ans++;
			sMin = score[i].second;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> score[i].first >> score[i].second;
		}

		solution();
	}

	return 0;
}