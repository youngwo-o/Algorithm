#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, r, c;
	cin >> N >> r >> c;

	int cnt = 0;
	while (N != 0) {
		int n = pow(2, N - 1); //��и� ������ ���� 2^N-1(�� ��и��� ��/�� ��)�� ����
		//�� ��и����� ���ϱ�
		int tmpR = r / n;
		int tmpC = c / n;

		//1��и�
		if (tmpR == 0 && tmpC == 0);
		//2��и�
		else if (tmpR == 0 && tmpC == 1)
			cnt += (n * n);
		//3��и�
		else if (tmpR == 1 && tmpC == 0) 
			cnt += (n * n * 2);
		//4��и�
		else if (tmpR == 1 && tmpC == 1) 
			cnt += (n * n * 3);

		//���� ��и� ������ �ٽ� ��и� ���ϱ�
		N--;
		r %= n;
		c %= n;
	}

	cout << cnt;

	return 0;
}