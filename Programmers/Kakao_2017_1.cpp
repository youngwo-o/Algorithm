#include <bits/stdc++.h>
#define MAX 100
#define pii pair<int,int>

using namespace std;

bool visited[MAX][MAX];
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int coloring(int r, int c, int m, int n, vector<vector<int>> picture) {
	queue<pii> q;

	visited[r][c] = true;
	q.push({ r, c });

	int cnt = 0;
	while (!q.empty()) {
		int nowR = q.front().first;
		int nowC = q.front().second;
		q.pop();

		cnt++;

		for (int i = 0; i < 4; ++i) {
			int nextR = nowR + d[i][0];
			int nextC = nowC + d[i][1];

			if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n || visited[nextR][nextC]) continue;

			if (picture[nextR][nextC] == picture[nowR][nowC]) {
				visited[nextR][nextC] = true;
				q.push({ nextR, nextC });
			}
		}
	}

	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (picture[i][j] && !visited[i][j]) {
				max_size_of_one_area = max(coloring(i, j, m, n, picture), max_size_of_one_area);
				number_of_area++;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}