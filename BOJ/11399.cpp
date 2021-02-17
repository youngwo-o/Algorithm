#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int p;
		cin >> p;
		P.push_back(p);
	}
	//적은 시간이 누적해서 더해져야 최소값을 만들 수 있기 때문에 오름차순으로 정렬
	sort(P.begin(), P.end());
	int pre = 0, ans = 0;
	for (auto p : P) {
		pre += p;
		ans += pre;
	}

	cout << ans;

	return 0;
}