#include <bits/stdc++.h>
#define MAX 200001

using namespace std;

int N, Q;
int origin[MAX], parent[MAX];
vector<vector<int>> input;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	parent[1] = 1;
	for (int i = 2; i <= N; ++i) {
		cin >> origin[i];
		parent[i] = i;
	}

	for (int i = 0; i < N - 1 + Q; ++i) {
		int x, a, b; cin >> x;
		if (x == 0) {
			cin >> a;
			input.push_back({ x, a });
		}
		else if (x == 1) {
			cin >> a >> b;
			input.push_back({ x, a, b });
		}
	}

	vector<string> ans;
	// 연결을 삭제하는 쿼리가 있음 
	// -> find는 가장 root를 부모로 설정해주기 때문에 find가 소용이 없어짐
	// 따라서, 마지막 쿼리부터 실행 
	// -> 아무런 연결이 없는 상태에서 시작해서 union-find
	for(int i = input.size() - 1; i >=0 ; --i) {
		if (input[i][0] == 0) { // 삭제쿼리 -> union 시켜줌
			int a = input[i][1];
			merge(a, origin[a]);
		}
		else if (input[i][0] == 1) {
			int a = input[i][1];
			int b = input[i][2];
			if (find(a) == find(b)) ans.push_back("YES");
			else ans.push_back("NO");
		}
	}

	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << "\n";
	}

	return 0;
}