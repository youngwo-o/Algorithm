#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[100001];
int *tree;

int init(int start, int end, int node) {
	if (start == end)
		return tree[node] = start;

	int mid = (start + end) / 2;

	int leftRes = init(start, mid, node * 2);
	int rightRes = init(mid + 1, end, node * 2 + 1);

	if (num[leftRes] <= num[rightRes])
		return tree[node] = leftRes;
	else
		return tree[node] = rightRes;
}

int findLowIdx(int start, int end, int left, int right, int node) {
	if (start > right || end < left)
		return -1;
	else if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	int leftRes = findLowIdx(start, mid, left, right, node * 2);
	int rightRes = findLowIdx(mid + 1, end, left, right, node * 2 + 1);

	if (leftRes == -1)
		return rightRes;
	else if (rightRes == -1)
		return leftRes;
	else if (num[leftRes] <= num[rightRes])
		return leftRes;
	else
		return rightRes;
}

long long findMax(int left, int right) {
	int idx = findLowIdx(0, n - 1, left, right, 1);
	long long size = (long long)(right - left + 1) * (long long)num[idx];

	if (idx > left) {
		long long s = findMax(left, idx - 1);
		size = max(s, size);
	}
	if (idx < right) {
		long long s = findMax(idx + 1, right);
		size = max(s, size);
	}

	return size;
}

int main() {
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}

		tree = new int[n * 4];

		init(0, n - 1, 1);

		cout << findMax(0, n - 1) << "\n";
	}

	return 0;
}