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
	//���� �ð��� �����ؼ� �������� �ּҰ��� ���� �� �ֱ� ������ ������������ ����
	sort(P.begin(), P.end());
	int pre = 0, ans = 0;
	for (auto p : P) {
		pre += p;
		ans += pre;
	}

	cout << ans;

	return 0;
}