#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 10001

using namespace std;

int n, m, sCity, eCity;
vector<pii> info[MAX], info_rev[MAX];
int entry[MAX];

void solution() {
	int ans = 0;

	queue<pii> q;
	vector<int> dist(MAX, -1);

	q.push({ sCity, 0 });
	dist[sCity] = 0;

	//모든 도시에 대한 최대 거리 구하기
	while (!q.empty()) {
		int curCity = q.front().first;
		int curDist = q.front().second;
		q.pop();

		for (auto next : info[curCity]) {
			int nextCity = next.first;
			int nextDist = curDist + next.second;
			
			dist[nextCity] = max(dist[nextCity], nextDist); //최대거리 구하기
			entry[nextCity]--; //우선적으로 거쳐야할 도시 1 감소

			if (entry[nextCity] == 0) //우선적으로 거쳐야할 모든 도시를 방문한 경우
				q.push({ dist[nextCity], nextCity }); //다음 도시로 이동할 수 있음
		}
	}

	set<pii> ansRoad;
	queue<pii> q2;
	vector<int> visited(MAX, 0);

	//도착 도시에서부터 백트래킹
	q2.push({ eCity, 0 });
	visited[eCity] = 1;

	while (!q2.empty()) {
		int curCity = q2.front().first;
		int curDist = q2.front().second;
		q2.pop();

		for (auto next : info_rev[curCity]) {
			int nextCity = next.first;
			int nextDist = curDist + next.second;

			//현재도시에서 다음 도시까지의 거리 + 시작 도시에서 다음 도시까지의 거리 = 도착 도시까지의 최대 거리
			//최대거리로 갈 수 있는 경로인 경우
			if (nextDist + dist[nextCity] == dist[eCity]) {
				ansRoad.insert({ curCity, nextCity }); //결과 도로 저장
				if (!visited[nextCity]) { //방문하지 않았을 경우만
					visited[nextCity] = 1;
					q2.push({ nextDist, nextCity });
				}
			}
		}
	}

	cout << dist[eCity] << "\n" << ansRoad.size() << "\n";
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int s, e, t;
		cin >> s >> e >> t;
		info[s].push_back({ e, t });
		info_rev[e].push_back({ s, t });
		entry[e]++; //위상정렬 (모든 도로는 일방통행, e번 도시를 가기전 우선적으로 거쳐가야하는 도시의 개수)
	}
	cin >> sCity >> eCity;

	solution();

	return 0;
}