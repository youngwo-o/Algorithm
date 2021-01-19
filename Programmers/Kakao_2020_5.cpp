#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool board[2][101][101] = { false };

bool check(int a, int x, int y) {
	//기둥
	if (a == 0) {
		//바닥에 설치하는 경우
		if (y == 0)
			return true;
		else {
			//기둥 위에 있거나 보의 한쪽 끝 위에 있는 경우
			if (board[0][x][y - 1] || board[1][x][y] || board[1][x - 1][y])
				return true;
		}
	}
	//보
	else if (a == 1) {
		//한쪽 끝이 기둥 위에 있는 경우
		if (board[0][x][y - 1] || board[0][x + 1][y - 1])
			return true;
		//양쪽 끝이 보와 연결되어 있는 경우
		else if (board[1][x - 1][y] && board[1][x + 1][y])
			return true;
	}

	return false;
}

void eliminate(int a, int x, int y) {
	bool res = true;

	board[a][x][y] = false;

	//기둥
	if (a == 0) {
		//삭제할 수 있는지 확인
		//위에 기둥이 있는 경우
		if (board[0][x][y + 1] && check(0, x, y + 1) == false)
			res = false;
		//왼쪽에 보가 있는 경우
		else if (board[1][x - 1][y + 1] && check(1, x - 1, y + 1) == false)
			res = false;
		//오른쪽에 보가 있는 경우
		else if (board[1][x][y + 1] && check(1, x, y + 1) == false)
			res = false;
	}
	//보
	else if (a == 1) {
		//삭제할 수 있는지 확인
		//왼쪽 위에 기둥이 있는 경우
		if (board[0][x][y] && check(0, x, y) == false)
			res = false;
		//오른 위에 기둥이 있는 경우
		else if (board[0][x + 1][y] && check(0, x + 1, y) == false)
			res = false;
		//왼쪽에 보가 있는 경우
		else if (board[1][x - 1][y] && check(1, x - 1, y) == false)
			res = false;
		//오른쪽에 보가 있는 경우
		else if (board[1][x + 1][y] && check(1, x + 1, y) == false)
			res = false;
	}

	if (res == false)
		board[a][x][y] = true;
}

void solution(int n, vector<vector<int>> build_frame) {
	for (int i = 0; i < build_frame.size(); ++i) {
		int x, y, a, b;
		x = build_frame[i][0];
		y = build_frame[i][1];
		a = build_frame[i][2];
		b = build_frame[i][3];

		//삭제
		if (b == 0)
			eliminate(a, x, y);
		//설치
		else if (b == 1) {
			if (check(a, x, y) == true)
				board[a][x][y] = true;
		}
	}
}

int main() {
	int n = 5;
	vector<vector<int>> build_frame = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };

	solution(n, build_frame);

	vector<vector<int>> ans;
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			if (board[0][i][j] == true)
				ans.push_back({ i, j, 0 });
			if (board[1][i][j] == true)
				ans.push_back({ i, j, 1 });
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	}

	return 0;
}