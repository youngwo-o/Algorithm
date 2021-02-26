#include <bits/stdc++.h>

using namespace std;

int MAX = 500000;
int N, K;
//s초에서 p이면, s + 2초에서 p일 수 있음
//홀수/짝수 초로 나누어서 visited 체크
vector<vector<bool>> visited(MAX + 1, vector<bool>(2, 0));

int solution() {
	int sec = 0;
	queue<pair<int, int>> q;

	if (N == K) return 0;

	q.push( {N, 0} );

	while (1) {
		K += sec; //동생의 위치 변경

		if (K > MAX) return -1;
		if (visited[K][sec % 2]) return sec;

		//1초 동안 갈 수 있는 모든 경우의 수
		for (int i = 0, qSize = q.size(); i < qSize; ++i) {
			int curN = q.front().first;
			int newSec = (q.front().second + 1) % 2;
			q.pop();

			int nextN;
			for (int j = 0; j < 3; ++j) {
				if (j == 0) nextN = curN - 1;
				else if (j == 1) nextN = curN + 1;
				else if (j == 2) nextN = curN * 2;

				if (nextN < 0 || nextN > MAX || visited[nextN][newSec]) continue;

				visited[nextN][newSec] = true;
				q.push({ nextN, newSec });
			}
		}

		sec++; //1초 증가
	}
}

int main() {
	cin >> N >> K;

	cout << solution();

	return 0;
}