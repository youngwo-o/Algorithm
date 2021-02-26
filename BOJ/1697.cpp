#include <bits/stdc++.h>

using namespace std;

int MAX = 100001;
int N, K;
vector<int> dist(MAX, INT_MAX);

int solution() {
	priority_queue<pair<int, int>> pq;

	dist[N] = 0;
	pq.push({ 0, N });

	while (!pq.empty()) {
		int curI = pq.top().second;
		int curD = -pq.top().first;
		pq.pop();

		if (curI == K) return curD;

		for (int i = 0; i < 3; ++i) {
			int next = curI;
			if (i == 0) next -= 1;
			else if (i == 1) next += 1;
			else if (i == 2) next *= 2;

			if (next < 0 || next >= MAX || dist[next] <= curD + 1) continue;

			dist[next] = curD + 1;
			pq.push({ -(curD + 1), next });
		}
	}
}

int main() {
	cin >> N >> K;

	cout << solution();

	return 0;
}