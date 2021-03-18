#include <bits/stdc++.h> 
#define MAX 801
#define pii pair<int,int>
#define INF 0x3f3f3f3f

using namespace std;

int N, E, v1, v2;
vector<pii> adj[MAX];

void dijkstra(int start, vector<int>& visited) {
	priority_queue<pii> q;

	visited[start] = 0;
	q.push({ 0, start });

	while (!q.empty()) {
		int idx = q.top().second;
		int dist = -q.top().first;
		q.pop();

		if (dist > visited[idx]) continue;

		for (auto& next : adj[idx]) {
			int nextIdx = next.first;
			int nextDist = next.second + dist;

			if (visited[nextIdx] > nextDist) {
				visited[nextIdx] = nextDist;
				q.push({ -nextDist, nextIdx });
			}
		}
	}
}

int solution() {
	vector<int> visited(MAX), visited1(MAX), visited2(MAX);
	fill(visited.begin(), visited.end(), INF);
	fill(visited1.begin(), visited1.end(), INF);
	fill(visited2.begin(), visited2.end(), INF);

	dijkstra(1, visited);
	dijkstra(v1, visited1);
	dijkstra(v2, visited2);

	int ans = -1;
	if (visited[v1] != INF && visited1[v2] != INF && visited2[N] != INF)
		ans = visited[v1] + visited1[v2] + visited2[N];
	if (visited[v2] != INF && visited2[v1] != INF && visited1[N] != INF) {
		if (ans == -1) ans = visited[v2] + visited2[v1] + visited1[N];
		else ans = min(ans, visited[v2] + visited2[v1] + visited1[N]);
	}

	return ans;
}

int main() {
	cin >> N >> E;
	for (int i = 0; i < E; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> v1 >> v2;

	cout << solution();

	return 0;
}