#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
int ans = INT_MAX;
int visited[9] = { 0 };

//시작지점 변경
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

		//한명씩 돌아가면서
		for (int i = 0; i < num.size(); ++i) {
			int sum = 0;

			//현재 시작점부터 시작
			for (int j = 0; j < newWeak.size() - 1; ++j) {
				sum += (newWeak[j + 1] - newWeak[j]);

				//i번째 친구가 현재까지 맡은 거리가 이동 가능한 거리보다 큰 경우
				if (dist[num[i]] < sum) {
					//외벽공사를 마친 곳까지 취약지점 배열에서 제거
					//한 친구가 하나의 지점만 맡은 경우도 있을 수 있음
					newWeak.erase(newWeak.begin(), newWeak.begin() + j + 1);
					break;
				}
			}
			//외벽공사를 모두 마친 경우
			if (sum <= dist[num[i]])
				return true;
		}
		//다음 시작 지점으로 바꾸고, 직선형태로 만들기
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
	//완전 탐색 => 친구가 선택되는 순서에 따라 결과가 달라질 수 있음
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