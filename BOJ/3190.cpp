#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int N;
int board[MAX][MAX];
queue<pair<int,char>> command;
int direct[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} }; //��, ��, ��, ��

int solution() {
	deque<pair<int, int>> snake; //���� ��ġ�� �Ӹ����� �������� ������� ����
	snake.push_back({ 1, 1 }); //���� ó�� ��ġ (���� 1)
	board[1][1] = 1; //���� ��ġ�� ������

	int t = 0, d = 0; //���� �ð�, ����
	int comT, comD; //���� ��ȯ �ð�, ����
	while (1) {
		if (!command.empty()) {
			comT = command.front().first;
			comD = command.front().second;
			command.pop();
		}
		else comT += 10000; //����� �� �̻� ���� ��� -> ���� �������� ������ �̵��ϵ���
		
		int hr = snake.front().first, hc = snake.front().second; //�� �Ӹ�
		int tr = snake.back().first, tc = snake.back().second; //�� ����
		while (t < comT) { //���� ��ȯ �ð��� �ɶ�����
			t++; //���� �ð� ����
			hr += direct[d][0]; //�� �Ӹ� ��ġ �̵�
			hc += direct[d][1];

			if (hr <= 0 || hr > N || hc <= 0 || hc > N || board[hr][hc] == 1) //��, �ڱ��ڽŰ� �ε����� ���
				return t;

			snake.push_front({ hr, hc }); //�̵��� �� �Ӹ� ��ġ�� snake�� �� �տ� ����

			if (board[hr][hc] == 0) { //�̵��� ĭ�� ����� ���ٸ�
				board[tr][tc] = 0; //���� ���� ��ġ�� ���������
				snake.pop_back(); //snake���� ���� ���� ��ġ ����
				tr = snake.back().first; //snake�� �� ������ ������ ���� ��ġ ����
				tc = snake.back().second;
			}
			board[hr][hc] = 1; //�̵��� ��ġ�� ������
		}

		//���� ��ȯ
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