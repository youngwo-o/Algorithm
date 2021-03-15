#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
	//1
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

	//2
	for (int i = 0; i < new_id.size(); ++i) {
		char c = new_id[i];
		if (islower(c));
		else if (isdigit(c));
		else if (c == '-' || c == '_' || c == '.');
		else {
			new_id.erase(i, 1);
			i--;
		}
	}

	//3
	for (int i = 0; i < new_id.size(); ++i) {
		if (new_id[i] == '.') {
			int cnt = 0;
			for (int j = i + 1; j < new_id.size(); ++j) {
				if (new_id[j] == '.') cnt++;
				else break;
			}
			new_id.erase(i, cnt);
		}
	}

	//4
	if (new_id.front() == '.') new_id.erase(new_id.begin());
	if (new_id.back() == '.') new_id.pop_back();

	//5
	if (new_id.empty()) new_id += 'a';

	//6
	if (new_id.size() >= 16) {
		new_id = new_id.substr(0, 15);
		if (new_id.back() == '.') new_id.pop_back();
	}

	//7
	if (new_id.size() <= 2) {
		while (new_id.size() < 3)
			new_id += new_id.back();
	}

	return new_id;
}