#include <bits/stdc++.h>
#define MAX 10

using namespace std;

int arr[MAX][MAX];

void solution(int N) {
	int r = 0, c = -1, d = 1;
	int cnt = 1;

	while (N > 0) {
		for (int i = 0; i < N; ++i) {
			c += d;
			arr[r][c] = cnt++;
		}
		N--;
		for (int j = 0; j < N; ++j) {
			r += d;
			arr[r][c] = cnt++;
		}

		d *= -1;
	}
}

void print(int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N;  cin >> N;
		solution(N);
		cout << "#" << tc << "\n";
		print(N);
	}

	return 0;
}