#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc= 0; tc < T; ++tc) {
		string str;
		cin >> str;

		stack<char> s;
		bool check = false;
		for (auto a : str) {
			if (a == '(') s.push('(');
			else if (a == ')') {
				if (s.empty()) {
					cout << "NO\n";
					check = true;
					break;
				}
				else s.pop();
			}
		}

		if (!check) {
			if (!s.empty()) cout << "NO\n";
			else cout << "YES\n";
		}
	}

	return 0;
}