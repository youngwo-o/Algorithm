#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int strToInt(string s) {
	int p = pow(10, s.length() - 1);
	int res = 0;

	for (int i = 0; i < s.length(); ++i) {
		res += ((s[i] - '0') * p);
		p /= 10;
	}

	return res;
}

bool cmp(vector<string> a, vector<string> b) {
	transform(a[0].begin(), a[0].end(), a[0].begin(), ::tolower);
	transform(b[0].begin(), b[0].end(), b[0].begin(), ::tolower);

	//header�� ������, number ��
	if (a[0] == b[0]) {
		int aNum = strToInt(a[1]);
		int bNum = strToInt(b[1]);

		//number�� ������, index ��(�Է� �� �־��� ��)����
		if (aNum == bNum)
			return strToInt(a[3]) < strToInt(b[3]);
		else  //number�� �ٸ���, number ��
			return aNum < bNum;
	}
	else //header �ٸ���, header ������
		return a[0] < b[0];
}

vector<string> solution(vector<string> files) {
	vector<string> answer;

	vector<vector<string>> f;
	for (int j = 0; j < files.size(); ++j) {
		string file = files[j];

		vector<string> hnt;
		int idx = 0;
		for (int i = 0; i < file.length(); ++i) {
			if (hnt.size() == 0 && ('0' <= file[i] && file[i] <= '9')) {
				hnt.push_back(file.substr(idx, i));
				idx = i;
			}
			else if (hnt.size() == 1 && !('0' <= file[i] && file[i] <= '9')) {
				hnt.push_back(file.substr(idx, i - idx));
				idx = i;
			}
			else if(hnt.size() == 2)
				hnt.push_back(file.substr(idx));
		}

		if (hnt.size() == 1) {
			hnt.push_back(file.substr(idx));
			hnt.push_back("");
		}
		else if (hnt.size() == 2) {
			hnt.push_back("");
		}

		//C++ sort => quick sort (unstable)
		//�Է� �� �־��� ������ �����Ҷ��� ����ؼ� ���� index �� ���� (stable�ϰ�)
		hnt.push_back(to_string(j));

		f.push_back(hnt);
	}

	sort(f.begin(), f.end(), cmp);

	for (auto s : f) {
		string res = s[0] + s[1] + s[2];
		cout << res << endl;
		answer.push_back(res);
	}

	return answer;
}

int main() {
	solution({ "aaa01", "AAA-01" });
	return 0;
}