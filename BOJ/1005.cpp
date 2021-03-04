#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, K, W;
int bTime[MAX], entry[MAX];
vector<int> info[MAX];

void solution() {
	int ans = 0;

	//���ͽ�Ʈ�� �̿� -> �ִ� �Ÿ��� ���� ó���ϱ� ����
	priority_queue<pair<int, int>> q;

	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0) //���� ������ 0�� ��忡�� ����
			q.push({ -bTime[i], i }); //�Ǽ� �ð�, ��� ��ȣ ����
	}

	while (!q.empty()) {
		int curI = q.top().second;
		int curD = -q.top().first;
		q.pop();

		if (curI == W) { //������ ����� ���
			ans = max(ans, curD); //�ִ� �Ÿ� ����
			continue;
		}

		for (auto next : info[curI]) {
			entry[next]--;

			if (entry[next] == 0) //���� ����� �ռ� ������ ��� �湮�� ���
				q.push({ -(curD + bTime[next]), next }); //���� ��� �湮 ����
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
			entry[y]++; //�������� (���� ���� ����)
		}
		cin >> W;

		solution();
	}

	return 0;
}