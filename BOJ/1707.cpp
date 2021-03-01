#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> info(20001);
vector<int> visited(20001, 0);

bool dfs(int idx, int check) {
	visited[idx] = check;
	for (auto nextIdx : info[idx]) {
		if (visited[nextIdx] == check) return false; //사이클이 존재하는 경우 실패
		else if(visited[nextIdx] == 0) //이전에 방문하지 않은 경우
			if(!dfs(nextIdx, check * -1)) return false; //리턴받은 값이 false인 경우에만 리턴 (true인 경우, 다음 간선도 확인해야함)
	}
	return true;
}

string solution() {
	//모든 정점을 확인해야함 (모든 정점끼리 연결되어 있는 것이 아니기 때문)
	for (int i = 1; i <= V; ++i) {
		if (visited[i] == 0) //이전에 방문하지 않은 경우
			if (!dfs(i, 1)) return "NO\n";
	}

	return "YES\n";
}

int main() {
	int K;
	cin >> K;
	for (int t = 1; t <= K; ++t) {
		cin >> V >> E;
		for (int i = 0; i < E; ++i) {
			int a, b;
			cin >> a >> b;
			info[a].push_back(b);
			info[b].push_back(a);
		}

		cout << solution();

		for (int i = 1; i <= V; ++i) {
			info[i].clear();
			visited[i] = 0;
		}
	}

	return 0;
}