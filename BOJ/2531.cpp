#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;
vector<int> belt;
int solution() {
	int left = 0, right = k - 1, ans = 0;
	
	map<int, int> m;
	for (int i = 0; i <= right; ++i) {
		m[belt[i]]++;
	}

	//투 포인터로 한번만 전체 탐색
	while (right != N + k - 2) {
		int mSize = m.size();
		//map의 [] 연산의 경우 사용 즉시 원소가 생성되므로
		//m[c] == 0 사용하지 않고 find() 사용해서 c가 포함되는지 찾기
		if (m.find(c) == m.end()) mSize++;
		ans = max(ans, mSize);

		int preLeft = left;
		m[belt[left++]]--; //이전 값 제거
		m[belt[++right]]++; //새로운 값 추가
		if (m[belt[preLeft]] == 0) //0인 경우 map에서 지우기
			m.erase(belt[preLeft]);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; ++i) {
		int b;
		cin >> b;
		belt.push_back(b);
	}
	//연속되어야 하므로 인데긋 0부터 k-1개의 원소를 뒤에 붙이기
	for (int i = 0; i < k - 1; ++i) {
		belt.push_back(belt[i]);
	}

	cout << solution();

	return 0;
}