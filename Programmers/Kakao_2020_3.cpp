#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key) {
	vector<vector<int>> newKey(key.size(), vector<int>(key.size()));

	for (int i = 0; i < key.size(); ++i) {
		for (int j = 0; j < key.size(); ++j) {
			newKey[j][key.size() - 1 - i] = key[i][j];
		}
	}

	return newKey;
}

bool match(int m, int n, vector<vector<int>> board) {
	for (int i = m - 1; i < m - 1 + n; ++i) {
		for (int j = m - 1; j < m - 1 + n; ++j) {
			//보드와 열쇠를 더한값이 1이 아닌 경우 (돌기 + 돌기, 홈 + 홈) -> 실패
			if (board[i][j] != 1)
				return false;
		}
	}

	return true;
}

vector<vector<int>> sum(int r, int c, vector<vector<int>> key, vector<vector<int>> board) {
	int x = 0, y = 0;
	for (int i = r; i < r + key.size(); ++i) {
		for (int j = c; j < c + key.size(); ++j) {
			board[i][j] += key[x][y];
			y++;
		}
		x++;
		y = 0;
	}

	return board;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int boardSize = key.size() * 2 + lock.size() - 2;
	vector<vector<int>> board(boardSize, vector<int>(boardSize));

	int n = lock.size(), m = key.size();

	//새로운 보드에 자물쇠 정보 위치에 맞게 저장
	int x = 0, y = 0;
	for (int i = m - 1; i < m - 1 + n; ++i) {
		for (int j = m - 1; j < m - 1 + n; ++j) {
			board[i][j] = lock[x][y];
			y++;
		}
		x++;
		y = 0;
	}

	//보드에 열쇠를 대입시켜보기
	for (int i = 0; i <= boardSize - m; ++i) {
		for (int j = 0; j <= boardSize - m; ++j) {
			//4가지 방향
			for (int k = 0; k < 4; ++k) {
				//보드와 열쇠 더하기
				vector<vector<int>> tmp = sum(i, j, key, board);

				//자물쇠와 열쇠가 맞는지 확인
				if (match(key.size(), lock.size(), tmp) == true)
					return true;

				//열쇠 회전
				key = rotate(key);
			}
		}
	}

	return false;
}

int main() {
	vector<vector<int>> key = { {0, 0, 0}, { 1,0,0 }, { 0,1,1 } };
	vector<vector<int>> lock = { {1, 1, 1}, { 1,1,0 }, { 1,0,1 } };

	if (solution(key, lock) == true)
		cout << "true";
	else
		cout << "false";

	return 0;
}