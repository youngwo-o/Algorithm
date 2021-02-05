#include <bits/stdc++.h>

using namespace std;

int findNumIdx(const string s) {
	for (int i = 0; i < s.length(); ++i) {
		if (isdigit(s[i]))
			return i;
	}
}

int getNum(const string s) {
	return stoi(s.substr(findNumIdx(s)));
}

string getHead(const string s) {
	string res = s.substr(0, findNumIdx(s));
	transform(res.begin(), res.end(), res.begin(), ::tolower);
	return res;
}

bool cmp(const string a, const string b) {
	string head1 = getHead(a), head2 = getHead(b);

	if (head1 == head2) {
		int num1 = getNum(a), num2 = getNum(b);
		
		return num1 < num2;
	}
	else
		return head1 < head2;
}

vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(), cmp);

	return files;
}