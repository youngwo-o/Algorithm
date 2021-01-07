#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int num[100001];
pair<int,int> *tree;

pair<int,int> init(int start, int end, int node) {
	if (start == end)
		return tree[node] = { num[start], num[start] };

	int mid = (start + end) / 2;

	pair<int, int> leftRes = init(start, mid, node * 2);
	pair<int,int> rightRes = init(mid + 1, end, node * 2 + 1);

	tree[node] = { min(leftRes.first, rightRes.first), max(leftRes.second, rightRes.second) };

	return tree[node];
}

pair<int, int> find(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return { 1000000001, 0 };
	else if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	
	pair<int, int> leftRes = find(start, mid, left, right, node * 2);
	pair<int, int> rightRes = find(mid + 1, end, left, right, node * 2 + 1);

	return { min(leftRes.first, rightRes.first), max(leftRes.second, rightRes.second) };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	int h = (int)ceil(log2(n));
	tree = new pair<int,int>[1 << (h + 1)];

	init(0, n - 1, 1);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		pair<int, int> res = find(0, n - 1, a - 1, b - 1, 1);
		cout << res.first << " " << res.second << "\n";
	}

	return 0;
}