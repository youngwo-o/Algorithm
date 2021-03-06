#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, K, M;
vector<int> tube[MAX + 1000];
int visited[MAX + 1000];

int solution() {
	queue<int> q;

	visited[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == N) return visited[cur];

		for (auto next : tube[cur]) {
			if (visited[next] == 0) {
				if (next > N) visited[next] = visited[cur]; //튜브인 경우
				else visited[next] = visited[cur] + 1; //역인 경우
				q.push(next);
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> M;
	for (int i = 1; i <= M; ++i) {
		for (int j = 0; j < K; ++j) {
			int a;
			cin >> a;				  //더미 노드 사용 (N + 1 인덱스부터)
			tube[a].push_back(i + N); //역의 인덱스에는 해당 튜브의 번호 저장
			tube[i + N].push_back(a); //튜브의 인덱스에는 역의 인덱스 저장
		}
	}

	cout << solution();

	return 0;
}