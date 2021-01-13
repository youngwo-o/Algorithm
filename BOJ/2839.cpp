#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int dp[5001];

int main() {
	cin >> n;

	memset(dp, -1, sizeof(dp));
	dp[3] = 1;
	dp[5] = 1;
	for (int i = 3; i <= n; ++i) {
		int res = 5001;
		if (i - 3 > 0 && dp[i - 3] != -1)
			res = min(res, dp[i - 3] + 1);
		if (i - 5 > 0 && dp[i - 5] != -1)
			res = min(res, dp[i - 5] + 1);

		if (res != 5001)
			dp[i] = res;
	}

	cout << dp[n];

	return 0;
}