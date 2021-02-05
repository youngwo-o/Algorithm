#include <bits/stdc++.h>

using namespace std;

//num�� n������ ��ȯ -> string return
string toNumber(int n, int num) {
	string res = "";
	string d = "0123456789ABCDEF";

	if (num == 0)
		return "0";

	while (num >= 1) {
		int r = num % n;
		res = d[r] + res;
		num /= n;
	}

	return res;
}

string solution(int n, int t, int m, int p) {
	string answer = "";

	int cnt = 0, num = 0, idx = 0;
	while (cnt != t) {
		string s = toNumber(n, num);

		for (int i = 0; i < s.length(); ++i) {
			//Ʃ���� ������ ���
			if (idx % m == p - 1) {
				answer += s[i];
				//Ʃ�갡 ���� Ƚ�� ����
				cnt++;
				//t�� ���� ��� break
				if (cnt == t) break ;
			}
			//���� ����
			idx++;
		}

		//n������ ��ȯ�� ���� ����
		num++;
	}

	return answer;
}

int main() {
	cout << solution(16, 16, 2, 2);
	return 0;
}