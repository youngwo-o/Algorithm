#include <bits/stdc++.h>
#define MAX 1001
#define pii pair<int,int>

using namespace std;

struct compare {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};

int N, M, X;
vector<pii> adj[MAX];
int dist[MAX], tot[MAX];

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pii, vector<pii>, compare> pq;
	pq.push({ s, 0 });
	dist[s] = 0;

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		if (dist[now.first] < now.second) continue;

		for (auto& next : adj[now.first]) {
			int nextDist = now.second + next.second;
			if (nextDist < dist[next.first]) {
				dist[next.first] = nextDist;
				pq.push({ next.first, nextDist });
			}
		}
	}
}

int solution() {
	for (int i = 1; i <= N; ++i) {
		dijkstra(i);

		if (i == X) { // 도착지점에서 모든 정점으로의 최단 거리 구하기
			for (int j = 1; j <= N; ++j) tot[j] += dist[j]; // 결과값에 저장
		}
		else tot[i] += dist[X]; // 현재지점에서 도착지점까지의 최단 거리 저장
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) ans = max(ans, tot[i]);
	return ans;
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; ++i) {
		int s, e, t; cin >> s >> e >> t;
		adj[s].push_back({ e, t });
	}

	cout << solution();

	return 0;
}