#include <bits/stdc++.h>
#define MAX 200001

using namespace std;

int N, C;
vector<int> home;

int solution() {
	int ans = 0;
	sort(home.begin(), home.end());

	int low = 1, high = home.back() - home.front();
	while (low <= high) {
		int mid = (low + high) / 2;

		int gap = 0, tmp = home[0], cnt = 1;
		for (int i = 1; i < N; ++i) {
			gap = home[i] - tmp;
			if (mid <= gap) { //�ִ� ���ݺ��� �۰ų� ���� ��� ������ ��ġ ����
				cnt++; //��ġ�� ������ ���� ����
				tmp = home[i];
			}
		}
		if (cnt >= C) { //��ġ�� �� �ִ� �������� ������ C���� ū ���
			low = mid + 1; //���� �� �а�
			ans = mid;
		}
		else high = mid - 1; //���� �� ����
	}

	return ans;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		home.push_back(x);
	}

	cout << solution();

	return 0;
}