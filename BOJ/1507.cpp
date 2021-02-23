#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> arr(21, vector<int>(21, 0));
vector<vector<int>> ans(21, vector<int>(21, 0));

int solution() {
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == k || j == k) continue;

				//i번 노드와 j번 노드를 직접 연결하는 간선이나 돌아가는 경로가 없는 경우
				if (arr[i][j] > arr[i][k] + arr[k][j])
					return -1;
				//같은 경우, i번 노드와 j번 노드를 직접 연결하는 것보다 k를 거쳐가는 것이 더 빠름
				//i번 노드와 j번 노드를 연결하는 간선은 없어도됨
				if (arr[i][j] == arr[i][k] + arr[k][j])
					ans[i][j] = 0;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			res += ans[i][j];
		}
	}
	
	return res;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			ans[i][j] = arr[i][j];
		}
	}

	cout << solution();

	return 0;
}