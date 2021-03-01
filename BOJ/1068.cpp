#include <bits/stdc++.h>

using namespace std;

int N, root;
int parent[50];
int ans = 0;

void dfs(int start) {
	bool check = false;
	for (int i = 0; i < N; ++i) {
		if (parent[i] == start) { //start�� �ڽ��� ���
			check = true;
			dfs(i);
		}
	}

	//�ڽ��� ���� ��� -> �������
	if (!check) ans++;
}

void solution() {
	bool check = false;
	for (int i = 0; i < N; ++i) {
		if (parent[i] == root) {
			check = true;
			dfs(i);
		}
	}

	if (!check) ans++;

	cout << ans;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> parent[i];
		if (parent[i] == -1) root = i;
	}
	int d;
	cin >> d;
	if (d == root) { //��Ʈ�� ����� ��� -> 0
		cout << "0";
		return 0;
	}
	//��� �����
	//���� ��带 �θ�� ���� ��� ����� (�� �Ʒ� �ڽĵ��� ���� ������ �ʾƵ� ��, �̹� ������ �θ𿡼� ����)
	parent[d] = -1;

	solution();

	return 0;
}