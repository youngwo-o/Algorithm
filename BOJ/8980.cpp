#include <bits/stdc++.h>

using namespace std;

int N, C, M;
vector<pair<pair<int, int>, int>> info;

bool cmp(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b) {
	//도착 도시 기준
	return a.first.second < b.first.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> C >> M;

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info.push_back({ {a, b}, c });
	}

	sort(info.begin(), info.end(), cmp);

	int ans = 0;
	vector<int> capacity(2001, 0); //잔여 용량 구하기 위한 배열
	for (int i = 0; i < M; ++i) {
		int boxCnt = 0;
		for (int j = info[i].first.first; j < info[i].first.second; ++j)
			boxCnt = max(boxCnt, capacity[j]); //적재 용량 중 가장 큰 값으로 -> 잔여 용량 구하기 위해

		//실을 용량, 잔여 용량 중 작은 값 싣기
		int n = min(info[i].second, C - boxCnt);
		ans += n;

		//n개 박스를 실었으므로 시작 도시에서 도착 도시 - 1 까지 적재 용량 갱신
		for (int j = info[i].first.first; j < info[i].first.second; ++j)
			capacity[j] += n;
	}

	cout << ans;

	return 0;
}