#include <iostream>
#include <string>

using namespace std;

string p;

bool isRight(string u) {
	int open = 0, close = 0;
	for (int i = 0; i < u.size(); ++i) {
		if (u[i] == '(')
			open++;
		else if (u[i] == ')') {
			if (open == 0)
				return false;
			else
				open--;
		}
	}

	return true;
}

string solution(string p) {
	string u, v;
	string newP = "";
	
	int open = 0, close = 0;
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] == '(')
			open++;
		else if (p[i] == ')')
			close++;

		//�������� ���ڿ��� �и�
		if (open == close) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1, p.size());

			//u�� �ùٸ� ���ڿ��� ���
			if (isRight(u) == true) {
				newP += u;
				//v�� ���� ��������� ����
				newP += solution(v);
			}
			//u�� �ùٸ� ���ڿ��� �ƴ� ���
			else {
				newP += '(';
				//v�� ���� ��������� ����
				newP += solution(v);
				newP += ')';

				//u�� ù��°�� ������ ���� ����, ��ȣ ���� ����� ���̱�
				for (int i = 1; i < u.size() - 1; ++i) {
					if (u[i] == '(')
						newP += ')';
					else if (u[i] == ')')
						newP += '(';
				}
			}

			break;
		}
	}

	return newP;
}

int main() {
	cin >> p;

	cout << solution(p);

	return 0;
}