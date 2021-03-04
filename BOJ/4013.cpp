#include <bits/stdc++.h>
#define MAX 500001

using namespace std;

int N, M, S, P;
vector<int> info[MAX], infoRev[MAX]; //SCC 코사라주
stack<int> s;
bool visited[MAX]; //dfs 시 방문 체크
vector<int> newInfo[MAX]; //SCC 끼리 연결 정보 저장
int atm[MAX]; //atm 현금 정보
int scc[MAX], sccAtm[MAX]; //각 정점이 몇번 SCC에 해당하는지 / 각 번호의 SCC가 갖는 현금 총합
int rest[MAX]; //레스토랑의 정점이 몇번 SCC에 해당하는지
int dp[MAX]; //인출 가능한 최대 현금 액수 임시 저장
int cnt = 0; //SCC 번호

void dfs(int idx) {
	visited[idx] = true;
	for (auto next : info[idx]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
	s.push(idx);
}

void dfsRev(int idx) {
	visited[idx] = true;
	scc[idx] = cnt; //현재 정점이 몇번 인덱스에 해당하는지 저장
	sccAtm[cnt] += atm[idx]; //해당 번호의 SCC가 갖는 현금의 총합 갱신
	for (auto next : infoRev[idx]) {
		if (!visited[next])
			dfsRev(next);
		else { //이미 방문한 곳인 경우 -> 몇번 SCC에 해당하는지 확인
			if (scc[next] != scc[idx]) //현재 SCC에 해당하지 않은 경우
				newInfo[scc[next]].push_back(scc[idx]); //현재 SCC와 연결 -> newInfo 연결 정보 갱신
		}
	}
}

void solution() {
	//SCC 만들기
	for (int i = 1; i <= N; ++i) {
		if (!visited[i])
			dfs(i);
	}
	memset(visited, 0, sizeof(visited));
	while (!s.empty()) {
		int idx = s.top();
		s.pop();

		if (!visited[idx]) {
			dfsRev(idx);
			cnt++;
		}
	}

	//레스토랑이 속한 scc를 1로 표시
	for (int i = 0; i < P; ++i) {
		int r;
		cin >> r;
		rest[scc[r]] = 1;
	}

	queue<int> q;
	q.push(scc[S]); //시작 정점의 SCC 번호를 큐에 넣기
	dp[scc[S]] = sccAtm[scc[S]]; //시작 정점의 SCC의 현금 총합 dp에 저장

	int ans = 0;
	while (!q.empty()) {
		int curScc = q.front();
		q.pop();

		if (rest[curScc]) //현재 SCC에 레스토랑이 있는 경우
			ans = max(ans, dp[curScc]); //최대값으로 갱신

		for (auto next : newInfo[curScc]) {
			//현재 SCC를 거치는 경우가 최대 값을 갖는 경우만
			if (dp[next] < dp[curScc] + sccAtm[next]) {
				dp[next] = dp[curScc] + sccAtm[next];
				q.push(next);
			}
		}
	}

	cout << ans;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		infoRev[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		cin >> atm[i];
	}
	cin >> S >> P;

	solution();

	return 0;
}