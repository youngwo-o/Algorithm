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
			s.push(next); //dfs���� �ǵ��ƿ��� ���ÿ� ����
		}
	}
}

void dfsRev(int idx) {
	visited[idx] = true;
	ans[cnt].push_back(idx); //���� SCC�� �����ϱ�
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
	//�ڻ���� �˰���
	for (int i = 1; i <= V; ++i) {
		//������ dfs Ž���ؼ� ������ �������� ������� ���ÿ� ����
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
			dfsRev(idx); //������ ž�������� ������ dfs Ž��
			cnt++; //SCC ���� 1 ����
		}
	}

	for (int i = 0; i < cnt; ++i) { //���� SCC �� �������� �������� ����
		sort(ans[i].begin(), ans[i].end());
	}
	
	sort(ans.begin(), ans.begin() + cnt, cmp); //SCC �� �ּ� ������ ��ȣ ������ ��� SCC ����
	
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