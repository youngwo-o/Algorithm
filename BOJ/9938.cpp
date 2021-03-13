#include <bits/stdc++.h>
#define MAX 300001

using namespace std;

int N, L;
bool drawer[MAX];
int parent[MAX];

int find(int u) {
	if (parent[u] == u)
		return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
	cout << "LADICA\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 1; i <= L; ++i) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; ++i) {
		int a, b;  cin >> a >> b;

		//루트 노드는 빈 서랍
		//현재 서랍이 비어있는 경우 -> 서랍 채우고 merge로 빈서랍을 부모로 지정
		if (!drawer[a]) {
			drawer[a] = true;
			merge(a, b);
		}
		else if (!drawer[b]) {
			drawer[b] = true;
			merge(b, a);
		}
		//현재 서랍이 채워져있는 경우 -> 빈 서랍이 있는지 확인
		else if (!drawer[find(parent[a])]) {
			drawer[find(parent[a])] = true;
			merge(a, b);
		}
		else if (!drawer[find(parent[b])]) {
			drawer[find(parent[b])] = true;
			merge(b, a);
		}
		else cout << "SMECE\n";
	}

	return 0;
}