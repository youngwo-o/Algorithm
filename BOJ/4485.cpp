#include <bits/stdc++.h>
#define MAX 125

using namespace std;

typedef struct jelda {
	int r, c, dist;
}Jelda;

struct compare {
	bool operator()(const Jelda& a, const Jelda& b) {
		return a.dist > b.dist;
	}
};

int N;
int arr[MAX][MAX], visited[MAX][MAX];
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void solution() {
	memset(visited, 0x3f, sizeof(visited));

	priority_queue<Jelda, vector<Jelda>, compare> pq;
	pq.push({ 0, 0, arr[0][0] });
	visited[0][0] = arr[0][0];

	while (!pq.empty()) {
		Jelda now = pq.top();
		pq.pop();

		if (visited[now.r][now.c] < now.dist) continue;

		for (int i = 0; i < 4; ++i) {
			int nr = now.r + d[i][0];
			int nc = now.c + d[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			int nextDist = now.dist + arr[nr][nc];
			if (visited[nr][nc] > nextDist) {
				visited[nr][nc] = nextDist;
				pq.push({ nr, nc, nextDist });
			}
		}
	}
}

int main() {
	int tc = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> arr[i][j];
			}
		}

		solution();

		cout << "Problem " << tc << ": " << visited[N - 1][N - 1] << "\n";
		tc++;
	}
}