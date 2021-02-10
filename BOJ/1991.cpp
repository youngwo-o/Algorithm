#include <bits/stdc++.h>

using namespace std;

int N;
int tree[26][2];

void preorder(int idx) {
	if (idx == -1) return;
	
	cout << (char)('A' + idx);
	preorder(tree[idx][0]);
	preorder(tree[idx][1]);
}

void inorder(int idx) {
	if (idx == -1) return;

	inorder(tree[idx][0]);
	cout << (char)('A' + idx);
	inorder(tree[idx][1]);
}

void postorder(int idx) {
	if (idx == -1) return;

	postorder(tree[idx][0]);
	postorder(tree[idx][1]);
	cout << (char)('A' + idx);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	memset(tree, -1, sizeof(tree));
	for (int i = 0; i < N; ++i) {
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')
			tree[a - 'A'][0] = b - 'A';
		if (c != '.')
			tree[a - 'A'][1] = c - 'A';
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);

	return 0;
}