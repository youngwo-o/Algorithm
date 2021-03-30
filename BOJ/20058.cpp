#include <bits/stdc++.h>
#define MAX 64

using namespace std;

int N, Q;
int ice[MAX][MAX];
int d[4][2] = { {-1, 0,}, {1, 0}, {0, -1}, {0, 1} };
bool visited[MAX][MAX];
int sum = 0;

void rotate(int r, int c, int len) {
	int n = len / 2;
	for (int k = 0; k < n; ++k) { // 기준점 정하기 ex. (0,0), (1,1), ...
		vector<int> tmp1, tmp2;
		for (int j = 0; j < len; ++j) tmp1.push_back(ice[r + len - 1][c + j]); //아래쪽 레이어 저장
		for (int i = len - 1; i >= 0; --i) tmp2.push_back(ice[r + i][c + len - 1]); //오른쪽 레이어 저장
		for (int i = 0; i < len; ++i) ice[r + i][c + len - 1] = ice[r][c + i]; //위쪽 레이어를 오른쪽으로 이동
		for (int i = len - 1; i >= 0; --i) ice[r][c + i] = ice[r + len - i - 1][c]; //왼쪽 레이어를 위쪽으로 이동
		for (int i = 0; i < len; ++i) ice[r + i][c] = tmp1[i]; //아래쪽 레이어를 왼쪽으로 이동
		for (int j = 0; j < len; ++j) ice[r + len - 1][c + j] = tmp2[j]; //왼쪽 레이어를 아래쪽으로 이동

		r++; c++; len -= 2; //기준점 이동, len 2 감소
	}
}

void fire(int r, int c, int len) {
	for (int i = 0; i < N; i += len) { //len만큼 증가하면서 나눠지는 모든 부분 rotate
		for (int j = 0; j < N; j += len)
			rotate(i, j, len);
	}
}

void melt() {
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (ice[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0; k < 4; ++k) {
				int nr = i + d[k][0];
				int nc = j + d[k][1];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				if (ice[nr][nc] == 0) continue;
				cnt++;
			}
			if (cnt < 3) v.push_back({ i, j }); //녹는 경우 v에 저장해둠
		}
	}

	for (pair<int, int> p : v) { //녹는 부분 ice 갱신
		ice[p.first][p.second]--;
	}
}

int bfs(int r, int c) {
	queue<pair<int, int>> q;
	visited[r][c] = true;
	q.push({ r, c });

	int iceSize = 0;
	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();

		sum += ice[now.first][now.second];
		iceSize++;

		for (int i = 0; i < 4; ++i) {
			int nr = now.first + d[i][0];
			int nc = now.second + d[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
			
			if (ice[nr][nc] != 0) {
				visited[nr][nc] = true;
				q.push({ nr, nc });
			}
		}
	}

	return iceSize;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	N = (1 << N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> ice[i][j];
		}
	}

	for (int i = 0; i < Q; ++i) {
		int L; cin >> L;
		fire(0, 0, pow(2, L));
		melt();
	}

	int maxSize = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (ice[i][j] != 0 && !visited[i][j]) {
				int iceSize = bfs(i, j);
				maxSize = max(maxSize, iceSize);
			}
		}
	}

	cout << sum << "\n" << maxSize;
}