#include <iostream>
#include <algorithm>

using namespace std;

int n, m, sum = 0;
int len[100001];
int res = 0, ans = 1000000001;

bool sol(int mid) {
	int res = 0;
	int cnt = 1;

	for (int i = 0; i < n; ++i) {
		if (len[i] > mid)
			return false;

		res += len[i];

		if (res > mid) {
			cnt++;
			res = len[i];
		}
	}

	if (cnt <= m)
		return true;
	else
		return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> len[i];
		sum += len[i];
	}

	int ans = 1000000001;
	int low = 1, high = sum;
	while (low <= high) {
		int mid = (low + high) / 2;

		if (sol(mid) == true) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}