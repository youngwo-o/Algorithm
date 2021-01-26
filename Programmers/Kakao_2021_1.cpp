#include <string>

using namespace std;

string solution(string new_id) {
	string tmp_id = "";

	for (int i = 0, len = new_id.size(); i < len;  ++i) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			tmp_id += (new_id[i] - 'A' + 'a');
		else
			tmp_id += new_id[i];
	}

	for (int i = 0; i < tmp_id.size(); ++i) {
		if (tmp_id[i] >= 'a' && tmp_id[i] <= 'z');
		else if (tmp_id[i] >= '1' && tmp_id[i] <= '9');
		else if (tmp_id[i] == '-' || tmp_id[i] == '_' || tmp_id[i] == '.');
		else {
			tmp_id = tmp_id.erase(i, 1);
			i--;
		}
	}

	for (int i = 0; i < tmp_id.size(); ++i) {
		if (tmp_id[i] == '.') {
			int cnt = 0;
			for (int j = i + 1; j < tmp_id.size(); ++j) {
				if (tmp_id[j] == '.')
					cnt++;
				else
					break;
			}
			tmp_id = tmp_id.erase(i + 1, cnt);
		}
	}

	if (tmp_id[0] == '.')
		tmp_id = tmp_id.substr(1, tmp_id.size() - 1);
	if (tmp_id[tmp_id.size() - 1] == '.')
		tmp_id = tmp_id.substr(0, tmp_id.size() - 1);

	if (tmp_id.size() == 0)
		tmp_id += 'a';
	if (tmp_id.size() >= 16)
		tmp_id = tmp_id.substr(0, 15);
	if (tmp_id[tmp_id.size() - 1] == '.')
		tmp_id = tmp_id.substr(0, tmp_id.size() - 1);

	if (tmp_id.size() <= 2) {
		char c = tmp_id[tmp_id.size() - 1];
		while (tmp_id.size() != 3) {
			tmp_id += c;
		}
	}

	return tmp_id;
}

int main() {
	solution("...!@BaT#*..y.abcdefghijklm");

	return 0;
}