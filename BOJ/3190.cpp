#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int N;
int board[MAX][MAX];
queue<pair<int,char>> command;
int direct[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} }; //오, 위, 왼, 아

int solution() {
	deque<pair<int, int>> snake; //뱀의 위치를 머리에서 꼬리까지 순서대로 저장
	snake.push_back({ 1, 1 }); //뱀의 처음 위치 (길이 1)
	board[1][1] = 1; //현재 위치를 뱀으로

	int t = 0, d = 0; //현재 시간, 방향
	int comT, comD; //방향 변환 시간, 방향
	while (1) {
		if (!command.empty()) {
			comT = command.front().first;
			comD = command.front().second;
			command.pop();
		}
		else comT += 10000; //명령이 더 이상 없는 경우 -> 현재 방향으로 끝까지 이동하도록
		
		int hr = snake.front().first, hc = snake.front().second; //뱀 머리
		int tr = snake.back().first, tc = snake.back().second; //뱀 꼬리
		while (t < comT) { //방향 변환 시간이 될때까지
			t++; //현재 시간 증가
			hr += direct[d][0]; //뱀 머리 위치 이동
			hc += direct[d][1];

			if (hr <= 0 || hr > N || hc <= 0 || hc > N || board[hr][hc] == 1) //벽, 자기자신과 부딪히는 경우
				return t;

			snake.push_front({ hr, hc }); //이동한 뱀 머리 위치를 snake의 맨 앞에 저장

			if (board[hr][hc] == 0) { //이동한 칸에 사과가 없다면
				board[tr][tc] = 0; //현재 꼬리 위치를 빈공간으로
				snake.pop_back(); //snake에서 현재 꼬리 위치 빼기
				tr = snake.back().first; //snake의 맨 마지막 값으로 꼬리 위치 갱신
				tc = snake.back().second;
			}
			board[hr][hc] = 1; //이동한 위치를 뱀으로
		}

		//방향 전환
		comD == 'L' ? d += 1 : d -= 1;
		if (d == -1) d = 3;
		else if (d == 4) d = 0;
	}

	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K, L;
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		int r, c; cin >> r >> c;
		board[r][c] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; ++i) {
		int x; char c; cin >> x >> c;
		command.push({ x, c });
	}

	cout << solution();

	return 0;
}