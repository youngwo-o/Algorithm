#include <bits/stdc++.h>
#define MAX 20001
#define pii pair<int,int>
#define INF 0x3f3f3f3f

using namespace std;

int V, E, K;
vector<pii> adj[MAX];

void solution() {
	int visited[MAX];
	memset(visited, INF, sizeof(visited));

	priority_queue<pii> q;
	visited[K] = 0;
	q.push({ 0, K });

	while (!q.empty()) {
		int now = q.top().second;
		int dist = -q.top().first;
		q.pop();

		if (dist > visited[now]) continue; //visited가 갱신되었을 수도 있기 때문

		for (auto& next : adj[now]) {
			int nextIdx = next.first;
			int nextDist = next.second + dist;

			if (visited[nextIdx] > nextDist) {
				visited[nextIdx] = nextDist;
				q.push({ -nextDist, nextIdx });
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (visited[i] == INF) cout << "INF\n";
		else cout << visited[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	for (int i = 0; i < E; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	solution();

	return 0;
}