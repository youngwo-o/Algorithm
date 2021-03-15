#include <bits/stdc++.h>

using namespace std;

string solution(string p) {
	//1
	if (p.empty()) return "";

	//2
	string u, v;
	int open = 0, close = 0;
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] == '(') open++;
		else if (p[i] == ')') close++;
		if (open == close) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1, p.size() - (i + 1));
			break;
		}
	}

	bool check = false;
	open = close = 0;
	for (int i = 0; i < u.size(); ++i) {
		if (u[i] == '(') open++;
		else if (u[i] == ')') {
			if (open <= 0) {
				check = true;
				break;
			}
			open--;
		}
	}

	//4
	if (check) {
		string tmp = '(' + solution(v) + ')';
		u.erase(u.begin());
		u.pop_back();
		for (auto _u : u) {
			if (_u == '(') tmp += ')';
			else if (_u == ')') tmp += '(';
		}
		return tmp;
	}
	//3
	else {
		u += solution(v);
		return u;
	}
}