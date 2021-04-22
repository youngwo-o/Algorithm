#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int N, M, k;
int money[MAX], parent[MAX];

int find(int node) {
	if (parent[node] < 0) return node;

	return parent[node] = find(parent[node]);
}

void merge(int v, int w) {
	v = find(v);
	w = find(w);

	if (v == w) return;

	// 친구비가 더 적은 사람이 부모가 되도록 merge
	if (money[v] < money[w]) parent[w] = v;
	else parent[v] = w;
}

int main() {
	cin >> N >> M >> k;
	for (int i = 1; i <= N; ++i) {
		cin >> money[i];
		parent[i] = -1;
	}
	for (int i = 0; i < M; ++i) {
		int v, w; cin >> v >> w;
		merge(v, w);
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (parent[i] == -1) ans += money[i];
	}

	if (ans <= k) cout << ans;
	else cout << "Oh no";

	return 0;
}