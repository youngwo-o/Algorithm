#include <iostream>
#include <algorithm>

using namespace std;

int t, n, m;
int note1[1000001], note2[1000001];

bool sol(int num) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num < note1[mid])
			right = mid - 1;
		else if (num > note1[mid])
			left = mid + 1;
		else
			return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> note1[j];
		}
		cin >> m;
		for (int j = 0; j < m; ++j) {
			cin >> note2[j];
		}

		sort(note1, note1 + n);

		for (int j = 0; j < m; ++j) {
			if (sol(note2[j]) == true)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}