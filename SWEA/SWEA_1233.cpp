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

	//������ ���
	if (isdigit(c)) {
		//������ ����̰ų� / �ڽ��� ���� ���
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
		cin.ignore(); //���� getline()�� ���� ���� ����
		tree = new char[N + 1];

		for (int i = 0; i < N; ++i) {
			vector<string> result;
			string str, token;
			getline(cin, str); //���ڿ� �б� (���� ����)

			 //ss�� ���ڿ� parsing
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