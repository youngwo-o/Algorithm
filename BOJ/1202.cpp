#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 300001

using namespace std;

int N, K;
vector<pair<int, int>> jew;
vector<int> bag;
priority_queue<int> pq;

long long solution() {
	sort(bag.begin(), bag.end());
	sort(jew.begin(), jew.end());

	long long ans = 0;
	int idx = 0;

	for (int i = 0; i < K; ++i) {
		while (idx < N &&jew[idx].first <= bag[i]) //���� ���濡 ���� �� �ִ� ������ ���� pq�� �� �ֱ�
			pq.push(jew[idx++].second);

		if (!pq.empty()) { //top ���� ���� ���濡 �ֱ� (top�� ���� ū ���� �������)
			ans += pq.top();
			pq.pop();
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int m, v; cin >> m >> v;
		jew.push_back({ m, v });
	}
	for (int i = 0; i < K; ++i) {
		int c; cin >> c;
		bag.push_back(c);
	}

	cout << solution();

	return 0;
}