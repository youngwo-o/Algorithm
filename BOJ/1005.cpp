#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, K, W;
int bTime[MAX], entry[MAX];
vector<int> info[MAX];

void solution() {
	int ans = 0;

	//다익스트라 이용 -> 최단 거리를 먼저 처리하기 위해
	priority_queue<pair<int, int>> q;

	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0) //진입 차수가 0인 노드에서 시작
			q.push({ -bTime[i], i }); //건설 시간, 노드 번호 저장
	}

	while (!q.empty()) {
		int curI = q.top().second;
		int curD = -q.top().first;
		q.pop();

		if (curI == W) { //마지막 노드인 경우
			ans = max(ans, curD); //최대 거리 저장
			continue;
		}

		for (auto next : info[curI]) {
			entry[next]--;

			if (entry[next] == 0) //다음 노드의 앞선 노드들을 모두 방문한 경우
				q.push({ -(curD + bTime[next]), next }); //다음 노드 방문 가능
		}
	}

	cout << ans <<"\n";
	for (int i = 1; i <= N; ++i) {
		info[i].clear();
	}
	memset(entry, 0, sizeof(entry));
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;
		for (int i = 1; i <= N; ++i) {
			cin >> bTime[i];
		}
		for (int i = 0; i < K; ++i) {
			int x, y;
			cin >> x >> y;
			info[x].push_back(y);
			entry[y]++; //위상정렬 (진입 차수 증가)
		}
		cin >> W;

		solution();
	}

	return 0;
}