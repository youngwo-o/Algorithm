#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int N, M, maxT = 0;
int tree[MAX];

int solution() {
	int ans = 0;
	int low = 0, high = maxT;
	while (low <= high) {
		int mid = (low + high) / 2;

		long long res = 0;
		for (int i = 0; i < N; ++i) {
			if (mid < tree[i]) res += (tree[i] - mid);
		}
		if (res >= M) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> tree[i];
		if (tree[i] > maxT) maxT = tree[i];
	}

	cout << solution();

	return 0;
}