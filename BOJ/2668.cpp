#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int N;
int num[MAX];
bool visited[MAX];
vector<int> ans;

void dfs(int s, int c) {
	if (visited[c]) { // 이미 방문한 곳인 경우
		// 다시 시작지점으로 돌아온 경우 => 사이클이 있음
		if (s == c) ans.push_back(s);
	}
	else {
		visited[c] = true;
		dfs(s, num[c]);
	}
}

void solution() {
	// 1번부터 dfs 돌면서 사이클이 있는지 찾기
	for (int i = 1; i <= N; ++i) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num[i];
	}

	solution();

	cout << ans.size() << "\n";
	for (auto& a : ans) {
		cout << a << "\n";
	}

	return 0;
}