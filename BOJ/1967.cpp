#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int n;
vector<pair<int,int>> adj[MAX];
int tmp, node, dist[MAX];

void dfs(int idx, int d) {
	dist[idx] = d;

	if (dist[idx] > tmp) { //�ִ밪�� ���
		tmp = dist[idx]; //����� ����
		node = idx; //��� ����
	}

	for (auto next : adj[idx]) {
		if (dist[next.first] == -1) //������ �湮���� ���� ���
			dfs(next.first, d + next.second);
	}
}

void solution() {
	/* 
	 * � �������� ����ص� ���� �ָ� �ִ� ������ ���� ������ �ش��ϴ� �� ���� �߿� �ϳ�
	 * ����, ��Ʈ�� ������������ ���ϰ�, ���� �ָ� �ִ� ������ ã�� (���� ������ �ش��ϴ� ���� 1)
	 * �ش� �������� ���� �ָ� �ִ� ������ ã�� (���� ������ �ش��ϴ� ���� 2)
	 * �� �� ���� ������ �Ÿ��� Ʈ���� ������ ��
	 */
	memset(dist, -1, sizeof(dist));
	dfs(1, 0); //��Ʈ ��忡�� ���� �� ���� ã��
	memset(dist, -1, sizeof(dist));
	tmp = 0;
	dfs(node, 0); //ã�� �������� ���� �� ���� ã��
	cout << tmp; //�ִ밪�� Ʈ���� ����
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; 
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	
	solution();

	return 0;
}