#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int N;
int num[MAX];
bool visited[MAX];
vector<int> ans;

void dfs(int s, int c) {
	if (visited[c]) { // �̹� �湮�� ���� ���
		// �ٽ� ������������ ���ƿ� ��� => ����Ŭ�� ����
		if (s == c) ans.push_back(s);
	}
	else {
		visited[c] = true;
		dfs(s, num[c]);
	}
}

void solution() {
	// 1������ dfs ���鼭 ����Ŭ�� �ִ��� ã��
	for (int i = 1; i <= N; ++i) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num[i];
	}

	solution();

	cout << ans.size() << "\n";
	for (auto& a : ans) {
		cout << a << "\n";
	}

	return 0;
}