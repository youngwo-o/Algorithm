#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp1(const pair<int, long long> a, const pair<int, long long> b) {
	if (a.second > b.second)
		return true;
	return false;
}

bool cmp2(const pair<int, long long> a, const pair<int, long long> b) {
	if (a.first < b.first)
		return true;
	return false;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;

	long long sum = 0;
	vector<pair<int, long long>> idx_foods;
	for (int i = 0, len = food_times.size(); i < len; ++i) {
		idx_foods.push_back({ i + 1, food_times[i] });
		sum += food_times[i];
	}

	//���̻� ���� ���� ���� ���
	if (sum <= k)
		return -1;

	sort(idx_foods.begin(), idx_foods.end(), cmp1);

	//�̹� k���� �� time�� �ٽ� ���� �ʱ����� pre�� �����س���
	long long pre = 0;
	while (1) {
		int size = idx_foods.size();

		//time�� ���� ���� �ͺ��� ����
		if (k > (idx_foods[size - 1].second - pre) * size) {
			k -= ((idx_foods[size - 1].second - pre) * size);
			pre = idx_foods[size - 1].second;
			idx_foods.pop_back();
		}
		else
			break;
	}

	sort(idx_foods.begin(), idx_foods.end(), cmp2);
	answer = idx_foods[k % idx_foods.size()].first;

	return answer;
}

int main() {
	vector<int> food_times = { 3, 1, 2 };
	long long k = 5;

	cout << solution(food_times, k);

	return 0;
}