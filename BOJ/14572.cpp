#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int N, K, D;
vector<vector<int>> algo;

bool cmp(const pii& a, const pii& b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> D;
	vector<pii> st;
	for (int i = 0; i < N; ++i) {
		int M, d; cin >> M >> d;
		st.push_back({ i, d });
		vector<int> tmpAlgo;
		for (int j = 0; j < M; ++j) {
			int a; cin >> a;
			tmpAlgo.push_back(a);
		}
		algo.push_back(tmpAlgo);
	}
	sort(st.begin(), st.end(), cmp); // �л� �Ƿ� ������������ ����

	int left = 0, right = 0, ans = 0;
	deque<pii> dq;
	map<int, int> know;
	while (right < N) {
		if (dq.empty()) { // �׷���� ���� ���
			dq.push_back(st[right++]); // right�� �׷쿡 �߰�
			for (auto& a : algo[dq.back().first]) {
				know[a] = 1; // �˰� �ִ� �˰��� ����
			}
		}
		else { // �׷���� �ִ� ���
			// ������� ���� ���ϴ� �л�(right)�� ���� ���ϴ� �л�(dq.front()) �� �Ƿ����� D���� ū ���
			while (!dq.empty() && st[right].second - dq.front().second > D) {
				for (auto& a : algo[dq.front().first]) {
					know[a]--; // ���� ���ϴ� �л��� �˰� �ִ� �˰����� �� ����
					if (know[a] == 0) know.erase(a);
				}
				dq.pop_front(); // ���� ���ϴ� �л��� �׷쿡�� ������
				left++;
			}
			for (auto& a : algo[st[right].first]) {
				know[a]++; // ���� ���ϴ� �л��� �˰����� �� ����
			}
			dq.push_back(st[right++]); // ���� ���ϴ� �л��� �׷쿡 �߰�
		}

		int cnt = 0;
		for (auto& k : know) {
			if (k.second == (right - left)) cnt++; //��� �л��� �˰��ִ� �˰����̶�� cnt ����
		}
		int E = (know.size() - cnt) * (right - left);
		ans = max(ans, E);
	}

	cout << ans;

	return 0;
}