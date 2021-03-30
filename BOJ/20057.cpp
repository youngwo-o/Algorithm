#include <bits/stdc++.h>
#define MAX 500

using namespace std;

int N;
int board[MAX][MAX];
int sum, r, c;
int d[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} }; //��, ��, ��, ��

void spread(int r, int c, int d) {
	int sand = board[r][c];
	if (sand == 0) return;
	board[r][c] = 0;

	int movedSand = ((int)(sand * 0.02) + (int)(sand * 0.1) + (int)(sand * 0.07) + (int)(sand * 0.01)) * 2 + (int)(sand * 0.05);
	if (d == 0) { //���� ����
		for (int i = r - 2; i <= r + 2; i += 4) {
			if (i < 0 || i >= N) continue;
			board[i][c] += (sand * 0.02);
		}
		for (int i = r - 1; i <= r + 1; i += 2) {
			if (i < 0 || i >= N) continue;
			if (c - 1 >= 0) board[i][c - 1] += (sand * 0.1);
			board[i][c] += (sand * 0.07);
			if (c + 1 < N) board[i][c + 1] += (sand * 0.01);
		}
		if(c - 2 >= 0) board[r][c - 2] += (sand * 0.05);
		if(c - 1 >= 0) board[r][c - 1] += (sand - movedSand);
	}
	else if (d == 1) { //�Ʒ���
		for (int j = c - 2; j <= c + 2; j += 4) {
			if (j < 0 || j >= N) continue;
			board[r][j] += (sand * 0.02);
		}
		for (int j = c - 1; j <= c + 1; j += 2) {
			if (j < 0 || j >= N) continue;
			if(r - 1 >= 0) 	board[r - 1][j] += (sand * 0.01);
			board[r][j] += (sand * 0.07);
			if (r + 1 < N) board[r + 1][j] += (sand * 0.1);
		}
		if(r + 2 < N) board[r + 2][c] += (sand * 0.05);
		if(r + 1 < N) board[r + 1][c] += (sand - movedSand);
	}
	else if (d == 2) { //������
		for (int i = r - 2; i <= r + 2; i += 4) {
			if (i < 0 || i >= N) continue;
			board[i][c] += (sand * 0.02);
		}
		for (int i = r - 1; i <= r + 1; i += 2) {
			if (i < 0 || i >= N) continue;
			if (c + 1 < N) board[i][c + 1] += (sand * 0.1);
			board[i][c] += (sand * 0.07);
			if (c - 1 >= 0) board[i][c - 1] += (sand * 0.01);
		}
		if (c + 2 < N) board[r][c + 2] += (sand * 0.05);
		if (c + 1 < N) board[r][c + 1] += (sand - movedSand);
	}
	else if (d == 3) { //����
		for (int j = c - 2; j <= c + 2; j += 4) {
			if (j < 0 || j >= N) continue;
			board[r][j] += (sand * 0.02);
		}
		for (int j = c - 1; j <= c + 1; j += 2) {
			if (j < 0 || j >= N) continue;
			if (r + 1 < N) 	board[r + 1][j] += (sand * 0.01);
			board[r][j] += (sand * 0.07);
			if (r - 1 >= 0) board[r - 1][j] += (sand * 0.1);
		}
		if (r - 2 >= 0) board[r - 2][c] += (sand * 0.05);
		if (r - 1 >= 0) board[r - 1][c] += (sand - movedSand);
	}
}

void move(int num) {
	if (num % 2 == 0) { // ¦�� -> ������, ����
		for (int i = 2; i < 4; ++i) {
			int cnt = 0;
			while (cnt < num) {
				cnt++;
				int nr = r + d[i][0];
				int nc = c + d[i][1];

				spread(nr, nc, i);
				r = nr;
				c = nc;
			}
		}
	}
	else { //Ȧ�� -> ����, �Ʒ���
		for (int i = 0; i < 2; ++i) {
			int cnt = 0;
			while (cnt < num) {
				cnt++;
				int nr = r + d[i][0];
				int nc = c + d[i][1];

				spread(nr, nc, i);
				r = nr;
				c = nc;
			}
		}
	}
}

void solution() {
	int cnt = 0;
	r = N / 2, c = N / 2;
	while (++cnt < N) {
		move(cnt);
	}
	//�� ���� �̵�
	for (int j = c - 1; j >= 0; --j) {
		spread(r, j, 0);
	}

	int nowSum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			nowSum += board[i][j];
		}
	}

	cout << sum - nowSum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			sum += board[i][j];
		}
	}

	solution();

	return 0;
}