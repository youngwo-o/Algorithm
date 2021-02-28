#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];
vector<int> ans;

void solution() {
	int left = 0, right = N - 1, tmp = INT_MAX;
	while(left < right) {
		int sum = arr[left] + arr[right];
		if (abs(sum) < tmp) {
			tmp = abs(sum);
			ans = { arr[left], arr[right] };
		}

		if (sum < 0) left++;
		else if (sum > 0) right--;
		else break;
	}

	cout << ans[0] << " " << ans[1] << "\n";
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	solution();

	return 0;
}