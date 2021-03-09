#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> arr;
	for (int i = 1; i <= N; ++i) {
		arr.push_back(i);
	}

	int idx = 0;
	vector<int> ans;
	while (N != 0) {
		idx = idx + K - 1;
		if (idx >= N)
			idx %= N;
		ans.push_back(arr[idx]);
		arr.erase(arr.begin() + idx);
		N--;
	}

	cout << "<";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i != ans.size() - 1) cout << ", ";
	}
	cout << ">";

	return 0;
}