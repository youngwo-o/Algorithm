#include <bits/stdc++.h>
#define MAX 8
#define pii pair<int,int>

using namespace std;

int N, K, maxH;
int arr[MAX][MAX];
vector<pii> top;
bool visited[MAX][MAX];
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int ans = 0;

void trail(int r, int c, int flag, int res) {
	visited[r][c] = true;

	for (int i = 0; i < 4; ++i) {
		int nr = r + d[i][0];
		int nc = c + d[i][1];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;

		if (flag == 0) { //������ ������ ���� ���� ���
			if (arr[nr][nc] < arr[r][c]) { //������ �� ���� ������ ���
				int tmp = visited[nr][nc];
				trail(nr, nc, flag, res + 1);
				visited[nr][nc] = tmp;
			}
			else { //������ ���ų� ���� ������ ��� -> ���� ���
				for (int j = 1; j <= K; ++j) { //�ִ� K ���̸�ŭ ���� �� ���� (1 ~ K���� ���)
					if (arr[nr][nc] - j < arr[r][c]) { //���� ������ �� ���� ��� -> �湮 ����
						int tmp = visited[nr][nc];
						arr[nr][nc] -= j;
						trail(nr, nc, 1, res + 1); //flag�� 1��
						visited[nr][nc] = tmp;
						arr[nr][nc] += j;
					}
				}
			}
		}
		else { //������ ������ ���� ���
			if (arr[nr][nc] < arr[r][c]) {
				int tmp = visited[nr][nc];
				trail(nr, nc, flag, res + 1);
				visited[nr][nc] = tmp;
			}
		}
	}

	ans = max(ans, res);
}

void solution() {
	for (auto t : top) {
		memset(visited, 0, sizeof(visited));
		trail(t.first, t.second, 0, 1);
		visited[t.first][t.second] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] > maxH) {
					maxH = arr[i][j];
					top.clear();
					top.push_back({ i, j });
				}
				else if (arr[i][j] == maxH)
					top.push_back({ i, j });
			}
		}

		solution();

		cout << "#" << tc << " " << ans << "\n";

		ans = maxH = 0;
		top.clear();
	}

	return 0;
}