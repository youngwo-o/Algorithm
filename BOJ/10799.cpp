#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int ans = 0;
	stack<int> s;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') { //�������� ���
				ans += s.size();
				i++;
			}
			else //�踷����� ������ ���
				s.push(1);
		}
		else if (str[i] == ')') { //�踷����� ���� ���
			ans++;
			s.pop();
		}
	}

	cout << ans;

	return 0;
}