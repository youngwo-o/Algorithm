#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr;
	arr.push_back(-1);
	for (int i = 1; i <= N; ++i) {
		int h;
		cin >> h;
		arr.push_back(h);
	}
	stack<int> s;
	vector<int> ans;
	for (int i = 1; i <= N; ++i) {
		if (s.empty()) ans.push_back(0);
		else {
			while (!s.empty()) {
				int topIdx = s.top();

				//��� ž�� ���̰� ���� �ٸ��� ������ ���� ��� ó�� ���ص���
				//top��° ž�� ���̰� ���� ž�� ���̺��� ū ��� -> ���� ����
				if (arr[topIdx] > arr[i]) {
					ans.push_back(topIdx);
					break;
				}

				s.pop();
			}

			//���� ������ ž�� ���� ���
			if (s.empty())
				ans.push_back(0);
		}

		//���� ž �ε��� ���ÿ� �߰�
		s.push(i);
	}

	for (auto a : ans) {
		cout << a << " ";
	}

	return 0;
}