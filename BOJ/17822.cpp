#include <bits/stdc++.h>

using namespace std;

int N, M, T;
vector<vector<int>> circle;

void rotate(int x, int d, int k) {
	if (d == 0) { // 시계방향
		for (int i = 0; i < k % M; ++i) {
			int tmp = circle[x][M - 1];
			for (int j = M - 1; j >= 1; --j) {
				circle[x][j] = circle[x][j - 1];
			}
			circle[x][0] = tmp;
		}
	}
	else if (d == 1) { //반시계방향
		for (int i = 0; i < k % M; ++i) {
			int tmp = circle[x][0];
			for (int j = 0; j < M - 1; ++j) {
				circle[x][j] = circle[x][j + 1];
			}
			circle[x][M - 1] = tmp;
		}
	}
}

void remove() {
	set<pair<int, int>> s;
	// 같은 원판에서 인접하면서 같은 수 찾기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			if (circle[i][j] != 0 && circle[i][j] == circle[i][j + 1]) {
				s.insert({ i, j });
				s.insert({ i, j + 1 });
			}
		}
		if (circle[i][0] != 0 && circle[i][0] == circle[i][M - 1]) {
			s.insert({ i, 0 });
			s.insert({ i, M - 1 });
		}
	}
	// 다른 원판에서 인접하면서 같은 수 찾기
	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < N - 1; ++i) {
			if (circle[i][j] != 0 && circle[i][j] == circle[i + 1][j]) {
				s.insert({ i, j });
				s.insert({ i + 1, j });
			}
		}
	}

	for (auto& p : s) {
		circle[p.first][p.second] = 0;
	}
	if (s.empty()) {
		double sum = 0, cnt = 0, avg;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (circle[i][j] != 0) {
					sum += circle[i][j];
					cnt++;
				}
			}
		}
		avg = sum / (double)cnt;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (circle[i][j] != 0) {
					if (circle[i][j] < avg) circle[i][j]++;
					else if (circle[i][j] > avg) circle[i][j]--;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) {
		vector<int> c;
		for (int j = 0; j < M; ++j) {
			int n; cin >> n;
			c.push_back(n);
		}
		circle.push_back(c);
	}
	for (int i = 0; i < T; ++i) {
		int x, d, k; cin >> x >> d >> k;
		for (int j = x - 1; j < N; j += x) {
			rotate(j, d, k);
		}

		remove();
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans += circle[i][j];
		}
	}

	cout << ans;

	return 0;
}