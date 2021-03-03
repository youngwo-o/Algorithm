#include <bits/stdc++.h>

using namespace std;

int N;
int num[100001];
int visited[100001];
int isSelected[100001];
int ans = 0;

void dfs(int idx) {
	visited[idx] = 1;

	if (visited[num[idx]] == 0)
		dfs(num[idx]);
	else if (isSelected[num[idx]] == 0) {
		int i = num[idx];
		ans++;
		while (i != idx) {
			ans++;
			i = num[i];
		}
	}

	isSelected[idx] = 1;
}

void solution() {
	memset(visited, 0, sizeof(visited));
	memset(isSelected, 0, sizeof(isSelected));
	ans = 0;

	for (int i = 1; i <= N; ++i) {
		if (visited[i] == 0)
			dfs(i);
	}
	
	cout << N - ans<< "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> num[i];
		}

		solution();
	}

	return 0;
}