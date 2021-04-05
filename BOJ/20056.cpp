#include <bits/stdc++.h>
#define MAX 51

using namespace std;

typedef struct _fb {
	int m, s, d;
}FB;

int N, M, K;
vector<FB> arr[MAX][MAX];
vector<FB> newArr[MAX][MAX];
int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

void move(int r, int c, int m, int s, int d) {
	int nr = r + dir[d][0] * s;
	int nc = c + dir[d][1] * s;

	if (nc <= 0) {
		int addC = nc % N;
		nc = N + addC;
	}
	else if (nc > N) {
		nc = nc % N;
		if (nc == 0) nc = N;
	}

	if (nr <= 0) {
		int addR = nr % N;
		nr = N + addR;
	}
	else if (nr > N) {
		nr = nr % N;
		if (nr == 0) nr = N;
	}

	newArr[nr][nc].push_back({ m, s, d });
}

void copy() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			arr[i][j] = newArr[i][j];
			newArr[i][j].clear();
		}
	}
}

int solution() {
	while (K--) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				for (auto fb : arr[i][j]) {
					move(i, j, fb.m, fb.s, fb.d);
				}
			}
		}

		copy();

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (arr[i][j].size() >= 2) {
					int nSize = arr[i][j].size();
					int sumM = 0, sumS = 0, cntEvenD = 0, cntOddD = 0;
					for (FB fb : arr[i][j]) {
						sumM += fb.m;
						sumS += fb.s;
						fb.d % 2 == 0 ? cntEvenD++ : cntOddD++;
					}

					if (sumM / 5 == 0) {
						arr[i][j].clear();
						continue;
					}

					int k = 1;
					if ((cntEvenD + cntOddD == nSize) && (cntEvenD == 0 || cntOddD == 0)) k = 0;
					for (; k < 8; k += 2) newArr[i][j].push_back({ sumM / 5, sumS / nSize, k });
				}
				else newArr[i][j] = arr[i][j];
			}
		}

		copy();
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (FB fb : arr[i][j]) ans += fb.m;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		arr[r][c].push_back({ m, s, d });
	}

	cout << solution();

	return 0;
}