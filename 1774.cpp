#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
pair<int,int> node[1001];
int d[1001];
typedef struct _data{
	int a, b;
	double len;
}Data;
vector<Data> info;

int find(int node) {
	if (node == d[node])
		return node;

	return d[node] = find(d[node]);
}

bool merge(int a, int b) {
	int ap = find(a);
	int bp = find(b);

	if (ap == bp)
		return false;

	d[bp] = ap;
	return true;
}

bool cmp(const Data& a, const Data& b) {
	return a.len < b.len;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		node[i] = make_pair(x, y);
		d[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 1; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			double len = sqrt(pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2));
			info.push_back({ i, j, len });
		}
	}

	sort(info.begin(), info.end(), cmp);
	double ans = 0;

	for (int i = 0; i < info.size(); ++i) {
		int a = info[i].a;
		int b = info[i].b;

		if (merge(a, b))
			ans += info[i].len;
	}

	printf("%.2f", ans);

	return 0;
}