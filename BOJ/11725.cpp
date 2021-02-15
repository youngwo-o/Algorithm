#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> node[100001];
bool visited[100001];
int parent[100001];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	queue<int> q;

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < node[now].size(); ++i) {
			int next = node[now][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				parent[next] = now;
			}
		}
	}

	for (int i = 2; i <= N; ++i) {
		cout << parent[i] << "\n";
	}

	return 0;
}