#include <bits/stdc++.h>
#define MAX 32001

using namespace std;

int N, M;
vector<int> info[MAX];
int entry[MAX];

void solution() {
	vector<int> ans;
	queue<int> q;
	
	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		ans.push_back(cur);

		for (auto next : info[cur]) {
			entry[next]--;

			if (entry[next] == 0) //선행되어야할 모든 노드를 방문한 경우 (다음 노드의 진입 차수가 0)
				q.push(next);	  //다음 노드로 이동 가능
		}
	}

	for (auto a : ans)
		cout << a << " ";
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		entry[b]++; //위상정렬
	}

	solution();

	return 0;
}