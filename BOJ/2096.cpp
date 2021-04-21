#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> minDp(3);
vector<int> maxDp(3);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b, c; cin >> a >> b >> c;

		int tmp0 = minDp[0], tmp2 = minDp[2];
		minDp[0] = min(minDp[0], minDp[1]) + a;
		minDp[2] = min(minDp[1], minDp[2]) + c;
		minDp[1] = min(minDp[1], min(tmp0, tmp2)) + b;

		tmp0 = maxDp[0], tmp2 = maxDp[2];
		maxDp[0] = max(maxDp[0], maxDp[1]) + a;
		maxDp[2] = max(maxDp[1], maxDp[2]) + c;
		maxDp[1] = max(maxDp[1], max(tmp0, tmp2)) + b;
	}

	int maxAns = max(maxDp[0], max(maxDp[1], maxDp[2]));
	int minAns = min(minDp[0], min(minDp[1], minDp[2]));

	cout << maxAns << " " << minAns;

	return 0;
}