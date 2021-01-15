#include <iostream>
#include <string>

using namespace std;

string s;

string compress(int len) {
	int pos = 0;
	string newS = "";
	while (pos <= s.size()) {
		string subS = s.substr(pos, len);

		int cnt = 0;
		for (int i = pos; i <= s.size();) {
			string tmpS = s.substr(i, len);
			if (subS == tmpS) {
				cnt++;
				i += len;
			}
			else
				break;
		}

		if (cnt > 1) {
			newS += (to_string(cnt) + subS);
			pos += (cnt * len);
		}
		else {
			newS += subS;
			pos += len;
		}
	}

	return newS;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	int ans = 1001;
	for (int i = 1; i <= s.size(); ++i) {
		string tmpS = compress(i);
		if (tmpS.size() < ans)
			ans = tmpS.size();
	}

	cout << ans;

	return 0;
}