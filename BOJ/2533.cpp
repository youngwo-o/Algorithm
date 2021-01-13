#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> f(1000001);
vector<vector<int>> newF(1000001);
int dp[1000001][2];
int visited[1000001] = { 0 };

void dfs(int node) {
	visited[node] = 1;
	for (int i = 0; i < f[node].size(); ++i) {
		int next = f[node][i];
		if (visited[next] == 0) {
			newF[node].push_back(next);
			dfs(next);
		}
	}
}

int solution(int now, int flag) {
	int& res = dp[now][flag];
	if (res != -1)
		return res;

	res = 0;

	if (flag == 0) {
		for (int i = 0; i < newF[now].size(); ++i) {
			res += solution(newF[now][i], 1);
		}
	}
	else if (flag == 1) {
		for (int i = 0; i < newF[now].size(); ++i) {
			int tmp1 = solution(newF[now][i], 0);
			int tmp2 = solution(newF[now][i], 1);

			res += min(tmp1, tmp2);
		}

		res++;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;

		f[u].push_back(v);
		f[v].push_back(u);
	}

	dfs(1);

	memset(dp, -1, sizeof(dp));

	cout << min(solution(1, 0), solution(1, 1));

	return 0;
}