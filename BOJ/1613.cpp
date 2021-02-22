#include <bits/stdc++.h>

using namespace std;

int n, k, s;
vector<vector<bool>> info(401, vector<bool>(401, false));

void solution() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i != j) {
					if (info[i][k] && info[k][j])
						info[i][j] = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		info[a][b] = true;
	}

	solution();

	cin >> s;
	for (int i = 0; i < s; ++i) {
		int a, b;
		cin >> a >> b;
		if (info[a][b]) cout << "-1\n";
		else if (info[b][a]) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}