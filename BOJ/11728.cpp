#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int N, M;
int A[MAX], B[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i)	cin >> B[i];

	vector<int> ans;
	int ai = 0, bi = 0;
	while (ai < N && bi < M) {
		if (A[ai] <= B[bi]) ans.push_back(A[ai++]);
		else ans.push_back(B[bi++]);
	}

	for (auto& a : ans) cout << a << " ";
	for (int i = ai; i < N; ++i) cout << A[i] << " ";
	for (int i = bi; i < M; ++i) cout << B[i] << " ";

	return 0;
}