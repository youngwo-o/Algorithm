#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
int ans = INT_MAX;
int visited[9] = { 0 };

//�������� ����
//ex. n = 12, weak = [1, 5, 6, 10] => [5, 6, 10, 13]
vector<int> rotate(int n, vector<int> weak) {
	vector<int> newWeak;

	for (int i = 1; i < weak.size(); ++i) {
		newWeak.push_back(weak[i]);
	}
	newWeak.push_back(weak[0] + n);

	return newWeak;
}

bool check(int n, vector<int> weak, vector<int> dist) {
	vector<int> newWeak = weak;

	for (int k = 0; k < weak.size(); ++k) {
		vector<int> tmp = newWeak;

		//�Ѹ� ���ư��鼭
		for (int i = 0; i < num.size(); ++i) {
			int sum = 0;

			//���� ���������� ����
			for (int j = 0; j < newWeak.size() - 1; ++j) {
				sum += (newWeak[j + 1] - newWeak[j]);

				//i��° ģ���� ������� ���� �Ÿ��� �̵� ������ �Ÿ����� ū ���
				if (dist[num[i]] < sum) {
					//�ܺ����縦 ��ģ ������ ������� �迭���� ����
					//�� ģ���� �ϳ��� ������ ���� ��쵵 ���� �� ����
					newWeak.erase(newWeak.begin(), newWeak.begin() + j + 1);
					break;
				}
			}
			//�ܺ����縦 ��� ��ģ ���
			if (sum <= dist[num[i]])
				return true;
		}
		//���� ���� �������� �ٲٰ�, �������·� �����
		newWeak = tmp;
		newWeak = rotate(n, newWeak);
	}

	return false;
}

void select(int idx, int n, vector<int> weak, vector<int> dist) {
	num.push_back(idx);

	if (check(n, weak, dist) == true) {
		ans = min(ans, (int)num.size());
		return;
	}

	for (int i = 0; i < dist.size(); ++i) {
		if (visited[i] == 0) {
			visited[i] = 1;
			select(i, n, weak, dist);
			num.pop_back();
			visited[i] = 0;
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	//���� Ž�� => ģ���� ���õǴ� ������ ���� ����� �޶��� �� ����
	for (int i = 0; i < dist.size(); ++i) {
		if (visited[i] == 0) {
			visited[i] = 1;
			select(i, n, weak, dist);
			num.pop_back();
			visited[i] = 0;
		}
	}

	if (ans == INT_MAX)
		ans = -1;

	return ans;
}

int main() {
	int n = 200;
	vector<int> weak = { 0, 10, 50, 80, 120, 160 };//{ 1, 5, 6, 10 };
	vector<int> dist = { 1, 10, 5, 40, 30 }; // { 1, 2, 3, 4 };

	solution(n, weak, dist);

	cout << ans;

	return 0;
}