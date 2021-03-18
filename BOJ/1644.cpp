#include <bits/stdc++.h>
#define MAX 4000000

using namespace std;

int arr[MAX + 1];
int prime[MAX];
int cnt = 0;

//에라토스테네스의 체
void calPrime() {
	int m = sqrt(MAX);
	for (int i = 2; i <= m; ++i) { //2, 3, ..., m 까지
		if (arr[i]) continue;

		for (int j = i + i; j <= MAX; j += i) //2의 배수, 3의배수, ... m의 배수는 true로 지정 (2, 3, 등 소수 제외)
			arr[j] = true;
	}
}

void setPrime() {
	for (int i = 2; i <= MAX; ++i) {
		if (!arr[i]) prime[cnt++] = i; //소수만 따로 배열에 저장
	}
}

int main() {
	int N; cin >> N;

	calPrime();
	setPrime();

	int ans = 0, sum = 0;
	int left = 0, right = 0;
	while (right <= cnt) {
		if (sum < N) //N보다 작은 경우
			sum += prime[right++]; //sum에 현재 소수 더하고, right 증가
		else { //N과 같거나 더 큰 경우 -> right를 증가시키면 N을 넘음
			if (sum == N) ans++;
			sum -= prime[left++]; //sum에 현재 소수 빼고, left 증가시키고 right를 증가시킬 수 있는지 판단해야함
		}
	}

	cout << ans;

	return 0;
}