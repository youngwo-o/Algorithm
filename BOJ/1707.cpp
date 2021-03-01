#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> info(20001);
vector<int> visited(20001, 0);

bool dfs(int idx, int check) {
	visited[idx] = check;
	for (auto nextIdx : info[idx]) {
		if (visited[nextIdx] == check) return false; //����Ŭ�� �����ϴ� ��� ����
		else if(visited[nextIdx] == 0) //������ �湮���� ���� ���
			if(!dfs(nextIdx, check * -1)) return false; //���Ϲ��� ���� false�� ��쿡�� ���� (true�� ���, ���� ������ Ȯ���ؾ���)
	}
	return true;
}

string solution() {
	//��� ������ Ȯ���ؾ��� (��� �������� ����Ǿ� �ִ� ���� �ƴϱ� ����)
	for (int i = 1; i <= V; ++i) {
		if (visited[i] == 0) //������ �湮���� ���� ���
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