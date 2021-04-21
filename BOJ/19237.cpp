#include <bits/stdc++.h>
#define MAX 20
#define pii pair<int,int>

using namespace std;

typedef struct _shark {
	int r, c, d;
}Shark;

int N, M, k;
Shark shark[MAX * MAX + 1];
vector<vector<int>> prior[MAX * MAX + 1]; // �� ����� ���� �켱���� (��, �Ʒ�, ��, ��)
pii smell[MAX][MAX] = { make_pair(0,0) };
int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //��, �Ʒ�, ��, ��

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

	// ��� �̵���Ű��
	for (int i = 1; i <= M; ++i) {
		int r = shark[i].r;
		int c = shark[i].c;
		int d = shark[i].d;

		// �Ѱܳ� ����� ���
		if (r == -1 && c == -1 && d == -1) continue;

		bool check = false;
		Shark mySmell = { -1, -1, -1 };
		for (int j = 0; j < 4; ++j) {
			int nd = prior[i][d][j] - 1;
			int nr = r + direct[nd][0];
			int nc = c + direct[nd][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			// ��� �ڽ��� ������ �ִ� ĭ, ���� ���� (������ ���ŵ��� ���� ��츸)
			if (mySmell.r == -1 && smell[nr][nc].first == i) {
				mySmell = { nr, nc, nd };
				continue;
			}
			// �ƹ� ������ ���� ĭ�� ���
			if (smell[nr][nc].first == 0) {
				check = true;
				moveArr[nr][nc].push_back(i);
				shark[i] = { nr, nc, nd };
				break;
			}
		}

		// �ƹ������� ���� ĭ�� ���� ��� -> �ڽ��� ������ �ִ� ĭ���� �̵��ؾ���
		if (!check) {
			shark[i] = mySmell;
			moveArr[shark[i].r][shark[i].c].push_back(i);
		}
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// ��ĭ�� �������� �ִ� ��� 
			if (moveArr[i][j].size() != 0) {
				sort(moveArr[i][j].begin(), moveArr[i][j].end());
				
				// ��ȣ�� ���� ���� ��� �� ��� �ѾƳ���
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