#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

struct compare {
	bool operator()(const pii& a, const pii& b) {
		if (a.first == b.first) // 값이 같으면 먼저 들어온 순서대로
			return a.second > b.second;
		return a.first > b.first; // 값이 더 작은게 먼저 나오도록
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L; cin >> N >> L;
	priority_queue<pii, vector<pii>, compare> pq;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		pq.push({ a, i });
		pii pfront = pq.top();
		while (pfront.second < i - L + 1) { // 최소값이 현재 범위 내의 값이 아닌 경우
			pq.pop(); // 큐에서 제거
			pfront = pq.top(); // 새로운 top을 다시 비교하도록
		}
		cout << pfront.first << " ";
	}

	return 0;
}