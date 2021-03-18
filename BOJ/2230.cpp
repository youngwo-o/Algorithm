#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int N, M;
int A[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	sort(A, A + N);

	int minDiff = INT_MAX;
	int left = 0, right = 0;
	while (left <= right && right < N) {
		int diff = A[right] - A[left];

		if (diff >= M) {
			minDiff = min(minDiff, diff);
			if (left == right) right++; //left�� ������ų �� ���� ���, right ����
			else left++; //���� ���ҽ�Ű�� ����
		}
		else right++; //���� ������Ű�� ����
	}

	cout << minDiff;
	
	return 0;
}