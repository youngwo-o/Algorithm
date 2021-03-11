#include <bits/stdc++.h>
#define MAX 1000
#define pii pair<int,int>

using namespace std;

int N, M;
vector<string> pool;
queue<pii> q;
int visited[MAX][MAX];
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int solution() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = r + d[i][0];
			int nc = c + d[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M || pool[nr][nc] == 'W') continue;

			if (visited[nr][nc] > visited[r][c] + 1) {
				visited[nr][nc] = visited[r][c] + 1;
				q.push({ nr, nc });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans += visited[i][j];
		}
	}
		
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;
		memset(visited, 0x3f, sizeof(visited));
		for (int i = 0; i < N; ++i) {
			string str; cin >> str;
			pool.push_back(str);
			for (int j = 0; j < M; ++j) {
				//물에서부터 사방으로 퍼져나가도록
				//땅에서부터 시작하면 시간초과!!
				if (pool[i][j] == 'W') {
					q.push({ i ,j });
					visited[i][j] = 0;
				}
			}
		}

		cout << "#" << tc << " " << solution() << "\n";

		pool.clear();
		while (!q.empty()) {
			q.pop();
		}
	}

	return 0;
}