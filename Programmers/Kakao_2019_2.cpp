#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
	if (a.first > b.first) {
		return true;
	}
	else if(a.first == b.first) {
		if (a.second < b.second)
			return true;
	}

	return false;
}

vector<int> solution(int N, vector<int> stages) {
	int num[501] = { 0 }; //i�� ���������� ���� Ŭ�������� ���� ����� ��
	int start = 0; //1�� ������������ ������ ����� ��
	for (int i = 0, len = stages.size(); i < len; ++i) {
		num[stages[i]]++;
		if (stages[i] >= 1)
			start++;
	}

	vector<pair<double, int>> tmp;
	for (int i = 1; i <= N; ++i) {
		//0���� ������ ��� ����!!
		if (start <= 0)
			tmp.push_back({ 0, i });
		//i�� ���������� ���������� ���� Ŭ�������� ���� ����� �� / ���������� ������ ����� ��
		else
			tmp.push_back({ (double)num[i] / start, i });

		//���������� ������ ��� �� ���� -> ���� Ŭ�������� ���� ����� �� ����
		start -= num[i];
	}

	sort(tmp.begin(), tmp.end(), cmp);

	vector<int> ans;
	for (int i = 0, len = tmp.size(); i < len; ++i) {
		ans.push_back(tmp[i].second);
	}

	return ans;
}

int main() {
	int N = 5;
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	vector<int> ans = solution(N, stages);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}

	return 0;
}