#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& stones, int k) {
	int cnt = 0;
	for (auto& s : stones) {
		if (s == 0) cnt++;
		else {
			cnt = 0;
			s--;
		}

		//�� �̻� ���� �� ���� ������� �������� k�� �ִ� ��� -> �ǳ� �� ����
		if (cnt == k) return false;
	}

	return true;
}

int solution(vector<int> stones, int k) {
	//stones ũ�� 200000����
	//stones ���� �� 200000000 ����
	//�̺�Ž�� �ʿ�!

	int left = 1, right = 0; //left : �ǳʴ� �ּ� ��� ��, right : �ǳʴ� �ִ� ��� ��
	for (auto s : stones) {
		right = max(s, right);
	}
	while (left <= right) {
		int mid = (left + right) / 2;

		vector<int> tmp = stones;
		for (auto& t : tmp) {
			if (t - mid < 0) t = 0;
			else t -= mid;
		}

		if (check(tmp, k)) left = mid + 1;
		else right = mid - 1;
	}

	return left;
}