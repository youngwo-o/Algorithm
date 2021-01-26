#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;

void dfs(int idx, int cnt, int num, string menu, string order) {
	menu += order[idx];

	//단품 메뉴의 개수가 조건을 충족할때
	if (cnt == num) {
		if (m.count(menu) == 0)
			m.insert({ menu, 1 });
		else
			m[menu]++;

		menu.pop_back();
		return;
	}

	//다음 메뉴 선택
	for (int i = idx + 1; i < order.size(); ++i) {
		dfs(i, cnt + 1, num, menu, order);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	//단품메뉴 개수에 따라
	for (int i = 0; i < course.size(); ++i) {
		int num = course[i];

		//하나의 오더에서 나올 수 있는 모든 메뉴의 경우 탐색
		for (int j = 0; j < orders.size(); ++j) {
			string menu;
			string tmp = orders[j];
			//오름차순 정렬 -> 단품메뉴의 조합의 중복 방지
			sort(tmp.begin(), tmp.end());

			//dfs로 재귀적으로 메뉴 탐색
			for (int k = 0; k < orders[j].size(); ++k) {
				dfs(k, 1, num, menu, tmp);
			}
		}

		int cnt = 0;
		vector<string> tmp;
		//단품메뉴의 조합 탐색
		for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it) {
			//최소 2명 이상의 손님으로부터 주문되어야함
			if (it->second >= 2) {
				if (it->second > cnt) {
					tmp.clear();
					tmp.push_back(it->first);
					cnt = it->second;
				}
				else if (it->second == cnt)
					tmp.push_back(it->first);
			}
		}
		m.clear();

		for (int j = 0; j < tmp.size(); ++j) {
			answer.push_back(tmp[j]);
		}
	}

	//결과값 오름차순으로 정렬
	sort(answer.begin(), answer.end());

	return answer;
}

int main() {
	vector<string> orders = { "XYZ", "XWY", "WXA" };
	vector<int> course = { 2, 3, 4 };

	solution(orders, course);

	return 0;
}