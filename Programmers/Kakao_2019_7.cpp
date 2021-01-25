#include <iostream>
#include <vector>

using namespace std;

int checkShape(int r, int c, vector<vector<int>> board) {
	int n = board.size();
	int num = board[r][c];

	if (c + 2 < n && r + 1 < n) {
		if (board[r][c + 1] == num && board[r][c + 2] == num && board[r + 1][c + 2] == num)
			return 1;
		if (board[r + 1][c] == num && board[r + 1][c + 1] == num && board[r + 1][c + 2] == num)
			return 3;
		if (board[r][c + 1] == num && board[r][c + 2] == num && board[r + 1][c] == num)
			return 5;
		if (board[r][c + 1] == num && board[r][c + 2] == num && board[r + 1][c + 1] == num)
			return 11;
	}
	if (c + 1 < n && r + 2 < n) {
		if (board[r][c + 1] == num && board[r + 1][c] == num && board[r + 2][c] == num)
			return 2;
		if (board[r + 1][c] == num && board[r + 2][c] == num && board[r + 2][c + 1] == num)
			return 6;
		if (board[r][c + 1] == num && board[r + 1][c + 1] == num && board[r + 2][c + 1] == num)
			return 8;
		if (board[r + 1][c] == num && board[r + 1][c + 1] == num && board[r + 2][c] == num)
			return 10;
	}
	if (c - 1 >= 0 && r + 2 < n) {
		if (board[r + 1][c] == num && board[r + 2][c] == num && board[r + 2][c - 1] == num)
			return 4;
		if (board[r + 1][c] == num && board[r + 1][c - 1] == num && board[r + 2][c] == num)
			return 12;
	}
	if (c - 2 >= 0 && r + 1 < n) {
		if (board[r + 1][c - 1] == num && board[r + 1][c - 2] == num && board[r + 1][c] == num)
			return 7;
	}
	if (c - 1 >= 0 && c + 1 < n && r + 1 < n) {
		if (board[r + 1][c - 1] == num && board[r + 1][c] == num && board[r + 1][c + 1] == num)
			return 9;
	}
}

bool checkAbove(int r, int c, int num, vector<vector<int>> board) {
	if (num == 3) {
		for (int j = c + 1; j <= c + 2; ++j) {
			for (int i = r; i >= 0; --i) {
				if (board[i][j] != 0)
					return false;
			}
		}
	}
	else if (num == 4) {
		for (int i = r + 1; i >= 0; --i) {
			if (board[i][c - 1] != 0)
				return false;
		}
	}
	else if (num == 6) {
		for (int i = r + 1; i >= 0; --i) {
			if (board[i][c + 1] != 0)
				return false;
		}
	}
	else if (num == 7) {
		for (int j = c - 2; j <= c - 1; ++j) {
			for (int i = r; i >= 0; --i) {
				if (board[i][j] != 0)
					return false;
			}
		}
	}
	else if (num == 9) {
		for (int i = r; i >= 0; --i) {
			if (board[i][c - 1] != 0)
				return false;
			if (board[i][c + 1] != 0)
				return false;
		}
	}
	else
		return false;

	return true;
}

void removeShape(int r, int c, int num, vector<vector<int>>& board) {
	board[r][c] = 0;

	if (num == 3) {
		board[r + 1][c] = 0;
		board[r + 1][c + 1] = 0;
		board[r + 1][c + 2] = 0;
	}
	else if (num == 4) {
		board[r + 1][c] = 0;
		board[r + 2][c] = 0;
		board[r + 2][c - 1] = 0;
	}
	else if (num == 6) {
		board[r + 1][c] = 0;
		board[r + 2][c] = 0;
		board[r + 2][c + 1] = 0;
	}
	else if (num == 7) {
		board[r + 1][c - 1] = 0;
		board[r + 1][c - 2] = 0;
		board[r + 1][c] = 0;
	}
	else if (num == 9) {
		board[r + 1][c - 1] = 0;
		board[r + 1][c] = 0;
		board[r + 1][c + 1] = 0;
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	int n = board.size();

	while (1) {
		int visited[201] = { 0 };
		int cnt = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] != 0 && visited[board[i][j]] == 0) {
					visited[board[i][j]] = 1;

					int res = checkShape(i, j, board);

					if (checkAbove(i, j, res, board)) {
						removeShape(i, j, res, board);
						answer++;
						cnt++;
					}
				}
			}
		}

		if (cnt == 0)
			break;
	}

	return answer;
}

int main() {
	vector<vector<int>> board = { {0,0,0,0,0,0,0,0,0,0 }, { 0,0,0,0,0,0,0,0,0,0 }, { 0,0,0,0,0,0,0,0,0,0 }, { 0,0,0,0,0,0,0,0,0,0 }, { 0,0,0,0,0,0,4,0,0,0 }, { 0,0,0,0,0,4,4,0,0,0 }, { 0,0,0,0,3,0,4,0,0,0 }, { 0,0,0,2,3,0,0,0,5,5 }, { 1,2,2,2,3,3,0,0,0,5 }, { 1,1,1,0,0,0,0,0,0,5 }
};
	cout << solution(board) << endl;

	return 0;
}