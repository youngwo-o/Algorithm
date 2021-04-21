#include <bits/stdc++.h>
#define MAX 50
#define pii pair<int,int>

using namespace std;

int N, M;
vector<vector<int>> arr(MAX, vector<int>(MAX));
vector<pii> virus;
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int ans = INT_MAX;

int spread() {
	vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
	queue<pii> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 3) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = r + d[i][0];
			int nc = c + d[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			if ((arr[nr][nc] == 0 || arr[nr][nc] == 2) && (visited[nr][nc] == 0 || visited[nr][nc] > visited[r][c] + 1)) {
				visited[nr][nc] = visited[r][c] + 1;
				q.push({ nr, nc });
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 0 && visited[i][j] == 0) return -1;
			else if(arr[i][j] == 0) res = max(res, visited[i][j] - 1);
		}
	}

	return res;
}

void selectVirus(int idx, int cnt) {
	int r = virus[idx].first;
	int c = virus[idx].second;

	arr[r][c] = 3; // 활성 바이러스로 만들기

	if (cnt == M) {
		int res = spread();
		if(res != -1) ans = min(ans, res);
		return;
	}

	for (int i = idx + 1; i < virus.size(); ++i) {
		selectVirus(i, cnt + 1);
		arr[virus[i].first][virus[i].second] = 2;
	}
}

void solution() {
	for (int i = 0; i < virus.size(); ++i) {
		selectVirus(i, 1);
		arr[virus[i].first][virus[i].second] = 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) virus.push_back({ i, j });
		}
	}

	solution();

	if (ans == INT_MAX) ans = -1;
	cout << ans;

	return 0;
}