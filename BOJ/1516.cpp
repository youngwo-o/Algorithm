#include <bits/stdc++.h>
#define MAX 501

using namespace std;

int N;
int buildTime[MAX], entry[MAX];
vector<int> adj[MAX];

void solution() {
	int ans[MAX] = { 0 };
	priority_queue<pair<int,int>> q;

	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0) q.push({ -buildTime[i], i });
	}

	while (!q.empty()) {
		int n = q.top().second;
		int t = -q.top().first;
		q.pop();

		ans[n] = t;

		for (auto next : adj[n]) {
			entry[next]--;

			if (entry[next] == 0) q.push({ -(buildTime[next] + t), next});
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << ans[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> buildTime[i];
		while (1) {
			int n; cin >> n;
			if (n == -1) break;
			adj[n].push_back(i);
			entry[i]++;
		}
	}

	solution();

	return 0;
}