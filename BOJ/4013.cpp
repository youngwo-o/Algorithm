#include <bits/stdc++.h>
#define MAX 500001

using namespace std;

int N, M, S, P;
vector<int> info[MAX], infoRev[MAX]; //SCC �ڻ����
stack<int> s;
bool visited[MAX]; //dfs �� �湮 üũ
vector<int> newInfo[MAX]; //SCC ���� ���� ���� ����
int atm[MAX]; //atm ���� ����
int scc[MAX], sccAtm[MAX]; //�� ������ ��� SCC�� �ش��ϴ��� / �� ��ȣ�� SCC�� ���� ���� ����
int rest[MAX]; //��������� ������ ��� SCC�� �ش��ϴ���
int dp[MAX]; //���� ������ �ִ� ���� �׼� �ӽ� ����
int cnt = 0; //SCC ��ȣ

void dfs(int idx) {
	visited[idx] = true;
	for (auto next : info[idx]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
	s.push(idx);
}

void dfsRev(int idx) {
	visited[idx] = true;
	scc[idx] = cnt; //���� ������ ��� �ε����� �ش��ϴ��� ����
	sccAtm[cnt] += atm[idx]; //�ش� ��ȣ�� SCC�� ���� ������ ���� ����
	for (auto next : infoRev[idx]) {
		if (!visited[next])
			dfsRev(next);
		else { //�̹� �湮�� ���� ��� -> ��� SCC�� �ش��ϴ��� Ȯ��
			if (scc[next] != scc[idx]) //���� SCC�� �ش����� ���� ���
				newInfo[scc[next]].push_back(scc[idx]); //���� SCC�� ���� -> newInfo ���� ���� ����
		}
	}
}

void solution() {
	//SCC �����
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

	//��������� ���� scc�� 1�� ǥ��
	for (int i = 0; i < P; ++i) {
		int r;
		cin >> r;
		rest[scc[r]] = 1;
	}

	queue<int> q;
	q.push(scc[S]); //���� ������ SCC ��ȣ�� ť�� �ֱ�
	dp[scc[S]] = sccAtm[scc[S]]; //���� ������ SCC�� ���� ���� dp�� ����

	int ans = 0;
	while (!q.empty()) {
		int curScc = q.front();
		q.pop();

		if (rest[curScc]) //���� SCC�� ��������� �ִ� ���
			ans = max(ans, dp[curScc]); //�ִ밪���� ����

		for (auto next : newInfo[curScc]) {
			//���� SCC�� ��ġ�� ��찡 �ִ� ���� ���� ��츸
			if (dp[next] < dp[curScc] + sccAtm[next]) {
				dp[next] = dp[curScc] + sccAtm[next];
				q.push(next);
			}
		}
	}

	cout << ans;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		infoRev[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		cin >> atm[i];
	}
	cin >> S >> P;

	solution();

	return 0;
}