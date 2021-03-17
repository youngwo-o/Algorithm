#include <bits/stdc++.h>
#define MAX 32001

using namespace std;

int N, M;
vector<int> adj[MAX];
int entry[MAX];

void solution() {
	priority_queue<int> q;

	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0) q.push(-i);
	}

	while (!q.empty()) {
		int n = -q.top();
		q.pop();

		cout << n << " ";

		for (auto next : adj[n]) {
			entry[next]--;

			if (entry[next] == 0) q.push(-next);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int A, B;  cin >> A >> B;
		adj[A].push_back(B);
		entry[B]++;
	}

	solution();

	return 0;
}