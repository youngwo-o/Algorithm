#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> doll;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		doll.push_back(a);
	}

	int ans = INT_MAX;
	int left = 0, right = 0;
	int preL = -1, preR = right;
	int cnt = 0;
	if (doll[0] == 1) cnt++; // 첫번째 인형이 라이언이라면 -> 현재 집합에 라이언 하나 추가
	while (right < N) {
		if (preL != left) { // left의 값이 증가한 경우
			if(preL != -1 && doll[preL] == 1) cnt--; // 이전 left가 라이언이였다면 -> 현재 집합에서 라이언 하나 제거
			preL = left;
		}
		else if (preR != right) {
			if (doll[right] == 1) cnt++; // 현재 right가 라이언이라면 -> 현재 집합에 라이언 하나 추가
			preR = right; 
		}

		if (cnt < K) right++; // 라이언의 개수가 K 보다 작은 경우 -> right 증가 (집합에 새로운 인형 추가)
		else { //라이언의 개수가 K 이상인 경우
			ans = min(ans, right - left + 1); // 결과를 max로 갱신
			left++; // left 증가 (집합의 개수 감소 시키기)
		}
	}

	if (ans == INT_MAX) ans = -1;
	cout << ans;

	return 0;
}