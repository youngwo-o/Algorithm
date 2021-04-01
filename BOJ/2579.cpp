#include <bits/stdc++.h>
#define MAX 301

using namespace std;

int N;
int arr[MAX], dp[MAX];

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	dp[3] = max(arr[1], arr[2]) + arr[3]; //첫번째 + 세번째 / 두번째 + 세번째 중 큰 값
	for (int i = 4; i <= N; ++i) {
		// 3 이전 계단까지 밟고, 그 1 이전 계단, 현재 계단 밟기 / 2 이전 계단까지 밟고 현재 계단 밟기
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}
	

	cout << dp[N];

	return 0;
}