#include <bits/stdc++.h>

using namespace std;

int N, M;
int info[501][501] = { 0 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		info[a][b] = 1;
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (info[i][k] && info[k][j])
					info[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int cnt = 0;
		for (int j = 1; j <= N; ++j) {
			if (!info[i][j] && !info[j][i]) cnt++;
		}

		if (cnt == 1) ans++;
	}
	cout << ans;

	return 0;
}