#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
	int left = 0, right = s.size() - 1;
	bool check = false;
	while (left <= right) {
		if (s[left] != s[right]) { //���ڰ� �ٸ� ���
			if (!check) { //������ �� ���ڸ� �������� ���� ���, �����ʿ��� �� ���� ����
				check = true;
				right--;
				continue;
			} else break;
		}
		left++;
		right--;
	}
	
	if (left > right) {
		if (!check) return 0;
		else return 1;
	}
	else {
		left = 0, right = s.size() - 1;
		check = false;
		while (left <= right) {
			if (s[left] != s[right]) { //���ڰ� �ٸ� ���
				if (!check) { //������ �� ���ڸ� �������� ���� ���, ���ʿ��� �� ���� ����
					check = true;
					left++;
					continue;
				} else break;
			}
			left++;
			right--;
		}

		if (left > right) {
			if (!check) return 0;
			else return 1;
		}
		else return 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string s;
		cin >> s;

		cout << solution(s) << "\n";
	}

	return 0;
}