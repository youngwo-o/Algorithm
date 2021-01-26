#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;

void dfs(int idx, int cnt, int num, string menu, string order) {
	menu += order[idx];

	//��ǰ �޴��� ������ ������ �����Ҷ�
	if (cnt == num) {
		if (m.count(menu) == 0)
			m.insert({ menu, 1 });
		else
			m[menu]++;

		menu.pop_back();
		return;
	}

	//���� �޴� ����
	for (int i = idx + 1; i < order.size(); ++i) {
		dfs(i, cnt + 1, num, menu, order);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	//��ǰ�޴� ������ ����
	for (int i = 0; i < course.size(); ++i) {
		int num = course[i];

		//�ϳ��� �������� ���� �� �ִ� ��� �޴��� ��� Ž��
		for (int j = 0; j < orders.size(); ++j) {
			string menu;
			string tmp = orders[j];
			//�������� ���� -> ��ǰ�޴��� ������ �ߺ� ����
			sort(tmp.begin(), tmp.end());

			//dfs�� ��������� �޴� Ž��
			for (int k = 0; k < orders[j].size(); ++k) {
				dfs(k, 1, num, menu, tmp);
			}
		}

		int cnt = 0;
		vector<string> tmp;
		//��ǰ�޴��� ���� Ž��
		for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it) {
			//�ּ� 2�� �̻��� �մ����κ��� �ֹ��Ǿ����
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

	//����� ������������ ����
	sort(answer.begin(), answer.end());

	return answer;
}

int main() {
	vector<string> orders = { "XYZ", "XWY", "WXA" };
	vector<int> course = { 2, 3, 4 };

	solution(orders, course);

	return 0;
}