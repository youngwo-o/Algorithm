#include <bits/stdc++.h>
#define MAX 1500

using namespace std;

int R, C;
vector<string> arr;
vector<pair<int, int>> swan;
queue<pair<int, int>> water;
queue<pair<int, int>> q;
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int visited[MAX][MAX];

bool meet() {
	queue<pair<int, int>> nq;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = r + d[i][0];
			int nc = c + d[i][1];

			if (nr == swan[1].first && nc == swan[1].second) return true;

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;

			visited[nr][nc] = 1;
			//다음에 녹을 빙하 정보 저장 (백조가 움직일 수 있는 곳)
			if (arr[nr][nc] == 'X') {
				nq.push({ nr, nc });
				continue;
			}
			q.push({ nr, nc });
		}
	}

	q = nq;
	return false;
}

void melt() {
	int wSize = water.size();

	while (wSize--) {
		int r = water.front().first;
		int c = water.front().second;
		water.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = r + d[i][0];
			int nc = c + d[i][1];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

			if (arr[nr][nc] == 'X') { //물과 맞닿아있는 빙하라면
				arr[nr][nc] = '.';
				water.push({ nr ,nc });
			}
		}
	}
}

int solution() {
	int ans = 0;

	q.push(swan[0]);
	visited[swan[0].first][swan[0].second] = 1;

	while (1) {
		if (meet()) return ans;

		ans++;

		melt();
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		string s; cin >> s;
		arr.push_back(s);
		for (int j = 0; j < C; ++j) {
			if (arr[i][j] == 'L') {
				swan.push_back({ i,j });
				arr[i][j] = '.';
				water.push({ i, j });
			}
			else if (arr[i][j] == '.') water.push({ i,j });
		}
	}

	cout << solution();

	return 0;
}