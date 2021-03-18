#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int N, M;
int A[MAX];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum = 0, ans  = 0;
	int left = 0, right = 0;
	while (right <= N) {
		if (sum >= M) {
			if (sum == M) ans++;
			sum -= A[left++];
		}
		else sum += A[right++];
	}

	cout << ans;

	return 0;
}