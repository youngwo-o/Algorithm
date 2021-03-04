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

			if (entry[next] == 0) //����Ǿ���� ��� ��带 �湮�� ��� (���� ����� ���� ������ 0)
				q.push(next);	  //���� ���� �̵� ����
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
		entry[b]++; //��������
	}

	solution();

	return 0;
}