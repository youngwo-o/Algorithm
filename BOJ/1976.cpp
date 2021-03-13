#include <bits/stdc++.h>
#define MAX 201

using namespace std;

int N, M;
int adj[MAX][MAX];
vector<int> plan;

string solution() {
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
			}
		}
	}

	if (plan.size() <= 1) return "YES";

	for (int i = 0; i < plan.size() - 1; ++i) {
		int a = plan[i], b = plan[i + 1];
		if (!adj[a][b]) return "NO";
	}

	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> adj[i][j];
			if (i == j) adj[i][j] = 1; //1 -> 1 로 가는 경우도 있음...ㅜㅜ
		}
	}
	for (int i = 0; i < M; ++i) {
		int p; cin >> p;
		plan.push_back(p);
	}

	cout << solution();

	return 0;
}