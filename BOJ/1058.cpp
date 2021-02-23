#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> arr(51, vector<int>(51, 0));

int solution() {
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (i != j && arr[i][k] != 0 && arr[k][j] != 0) {
					if (arr[i][j] == 0)
						arr[i][j] = arr[i][k] + arr[k][j];
					else
						arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int res = 0;
		for (int j = 1; j <= N; ++j) {
			//서로 친구이거나, 친구의 친구인 경우만
			if (arr[i][j] > 0 && arr[i][j] <= 2)
				res++;
		}
		ans = max(ans, res);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			if (s[j] == 'Y') arr[i][j + 1] = 1;
		}
	}

	cout << solution();

	return 0;
}