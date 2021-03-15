#include <bits/stdc++.h>
#define MAX 17

using namespace std;

int N, ans;
int s[MAX][MAX], isSelected[MAX];

void solution() {
	ans = INT_MAX;

	do {
		vector<int> f1, f2;
		for (int i = 1; i <= N; ++i) {
			if (isSelected[i] == 1) f1.push_back(i);
			else if (isSelected[i] == 0) f2.push_back(i);
		}
		int res1 = 0, res2 = 0;
		for (int i = 0; i < f1.size(); ++i) {
			for (int j = i + 1; j < f1.size(); ++j) {
				res1 += (s[f1[i]][f1[j]] + s[f1[j]][f1[i]]);
			}
		}
		for (int i = 0; i < f2.size(); ++i) {
			for (int j = i + 1; j < f2.size(); ++j) {
				res2 += (s[f2[i]][f2[j]] + s[f2[j]][f2[i]]);
			}
		}
		ans = min(ans, abs(res1 - res2));
	} while (next_permutation(isSelected + 1, isSelected + N));
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> s[i][j];
			}
			if (i > N / 2) isSelected[i] = 1;
		}

		solution();

		cout << "#" << tc << " " << ans << "\n";
		memset(isSelected, 0, sizeof(isSelected));
	}

	return 0;
}