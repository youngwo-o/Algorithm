#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 20
#define V_MAX 1024

using namespace std;

int w, h;
vector<string> room;
pii robot; //�κ��� ���� ��ġ
map<pii, int> dirty; //������ ���� �ε����� ��ġ������ �ٷ� ������ �� �ֵ���
int cnt = 0; //������ ���� �ε���
int visited[MAX][MAX][V_MAX]; //visited[i][j][k] : (i,j) ��ġ���� k�� ��Ʈ �ε����� �ش��ϴ� ���� û�������� �ּ� �̵� Ƚ��
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int solution() {
	int ans = INT_MAX;
	queue<pair<pii,int>> q;
	memset(visited, 0x3f, sizeof(visited));

	visited[robot.first][robot.second][0] = 0;
	q.push({ robot, 0 });

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int v = q.front().second;
		q.pop();

		if (v == pow(2, cnt) - 1) //��� û���� ���
			return visited[r][c][v];

		for (int i = 0; i < 4; ++i) {
			int nr = r + d[i][0];
			int nc = c + d[i][1];
			int nv = v;

			if (nr < 0 || nr >= h || nc < 0 || nc >= w || room[nr][nc] == 'x') continue;

			if (room[nr][nc] == '*' || room[nr][nc] == '.') {
				if (room[nr][nc] == '*') //������ ���� ���
					nv |= (1 << dirty[{nr, nc}]); //��Ʈ���� �ش� ��ġ�� dirty �ε��� �湮 üũ

				if (visited[nr][nc][nv] > visited[r][c][v] + 1) {
					visited[nr][nc][nv] = visited[r][c][v] + 1;
					q.push({ {nr,nc}, nv });
				}
			}
		}
	}

	return -1;
}

int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; ++i) {
			string str;
			cin >> str;
			room.push_back(str);
			for (int j = 0; j < w; ++j) {
				if (room[i][j] == 'o') {
					robot = { i, j };
					room[i][j] = '.'; //��������� ����
				}
				else if (room[i][j] == '*') dirty[{i, j}] = cnt++;
			}
		}

		cout << solution() << "\n";

		room.clear();
		dirty.clear();
		cnt = 0;
	}

	return 0;
}