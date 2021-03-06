#include <bits/stdc++.h>
#define MAX 50

using namespace std;

int N, M;
vector<string> board;
int visited[MAX][MAX], dp[MAX][MAX]; //dp[r][c] : (r,c)의 위치에서 움직일 수 있는 횟수의 최대값
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

//BFS는 중복 방문 체크가 어렵기 때문에 DFS 사용
int dfs(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M || board[r][c] == 'H') return 0; //더이상 이동 불가
	if (visited[r][c] != 0) { //현재 경로에서 이미 방문한 위치라면 사이클 생김
		cout << "-1";
		exit(0);
	}
	if (dp[r][c] != -1) return dp[r][c]; //이미 탐색한 위치라면 (dp가 초기값이 아닌 경우)

	visited[r][c] = 1; //방문 체크
	dp[r][c] = 0; //이동 횟수 0으로 설정

	for (int i = 0; i < 4; ++i) {
		int nr = r + d[i][0] * (board[r][c] - '0');
		int nc = c + d[i][1] * (board[r][c] - '0');

		dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1); //해당 방향으로 이동할 경우가 최대값이라면 dp 갱신
	}

	visited[r][c] = 0; //방문 체크 해제
	return dp[r][c];
}

void solution() {
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		board.push_back(s);
	}

	solution();

	return 0;
}