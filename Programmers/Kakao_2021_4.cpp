#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

vector<pair<int, int>> info[201];
vector<int> d[201];

// start노드에서 모든 노드로의 최단 거리 구하기
vector<int> dijkstra(int start, int n) {
	vector<int> tmpD(n + 1, INT_MAX);
	priority_queue<pair<int, int>> q;

	q.push({ 0, start });
	tmpD[start] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		int dist = -q.top().first;
		q.pop();

		if (dist > tmpD[now])
			continue;

		for (int i = 0; i < info[now].size(); ++i) {
			int nextN = info[now][i].first;
			int nextDist = dist + info[now][i].second;

			if (nextDist < tmpD[nextN]) {
				tmpD[nextN] = nextDist;
				q.push({ -nextDist, nextN });
			}
		}
	}

	return tmpD;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INT_MAX;

	for (auto& fa : fares) {
		int c = fa[0];
		int d = fa[1];
		int f = fa[2];

		info[c].push_back({ d, f });
		info[d].push_back({ c, f });
	}

	//모든 노드에서 모든 노드로의 최단거리 배열 저장
	for (int i = 1; i <= n; ++i) {
		d[i] = dijkstra(i, n);
	}

	//s노드에서 어떤 노드까지의 거리 + 그 노드에서 a까지의 거리 + 그 노드에서 b까지의 거리
	//이 중 최단 거리를 구함
	for (int i = 1; i <= n; ++i) {
		answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
	}

	return answer;
}

int main() {
	//cout << solution(6, 4, 6, 2, { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50}, {2, 4, 66}, { 2, 3, 22}, { 1, 6, 25 }});
	//cout << solution(7, 3, 4, 1, { {5, 7, 9},{4, 6, 4},{3, 6, 1},{3, 2, 3},{2, 1, 6 }
	cout << solution(6, 4, 5, 6, { {2,6,6},{6,3,7},{4,6,7},{6,5,11},{2,5,12}, {5, 3, 20},{2, 4, 8}, {4, 3, 9}});
	return 0;
}