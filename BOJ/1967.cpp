#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int n;
vector<pair<int,int>> adj[MAX];
int tmp, node, dist[MAX];

void dfs(int idx, int d) {
	dist[idx] = d;

	if (dist[idx] > tmp) { //최대값인 경우
		tmp = dist[idx]; //결과값 갱신
		node = idx; //노드 갱신
	}

	for (auto next : adj[idx]) {
		if (dist[next.first] == -1) //이전에 방문하지 않은 경우
			dfs(next.first, d + next.second);
	}
}

void solution() {
	/* 
	 * 어떤 정점에서 출발해도 가장 멀리 있는 정점은 원의 지름에 해당하는 두 정점 중에 하나
	 * 따라서, 루트를 시작정점으로 정하고, 가장 멀리 있는 정점을 찾고 (원의 지름에 해당하는 정점 1)
	 * 해당 정점에서 가장 멀리 있는 정점을 찾음 (원의 지름에 해당하는 정점 2)
	 * 이 두 정점 사이의 거리가 트리의 지름이 됨
	 */
	memset(dist, -1, sizeof(dist));
	dfs(1, 0); //루트 노드에서 가장 먼 정점 찾기
	memset(dist, -1, sizeof(dist));
	tmp = 0;
	dfs(node, 0); //찾은 정점에서 가장 먼 정점 찾기
	cout << tmp; //최대값이 트리의 지름
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; 
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	
	solution();

	return 0;
}