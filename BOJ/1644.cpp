#include <bits/stdc++.h>
#define MAX 4000000

using namespace std;

int arr[MAX + 1];
int prime[MAX];
int cnt = 0;

//�����佺�׳׽��� ü
void calPrime() {
	int m = sqrt(MAX);
	for (int i = 2; i <= m; ++i) { //2, 3, ..., m ����
		if (arr[i]) continue;

		for (int j = i + i; j <= MAX; j += i) //2�� ���, 3�ǹ��, ... m�� ����� true�� ���� (2, 3, �� �Ҽ� ����)
			arr[j] = true;
	}
}

void setPrime() {
	for (int i = 2; i <= MAX; ++i) {
		if (!arr[i]) prime[cnt++] = i; //�Ҽ��� ���� �迭�� ����
	}
}

int main() {
	int N; cin >> N;

	calPrime();
	setPrime();

	int ans = 0, sum = 0;
	int left = 0, right = 0;
	while (right <= cnt) {
		if (sum < N) //N���� ���� ���
			sum += prime[right++]; //sum�� ���� �Ҽ� ���ϰ�, right ����
		else { //N�� ���ų� �� ū ��� -> right�� ������Ű�� N�� ����
			if (sum == N) ans++;
			sum -= prime[left++]; //sum�� ���� �Ҽ� ����, left ������Ű�� right�� ������ų �� �ִ��� �Ǵ��ؾ���
		}
	}

	cout << ans;

	return 0;
}