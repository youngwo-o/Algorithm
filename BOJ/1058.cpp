#include <bits/stdc++.h>
#define MAX 50
#define INF  2500

using namespace std;

int N;
int adj[MAX][MAX];

int solution() {
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j || i == k || j == k) continue;
				if (adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			// ���� �ƴ� ģ���̰ų� (1) / �� �ٸ� �ǳʼ� �ƴ� ģ�� (2) �� ����
			if (i != j && adj[i][j] <= 2) cnt++;
		}
		ans = max(ans, cnt);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		string str; cin >> str;
		for (int j = 0; j < N; ++j) {
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = (str[j] == 'Y' ? 1 : INF);
		}
	}

	cout << solution();

	return 0;
}