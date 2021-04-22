#include <bits/stdc++.h>
#define MAX 13
#define MAX_HORSE 11

using namespace std;

typedef struct _horse {
	int r, c, d;
}Horse;

int N, K;
int board[MAX][MAX];
Horse horse[MAX_HORSE];
vector<int> position[MAX][MAX];
int direct[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; // 오, 왼, 위, 아래

int solution() {
	int cnt = 1;
	while (1) {
		if (cnt > 1000) return -1;

		for (int i = 1; i <= K; ++i) {
			int r = horse[i].r;
			int c = horse[i].c;
			int d = horse[i].d;

			int pos = find(position[r][c].begin(), position[r][c].end(), i) - position[r][c].begin();
			vector<int> move; // 현재 위치에서 움직여야할 말들
			for (int j = pos; j < position[r][c].size(); ++j) {
				move.push_back(position[r][c][j]);
			}

			int nr = r + direct[d][0];
			int nc = c + direct[d][1];
			// 체스판을 벗어나거나, 파란색인 경우
			if (nr <= 0 || nr > N || nc <= 0 || nc > N || board[nr][nc] == 2) {
				if (d == 0 || d == 2) d++;
				else d--;
			
				horse[move[0]].d = d; // 가장 아래있는 말만 방향 변경

				nr = r + direct[d][0];
				nc = c + direct[d][1];

				// 방향을 바꿨는데도 체스판을 벗어나거나, 파란색인 경우
				if (nr <= 0 || nr > N || nc <= 0 || nc > N || board[nr][nc] == 2) continue;
			}

			// 다음 위치가 흰색이거나 빨간색인 경우
			if (board[nr][nc] == 1) reverse(move.begin(), move.end()); // 빨간색인 경우에는 반대로
			position[r][c].erase(pos + position[r][c].begin(), position[r][c].end());
			for (auto& t : move) {
				position[nr][nc].push_back(t);
				horse[t].r = nr;
				horse[t].c = nc;
			}

			// 이동한 위치에 말이 4개 이상인지 확인
			if (position[nr][nc].size() >= 4) return cnt;
		}

		cnt++;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= K; ++i) {
		int r, c, d; cin >> r >> c >> d;
		horse[i] = { r, c, d - 1 };
		position[r][c].push_back(i);
	}

	cout << solution();

	return 0;
}