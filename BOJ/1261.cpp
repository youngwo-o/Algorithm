#include <bits/stdc++.h>
#define MAX 100
using namespace std;

typedef struct _info {
	int r, c, cnt;
}Info;

struct compare {
	bool operator()(const Info& a, const Info& b) {
		return a.cnt > b.cnt;
	}
};

int N, M;
string arr[MAX];
int visited[MAX][MAX];
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void solution() {
	memset(visited, 0x3f, sizeof(visited));
	priority_queue<Info, vector<Info>, compare> pq;
	pq.push({ 0, 0, 0 });
	visited[0][0] = 0;

	while (!pq.empty()) {
		Info now = pq.top();
		pq.pop();

		if (now.cnt > visited[now.r][now.c]) continue;

		for (int i = 0; i < 4; ++i) {
			int nr = now.r + d[i][0];
			int nc = now.c + d[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			int nextCnt = now.cnt;
			if (arr[nr][nc] == '1') nextCnt++;

			if (visited[nr][nc] > nextCnt) {
				visited[nr][nc] = nextCnt;
				pq.push({ nr, nc, nextCnt });
			}
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	solution();

	cout << visited[N - 1][M - 1];

	return 0;
}