#include <bits/stdc++.h>

using namespace std;

int N, M;
int INF = 1000000;
vector<vector<int>> dist(101, vector<int>(101, 0));
vector<bool> isSelected(101, false);
vector<int> ans;

int makeSet(int idx) {
	//bfs�� ����ȸ �����
	vector<int> set;
	queue<int> q;
	
	isSelected[idx] = true;
	q.push(idx);
	set.push_back(idx);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 1; i <= N; ++i) {
			//���� �˰� �ְ�, �̹� ���õ��� ���� ���
			if (dist[curr][i] != INF && !isSelected[i]) {
				isSelected[i] = true;
				q.push(i);
				set.push_back(i);
			}
		}
	}

	int res1 = 0, res2 = INT_MAX;
	for (auto i : set) {
		int tmpRes = 0;
		for(auto j : set) {
			if (i != j)
				tmpRes = max(tmpRes, dist[i][j]);
		}
		if (tmpRes < res2) {
			res1 = i;
			res2 = tmpRes;
		}
	}

	return res1;
}

void solution() {
	//floyd warshall�� �ִ� �Ÿ� ���ϱ�
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (!isSelected[i]) //���õ��� ���� ��� -> i�� ������ ����ȸ �����
			ans.push_back(makeSet(i));
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i^j) dist[i][j] = INF; //���� �ٸ� ��� INF
		}
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = dist[b][a] = 1;
	}

	solution();

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int a : ans) {
		cout << a << "\n";
	}

	return 0;
}