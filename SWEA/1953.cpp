#include <bits/stdc++.h>
#define MAX 51

using namespace std;

int N, M, R, C, L;
int tunnel[MAX][MAX];
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; //��, ��, ��, ��

int solution() {
	int ans = 0;
	int visited[MAX][MAX] = { 0 };
	queue<pair<int, int>> q;

	visited[R][C] = 1;
	q.push({ R, C });

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (visited[r][c] > L) break;

		ans++;

		int type = tunnel[r][c];
		for (int i = 0; i < 4; ++i) { //4�������� �̵�
			//���� ��ġ�� �ͳ��� �̵� �������� üũ
			if (i == 0 && (type == 2 || type == 6 || type == 7)) continue;
			else if (i == 1 && (type == 2 || type == 4 || type == 5)) continue;
			else if (i == 2 && (type  == 3 || type == 4 || type == 7)) continue;
			else if(i == 3 && (type == 3 || type == 5 || type == 6)) continue;

			int nr = r + d[i][0];
			int nc = c + d[i][1];
			
			//���� ��ġ�� ���� ���� ����ų� / �ͳ��� ���ų� / �̹� �湮�� ���
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || tunnel[nr][nc] == 0 || visited[nr][nc]) continue;

			int ntype = tunnel[nr][nc];
			//���� ��ġ�� �ͳ��� �̵� �������� üũ
			if (i == 0 && (ntype == 2 || ntype == 4 || ntype == 5)) continue;
			else if (i == 1 && (ntype == 2 || ntype == 6 || ntype == 7)) continue;
			else if (i == 2 && (ntype == 3 || ntype == 5 || ntype == 6)) continue;
			else if (i == 3 && (ntype == 3 || ntype == 4 || ntype == 7)) continue;
			
			visited[nr][nc] = visited[r][c] + 1;
			q.push({ nr ,nc });
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> tunnel[i][j];
			}
		}

		cout << "#" << tc << " " << solution() << "\n";
	}

	return 0;
}