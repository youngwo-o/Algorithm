#include <bits/stdc++.h>
#define MAX 300001

using namespace std;

int N, M, K, X;
vector<int> adj[MAX];
vector<int> visited(MAX, -1);

void solution() {
	vector<int> ans;
	queue<int> q;

	visited[X] = 0;
	q.push(X);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visited[cur] == K) {
			ans.push_back(cur);
			continue;
		}

		for (auto next : adj[cur]) {
			if (visited[next] == -1) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	if (ans.empty()) cout << "-1";
	else {
		sort(ans.begin(), ans.end());
		for (auto a : ans) {
			cout << a << "\n";
		}
	}
}

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	solution();

	return 0;
}