#include <bits/stdc++.h>
#define MAX 500

using namespace std;

int N;
int board[MAX][MAX];
int sum, r, c;
int d[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} }; //왼, 아, 오, 위
int dR[4][10] = { {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0},
				  {0, 1, 0, -1, 2, 1, 0, -1, 0, 1},
				  {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0},
				  {0, -1, 0, 1, -2, -1, 0, 1, 0, -1}
				};
int dC[4][10] = { {0, -1, 0, 1, -2, -1, 0, 1, 0, -1},
				  {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0},
				  {0, 1, 0, -1, 2, 1, 0, -1, 0, 1},
				  {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0}
				};
int per[9] = { 2, 10, 7, 1, 5, 10, 7, 1, 2 };

void spread(int r, int c, int d) {
	int sand = board[r][c];
	if (sand == 0) return;
	board[r][c] = 0;

	int movedSand = ((int)(sand * 0.02) + (int)(sand * 0.1) + (int)(sand * 0.07) + (int)(sand * 0.01)) * 2 + (int)(sand * 0.05);

	for (int i = 0; i < 9; ++i) {
		int nr = r + dR[d][i];
		int nc = c + dC[d][i];
		int add = (sand * per[i]) / 100;

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		else board[nr][nc] += add;
	}

	int nr = r + dR[d][9];
	int nc = c + dC[d][9];

	if (nr < 0 || nr >= N || nc < 0 || nc >= N);
	else board[nr][nc] += (sand - movedSand);
}

void move(int num) {
	if (num % 2 == 0) { // 짝수 -> 오른쪽, 위쪽
		for (int i = 2; i < 4; ++i) {
			int cnt = 0;
			while (cnt < num) {
				cnt++;
				int nr = r + d[i][0];
				int nc = c + d[i][1];

				spread(nr, nc, i);
				r = nr;
				c = nc;
			}
		}
	}
	else { //홀수 -> 왼쪽, 아래쪽
		for (int i = 0; i < 2; ++i) {
			int cnt = 0;
			while (cnt < num) {
				cnt++;
				int nr = r + d[i][0];
				int nc = c + d[i][1];

				spread(nr, nc, i);
				r = nr;
				c = nc;
			}
		}
	}
}

void solution() {
	int cnt = 0;
	r = N / 2, c = N / 2;
	while (++cnt < N) {
		move(cnt);
	}
	//맨 윗줄 이동
	for (int j = c - 1; j >= 0; --j) {
		spread(r, j, 0);
	}

	int nowSum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			nowSum += board[i][j];
		}
	}

	cout << sum - nowSum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			sum += board[i][j];
		}
	}

	solution();

	return 0;
}
