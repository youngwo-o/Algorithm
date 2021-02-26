#include <bits/stdc++.h>

using namespace std;

int MAX = 100001;
int N, K;
vector<int> dist(MAX, INT_MAX);
int ans1 = INT_MAX, ans2 = 0;

void solution() {
	priority_queue<pair<int, int>> pq;

	dist[N] = 0;
	pq.push({ 0, N });

	while (!pq.empty()) {
		int curI = pq.top().second;
		int curD = -pq.top().first;
		pq.pop();

		if (curD > ans1) continue; //ans1보다 더 큰 경우 진행할 필요 X

		if (curI == K) {
			if (ans1 > curD) {
				ans1 = curD;
				ans2 = 1;
			}
			else if (ans1 == curD)
				ans2++;
			continue;
		}

		for (int i = 0; i < 3; ++i) {
			int next = curI;
			if (i == 0) next -= 1;
			else if (i == 1) next += 1;
			else if (i == 2) next *= 2;

			if (next < 0 || next >= MAX || dist[next] < curD + 1) continue;

			dist[next] = curD + 1;
			pq.push({ -(curD + 1), next });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	solution();

	cout << ans1 << "\n" << ans2;

	return 0;
}