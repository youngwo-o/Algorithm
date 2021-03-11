#include <bits/stdc++.h>

using namespace std;

int cost[4];
int plan[13];
int ans = INT_MAX;

void dfs(int m, int t, int res) {
	if (m > 12) {
		ans = min(ans, res);
		return;
	}

	int nextM;
	if (t == 0 || t == 1) nextM = m + 1;
	else if (t == 2) nextM = m + 3;
	else nextM = m + 12;

	int newRes = res;
	if (t == 0) newRes += (plan[m] * cost[t]);
	else newRes += cost[t];

 	for (int i = 0; i < 4; ++i) {
		dfs(nextM, i, newRes);
	}
}

void solution() {
	for (int i = 0; i < 4; ++i) { //이용권 종류
		dfs(1, i, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		for (int i = 0; i < 4; ++i) {
			cin >> cost[i];
		}
		for (int i = 1; i <= 12; ++i) {
			cin >> plan[i];
		}

		solution();
		cout << "#" << tc << " " << ans << "\n";

		ans = INT_MAX;
	}

	return 0;
}