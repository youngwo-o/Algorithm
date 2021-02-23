#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> arr(21, vector<int>(21, 0));
vector<vector<int>> ans(21, vector<int>(21, 0));

int solution() {
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == k || j == k) continue;

				//i�� ���� j�� ��带 ���� �����ϴ� �����̳� ���ư��� ��ΰ� ���� ���
				if (arr[i][j] > arr[i][k] + arr[k][j])
					return -1;
				//���� ���, i�� ���� j�� ��带 ���� �����ϴ� �ͺ��� k�� ���İ��� ���� �� ����
				//i�� ���� j�� ��带 �����ϴ� ������ �����
				if (arr[i][j] == arr[i][k] + arr[k][j])
					ans[i][j] = 0;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			res += ans[i][j];
		}
	}
	
	return res;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			ans[i][j] = arr[i][j];
		}
	}

	cout << solution();

	return 0;
}