#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& stones, int k) {
	int cnt = 0;
	for (auto& s : stones) {
		if (s == 0) cnt++;
		else {
			cnt = 0;
			s--;
		}

		//더 이상 밟을 수 없는 디딤돌이 연속으로 k개 있는 경우 -> 건널 수 없음
		if (cnt == k) return false;
	}

	return true;
}

int solution(vector<int> stones, int k) {
	//stones 크기 200000이하
	//stones 원소 값 200000000 이하
	//이분탐색 필요!

	int left = 1, right = 0; //left : 건너는 최소 사람 수, right : 건너는 최대 사람 수
	for (auto s : stones) {
		right = max(s, right);
	}
	while (left <= right) {
		int mid = (left + right) / 2;

		vector<int> tmp = stones;
		for (auto& t : tmp) {
			if (t - mid < 0) t = 0;
			else t -= mid;
		}

		if (check(tmp, k)) left = mid + 1;
		else right = mid - 1;
	}

	return left;
}