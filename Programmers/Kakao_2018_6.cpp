#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//num을 n진수로 변환 -> string return
string toNNumber(int n, int num) {
	string res = "";

	if (num == 0 || num == 1) return to_string(num);

	vector<int> tmp;
	//num이 0이 될때까지 n으로 나눈 나머지 값 tmp에 저장
	while (num >= 1) {
		tmp.push_back(num % n);
		num /= n;
	}

	//tmp 거꾸로
	reverse(tmp.begin(), tmp.end());

	string d = "0123456789ABCDEF";

	//tmp값에 맞는 문자로 변환
	for (auto t : tmp) {
		res += d[t];
	}

	return res;
}

string solution(int n, int t, int m, int p) {
	string answer = "";

	int cnt = 0, num = 0, idx = 0;
	while (1) {
		string s = toNNumber(n, num);

		for (int i = 0; i < s.length(); ++i) {
			//튜브의 순서인 경우
			if (idx % m == p - 1) {
				answer += s[i];
				//튜브가 말한 횟수 증가
				cnt++;
				//t번 말한 경우 break
				if (cnt == t) break;
			}
			//순서 증가
			idx++;
		}

		//t번 말한 경우 break
		if (cnt == t) break;

		//n진수로 변환할 숫자 증가
		num++;
	}

	return answer;
}

int main() {
	cout << solution(16, 16, 2, 2);
	return 0;
}