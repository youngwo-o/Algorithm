#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

struct compare {
	bool operator()(const pii& a, const pii& b) {
		if (a.first == b.first) // ���� ������ ���� ���� �������
			return a.second > b.second;
		return a.first > b.first; // ���� �� ������ ���� ��������
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
		while (pfront.second < i - L + 1) { // �ּҰ��� ���� ���� ���� ���� �ƴ� ���
			pq.pop(); // ť���� ����
			pfront = pq.top(); // ���ο� top�� �ٽ� ���ϵ���
		}
		cout << pfront.first << " ";
	}

	return 0;
}