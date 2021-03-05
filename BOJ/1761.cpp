#include <bits/stdc++.h>
#define MAX 40001

using namespace std;

int N, M;
vector<pair<int,int>> adj[MAX];
int depth[MAX], parent[MAX];
bool visited[MAX];

void makeTree(int idx) { //트리 만들기
	visited[idx] = true;
	for (auto next : adj[idx]) { //연결되어 있는 노드 모두 탐색
		if (!visited[next.first]) { //방문하지 않은 노드인 경우
			depth[next.first] = depth[idx] + 1; //깊이 설정
			parent[next.first] = idx; //자식 노드로 설정 (부모 값 갱신)
			makeTree(next.first); //해당 노드부터 다시 트리 만들기
		}
	}
}

//LCA(Lowest Common Ancestor) 알고리즘
void solution(int a, int b) {
	int ans = 0;

	if (depth[b] < depth[a]) swap(a, b); //a의 깊이가 더 작도록 a, b swap
	int diff = depth[b] - depth[a]; //깊이의 차이 구하기

	for(int k = 0; k < diff; ++k) { //깊이의 차이만큼 b (더 깊은 노드)를 위로 올리기 (부모 노드로 지정)
		int p = parent[b];
		for (auto info : adj[b]) {
			if (p == info.first) {
				ans += info.second; //두 정점 사이의 거리 더하기
				break;
			}
		}
		b = parent[b];
	}

	while (a != b) { //a, b가 같지 않은 경우만 a, b를 하나씩 위로 올리기
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
	depth[1] = 0; //1번 노드를 루트로 지정
	makeTree(1);

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		solution(a, b);
	}

}