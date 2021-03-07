#include <bits/stdc++.h>

using namespace std;

int N;
char* tree;

bool isLeaf(int idx) {
	return (1 <= idx && idx <= N && tree[idx] == 0);
}

int solution(int idx) {
	if (idx > N) return 0;

	char c = tree[idx];

	//숫자인 경우
	if (isdigit(c)) {
		//마지막 노드이거나 / 자식이 없는 경우
		if ((idx*2 > N) && (idx*2+1 > N) || isLeaf(idx*2) && isLeaf(idx*2+1)) return 1;
		else return 0;
	}
	else return solution(idx*2) & solution(idx*2+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int tc = 1; tc <= 10; ++tc) {
		cin >> N;
		cin.ignore(); //다음 getline()을 위해 개행 무시
		tree = new char[N + 1];

		for (int i = 0; i < N; ++i) {
			vector<string> result;
			string str, token;
			getline(cin, str); //문자열 읽기 (공백 포함)

			 //ss로 문자열 parsing
			stringstream ss(str);
			while (getline(ss, token, ' ')) {
				result.push_back(token);
			}

			tree[stoi(result[0])] = (result[1].c_str())[0];
		}

		cout << "#" << tc << " " << solution(1) << "\n";
	}

	return 0;
}