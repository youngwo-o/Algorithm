#include <bits/stdc++.h>
#define MAX 21
#define pii pair<int,int>

using namespace std;

int N, M, F;
int board[MAX][MAX], dist[MAX][MAX];
vector<vector<int>> info;
bool isVisited[MAX * MAX];
pii taxi;
int d[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int bfs(pii start, pii dest) {
	memset(dist, 0, sizeof(dist));
	queue<pii> q;

	dist[start.first][start.second] = 1;
	q.push(start);

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		if (now == dest) return dist[now.first][now.second] - 1;

		for (int i = 0; i < 4; ++i) {
			int nr = now.first + d[i][0];
			int nc = now.second + d[i][1];

			if (nr <= 0 || nr > N || nc <= 0 || nc > N || dist[nr][nc]) continue;

			if (board[nr][nc] != 1) {
				q.push({ nr, nc });
				dist[nr][nc] = dist[now.first][now.second] + 1;
			}
		}
	}

	return -1;
}

int solution() {
	int cnt = 0;
	while (cnt < M) {
		int minLen = INT_MAX;
		pair<int, pii> dest;
		for (int i = 0; i < M; ++i) {
			if (!isVisited[i]) {
				pii next = { info[i][0], info[i][1] };
				int res = bfs(taxi, next);
				if (res == -1) continue;

				if (res < minLen) {
					minLen = res;
					dest = { i, next };
				}
				else if (res == minLen) {
					if (next.first < dest.second.first) dest = { i, next };
					else if (next.first == dest.second.first && next.second < dest.second.second) dest = { i, next };
				}
			}
		}
		F -= minLen;
		if (F < 0) return -1;
		taxi = dest.second;
		isVisited[dest.first] = true;

		pii next = { info[dest.first][2], info[dest.first][3] };
		minLen = bfs(taxi, next);
		if (minLen == -1) return -1;
		F -= minLen;
		if (F < 0) return -1;
		taxi = next;
		F += (minLen * 2);

		cnt++;
	}

	return F;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> F;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}
	cin >> taxi.first >> taxi.second;
	for (int i = 2; i < M + 2; ++i) {
		vector<int> tmp(4, 0);
		cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
		info.push_back(tmp);
	}

	cout << solution();

	return 0;
}