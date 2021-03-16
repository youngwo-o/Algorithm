#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<unsigned int, unsigned int>> time;
	for (int i = 0; i < N; ++i) {
		unsigned int s, e;
		cin >> s >> e;
		time.push_back({ e, s });
	}

	sort(time.begin(), time.end());

	int ans = 0, endT = 0;
	for (int i = 0; i < time.size(); ++i) {
		if (endT <= time[i].second) {
			endT = time[i].first;
			ans++;
		}
	}

	cout << ans;

	return 0;
}