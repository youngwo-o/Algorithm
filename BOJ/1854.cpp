#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 1001
#define INF 0x3f3f3f3f

using namespace std;

int n, m, k;
vector<pii> adj[MAX];
int cnt[MAX];

struct compare {
	bool operator()(pii& a, pii& b) {
		return b.second < a.second;
	}
};

void solution() {
	priority_queue<pii, vector<pii>, compare> pq;
	int dist[MAX];
	memset(dist, 0x3f, sizeof(dist));

	pq.push({ 1, 0 });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		if (++cnt[now.first] == k)
			dist[now.first] = now.second;
		
		for (pii next : adj[now.first]) {
			int nextDist = next.second + now.second;

			if (nextDist <= dist[next.first]) {
				pq.push({ next.first, nextDist });
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (dist[i] == INF) cout << "-1\n";
		else cout << dist[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	solution();

	return 0;
}