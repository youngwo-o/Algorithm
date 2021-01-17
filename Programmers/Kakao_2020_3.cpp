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
			//����� ���踦 ���Ѱ��� 1�� �ƴ� ��� (���� + ����, Ȩ + Ȩ) -> ����
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

	//���ο� ���忡 �ڹ��� ���� ��ġ�� �°� ����
	int x = 0, y = 0;
	for (int i = m - 1; i < m - 1 + n; ++i) {
		for (int j = m - 1; j < m - 1 + n; ++j) {
			board[i][j] = lock[x][y];
			y++;
		}
		x++;
		y = 0;
	}

	//���忡 ���踦 ���Խ��Ѻ���
	for (int i = 0; i <= boardSize - m; ++i) {
		for (int j = 0; j <= boardSize - m; ++j) {
			//4���� ����
			for (int k = 0; k < 4; ++k) {
				//����� ���� ���ϱ�
				vector<vector<int>> tmp = sum(i, j, key, board);

				//�ڹ���� ���谡 �´��� Ȯ��
				if (match(key.size(), lock.size(), tmp) == true)
					return true;

				//���� ȸ��
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