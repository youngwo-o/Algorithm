#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	vector<pii> ice;
	for (int i = 0; i < N; ++i) {
		int g, x; cin >> g >> x;
		ice.push_back({ x, g });
	}
	sort(ice.begin(), ice.end()); // 얼음을 좌표 순서대로 정렬

	int res = 0, ans = 0;
	queue<pii> q;
	for (auto& i : ice) {
		// 현재 얼음의 위치와 큐의 가장 앞에 있는 얼음의 위치 차이가 K * 2 이상인 경우, 큐에서 빼냄
		// 좌우 K만큼 떨어진 양동이까지 닿을 수 있으므로
		while (!q.empty() && i.first - q.front().first > K * 2) {
			res -= q.front().second;
			q.pop();
		}
		res += i.second;
		q.push(i); // 현재 얼음 정보 큐에 넣기

		ans = max(ans, res);
	}

	cout << ans;
	
	return 0;
}