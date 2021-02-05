#include <bits/stdc++.h>

using namespace std;

//num을 n진수로 변환 -> string return
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
			//튜브의 순서인 경우
			if (idx % m == p - 1) {
				answer += s[i];
				//튜브가 말한 횟수 증가
				cnt++;
				//t번 말한 경우 break
				if (cnt == t) break ;
			}
			//순서 증가
			idx++;
		}

		//n진수로 변환할 숫자 증가
		num++;
	}

	return answer;
}

int main() {
	cout << solution(16, 16, 2, 2);
	return 0;
}