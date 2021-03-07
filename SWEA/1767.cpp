#include <bits/stdc++.h>
#define MAX 13

using namespace std;

int N, maxCnt, ans = INT_MAX;
int arr[MAX][MAX];
vector<pair<int, int>> core;

int isAble(int idx, int d) {
	int r = core[idx].first;
	int c = core[idx].second;

	int cnt = 0;
	if (d == 0) {
		for (int j = c + 1; j < N; ++j) {
			if (arr[r][j]) return 0;
		}
		for (int j = c + 1; j < N; ++j) {
			cnt++;
			arr[r][j] = 2;
		}
	}
	else if (d == 1) {
		for (int j = c - 1; j >= 0; --j) {
			if (arr[r][j]) return 0;
		}
		for (int j = c - 1; j >= 0; --j) {
			cnt++;
			arr[r][j] = 2;
		}
	}
	else if (d == 2) {
		for (int i = r + 1; i < N; ++i) {
			if (arr[i][c]) return 0;
		}
		for (int i = r + 1; i < N; ++i) {
			cnt++;
			arr[i][c] = 2;
		}
	}
	else if (d == 3) {
		for (int i = r - 1; i >= 0; --i) {
			if (arr[i][c]) return 0;
		}
		for (int i = r - 1; i >= 0; --i) {
			cnt++;
			arr[i][c] = 2;
		}
	}

	return cnt;
}

void disconnect(int idx, int d) {
	int r = core[idx].first;
	int c = core[idx].second;

	if (d == 0) {
		for (int j = c + 1; j < N; ++j) {
			arr[r][j] = 0;
		}
	}
	else if (d == 1) {
		for (int j = c - 1; j >= 0; --j) {
			arr[r][j] = 0;
		}
	}
	else if (d == 2) {
		for (int i = r + 1; i < N; ++i) {
			arr[i][c] = 0;
		}
	}
	else if (d == 3) {
		for (int i = r - 1; i >= 0; --i) {
			arr[i][c] = 0;
		}
	}
}

void dfs(int idx, int resCnt, int resLen) {
	if (idx == core.size()) {
		if (resCnt > maxCnt) {
			maxCnt = resCnt;
			ans = resLen;
		}
		else if (resCnt == maxCnt)
			ans = min(ans, resLen);
		return;
	}

	for (int d = 0; d < 4; ++d) {
		int res = isAble(idx, d);
		if (res != 0) { //연결 가능한 경우
			dfs(idx + 1, resCnt + 1, resLen + res);
			disconnect(idx, d);
		}
	}

	dfs(idx + 1, resCnt, resLen); //연결 불가능 / 안하는 경우
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
			for (int j = 0; j < N; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					if (i == 0 || i == N - 1 || j == 0 || j == N - 1) maxCnt++;
					else core.push_back({ i, j });
				}
			}
		}

		dfs(0, maxCnt, 0);

		cout << "#" << tc << " " << ans << "\n";

		ans = INT_MAX;
		maxCnt = 0;
		core.clear();
	}
}