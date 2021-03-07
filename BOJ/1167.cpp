#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int V;
vector<pair<int,int>> adj[MAX];
int dist[MAX], node, tmp;

void dfs(int idx, int d) {
	dist[idx] = d;

	if (dist[idx] > tmp) {
		tmp = dist[idx];
		node = idx;
	}

	for (auto next : adj[idx]) {
		if (dist[next.first] == -1) 
			dfs(next.first, d + next.second);
	}
}

void solution() {
	memset(dist, -1, sizeof(dist)); 
	dfs(1, 0);
	tmp = 0;
	memset(dist, -1, sizeof(dist));
	dfs(node, 0);
	cout << tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V;
	for (int i = 1; i <= V; ++i) {
		int a, b, c;
		cin >> a;
		while (cin >> b) {
			if (b == -1) break;
			cin >> c;
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
	}

	solution();

	return 0;
}