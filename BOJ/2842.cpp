#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> godo(50, vector<int>(50, 0));
struct pos { int r, c; };
pos P;
vector<pos> K;
set<int> godoSet;
bool visited[50][50];
int d[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
int ans = INT_MAX;

bool isEnd() {
	for (auto k : K) {
		if (!visited[k.r][k.c]) return false;
	}
	return true;
}

void dfs(int r, int c, int low, int high) {
	if (godo[r][c] < low || godo[r][c] > high)
		return;

	visited[r][c] = true;

	for (int i = 0; i < 8; ++i) {
		int nr = r + d[i][0];
		int nc = c + d[i][1];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;

		dfs(nr, nc, low, high);
	}
}

void solution() {
	set<int>::iterator left = godoSet.begin(), right = godoSet.begin();
	//투 포인터
	while (left != godoSet.end() && right != godoSet.end()) {
		memset(visited, 0, sizeof(visited));

		dfs(P.r, P.c, *left, *right); //left <= 고도 <= right로 갈 수 있는 모든 칸 탐색

		if (isEnd()) ans = min(ans, *right - *left); //모든 집을 들릴 수 있고, 최소 피로도라면 결과 갱신
		else {
			right++; //모든 집을 들릴 수 없는 경우 -> right 값 증가
			continue;
		}

		left++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < N; ++j) {
			if (str[j] == 'P') P = { i, j };
			else if (str[j] == 'K') K.push_back({ i, j });
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> godo[i][j];
			godoSet.insert(godo[i][j]);
		}
	}

	solution();

	cout << ans;

	return 0;
}