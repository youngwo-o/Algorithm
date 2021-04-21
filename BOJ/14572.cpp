#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int N, K, D;
vector<vector<int>> algo;

bool cmp(const pii& a, const pii& b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> D;
	vector<pii> st;
	for (int i = 0; i < N; ++i) {
		int M, d; cin >> M >> d;
		st.push_back({ i, d });
		vector<int> tmpAlgo;
		for (int j = 0; j < M; ++j) {
			int a; cin >> a;
			tmpAlgo.push_back(a);
		}
		algo.push_back(tmpAlgo);
	}
	sort(st.begin(), st.end(), cmp); // 학생 실력 오름차순으로 정렬

	int left = 0, right = 0, ans = 0;
	deque<pii> dq;
	map<int, int> know;
	while (right < N) {
		if (dq.empty()) { // 그룹원이 없는 경우
			dq.push_back(st[right++]); // right를 그룹에 추가
			for (auto& a : algo[dq.back().first]) {
				know[a] = 1; // 알고 있는 알고리즘 저장
			}
		}
		else { // 그룹원이 있는 경우
			// 현재까지 가장 잘하는 학생(right)과 가장 못하는 학생(dq.front()) 의 실력차가 D보다 큰 경우
			while (!dq.empty() && st[right].second - dq.front().second > D) {
				for (auto& a : algo[dq.front().first]) {
					know[a]--; // 가장 못하는 학생이 알고 있는 알고리즘의 수 감소
					if (know[a] == 0) know.erase(a);
				}
				dq.pop_front(); // 가장 못하는 학생을 그룹에서 빼내기
				left++;
			}
			for (auto& a : algo[st[right].first]) {
				know[a]++; // 가장 잘하는 학생의 알고리즘의 수 증가
			}
			dq.push_back(st[right++]); // 가장 잘하는 학생을 그룹에 추가
		}

		int cnt = 0;
		for (auto& k : know) {
			if (k.second == (right - left)) cnt++; //모든 학생이 알고있는 알고리즘이라면 cnt 증가
		}
		int E = (know.size() - cnt) * (right - left);
		ans = max(ans, E);
	}

	cout << ans;

	return 0;
}