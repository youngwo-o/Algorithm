#include <bits/stdc++.h>
#define MAX 200

using namespace std;

int N, K;
int A[MAX];
bool robot[MAX];

int solution() {
	int turn = 0;

	while (1) {
		turn++;

		int tmp1 = A[2 * N - 1];
		for (int i = 2 * N - 1; i >= 1; --i) {
			A[i] = A[i - 1];
			robot[i] = robot[i - 1];
		}
		A[0] = tmp1;
		robot[0] = false;

		for (int i = N - 1; i >= 0; --i) {
			if (i == N - 1 && robot[i]) robot[i] = false;
			else {
				if (robot[i] && !robot[i + 1] && A[i + 1] > 0) {
					robot[i + 1] = true;
					robot[i] = false;
					A[i + 1]--;
				}
			}
		}
		if (!robot[0] && A[0] > 0) {
			robot[0] = true;
			A[0]--;
		}

		int cnt = 0;
		for (int i = 0; i < 2 * N; ++i) {
			if (A[i] == 0) cnt++;
		}
		if (cnt >= K) return turn;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; ++i) {
		cin >> A[i];
	}

	cout << solution();

	return 0;
}