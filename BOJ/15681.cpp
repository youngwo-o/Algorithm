#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, R, Q;
vector<int> adj[MAX];
int parent[MAX], child[MAX];

// 트리 만들면서 자식 수 세기
int makeTree(int idx) {
	for (auto& next : adj[idx]) {
		if (parent[next] != 0) continue; // 이미 방문한 경우
		parent[next] = idx; // 부모 노드 지정
		child[idx] += makeTree(next); // 자식 수 재귀적으로 추가
	}
	return child[idx]; // 자식 노드 개수 리턴
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;
	for (int i = 1; i < N; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i) {
		child[i] = 1;
	}
	parent[R] = R;
	makeTree(R);

	for (int i = 0; i < Q; ++i) {
		int u; cin >> u;
		cout << child[u] << "\n";
	}

	return 0;
}