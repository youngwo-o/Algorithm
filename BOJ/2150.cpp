#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int V, E;
vector<int> edge[MAX], edgeRev[MAX];
vector<vector<int>> ans(MAX);
bool visited[MAX];
stack<int> s;
int cnt = 0;

void dfs(int idx) {
	visited[idx] = true;
	for (auto next : edge[idx]) {
		if (!visited[next]) {
			dfs(next);
			s.push(next); //dfs에서 되돌아오면 스택에 삽입
		}
	}
}

void dfsRev(int idx) {
	visited[idx] = true;
	ans[cnt].push_back(idx); //같은 SCC로 저장하기
	for (auto next : edgeRev[idx]) {
		if (!visited[next]) {
			dfsRev(next);
		}
	}
}

bool cmp(const vector<int> a, const vector<int> b) {
	return a[0] < b[0];
}

void solution() {
	//SCC (Strongly Connected Component)
	//코사라주 알고리즘
	for (int i = 1; i <= V; ++i) {
		//정방향 dfs 탐색해서 끝나는 정점들을 순서대로 스택에 삽입
		if (!visited[i]) {
			dfs(i);
			s.push(i);
		}
	}
	memset(visited, 0, sizeof(visited));
	while (!s.empty()) {
		int idx = s.top();
		s.pop();

		if (!visited[idx]) {
			dfsRev(idx); //스택의 탑에서부터 역방향 dfs 탐색
			cnt++; //SCC 개수 1 증가
		}
	}

	for (int i = 0; i < cnt; ++i) { //같은 SCC 내 정점들을 오름차순 정렬
		sort(ans[i].begin(), ans[i].end());
	}
	
	sort(ans.begin(), ans.begin() + cnt, cmp); //SCC 내 최소 정점의 번호 순으로 모든 SCC 정렬
	
	cout << cnt << "\n";
	for (int i = 0; i < cnt; ++i) {
		for (auto a : ans[i]) {
			cout << a << " ";
		}
		cout << "-1\n";
	}
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edgeRev[b].push_back(a);
	}

	solution();

	return 0;
}