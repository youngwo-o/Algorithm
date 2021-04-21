#include <bits/stdc++.h>
#define MAX 4
#define SHARK 17
#define pii pair<int,int>

using namespace std;

vector<vector<int>> arr(MAX, vector<int>(MAX));
vector<pair<pii, int>> fish(MAX * MAX + 2); //물고기 + 상어 상태 배열
int direct[8][2] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
int ans = 0;

void moveFish() {
	for (int i = 1; i <= MAX * MAX; ++i) {
		int r = fish[i].first.first;
		int c = fish[i].first.second;
		int d = fish[i].second;

		if (r == -1 && c == -1) continue; // 먹힌 물고기인 경우 이동 X

		for (int j = 0; j < 8; ++j) {
			if (d == 8) d = 0;
			int nr = r + direct[d][0];
			int nc = c + direct[d][1];

			if (nr < 0 || nr >= MAX || nc < 0 || nc >= MAX || arr[nr][nc] == SHARK) {
				d++;
				continue;
			}

			int nn = arr[nr][nc];
			fish[i] = { {nr, nc}, d };
			fish[arr[nr][nc]].first = { r, c };
			swap(arr[r][c], arr[nr][nc]);
			break;
		}
	}
}

void solution(int res) {
	// 물고기 이동
	moveFish();

	vector<pair<pii, int>> tmpFish = fish; // 물고기 + 상어 상태 임시 저장
	vector<vector<int>> tmpArr = arr; // 위치 배열 임시 저장

	// 상어 이동
	int cnt = 1;
	while (1) {
		int r = fish[SHARK].first.first, c = fish[SHARK].first.second, d = fish[SHARK].second;
		int nr = r + direct[d][0] * cnt;
		int nc = c + direct[d][1] * cnt;
		cnt++;

		if (nr < 0 || nr >= MAX || nc < 0 || nc >= MAX) break;
		if (arr[nr][nc] == 0) continue;

		int fishNum = arr[nr][nc];
		fish[fishNum].first = { -1, -1 }; // 먹힌 물고기는 위치를 (-1, -1) 로 지정
		fish[SHARK] = { {nr, nc}, fish[fishNum].second };
		arr[nr][nc] = SHARK;
		arr[r][c] = 0;

		solution(res + fishNum);

		// 리턴 후 원상태로 복구
		arr = tmpArr;
		fish = tmpFish;
	}

	ans = max(ans, res);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			int a, b; cin >> a >> b;
			arr[i][j] = a;
			fish[a] = { {i, j}, b - 1 };
		}
	}

	int tmp = arr[0][0];
	fish[SHARK] = { {0,0}, fish[tmp].second };
	fish[tmp].first = { -1, -1 };
	arr[0][0] = SHARK;
	
	solution(tmp);

	cout << ans;

	return 0;
}