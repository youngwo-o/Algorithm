#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int N;
int jTime[MAX], entry[MAX];
vector<int> info[MAX];

void solution() {
	int ans = 0;
	//다익스트라 -> 최단 시간부터 처리하기 위해
	priority_queue<pair<int,int>> q;

	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0) 
			q.push({ -jTime[i], i });
	}

	while (!q.empty()) {
		int curI = q.top().second;
		int curT = -q.top().first;
		q.pop();

		if (info[curI].empty()) { //더 이상 갈 곳이 없는 경우 (마지막 작업)
			ans = max(ans, curT); //모든 작업이 끝나는 시간을 구하기 위해
			continue;
		}

		for (auto next : info[curI]) {
			entry[next]--;

			if (entry[next] == 0) //선행 작업을 모두 수행한 경우
				q.push({ -(curT + jTime[next]), next });
		}
	}

	cout << ans;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int t, n;
		cin >> jTime[i] >> n;
		for (int j = 0; j < n; ++j) {
			int a;
			cin >> a;
			if (i != a) {
				info[a].push_back(i);
				entry[i]++;
			}
		}
	}

	solution();

	return 0;
}