#include <bits/stdc++.h>

using namespace std;

map<string, int> m1;
map<string, int> m2;

//�������� �����
void makeSet(string str, map<string, int>& m) {
	for (int i = 0, len = str.size() - 1; i < len; ++i) {
		if(isalpha(str[i]) && isalpha(str[i + 1])) {
				string s = str.substr(i, 2);
				m[s]++;
		}
	}
}

int solution(string str1, string str2) {
	//�ҹ��ڷ� ����
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	makeSet(str1, m1);
	makeSet(str2, m2);

	int a = 0, b = 0;
	//m1 ���տ��� ������, �������� ���� ���ϱ�
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
	//�����տ� m1 ���տ� ���� m2���� �ִ� ���ڿ� ���� �߰�
	for (auto it : m2) {
		b += it.second;
	}

	return b ? ((double)a / b) * 65536 : 65536;
}

int main() {
	cout << solution("FRANCE", "french");
	return 0;
}