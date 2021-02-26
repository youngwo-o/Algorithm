#include <bits/stdc++.h>

using namespace std;

int MAX = 500000;
int N, K;
//s�ʿ��� p�̸�, s + 2�ʿ��� p�� �� ����
//Ȧ��/¦�� �ʷ� ����� visited üũ
vector<vector<bool>> visited(MAX + 1, vector<bool>(2, 0));

int solution() {
	int sec = 0;
	queue<pair<int, int>> q;

	if (N == K) return 0;

	q.push( {N, 0} );

	while (1) {
		K += sec; //������ ��ġ ����

		if (K > MAX) return -1;
		if (visited[K][sec % 2]) return sec;

		//1�� ���� �� �� �ִ� ��� ����� ��
		for (int i = 0, qSize = q.size(); i < qSize; ++i) {
			int curN = q.front().first;
			int newSec = (q.front().second + 1) % 2;
			q.pop();

			int nextN;
			for (int j = 0; j < 3; ++j) {
				if (j == 0) nextN = curN - 1;
				else if (j == 1) nextN = curN + 1;
				else if (j == 2) nextN = curN * 2;

				if (nextN < 0 || nextN > MAX || visited[nextN][newSec]) continue;

				visited[nextN][newSec] = true;
				q.push({ nextN, newSec });
			}
		}

		sec++; //1�� ����
	}
}

int main() {
	cin >> N >> K;

	cout << solution();

	return 0;
}