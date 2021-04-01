#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> name;
set<string> dup;

bool cmp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	else return a.length() < b.length();
}

int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			string s; cin >> s;
			if (dup.count(s) == 0) {
				dup.insert(s);
				name.push_back(s);
			}
		}

		sort(name.begin(), name.end(), cmp);

		cout << "#" << tc << "\n";
		for (auto& n : name) {
			cout << n << "\n";
		}

		name.clear();
		dup.clear();
	}
}