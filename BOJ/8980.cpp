#include <bits/stdc++.h>

using namespace std;

int N, C, M;
vector<pair<pair<int, int>, int>> info;

bool cmp(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b) {
	//���� ���� ����
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
	vector<int> capacity(2001, 0); //�ܿ� �뷮 ���ϱ� ���� �迭
	for (int i = 0; i < M; ++i) {
		int boxCnt = 0;
		for (int j = info[i].first.first; j < info[i].first.second; ++j)
			boxCnt = max(boxCnt, capacity[j]); //���� �뷮 �� ���� ū ������ -> �ܿ� �뷮 ���ϱ� ����

		//���� �뷮, �ܿ� �뷮 �� ���� �� �Ʊ�
		int n = min(info[i].second, C - boxCnt);
		ans += n;

		//n�� �ڽ��� �Ǿ����Ƿ� ���� ���ÿ��� ���� ���� - 1 ���� ���� �뷮 ����
		for (int j = info[i].first.first; j < info[i].first.second; ++j)
			capacity[j] += n;
	}

	cout << ans;

	return 0;
}