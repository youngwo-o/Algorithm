#include <iostream>

#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> m1;
map<string, int> m2;

//다중집합 만들기
void makeSet(string str, map<string, int>& m) {
	for (int i = 0, len = str.size() - 1; i < len; ++i) {
		//두글자 모두 알파벳인 경우만
		if ('a' <= str[i] && str[i] <= 'z') {
			if ('a' <= str[i + 1] && str[i + 1] <= 'z') {
				string s = str.substr(i, 2);
				m[s]++;
			}
		}
	}
}

int solution(string str1, string str2) {
	//소문자로 통일
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	makeSet(str1, m1);
	makeSet(str2, m2);

	int a = 0, b = 0;
	//m1 집합에서 교집합, 합집합의 개수 구하기
	for (auto it : m1) {
		string s = it.first;

		if (m2[s] == 0)
			b += it.second;
		else {
			a += min(it.second, m2[s]);
			b += max(it.second, m2[s]);
			m2.erase(s);
		}
	}
	//합집합에 m1 집합에 없고 m2에만 있는 문자열 개수 추가
	for (auto it : m2) {
		b += it.second;
	}

	double j;
	if (b != 0)
		j = (double)a / b;
	else
		return 65536;

	return j * 65536;
}

int main() {
	cout << solution("FRANCE", "french");
	return 0;
}