#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[9];
	int isSelected[9] = { 0 };

	for (int i = 0; i < 9; ++i) {
		cin >> arr[i];
		if (i >= 2) isSelected[i] = 1;
	}

	do {
		int tot = 0;
		for (int i = 0; i < 9; ++i) {
			if (isSelected[i]) tot += arr[i];
		}
		if (tot == 100)
			break;
	} while (next_permutation(isSelected, isSelected + 9));

	for (int i = 0; i < 9; ++i) {
		if (isSelected[i]) cout << arr[i] << "\n";
	}

	return 0;
}