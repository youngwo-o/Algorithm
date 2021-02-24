#include <bits/stdc++.h>

using namespace std;

int N, K;
int INF = 1000000;
vector<int> dist(100001, INF);

bool isAble(int n, int d) {
	if (n < 0 || n >= 100001 || dist[n] <= d)
		return false;
	return true;
}

int solution() {
	priority_queue<pair<int,int>> q;

	dist[N] = 0;
	q.push({ 0, N });

	while (!q.empty()) {
		int curD = -q.top().first;
		int curI = q.top().second;
		q.pop();
		
		if (curI == K) return curD;

		int n1 = curI - 1;
		int n2 = curI + 1;
		int n3 = curI * 2;

		if (isAble(n1, curD + 1)) {
			q.push({ -(curD + 1), n1 });
			dist[n1] = curD + 1;
		}
		if (isAble(n2, curD + 1)) {
			q.push({ -(curD + 1), n2 });
			dist[n2] = curD + 1;
		}
		if (isAble(n3, curD)) {
			q.push({ -curD, n3 });
			dist[n3] = curD;
		}
	}
}

int main() {
	cin >> N >> K;
	
	cout << solution();

	return 0;
}