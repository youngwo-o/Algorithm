#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 1001
#define INF 0x3f3f3f3f

using namespace std;

struct compare {
	bool operator()(pii& a, pii& b) {
		return b.second < a.second;
	}
};

int n, m, k;
vector<pii> adj[MAX];
priority_queue<int> dist[MAX]; //내림차순 정렬 (큰 값이 top 으로)

void solution() {
	priority_queue<pii, vector<pii>, compare> pq;

	pq.push({ 1, 0 });
	dist[1].push(0);

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		for (pii next : adj[now.first]) {
			int nextDist = next.second + now.second;

			if (dist[next.first].size() < k) { // dist 크기가 k 보다 작으면 dist에 추가
				dist[next.first].push(nextDist);
				pq.push({ next.first, nextDist });
			}
			else if(dist[next.first].top() > nextDist) { // 현재 dist의 top보다 작은 값인 경우
				dist[next.first].pop(); // top 빼내기
				dist[next.first].push(nextDist); // 새로운 값을 dist에 추가
				pq.push({ next.first, nextDist });
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (dist[i].size() < k) cout << "-1\n";
		else cout << dist[i].top() << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	solution();

	return 0;
}