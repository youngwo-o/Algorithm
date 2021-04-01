#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

string s1, s2;
int dp[MAX][MAX];

int main() {
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;

	for (int i = 1; i < s1.length(); ++i) {
		for (int j = 1; j < s2.length(); ++j) {
			// LCS(ABCD, AEBD) = LCS(ABC, AED) + 1
			if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			// LCS(ABC, AEB) = MAX(LCS(AB, AEB), LCS(ABC, AE))
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[s1.length() - 1][s2.length() - 1];

	return 0;
}