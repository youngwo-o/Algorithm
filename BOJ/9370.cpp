#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 200000000

using namespace std;

int n, m, t; //교차로, 도로, 목적지 후보
int s, g, h; //출발지, 지나간 도로의 교차로
vector<vector<pair<int,int>>> road; //도로 정보
vector<int> distS;
vector<int> distG;
vector<int> distH;
vector<int> dest;
vector<int> ans;

void dijkstra(int start, vector<int>& dist) {
	priority_queue<pii> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curI = pq.top().second;
		int curD = -pq.top().first;
		pq.pop();

		for (auto next : road[curI]) {
			int nextI = next.first;
			int nextD = curD + next.second;

			if (nextD >= dist[nextI]) continue;

			dist[nextI] = nextD;
			pq.push({ -nextD, nextI });
		}
	}
}

void solution() {
	dijkstra(s, distS);
	dijkstra(g, distG);
	dijkstra(h, distH);

	for (auto d : dest) {
		int minLen = distS[d];
		int ghLen = distS[g] + distG[h] + distH[d];
		int hgLen = distS[h] + distH[g] + distG[d];

		if (minLen == ghLen || minLen == hgLen)
			ans.push_back(d);
	}

	sort(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a << " ";
	} cout << "\n";

	ans.clear();
	dest.clear();
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		road = vector<vector<pii>>(n + 1);
		distS = vector<int>(n + 1, INF);
		distG = vector<int>(n + 1, INF);
		distH = vector<int>(n + 1, INF);

		for (int i = 0; i < m; ++i) {
			int a, b, d;
			cin >> a >> b >> d;
			road[a].push_back({ b, d });
			road[b].push_back({ a, d });
		}
		for (int i = 0; i < t; ++i) {
			int x;
			cin >> x;
			dest.push_back(x);
		}

		solution();
	}

	return 0;
}