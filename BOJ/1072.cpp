#include <bits/stdc++.h>

using namespace std;

int main() {
	long long X, Y, Z; //int 사용하면 Z 도출 시 overflow
	cin >> X >> Y;
	Z = (Y * 100) / X;

	int low = 1, high = 1000000000, ans = -1;
	while (low <= high) {
		int mid = (low + high) / 2;

		int newZ = ((Y + mid) * 100) / (X + mid);

		if (Z < newZ) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ans;

	return 0;
}