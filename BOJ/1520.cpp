#include <bits/stdc++.h>
#define MAX 500

using namespace std;

int N, M;
int arr[MAX][MAX], dp[MAX][MAX];
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// DFS + DP
int dfs(int r, int c) {
	if (r == M - 1 && c == N - 1) return 1;

	// ������ �湮���� ���� ���̶��
	if (dp[r][c] == -1) {
		dp[r][c] = 0;

		for (int i = 0; i < 4; ++i) {
			int nr = r + d[i][0];
			int nc = c + d[i][1];

			if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
			
			// ��������� �� �� �ִ� ���
			// dfs ��� ȣ��� �ش� �������κ��� �� �� �ִ� ����� �� ������
			if (arr[r][c] > arr[nr][nc]) dp[r][c] += dfs(nr, nc); // ��� �� ����� �� ���ϱ�
		}
	}

	// �̹� Ž���� ���̶�� �ش� �������κ��� �� �� �ִ� ����� ���� ����
	return dp[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			dp[i][j] = -1; // �湮 üũ�ϱ� ���� -1��
		}
	}

	cout << dfs(0, 0);

	return 0;
}