#include <bits/stdc++.h>
#define MAX 20

using namespace std;

int R, C, ans;
string board[MAX];
bool alpha[26];
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dfs(int r, int c, int cnt) {
	alpha[board[r][c] - 'A'] = true;

	ans = max(ans, cnt);

	for (int i = 0; i < 4; ++i) {
		int nr = r + d[i][0];
		int nc = c + d[i][1];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

		if (!alpha[board[nr][nc] - 'A']) {
			dfs(nr, nc, cnt + 1);
			alpha[board[nr][nc] - 'A'] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> board[i];
	}

	dfs(0, 0, 1);

	cout << ans;

	return 0;
}