#include <bits/stdc++.h>
#define change(idx) light[idx] = (light[idx] == '0' ? '1' : '0');

using namespace std;

int N;
string light, res;

int solution(int push0) {
	int ans = 0;

	if (push0) {
		change(0);
		change(1);
		ans++;
	}

	//i - 1번 스위치는 i번 스위치의 on/off에 따라 결정됨
	for (int i = 1; i <= N; ++i) {
		//현재 i - 1번 스위치가 결과값의 i - 1번 스위치와 다른 경우
		if (light[i - 1] != res[i - 1]) {
			if (i == N) //i가 N인 경우 스위치 상태를 바꿀 수 없기 때문에 -1 리턴
				return -1;

			ans++;
			if (i - 1 >= 0) change(i - 1);
			change(i);
			if(i  + 1 < N) change(i + 1);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> light >> res;

	int ans = INT_MAX;
	string tmp = light;
	int res1 = solution(0); //0번 스위치를 켜지 않은 경우
	light = tmp;
	int res2 = solution(1); //0번 스위치를 키는 경우
	if (res1 == -1 && res2 == -1)
		ans = -1;
	else if(res1 != -1) ans = min(ans, res1);
	else if (res2 != -1) ans = min(ans, res2);

	cout << ans;

	return 0;
}