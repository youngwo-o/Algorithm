#include <bits/stdc++.h>
#define MAX 50

using namespace std;

int N, M;
vector<string> board;
int visited[MAX][MAX], dp[MAX][MAX]; //dp[r][c] : (r,c)�� ��ġ���� ������ �� �ִ� Ƚ���� �ִ밪
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

//BFS�� �ߺ� �湮 üũ�� ��Ʊ� ������ DFS ���
int dfs(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M || board[r][c] == 'H') return 0; //���̻� �̵� �Ұ�
	if (visited[r][c] != 0) { //���� ��ο��� �̹� �湮�� ��ġ��� ����Ŭ ����
		cout << "-1";
		exit(0);
	}
	if (dp[r][c] != -1) return dp[r][c]; //�̹� Ž���� ��ġ��� (dp�� �ʱⰪ�� �ƴ� ���)

	visited[r][c] = 1; //�湮 üũ
	dp[r][c] = 0; //�̵� Ƚ�� 0���� ����

	for (int i = 0; i < 4; ++i) {
		int nr = r + d[i][0] * (board[r][c] - '0');
		int nc = c + d[i][1] * (board[r][c] - '0');

		dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1); //�ش� �������� �̵��� ��찡 �ִ밪�̶�� dp ����
	}

	visited[r][c] = 0; //�湮 üũ ����
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