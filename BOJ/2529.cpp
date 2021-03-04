#include <bits/stdc++.h>

using namespace std;

int k;
vector<int> entry(10);

void findMax() { //가장 큰 값 찾기
	vector<int> entryTmp = entry;
	priority_queue<int> q;

	for (int i = 0; i <= k; ++i) {
		if (entryTmp[i] == 0)
			q.push(-i);
	}

	vector<int> res;
	while (!q.empty()) {
		int cur = -q.top(); //작은 인덱스가 앞으로 오도록 -> 작은 인덱스에 먼저 큰 값을 할당해야함
		q.pop();

		res.push_back(cur);

		if (cur - 1 >= 0) { //왼쪽 인덱스 검사
			entryTmp[cur - 1]--;
			if (entryTmp[cur - 1] == 0) //다음 인덱스의 앞선 인덱스를 모두 방문한 경우 (진입 차수가 0)
				q.push(-(cur - 1));
		}
		if (cur + 1 <= k) { //오른쪽 인덱스 검사
			entryTmp[cur + 1]--;
			if (entryTmp[cur + 1] == 0) //다음 인덱스의 앞선 인덱스를 모두 방문한 경우 (진입 차수가 0)
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

void findMin() { //가장 작은 값 찾기
	vector<int> entryTmp = entry;
	priority_queue<int> q;

	for (int i = 0; i <= k; ++i) {
		if (entryTmp[i] == 0)
			q.push(i);
	}

	vector<int> res;
	while (!q.empty()) {
		int cur = q.top(); //큰 인덱스가 앞으로 오도록 -> 큰 인덱스에 먼저 큰 값을 할당해야함
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