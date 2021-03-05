#include <bits/stdc++.h>
#define MAX 40001

using namespace std;

int N, M;
vector<pair<int,int>> adj[MAX];
int depth[MAX], parent[MAX];
bool visited[MAX];

void makeTree(int idx) { //Ʈ�� �����
	visited[idx] = true;
	for (auto next : adj[idx]) { //����Ǿ� �ִ� ��� ��� Ž��
		if (!visited[next.first]) { //�湮���� ���� ����� ���
			depth[next.first] = depth[idx] + 1; //���� ����
			parent[next.first] = idx; //�ڽ� ���� ���� (�θ� �� ����)
			makeTree(next.first); //�ش� ������ �ٽ� Ʈ�� �����
		}
	}
}

//LCA(Lowest Common Ancestor) �˰���
void solution(int a, int b) {
	int ans = 0;

	if (depth[b] < depth[a]) swap(a, b); //a�� ���̰� �� �۵��� a, b swap
	int diff = depth[b] - depth[a]; //������ ���� ���ϱ�

	for(int k = 0; k < diff; ++k) { //������ ���̸�ŭ b (�� ���� ���)�� ���� �ø��� (�θ� ���� ����)
		int p = parent[b];
		for (auto info : adj[b]) {
			if (p == info.first) {
				ans += info.second; //�� ���� ������ �Ÿ� ���ϱ�
				break;
			}
		}
		b = parent[b];
	}

	while (a != b) { //a, b�� ���� ���� ��츸 a, b�� �ϳ��� ���� �ø���
		int ap = parent[a], bp = parent[b];
		for (auto info : adj[a]) {
			if (info.first == ap) {
				ans += info.second;
				break;
			}
		}
		for (auto info : adj[b]) {
			if (info.first == bp) {
				ans += info.second;
				break;
			}
		}
		a = ap;
		b = bp;
	}
	
	cout << ans << "\n";
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	depth[1] = 0; //1�� ��带 ��Ʈ�� ����
	makeTree(1);

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		solution(a, b);
	}

}