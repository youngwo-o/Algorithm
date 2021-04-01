#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> home;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> K;
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			home.push_back(a);
		}
		int sum = 0, ans = 0;
		for (int i = 0; i < M; ++i) sum += home[i]; // 0 ~ M - 1 �������� �� ���ϱ�
		if (sum < K) ans++;

		if (N != M) { // N == M �� ��� �� �ʿ� X
			for (int i = 0; i < M - 1; ++i) { // ���ӵǵ��� M - 1 �� �����̱�
				home.push_back(home[i]);
			}

			for (int i = 0; i != N - 1; ++i) {
				sum -= home[i]; // ���� �� ����
				sum += home[i + M]; //������ �� �߰�
				if (sum < K) ans++;
			}
		}

		cout << ans << "\n";
		home.clear();
	}

	return 0;
}