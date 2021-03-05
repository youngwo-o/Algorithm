#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int N, M, S, T;
vector<int> info[MAX], infoRev[MAX], newInfo[MAX];
int visited[MAX];
stack<int> s;
int cnt = 0;
int scc[MAX], sccLen[MAX];

void dfs(int idx) {
	visited[idx] = 1;
	for (auto next : info[idx]) {
		if (!visited[next])
			dfs(next);
	}
	s.push(idx);
}

void dfsRev(int idx) {
	visited[idx] = 1;
	scc[idx] = cnt;
	sccLen[cnt]++;
	for (auto next : infoRev[idx]) {
		if (!visited[next])
			dfsRev(next);
		else { //�̹� �湮�� ������ ���
			if (scc[next] != scc[idx]) //���� ������ �ٸ� SCC�� ���ϸ�
				newInfo[scc[next]].push_back(scc[idx]); //���� ���� ����
		}
	}
}

void solution() {
	//SCC, �ڻ����
	for (int i = 1; i <= N; ++i) {
		if (!visited[i])
			dfs(i);
	}
	memset(visited, 0, sizeof(visited));
	while (!s.empty()) {
		int idx = s.top();
		s.pop();

		if (!visited[idx]) {
			dfsRev(idx);
			cnt++;
		}
	}

	memset(visited, 0, sizeof(visited));
	queue<int> q;
	int startScc = scc[S];
	q.push(startScc);
	visited[startScc] = sccLen[startScc];
	int ans = 0;
	while (!q.empty()) {
		int curScc = q.front();
		q.pop();

		if (curScc == scc[T]) { //���� ������ SCC�� ���� SCC���
			ans = max(ans, visited[curScc]);
			break;
		}

		for (auto next : newInfo[curScc]) {
			//������� ������ ������ ���� �� ū �͸�
			if (visited[next] < visited[curScc] + sccLen[next]) {
				visited[next] = visited[curScc] + sccLen[next];
				q.push(next);
			}
		}
	}

	cout << ans;
}

int main() {
	cin >> N >> M >> S >> T;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		infoRev[b].push_back(a);
	}

	solution();

	return 0;
}