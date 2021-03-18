#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int N, M;
int A[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	sort(A, A + N);

	int minDiff = INT_MAX;
	int left = 0, right = 0;
	while (left <= right && right < N) {
		int diff = A[right] - A[left];

		if (diff >= M) {
			minDiff = min(minDiff, diff);
			if (left == right) right++; //left를 증가시킬 수 없는 경우, right 증가
			else left++; //차이 감소시키기 위해
		}
		else right++; //차이 증가시키기 위해
	}

	cout << minDiff;
	
	return 0;
}