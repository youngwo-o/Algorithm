#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> ans;

	map<string, string> user;
	for (int i = 0, len = record.size(); i < len; ++i) {
		string str = record[i];

		string cmd = "", uid = "", name = "";
		int idx, idx2;
		for (int j = 0, sLen = str.size(); j < sLen; ++j) {
			if (str[j] == ' ') {
				if (cmd == "") {
					cmd = str.substr(0, j);
					idx = j + 1;

					if (cmd == "Leave")
						uid = str.substr(j + 1);
				}
				else {
					if (cmd == "Enter") {
						uid = str.substr(idx, j - idx);
						name = str.substr(j + 1);
					}
					else if (cmd == "Change") {
						uid = str.substr(idx, j - idx);
						name = str.substr(j + 1);
					}
				}
			}
		}

		if (cmd == "Enter" || cmd == "Change") {
			if (user.count(uid) == 0)
				user.insert({ uid, name });
			else
				user[uid] = name;
		}
	}

	for (int i = 0, len = record.size(); i < len; ++i) {
		string str = record[i];

		string cmd = "", uid = "", name = "";
		int idx, idx2;
		for (int j = 0, sLen = str.size(); j < sLen; ++j) {
			if (str[j] == ' ') {
				if (cmd == "") {
					cmd = str.substr(0, j);
					idx = j + 1;

					if (cmd == "Leave")
						uid = str.substr(j + 1);
				}
				else {
					if (cmd == "Enter") {
						uid = str.substr(idx, j - idx);
						name = str.substr(j + 1);
					}
					else if (cmd == "Change") {
						uid = str.substr(idx, j - idx);
						name = str.substr(j + 1);
					}
				}
			}
		}

		if (cmd == "Enter")
			ans.push_back(user[uid] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		else if (cmd == "Leave")
			ans.push_back(user[uid] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
	}

	return ans;
}

int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

	vector<string> ans = solution(record);

	cout << "-------------------------------------------------\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}