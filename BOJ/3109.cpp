#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<string> arr;
int d[3] = { -1, 0, 1 };

bool dfs(int r, int c) {
	//�ѹ� ���� ���� �ٽ� �Ȱ�����
	//�ѹ� ���µ� �������� ���, �ѹ� ���µ� �������� ��� -> �ٽô� ���� �ʾƵ���
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