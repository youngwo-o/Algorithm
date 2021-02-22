#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> ans(101, vector<int>(101, 0));

void solution() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i != j) {
					int res1 = ans[i][k];
					int res2 = ans[k][j];
					if (res1 != 0 && res2 != 0) {
						if (ans[i][j] != 0)
							ans[i][j] = min(res1 + res2, ans[i][j]);
						else
							ans[i][j] = res1 + res2;
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (ans[a][b] != 0)
			ans[a][b] = min(ans[a][b], c);
		else 
			ans[a][b] = c;
	}

	solution();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}