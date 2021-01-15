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

		//균형잡힌 문자열로 분리
		if (open == close) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1, p.size());

			//u가 올바른 문자열인 경우
			if (isRight(u) == true) {
				newP += u;
				//v에 대해 재귀적으로 수행
				newP += solution(v);
			}
			//u가 올바른 문자열이 아닌 경우
			else {
				newP += '(';
				//v에 대해 재귀적으로 수행
				newP += solution(v);
				newP += ')';

				//u의 첫번째와 마지막 문자 제외, 괄호 방향 뒤집어서 붙이기
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