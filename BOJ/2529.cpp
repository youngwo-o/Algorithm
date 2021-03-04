#include <bits/stdc++.h>

using namespace std;

int k;
vector<int> entry(10);

void findMax() { //���� ū �� ã��
	vector<int> entryTmp = entry;
	priority_queue<int> q;

	for (int i = 0; i <= k; ++i) {
		if (entryTmp[i] == 0)
			q.push(-i);
	}

	vector<int> res;
	while (!q.empty()) {
		int cur = -q.top(); //���� �ε����� ������ ������ -> ���� �ε����� ���� ū ���� �Ҵ��ؾ���
		q.pop();

		res.push_back(cur);

		if (cur - 1 >= 0) { //���� �ε��� �˻�
			entryTmp[cur - 1]--;
			if (entryTmp[cur - 1] == 0) //���� �ε����� �ռ� �ε����� ��� �湮�� ��� (���� ������ 0)
				q.push(-(cur - 1));
		}
		if (cur + 1 <= k) { //������ �ε��� �˻�
			entryTmp[cur + 1]--;
			if (entryTmp[cur + 1] == 0) //���� �ε����� �ռ� �ε����� ��� �湮�� ��� (���� ������ 0)
				q.push(-(cur + 1));

		}
	}

	vector<int> maxAns(k + 1);
	int maxNum = 9;
	for (auto idx : res) {
		maxAns[idx] = maxNum--;
	}

	for (auto num : maxAns) {
		cout << num;
	}
	cout << "\n";
}

void findMin() { //���� ���� �� ã��
	vector<int> entryTmp = entry;
	priority_queue<int> q;

	for (int i = 0; i <= k; ++i) {
		if (entryTmp[i] == 0)
			q.push(i);
	}

	vector<int> res;
	while (!q.empty()) {
		int cur = q.top(); //ū �ε����� ������ ������ -> ū �ε����� ���� ū ���� �Ҵ��ؾ���
		q.pop();

		res.push_back(cur);

		if (cur - 1 >= 0) {
			entryTmp[cur - 1]--;
			if (entryTmp[cur - 1] == 0) q.push(cur - 1);
		}
		if (cur + 1 <= k) {
			entryTmp[cur + 1]--;
			if (entryTmp[cur + 1] == 0) q.push(cur + 1);

		}
	}

	vector<int> minAns(k + 1);
	int  minNum = k;
	for (auto idx : res) {
		minAns[idx] = minNum--;
	}
	for (auto num : minAns) {
		cout << num;
	}
}

void solution() {
	findMax();
	findMin();
}

int main() {
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		char c;
		cin >> c;
		if (c == '<')
			entry[i - 1]++;
		else if (c == '>')
			entry[i]++;
	}

	solution();

	return 0;
}