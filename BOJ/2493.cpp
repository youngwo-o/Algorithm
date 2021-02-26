#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr;
	arr.push_back(-1);
	for (int i = 1; i <= N; ++i) {
		int h;
		cin >> h;
		arr.push_back(h);
	}
	stack<int> s;
	vector<int> ans;
	for (int i = 1; i <= N; ++i) {
		if (s.empty()) ans.push_back(0);
		else {
			while (!s.empty()) {
				int topIdx = s.top();

				//모든 탑은 높이가 서로 다르기 때문에 같은 경우 처리 안해도됨
				//top번째 탑의 높이가 현재 탑의 높이보다 큰 경우 -> 수신 가능
				if (arr[topIdx] > arr[i]) {
					ans.push_back(topIdx);
					break;
				}

				s.pop();
			}

			//수신 가능한 탑이 없는 경우
			if (s.empty())
				ans.push_back(0);
		}

		//현재 탑 인덱스 스택에 추가
		s.push(i);
	}

	for (auto a : ans) {
		cout << a << " ";
	}

	return 0;
}