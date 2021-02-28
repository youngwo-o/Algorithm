#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;
vector<int> belt;
int solution() {
	int left = 0, right = k - 1, ans = 0;
	
	map<int, int> m;
	for (int i = 0; i <= right; ++i) {
		m[belt[i]]++;
	}

	//�� �����ͷ� �ѹ��� ��ü Ž��
	while (right != N + k - 2) {
		int mSize = m.size();
		//map�� [] ������ ��� ��� ��� ���Ұ� �����ǹǷ�
		//m[c] == 0 ������� �ʰ� find() ����ؼ� c�� ���ԵǴ��� ã��
		if (m.find(c) == m.end()) mSize++;
		ans = max(ans, mSize);

		int preLeft = left;
		m[belt[left++]]--; //���� �� ����
		m[belt[++right]]++; //���ο� �� �߰�
		if (m[belt[preLeft]] == 0) //0�� ��� map���� �����
			m.erase(belt[preLeft]);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; ++i) {
		int b;
		cin >> b;
		belt.push_back(b);
	}
	//���ӵǾ�� �ϹǷ� �ε��� 0���� k-1���� ���Ҹ� �ڿ� ���̱�
	for (int i = 0; i < k - 1; ++i) {
		belt.push_back(belt[i]);
	}

	cout << solution();

	return 0;
}