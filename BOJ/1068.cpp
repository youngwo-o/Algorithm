#include <bits/stdc++.h>

using namespace std;

int N, root;
int parent[50];
int ans = 0;

void dfs(int start) {
	bool check = false;
	for (int i = 0; i < N; ++i) {
		if (parent[i] == start) { //start의 자식인 경우
			check = true;
			dfs(i);
		}
	}

	//자식이 없는 경우 -> 리프노드
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
	if (d == root) { //루트를 지우는 경우 -> 0
		cout << "0";
		return 0;
	}
	//노드 지우기
	//지울 노드를 부모로 갖는 노드 지우기 (그 아래 자식들은 따로 지우지 않아도 됨, 이미 지워진 부모에서 막힘)
	parent[d] = -1;

	solution();

	return 0;
}