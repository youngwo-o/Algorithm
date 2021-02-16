#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, r, c;
	cin >> N >> r >> c;

	int cnt = 0;
	while (N != 0) {
		int n = pow(2, N - 1); //사분면 나누기 위해 2^N-1(각 사분면의 행/열 수)로 지정
		//몇 사분면인지 정하기
		int tmpR = r / n;
		int tmpC = c / n;

		//1사분면
		if (tmpR == 0 && tmpC == 0);
		//2사분면
		else if (tmpR == 0 && tmpC == 1)
			cnt += (n * n);
		//3사분면
		else if (tmpR == 1 && tmpC == 0) 
			cnt += (n * n * 2);
		//4사분면
		else if (tmpR == 1 && tmpC == 1) 
			cnt += (n * n * 3);

		//현재 사분면 내에서 다시 사분면 구하기
		N--;
		r %= n;
		c %= n;
	}

	cout << cnt;

	return 0;
}