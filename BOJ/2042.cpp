#include <iostream>
#include <cmath>

using namespace std;

int n, m, k;
long long num[1000001];
long long *tree;

long long init(int start, int end, int node) {
	if (start == end)
		return tree[node] = num[start];

	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, long long diff) {
	if (idx < start || end < idx)
		return;

	tree[node] += diff;

	if (start == end)
		return;

	int mid = (start + end) / 2;

	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	
	int h = (int)ceil(log2(n));
	tree = new long long[1 << (h + 1)];

	init(0, n - 1, 1);

	for (int i = 0; i < m + k; ++i) {
		long long a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1) {
			long long diff = c - num[b - 1];
			num[b - 1] = c;
			update(0, n - 1, 1, b - 1, diff);
		}
		else if (a == 2) {
			cout << sum(0, n - 1, 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}