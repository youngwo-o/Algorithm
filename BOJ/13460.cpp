#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int N, M;
vector<string> board;
pii red, blue, hole;
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void move(pii& next1, pii& next2, int i) { //멈춘 구슬의 위치, 그 외 구슬의 위치, 이동 방향
	if (board[next1.first][next1.second] == '#') { //멈춘 구슬의 위치가 벽인 경우 -> 뒤로 한칸 이동
		next1.first -= d[i][0];
		next1.second -= d[i][1];
	}

	//멈춘 구슬의 위치와 그 외 구슬의 위치가 같고 해당 위치가 구멍이 아닌 경우 / 그 외 구슬이 벽을 만나는 경우
	if ((next1 == next2 && next1 != hole) || board[next2.first][next2.second] == '#') {
		next2.first -= d[i][0]; //그 외 구슬을 뒤로 한칸 이동
		next2.second -= d[i][1];
	}
	else if (board[next2.first][next2.second] == '.') { //그 외 구슬이 아직 이동 가능한 경우
		while (1) { //그 외 구슬만 다시 이동
			next2.first += d[i][0];
			next2.second += d[i][1];

			if ((next2 == next1 && next2 != hole) || board[next2.first][next2.second] == '#') {
				next2.first -= d[i][0];
				next2.second -= d[i][1];
				break;
			}
			else if (board[next2.first][next2.second] == 'O')
				break;
		}
	}
}

int solution() {
	queue<pair<pii,pii>> q;
	map<pair<pii, pii>, int> visited;

	q.push({ red, blue });
	visited[{red, blue}] = 0;

	while (!q.empty()) {
		pii nowRed = q.front().first;
		pii nowBlue = q.front().second;
		q.pop();

		//이동 횟수가 10을 넘는 경우, 파란 구슬이 구멍에 들어가는 경우 더 이상 진행 불가
		if (visited[{nowRed, nowBlue}] > 10 || nowBlue == hole) continue;
		//빨간 구슬이 구멍에 들어가는 경우 결과값 리턴
		if (nowRed == hole) return visited[{nowRed, nowBlue}];

		for (int i = 0; i < 4; ++i) { //사방으로 이동
			pii nextRed = nowRed;
			pii nextBlue = nowBlue;

			//빨간 구슬, 파란 구슬 동시 이동
			while (1) {
				bool check = false;
				nextRed.first += d[i][0];
				nextRed.second += d[i][1];
				nextBlue.first += d[i][0];
				nextBlue.second += d[i][1];

				//빨간 구슬이 벽을 만나거나 구멍을 만나는 경우 -> move()를 통해 파란 구슬 위치 지정
				if (board[nextRed.first][nextRed.second] == '#' || board[nextRed.first][nextRed.second] == 'O') {
					move(nextRed, nextBlue, i);
					check = true;
				}
				//파란 구슬이 벽을 만나거나 구멍을 만나는 경우 -> move()를 통해 빨간 구슬 위치 지정
				else if (board[nextBlue.first][nextBlue.second] == '#' || board[nextBlue.first][nextBlue.second] == 'O') {
					move(nextBlue, nextRed, i);
					check = true;
				}

				if (check) {
					//다음 빨간구슬, 파란 구슬의 위치를 이전에 방문하지 않은 경우 방문 가능
					if (visited.find({ nextRed, nextBlue }) == visited.end()) {
						visited[{nextRed, nextBlue}] = visited[{nowRed, nowBlue}] + 1;
						q.push({ nextRed, nextBlue });
					}
					else {//이전에 방문한 경우
						  //이동 횟수가 더 작은 경우 다시 방문 가능
						if (visited[{nextRed, nextBlue}] > visited[{nowRed, nowBlue}] + 1) {
							visited[{nextRed, nextBlue}] = visited[{nowRed, nowBlue}] + 1;
							q.push({ nextRed, nextBlue });
						}
					}
					break;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		board.push_back(str);
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 'R') {
				red = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'O') hole = { i, j };
		}
	}

	cout << solution();

	return 0;
}