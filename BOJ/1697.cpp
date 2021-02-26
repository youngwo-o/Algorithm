#include <bits/stdc++.h>

using namespace std;

int MAX = 100000;
int N, K;
vector<int> dist(MAX + 1, -1);

int solution() {
	queue<pair<int, int>> q;

	dist[N] = 0;
	q.push({ N, 0 });

	while (!q.empty()) {
		int curI = q.front().first;
		int curD = q.front().second;
		q.pop();

		if (curI == K) return curD;

		for (int i = 0; i < 3; ++i) {
			int next = curI;
			if (i == 0) next -= 1;
			else if (i == 1) next += 1;
			else if (i == 2) next *= 2;

			if (next < 0 || next > MAX || dist[next] != -1) continue;

			dist[next] = curD + 1;
			q.push({ next, curD + 1 });
		}
	}
}

int main() {
	cin >> N >> K;

	cout << solution();

	return 0;
}