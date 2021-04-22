#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n, m;
int parent[MAX];

int find(int a) {
	if (a == parent[a]) return a;

	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int c, a, b; cin >> c >> a >> b;
		if (c == 0) {
			merge(a, b);
		}
		else if (c == 1) {
			int ap = find(a);
			int bp = find(b);
			if (ap == bp) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}