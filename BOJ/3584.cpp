#include <bits/stdc++.h>
#define MAX 10001
#define MAX_DEPTH 18

using namespace std;

int N;
vector<int> adj[MAX];
int isChild[MAX];
int depth[MAX], parent[MAX][MAX_DEPTH];

void makeTree(int idx, int cnt) {
	depth[idx] = cnt;
	for (auto& next : adj[idx]) {
		if (depth[next] != 0) continue;
		parent[next][0] = idx; // next의 첫번째 부모는 idx
		makeTree(next, cnt + 1);
	}
}

int solution(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b); //a의 깊이가 더 깊도록
	int diff = depth[a] - depth[b];

	//깊이 차를 줄이면서 a를 이동시킴 -> a, b의 깊이를 동일하게
	int k = 0;
	while (diff != 0) {
		if (diff % 2) a = parent[a][k];
		diff /= 2;
		k++;
	}

	if (a == b) return a;

	for (int i = MAX_DEPTH - 1; i >= 0; --i) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
	
		for (int i = 1; i < N; ++i) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			isChild[b] = true;
		}

		int p; // 부모 노드 찾기
		for (int i = 1; i <= N; ++i) {
			if (!isChild[i]) p = i;
		}

		makeTree(p, 1);
		for (int j = 0; j < MAX_DEPTH - 1; ++j) { // 2^j 번째 부모 저장
			for (int i = 2; i <= N; ++i) {
				if (parent[i][j] != 0) parent[i][j + 1] = parent[parent[i][j]][j];
				//ex) 두번째 부모(j + 1)은 첫번째 부모(j)의 첫번째 부모
			}
		}

		int a, b; cin >> a >> b;
		cout << solution(a, b) << "\n";

		for (int i = 1; i <= N; ++i) {
			adj[i].clear();
		}
		memset(depth, 0, sizeof(depth));
		memset(parent, 0, sizeof(parent));
		memset(isChild, false, sizeof(isChild));
	}

	return 0;
}