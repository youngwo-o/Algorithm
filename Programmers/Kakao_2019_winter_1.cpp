#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	int row = board.size();
	int col = board[0].size();
	vector<stack<int>> s(col + 1);

	for (int j = 0; j < col; ++j) {
		for (int i = row - 1; i >= 0; --i) {
			if (board[i][j] != 0)
				s[j].push(board[i][j]);
		}
	}

	stack<int> tmp;
	for (auto m : moves) {
		if (!s[m].empty()) {
			int n = s[m].top();
			s[m].pop();

			if (!tmp.empty() && tmp.top() == n) {
				tmp.pop();
				answer += 2;
			}
			else tmp.push(n);
		}
	}

	return answer;
}