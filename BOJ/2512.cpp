#include <iostream>
#include <algorithm>

using namespace std;


int n, m, maxCost = 0, minCost = 100001;
int cost[10001];

int sum(int num) {
	int res = 0;

	for (int i = 0; i < n; ++i) {
		if (cost[i] <= num)
			res += cost[i];
		else
			res += num;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
		maxCost = max(maxCost, cost[i]);
	}
	cin >> m;

	pair<int, int> ans = { 0,0 };
	int low = 1, high = maxCost;
	while (low <= high) {
		int mid = (low + high) / 2;

		int res = sum(mid);

		if (res > m)
			high = mid - 1;
		else if (res <= m) {
			if (ans.first <= res)
				ans = { res, mid };
			low = mid + 1;
		}
	}

	cout << ans.second << "\n";

	return 0;
}