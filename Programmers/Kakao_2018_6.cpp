#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//num�� n������ ��ȯ -> string return
string toNNumber(int n, int num) {
	string res = "";

	if (num == 0 || num == 1) return to_string(num);

	vector<int> tmp;
	//num�� 0�� �ɶ����� n���� ���� ������ �� tmp�� ����
	while (num >= 1) {
		tmp.push_back(num % n);
		num /= n;
	}

	//tmp �Ųٷ�
	reverse(tmp.begin(), tmp.end());

	string d = "0123456789ABCDEF";

	//tmp���� �´� ���ڷ� ��ȯ
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
			//Ʃ���� ������ ���
			if (idx % m == p - 1) {
				answer += s[i];
				//Ʃ�갡 ���� Ƚ�� ����
				cnt++;
				//t�� ���� ��� break
				if (cnt == t) break;
			}
			//���� ����
			idx++;
		}

		//t�� ���� ��� break
		if (cnt == t) break;

		//n������ ��ȯ�� ���� ����
		num++;
	}

	return answer;
}

int main() {
	cout << solution(16, 16, 2, 2);
	return 0;
}