#include <bits/stdc++.h>

using namespace std;

int T, n, d;
vector<vector<int>> arr;

void print() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void rotate() {
	vector<vector<int>> newArr(n, vector<int>(n));

	if (d > 0) {
		for (int k = 0; k < d; k += 45) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					//주 대각선
					if (i == j)
						newArr[i][n / 2] = arr[i][j];
					//가운데 열
					else if (j == n / 2)
						newArr[i][n - 1 - i] = arr[i][j];
					//부 대각선
					else if (j == n - 1 - i) 
						newArr[n / 2][j] = arr[i][j];
					//가운데 행
					else if (i == n / 2)
						newArr[j][j] = arr[i][j];
					else
						newArr[i][j] = arr[i][j];
				}
			}
			
			arr = newArr;
		}
	}
	else {
		for (int k = 0; k < (-d); k += 45) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					//주 대각선
					if (i == j)
						newArr[n / 2][j] = arr[i][j];
					//가운데 열
					else if (j == n / 2)
						newArr[i][i] = arr[i][j];
					//부 대각선
					else if (j == n - 1 - i)
						newArr[i][n / 2] = arr[i][j];
					//가운데 행
					else if (i == n / 2)
						newArr[n - 1 - j][j] = arr[i][j];
					else
						newArr[i][j] = arr[i][j];
				}
			}

			arr = newArr;
		}
	}

	print();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> d;

		arr = vector<vector<int>>(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
			}
		}

		rotate();
	}

	return 0;
}