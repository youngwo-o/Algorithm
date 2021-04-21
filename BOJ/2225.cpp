#include <bits/stdc++.h>
#define MAX 201
#define MOD 1000000000

using namespace std;

int N, K;
int dp[MAX][MAX]; //dp[K][N] : 정수 K개를 더해서 합이 N이 되는 경우의 수

int main() {
	cin >> N >> K;
	
	for (int i = 1; i <= K; ++i) {
		dp[i][0] = 1; // 정수 i개를 더해서 0이 되는 경우의 수는 무조건 1개 (0, 0 + 0, 0 + 0 + 0 ...)
	}

	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[K][N];

	return 0;
}