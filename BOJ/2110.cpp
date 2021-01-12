#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int h[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	sort(h, h + n);
	
	int dist = 0, ans = 0;
	int low = 1, high = h[n - 1] - h[0];
	while (low <= high) {
		int mid = (low + high) / 2;
		int s = h[0];
		int cnt = 1;

		for (int i = 1; i < n; ++i) {
			dist = h[i] - s;
			if (mid <= dist) {
				cnt++;
				s = h[i];
			}
		}

		if (cnt >= c) {
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << ans << "\n";

	return 0;
}