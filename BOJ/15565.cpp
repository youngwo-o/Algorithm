#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> doll;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		doll.push_back(a);
	}

	int ans = INT_MAX;
	int left = 0, right = 0;
	int preL = -1, preR = right;
	int cnt = 0;
	if (doll[0] == 1) cnt++; // ù��° ������ ���̾��̶�� -> ���� ���տ� ���̾� �ϳ� �߰�
	while (right < N) {
		if (preL != left) { // left�� ���� ������ ���
			if(preL != -1 && doll[preL] == 1) cnt--; // ���� left�� ���̾��̿��ٸ� -> ���� ���տ��� ���̾� �ϳ� ����
			preL = left;
		}
		else if (preR != right) {
			if (doll[right] == 1) cnt++; // ���� right�� ���̾��̶�� -> ���� ���տ� ���̾� �ϳ� �߰�
			preR = right; 
		}

		if (cnt < K) right++; // ���̾��� ������ K ���� ���� ��� -> right ���� (���տ� ���ο� ���� �߰�)
		else { //���̾��� ������ K �̻��� ���
			ans = min(ans, right - left + 1); // ����� max�� ����
			left++; // left ���� (������ ���� ���� ��Ű��)
		}
	}

	if (ans == INT_MAX) ans = -1;
	cout << ans;

	return 0;
}