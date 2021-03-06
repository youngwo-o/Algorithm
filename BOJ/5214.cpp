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
				if (next > N) visited[next] = visited[cur]; //Ʃ���� ���
				else visited[next] = visited[cur] + 1; //���� ���
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
			cin >> a;				  //���� ��� ��� (N + 1 �ε�������)
			tube[a].push_back(i + N); //���� �ε������� �ش� Ʃ���� ��ȣ ����
			tube[i + N].push_back(a); //Ʃ���� �ε������� ���� �ε��� ����
		}
	}

	cout << solution();

	return 0;
}