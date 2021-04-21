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
	sort(ice.begin(), ice.end()); // ������ ��ǥ ������� ����

	int res = 0, ans = 0;
	queue<pii> q;
	for (auto& i : ice) {
		// ���� ������ ��ġ�� ť�� ���� �տ� �ִ� ������ ��ġ ���̰� K * 2 �̻��� ���, ť���� ����
		// �¿� K��ŭ ������ �絿�̱��� ���� �� �����Ƿ�
		while (!q.empty() && i.first - q.front().first > K * 2) {
			res -= q.front().second;
			q.pop();
		}
		res += i.second;
		q.push(i); // ���� ���� ���� ť�� �ֱ�

		ans = max(ans, res);
	}

	cout << ans;
	
	return 0;
}