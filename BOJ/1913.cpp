#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1000][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	int num = N * N;
	int d[4][2] = {{ 1, 0}, {0, 1} , {-1, 0} , {0, -1} };
	for (int i = 0; i < N / 2; ++i) {
		int cnt = 0;
		int r = i, c = i;

		while (cnt < 4) {
			if (arr[r][c] != 0) break;

			int nr = r + d[cnt][0];
			int nc = c + d[cnt][1];

			if (nr >= i && nr < N - i && nc >= i && nc < N - i) {
				arr[r][c] = num--;
				r = nr;
				c = nc;
			}
			else cnt++;
		}
	}
	arr[N / 2][N / 2] = 1;
	

	pair<int, int> ans;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << arr[i][j] << " ";
			if (arr[i][j] == K) ans = { i, j };
		}
		cout << "\n";
	}
	cout << ans.first + 1 << " " << ans.second + 1;
}