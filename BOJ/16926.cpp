#include <bits/stdc++.h>

using namespace std;

int N, M, R, num;
int** arr;

void rotate() {
	int d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //현재 위치에 가져올 다음 인덱스를 위한 델타 값

	//(i, i)를 기준으로 회전시키기
	for (int i = 0; i < num; ++i) {
		int tmp = arr[i][i];

		int cnt = 0;
		int r = i, c = i;

		while (cnt < 4) { //방향이 4번 바뀔때까지
			int nr = r + d[cnt][0];
			int nc = c + d[cnt][1];

			//현재 레이어의 범위를 벗어나지 않는 경우
			if (nr >= i && nr < N - i && nc >= i && nc < M - i) {
				arr[r][c] = arr[nr][nc];
				r = nr;
				c = nc;
			}
			//범위를 벗어나면 방향 바꾸기
			else cnt++;
		}

		arr[i + 1][i] = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;
	arr = new int*[N];
	for (int i = 0; i < N; ++i) {
		arr[i] = new int[M];
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	num = min(N, M) / 2;

	for (int i = 0; i < R; ++i) {
		rotate();
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << arr[i][j] << " ";
		cout << "\n";
	}

	return 0;
}