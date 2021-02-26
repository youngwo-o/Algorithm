#include <bits/stdc++.h>

using namespace std;

void star(int r, int c, int n, vector<vector<char>>& pattern) {
	for (int i = r; i < r + n; ++i) {
		if (i == r || i == r + n - 1) {
			for (int j = c; j < c + n; ++j)
				pattern[i][j] = '*';
		}
		else
			pattern[i][c] = pattern[i][c + n - 1] = '*';
	}

	if (n == 3) return;

	star(r, c, n / 3, pattern);
	star(r, c + n / 3, n / 3, pattern);
	star(r, c + n / 3 * 2, n / 3, pattern);

	star(r + n / 3, c, n / 3, pattern);
	star(r + n / 3, c + n / 3 * 2, n / 3, pattern);

	star(r + n / 3 * 2, c, n / 3, pattern);
	star(r + n / 3 * 2, c + n / 3, n / 3, pattern);
	star(r + n / 3 * 2, c + n / 3 * 2, n / 3, pattern);
}

void star10(int N) {
	vector<vector<char>> pattern(N, vector<char>(N, ' '));

	star(0, 0, N, pattern);

	for (int i = 0; i < N; ++i) {
		for (auto p : pattern[i])
			cout << p;
		cout << "\n";
	}
}

void star5(int N) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < (N - i); ++j)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; ++j)
			cout << "*";

		cout << "\n";
	}
}

void star6(int N) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i - 1; ++j)
			cout << " ";
		for (int j = 0; j < 2 * N - (2 * i - 1); ++j)
			cout << "*";

		cout << "\n";
	}
}

int main() {
	int N;
	cin >> N;

	return 0;
}