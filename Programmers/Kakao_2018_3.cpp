#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int ans = 0;

bool fourBlock(int r, int c, vector<string> board, vector<string>& newBoard) {
	int m = board.size();
	int n = board[0].size();

	char b = board[r][c];

	int dr[3] = { 0, 1, 1 };
	int dc[3] = { 1, 0, 1 };

	//���� ��ġ ���� 3���� Ȯ��
	for (int i = 0; i < 3; ++i) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];

		if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n)
			return false;

		if (board[nextR][nextC] != b)
			return false;
	}

	//newBoard���� ����
	newBoard[r][c] = ' ';
	for (int i = 0; i < 3; ++i) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];

		newBoard[nextR][nextC] = ' ';
	}

	return true;
}

bool check(int m, int n, vector<string>& board) {
	vector<string> newBoard = board;
	bool checkEnd = false;

	//��ü ��� Ž��
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] != ' ') {
				//2X2 �������� Ȯ��
				if (fourBlock(i, j, board, newBoard))
					checkEnd = true;
			}
		}
	}

	//2X2 ���°� ���� ��� break�ϱ� ���� false return
	if (!checkEnd)
		return false;

	//���ŵ� ��� ���� Ȯ��
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] != newBoard[i][j])
				ans++;
		}
	}

	//��� ����Ʈ����
	for (int j = 0; j < n; ++j) {
		queue<char> q;
		for (int i = m - 1; i >= 0; --i) {
			if (newBoard[i][j] != ' ')
				q.push(newBoard[i][j]);

			newBoard[i][j] = ' ';
		}

		for (int i = m - 1; i >= 0; --i) {
			if (!q.empty()) {
				newBoard[i][j] = q.front();
				q.pop();
			}
			else
				newBoard[i][j] = ' ';
		}
	}

	//���� ����
	board = newBoard;

	return true;
}

int solution(int m, int n, vector<string> board) {
	while (1) {
		if (!check(m, n, board))
			break;
	}

	return ans;
}

int main() {
	cout << solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" });

	return 0;
}