#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int N, M;
vector<string> maze;

int solution(pii start) {
	int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(64, -1))); //현재위치, 현재 갖고 있는 키 정보에 따라 최단거리 저장
	queue<pair<pii, pii>> q; //현재위치, 현재 갖고 있는 키 정보, 현재까지 거리

	q.push({ start, {0, 0} });
	visited[start.first][start.second][0] = 0;

	while (!q.empty()) {
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curK = q.front().second.first;
		int curD = q.front().second.second;
		q.pop();

		if (maze[curR][curC] == '1') return curD;

		for (int i = 0; i < 4; ++i) {
			int nextR = curR + d[i][0];
			int nextC = curC + d[i][1];

			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M || maze[nextR][nextC] == '#') continue;

			int nextK = curK;
			char next = maze[nextR][nextC];
			if (islower(next)) //키인 경우
				nextK = (nextK | (1 << (next - 'a'))); //갖고 있는 키 정보 갱신
			else if (isupper(next) && ((nextK & (1 << (next - 'a'))) != (1 << (next - 'a')))) continue; //문이고, 해당 문에 맞는 키를 갖고 있지 않은 경우 -> 넘어감

			int nextD = curD + 1;
			
			//이전에 방문하지 않았거나, 최단거리인 경우
			if (visited[nextR][nextC][nextK] == -1 || nextD < visited[nextR][nextC][nextK]) {
				visited[nextR][nextC][nextK] = nextD;
				q.push({ {nextR, nextC}, {nextK, nextD} });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	pii start;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		maze.push_back(str);

		for (int j = 0; j < M; ++j) {
			if (maze[i][j] == '0') start = { i, j };
		}
	}

	cout << solution(start);

	return 0;
}