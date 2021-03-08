#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int N, M;
vector<string> board;
pii red, blue, hole;
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void move(pii& next1, pii& next2, int i) { //���� ������ ��ġ, �� �� ������ ��ġ, �̵� ����
	if (board[next1.first][next1.second] == '#') { //���� ������ ��ġ�� ���� ��� -> �ڷ� ��ĭ �̵�
		next1.first -= d[i][0];
		next1.second -= d[i][1];
	}

	//���� ������ ��ġ�� �� �� ������ ��ġ�� ���� �ش� ��ġ�� ������ �ƴ� ��� / �� �� ������ ���� ������ ���
	if ((next1 == next2 && next1 != hole) || board[next2.first][next2.second] == '#') {
		next2.first -= d[i][0]; //�� �� ������ �ڷ� ��ĭ �̵�
		next2.second -= d[i][1];
	}
	else if (board[next2.first][next2.second] == '.') { //�� �� ������ ���� �̵� ������ ���
		while (1) { //�� �� ������ �ٽ� �̵�
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

		//�̵� Ƚ���� 10�� �Ѵ� ���, �Ķ� ������ ���ۿ� ���� ��� �� �̻� ���� �Ұ�
		if (visited[{nowRed, nowBlue}] > 10 || nowBlue == hole) continue;
		//���� ������ ���ۿ� ���� ��� ����� ����
		if (nowRed == hole) return visited[{nowRed, nowBlue}];

		for (int i = 0; i < 4; ++i) { //������� �̵�
			pii nextRed = nowRed;
			pii nextBlue = nowBlue;

			//���� ����, �Ķ� ���� ���� �̵�
			while (1) {
				bool check = false;
				nextRed.first += d[i][0];
				nextRed.second += d[i][1];
				nextBlue.first += d[i][0];
				nextBlue.second += d[i][1];

				//���� ������ ���� �����ų� ������ ������ ��� -> move()�� ���� �Ķ� ���� ��ġ ����
				if (board[nextRed.first][nextRed.second] == '#' || board[nextRed.first][nextRed.second] == 'O') {
					move(nextRed, nextBlue, i);
					check = true;
				}
				//�Ķ� ������ ���� �����ų� ������ ������ ��� -> move()�� ���� ���� ���� ��ġ ����
				else if (board[nextBlue.first][nextBlue.second] == '#' || board[nextBlue.first][nextBlue.second] == 'O') {
					move(nextBlue, nextRed, i);
					check = true;
				}

				if (check) {
					//���� ��������, �Ķ� ������ ��ġ�� ������ �湮���� ���� ��� �湮 ����
					if (visited.find({ nextRed, nextBlue }) == visited.end()) {
						visited[{nextRed, nextBlue}] = visited[{nowRed, nowBlue}] + 1;
						q.push({ nextRed, nextBlue });
					}
					else {//������ �湮�� ���
						  //�̵� Ƚ���� �� ���� ��� �ٽ� �湮 ����
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