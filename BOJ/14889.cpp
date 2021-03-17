#include <bits/stdc++.h>
#define MAX 20

using namespace std;

int N;
int S[MAX][MAX], isSelected[MAX];

int solution() {
	int ans = INT_MAX;
	do {
		int res1 = 0, res2 = 0;
		for (int i = 0; i < N; ++i) {
			if (isSelected[i] == 0) {
				for (int j = i + 1; j < N; ++j) {
					if(isSelected[j] == 0) res1 += (S[i][j] + S[j][i]);
				}
			}
			else if (isSelected[i] == 1) {
				for (int j = i + 1; j < N; ++j) {
					if(isSelected[j] == 1) res2 += (S[i][j] + S[j][i]);
				}
			}
		}
		ans = min(abs(res1 - res2), ans);
	} while (next_permutation(isSelected, isSelected + N));

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> S[i][j];
		}
		if (i >= N / 2) isSelected[i] = 1;
	}
	
	cout << solution();

	return 0;
}