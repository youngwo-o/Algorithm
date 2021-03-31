#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int N, ans;
int A[MAX];
int dp[MAX];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	for (int i = 0; i < N; ++i) {
		if(dp[i] == 0) dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}