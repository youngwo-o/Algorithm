#include <bits/stdc++.h>
#define MAX 20
#define pii pair<int,int>

using namespace std;

typedef struct _shark {
	int r, c, d;
}Shark;

int N, M, k;
Shark shark[MAX * MAX + 1];
vector<vector<int>> prior[MAX * MAX + 1]; // 각 상어의 방향 우선순위 (위, 아래, 왼, 오)
pii smell[MAX][MAX] = { make_pair(0,0) };
int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //위, 아래, 왼, 오

void smellSpread() {
	for (int i = 1; i <= M; ++i) {
		int r = shark[i].r;
		int c = shark[i].c;

		if (r == -1 && c == -1) continue;

		smell[r][c] = { i, k + 1 };
	}
}

void smellRemove() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (smell[i][j].first != 0) {
				smell[i][j].second--;
				if (smell[i][j].second == 0) smell[i][j].first = 0;
			}
		}
	}
}

void move() {
	vector<int> moveArr[MAX][MAX];

	// 상어 이동시키기
	for (int i = 1; i <= M; ++i) {
		int r = shark[i].r;
		int c = shark[i].c;
		int d = shark[i].d;

		// 쫓겨난 상어인 경우
		if (r == -1 && c == -1 && d == -1) continue;

		bool check = false;
		Shark mySmell = { -1, -1, -1 };
		for (int j = 0; j < 4; ++j) {
			int nd = prior[i][d][j] - 1;
			int nr = r + direct[nd][0];
			int nc = c + direct[nd][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			// 상어 자신의 냄새가 있는 칸, 방향 저장 (이전에 갱신되지 않은 경우만)
			if (mySmell.r == -1 && smell[nr][nc].first == i) {
				mySmell = { nr, nc, nd };
				continue;
			}
			// 아무 냄새가 없는 칸인 경우
			if (smell[nr][nc].first == 0) {
				check = true;
				moveArr[nr][nc].push_back(i);
				shark[i] = { nr, nc, nd };
				break;
			}
		}

		// 아무냄새가 없는 칸이 없는 경우 -> 자신의 냄새가 있는 칸으로 이동해야함
		if (!check) {
			shark[i] = mySmell;
			moveArr[shark[i].r][shark[i].c].push_back(i);
		}
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// 한칸에 여러마리 있는 경우 
			if (moveArr[i][j].size() != 0) {
				sort(moveArr[i][j].begin(), moveArr[i][j].end());
				
				// 번호가 가장 작은 상어 외 모두 쫓아내기
				for (int k = 1; k < moveArr[i][j].size(); ++k) {
					int num = moveArr[i][j][k];
					shark[num] = { -1, -1, -1 };
				}
			}
		}
	}
}

bool lastShark() {
	for (int i = 2; i <= M; ++i) {
		if (shark[i].r != -1) return false;
	}
	return true;
}

int solution() {
	int ans = 0;
	while (ans < 1000) {
		smellRemove();
		move();
		smellSpread();
		ans++;

		if (lastShark()) return ans;
	}

	return -1;
}

int main() {
	cin >> N >> M >> k;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int num; cin >> num;
			if (num != 0) {
				shark[num].r = i;
				shark[num].c = j;
			}
		}
	}
	for (int i = 1; i <= M; ++i) {
		cin >> shark[i].d;
		shark[i].d--;
	}
	for (int i = 1; i <= M; ++i) {
		vector<vector<int>> p;
		for (int j = 0; j < 4; ++j) {
			vector<int> tmp(4);
			cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
			p.push_back(tmp);
		}
		prior[i] = p;
	}

	smellSpread();
	cout << solution();

	return 0;
}