#include <bits/stdc++.h>
#define MAX 1001
#define pii pair<int,int>
#define INF 0x3f

using namespace std;

int N, M, S, E;
vector<pii> adj[MAX]; 
int visited[MAX];

void solution() {
	memset(visited, INF, sizeof(visited));
	priority_queue<pii> q;

	visited[S] = 0;
	q.push({ 0, S });

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int s, e, c; cin >> s >> e >> c;
		adj[s].push_back({ e, c });
	}
	cin >> S >> E;

	solution();

	cout << visited[E];

	return 0;
}