#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 1001
#define INF 0x3f3f3f3f //byte ����

using namespace std;

int w, h;
vector<string> b;
pii sg;
int visited[MAX][MAX], fireVisited[MAX][MAX];
int d[4][2] = { {0,1 }, {0, -1}, {1, 0 }, { -1, 0 } };

void fireBfs() {
	memset(fireVisited, 0x3f, sizeof(fireVisited)); //memset : byte ���� �ʱ�ȭ
	queue<pii> q;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (b[i][j] == '*') {
				q.push({ i, j });
				fireVisited[i][j] = 0;
			}
		}
	}

	//���� ���ʸ��� �ش� ��ġ�� �̵��ϴ��� ���ϱ� ����
	//bfs�� ���鼭 fireVisited�� ����
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int j = 0; j < 4; ++j) {
			int nr = r + d[j][0];
			int nc = c + d[j][1];

			if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

			if (fireVisited[nr][nc] == INF && (b[nr][nc] == '.' || b[nr][nc] == '@')) {
				fireVisited[nr][nc] = fireVisited[r][c] + 1;
				q.push({ nr ,nc });
			}
		}
	}
}

int solution() {
	fireBfs();

	memset(visited, INF, sizeof(visited));
	queue<pii> q;
	visited[sg.first][sg.second] = 0;
	q.push(sg);

	while (!q.empty()) {
		for (int i = 0, qSize = q.size(); i < qSize; ++i) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			//�迭�� �����ڸ��� ��� -> Ż�� ����
			if (r == 0 || r == h - 1 || c == 0 || c == w - 1)
				return visited[r][c] + 1;

			for (int j = 0; j < 4; ++j) {
				int nr = r + d[j][0];
				int nc = c + d[j][1];

				if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

				//���� ��ġ�� �� �����̰� / �ִ� �Ÿ��̰� / ����̰� ���� �����ϴ� �ð����� ���� �ð��� ������ �� �ִٸ�
				if (b[nr][nc] == '.' && visited[nr][nc] > visited[r][c] + 1 && fireVisited[nr][nc] > visited[r][c] + 1) {
					visited[nr][nc] = visited[r][c] + 1;
					q.push({ nr, nc });
				}
			}
		}
	}

	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> w >> h;
		for (int i = 0; i < h; ++i) {
			string tmp;
			cin >> tmp;
			b.push_back(tmp);
			for (int j = 0; j < w; ++j) {
				if (b[i][j] == '@')
					sg = { i, j };
			}
		}
		int res = solution();
		if (res == -1) cout << "IMPOSSIBLE\n";
		else cout << res << "\n";

		b.clear();
	}
}