#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 1001
#define INF 0x3f3f3f3f

using namespace std;

struct compare {
	bool operator()(pii& a, pii& b) {
		return b.second < a.second;
	}
};

int n, m, k;
vector<pii> adj[MAX];
priority_queue<int> dist[MAX]; //�������� ���� (ū ���� top ����)

void solution() {
	priority_queue<pii, vector<pii>, compare> pq;

	pq.push({ 1, 0 });
	dist[1].push(0);

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		for (pii next : adj[now.first]) {
			int nextDist = next.second + now.second;

			if (dist[next.first].size() < k) { // dist ũ�Ⱑ k ���� ������ dist�� �߰�
				dist[next.first].push(nextDist);
				pq.push({ next.first, nextDist });
			}
			else if(dist[next.first].top() > nextDist) { // ���� dist�� top���� ���� ���� ���
				dist[next.first].pop(); // top ������
				dist[next.first].push(nextDist); // ���ο� ���� dist�� �߰�
				pq.push({ next.first, nextDist });
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (dist[i].size() < k) cout << "-1\n";
		else cout << dist[i].top() << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	solution();

	return 0;
}