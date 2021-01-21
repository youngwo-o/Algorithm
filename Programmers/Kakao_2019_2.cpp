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
	int num[501] = { 0 }; //i번 스테이지를 아직 클리어하지 못한 사람의 수
	int start = 0; //1번 스테이지까지 도달한 사람의 수
	for (int i = 0, len = stages.size(); i < len; ++i) {
		num[stages[i]]++;
		if (stages[i] >= 1)
			start++;
	}

	vector<pair<double, int>> tmp;
	for (int i = 1; i <= N; ++i) {
		//0으로 나누는 경우 조심!!
		if (start <= 0)
			tmp.push_back({ 0, i });
		//i번 스테이지에 도달했으나 아직 클리어하지 못한 사람의 수 / 스테이지에 도달한 사람의 수
		else
			tmp.push_back({ (double)num[i] / start, i });

		//스테이지에 도달한 사람 수 갱신 -> 아직 클리어하지 못한 사람의 수 빼기
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