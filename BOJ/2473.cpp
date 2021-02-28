#include <bits/stdc++.h>

using namespace std;

int N;
int arr[5000];
vector<int> ans;

void solution() {
	long long tmp = LLONG_MAX;
	//첫번째 선택할 용액은 for문으로 미리 선택해둠
	for (int i = 0; i < N; ++i) {
		//투 포인터로 나머지 두 용액 구하기
		int left = i + 1, right = N - 1;
		while (left < right) {
			long long sum = (long long)arr[i] + arr[left] + arr[right]; //캐스팅 주의!! (용액의 최대, 최소값 => +- 1,000,000,000)
			if (abs(sum) < tmp) {
				tmp = abs(sum);
				ans = { arr[i], arr[left], arr[right] };
			}

			if (sum < 0) left++;
			else if (sum > 0) right--;
			else break;
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];
	cout << "\n";
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