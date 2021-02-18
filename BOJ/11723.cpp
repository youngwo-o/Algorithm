#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> M;
	cin.ignore();

	int s = 0;
	for (int i = 0; i < M; ++i) {
		string command;
		cin >> command;

		int x;
		if (command == "add") {
			cin >> x;
			s |= (1 << x);
		}
		else if (command == "remove") {
			cin >> x;
			s &= ~(1 << x);
		}
		else if (command == "check") {
			cin >> x;
			cout << ((s & (1 << x)) == 0 ? 0 : 1) << "\n";
		}
		else if (command == "toggle") {
			cin >> x;
			s ^= (1 << x);
		}
		else if (command == "all")
			s |= ~(0 << 20);
		else if (command == "empty")
			s = 0;
	}

	return 0;
}