#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, R, Q;
vector<int> adj[MAX];
int parent[MAX], child[MAX];

// Ʈ�� ����鼭 �ڽ� �� ����
int makeTree(int idx) {
	for (auto& next : adj[idx]) {
		if (parent[next] != 0) continue; // �̹� �湮�� ���
		parent[next] = idx; // �θ� ��� ����
		child[idx] += makeTree(next); // �ڽ� �� ��������� �߰�
	}
	return child[idx]; // �ڽ� ��� ���� ����
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