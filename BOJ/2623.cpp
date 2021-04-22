#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, M;
vector<int> adj[MAX];
int entry[MAX];

vector<int> solution() {
	vector<int> ans;

	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int s = q.front();
		q.pop();

		ans.push_back(s);

		for (auto& next : adj[s]) {
			entry[next]--;

			if (entry[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (entry[i] != 0) return { 0 };
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int n; cin >> n;
		vector<int> tmp;
		for (int i = 0; i < n; ++i) {
			int s; cin >> s;
			tmp.push_back(s);
		}
		for (int i = 0; i < n - 1; ++i) {
			adj[tmp[i]].push_back(tmp[i + 1]);
			entry[tmp[i + 1]]++;
		}
	}

	for (auto& a : solution()) {
		cout << a << "\n";
	}

	return 0;
}