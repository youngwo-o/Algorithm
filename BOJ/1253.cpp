#include <bits/stdc++.h>
#define MAX 2000

using namespace std;

int N;
int num[MAX];

int solution() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		int left = 0, right = N - 1;
		if (i == left) left++;
		else if (i == right) right--;
		while (left < right) {
			int sum = num[left] + num[right];
			if (sum == num[i]) {
				cnt++;
				break;
			}
			else if (sum < num[i]) {
				left++;
				if (left == i) left++;
			}
			else if (sum > num[i]) {
				right--;
				if (right == i) right--;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	sort(num, num + N);

	cout << solution();

	return 0;
}