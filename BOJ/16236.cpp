#include <bits/stdc++.h>
#define MAX 20
#define pii pair<int,int>

using namespace std;

int N;
int space[MAX][MAX], visited[MAX][MAX];
pii shark;
int sharkSize = 2, cnt = 0;
int d[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

struct cmp { //priority_queue �񱳿����� ����
	bool operator()(pii a, pii b) { //a : �θ� ���, b : ���� ���
		if (a.first > b.first) return true; //���� �������� �������� ����
		else if (a.first == b.first) //���� ���� ���
			if (a.second > b.second) return true; //���� �������� �������� ����
		return false;
	}
};

int eat() {
	priority_queue<pii, vector<pii>, cmp> pq; //�ڷ���, �����̳�, ����� ���� ��
	queue<pair<int, int>> q;

	visited[shark.first][shark.second] = 1;
	q.push(shark);

	int len = -1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		//���� �� �ִ� ������� ���
		if (space[r][c] != 0 && space[r][c] < sharkSize && (len == -1 || len == visited[r][c] - 1)) {
			pq.push({ r, c });
			len = visited[r][c] - 1; //�ִ� �Ÿ� ����
		}

		for (int i = 0; i < 4; ++i) {
			int nr = r + d[i][0];
			int nc = c + d[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;

			if (space[nr][nc] <= sharkSize) {
				visited[nr][nc] = visited[r][c] + 1;
				q.push({ nr, nc });
			}
		}
	}
	
	if (pq.empty()) return -1;
	else {
		int r = pq.top().first;
		int c = pq.top().second;
		shark = { r, c };
		space[r][c] = 0;
		cnt++;
		return visited[r][c] - 1;
	}
}

int solution() {
	int ans = 0;

	while (1) {
		int res = eat();
		if (res == -1) break;
		ans += res;

		if (cnt == sharkSize) {
			sharkSize++;
			cnt = 0;
		}

		memset(visited, 0, sizeof(visited));
	}

	return ans;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				shark = { i, j };
				space[i][j] = 0;
			}
		}
	}

	cout << solution();

	return 0;
}