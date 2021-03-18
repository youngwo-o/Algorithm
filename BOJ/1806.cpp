#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int N, S;
int num[MAX];

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}

	int sum = 0, minLen = INT_MAX;
	int left = 0, right = 0;
	while (right <= N) {
		if (sum >= S) {
			minLen = min(right - left, minLen);
			sum -= num[left++];
		}
		else sum += num[right++];
	}

	if (minLen == INT_MAX) minLen = 0;

	cout << minLen;

	return 0;
}