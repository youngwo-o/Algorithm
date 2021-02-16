#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> degree;

int solution() {
	int nowMax = -271, ans = 0;
	for (auto d : degree) {
		int min = d.second;
		int max = d.first;

		if (nowMax < min) {
			nowMax = max;
			ans++;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		degree.push_back({ b, a });
	}

	sort(degree.begin(), degree.end());

	cout << solution();

	return 0;
}