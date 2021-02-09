#include <bits/stdc++.h>

using namespace std;

int solution(const string& str1, const string& str2) {
	int len = (str1.length() > str2.length()) ? str2.length() : str1.length();

	for (int i = 0; i < len; ++i) {
		if (str1[i] != str2[i])
			return i + 1;
	}

	return str1.length() > len ? len + 1 : len;
}

int solution(vector<string> words) {
	int answer = 0;

	sort(words.begin(), words.end());

	for (int i = 0; i < words.size(); ++i) {
		int res = 0;

		if (i - 1 >= 0)
			res = max(res, solution(words[i], words[i - 1]));
		if (i + 1 < words.size())
			res = max(res, solution(words[i], words[i + 1]));
	
		answer += res;
	}

	return answer;
}