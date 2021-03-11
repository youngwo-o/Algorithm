#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int parent[MAX], networkSize[MAX];

int findParent(int idx) {
	if (idx == parent[idx])
		return idx;

	return parent[idx] = findParent(parent[idx]);
}

void merge(int idx1, int idx2) {
	int p1 = findParent(idx1), p2 = findParent(idx2);

	if (p1 != p2) {
		if (networkSize[p1] < networkSize[p2]) swap(p1, p2);

		parent[p2] = p1;
		networkSize[p1] += networkSize[p2];
		networkSize[p2] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int F; cin >> F;
		for (int i = 0; i < MAX; ++i) {
			parent[i] = i;
			networkSize[i] = 1;
		}

		map<string, int> person;
		int cnt = 1;

		for (int i = 0; i < F; ++i) {
			string f1, f2; cin >> f1 >> f2;
			
			if (person.find(f1) == person.end()) person[f1] = cnt++;
			if (person.find(f2) == person.end()) person[f2] = cnt++;

			int p1 = findParent(person[f1]);
			int p2 = findParent(person[f2]);

			if (p1 == p2) cout << max(networkSize[p1], networkSize[p2]) << "\n";
			else {
				merge(p1, p2);
				cout << max(networkSize[p1], networkSize[p2]) << "\n";
			}
		}
	}

	return 0;
}