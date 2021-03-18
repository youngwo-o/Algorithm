#include <bits/stdc++.h>
#define MAX 50

using namespace std;

int N, M, tNum;
set<int> truth;
vector<int> party[MAX];

int main() {
	cin >> N >> M;
	cin >> tNum;
	for (int i = 0; i < tNum; ++i) {
		int a; cin >> a;
		truth.insert(a);
	}
	queue<int> q;
	for (int i = 0; i < M; ++i) {
		int pNum; cin >> pNum;
		for (int j = 0; j < pNum; ++j) {
			int a; cin >> a;
			party[i].push_back(a);
		}
		q.push(i);
	}

	int ans = M;
	while (1) {
		int cnt = 0;
		for (int i = 0, qSize = q.size(); i < qSize; ++i) {
			int idx = q.front();
			q.pop();

			bool check = false;
			for (auto p : party[idx]) {
				if (truth.find(p) != truth.end()) check = true;
			}

			if (check == false) q.push(idx);
			else {
				for (auto p : party[idx]) truth.insert(p);
				cnt++;
			}
		}
		if (cnt == 0) break;
		
		ans -= cnt;
	}

	cout << ans;

	return 0;
}