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
			if (mid <= gap) { //최대 간격보다 작거나 같은 경우 공유기 설치 가능
				cnt++; //설치한 공유기 개수 증가
				tmp = home[i];
			}
		}
		if (cnt >= C) { //설치할 수 있는 공유기의 개수가 C보다 큰 경우
			low = mid + 1; //간격 더 넓게
			ans = mid;
		}
		else high = mid - 1; //간격 더 좁게
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