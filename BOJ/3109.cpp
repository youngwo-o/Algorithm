#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<string> arr;
int d[3] = { -1, 0, 1 };

bool dfs(int r, int c) {
	//한번 갔던 곳은 다시 안가도됨
	//한번 갔는데 성공했을 경우, 한번 갔는데 실패했을 경우 -> 다시는 가지 않아도됨
	arr[r][c] = 'o';

	if (c == C - 1) return true;

	for (int i = 0; i < 3; ++i) {
		int nr = r + d[i];
		int nc = c + 1;

		if (nr < 0 || nr >= R) continue;

		if (arr[nr][nc] == '.')
			if(dfs(nr, nc)) return true;
	}

	return false;
}

int solution() {
	int ans = 0;
	for (int i = 0; i < R; ++i)
		if (dfs(i, 0)) ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		string str;
		cin >> str;
		arr.push_back(str);
	}

	cout << solution();

	return 0;
}