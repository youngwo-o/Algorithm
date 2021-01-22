#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> tmpRes;

bool cmp(const vector<int>& a, const vector<int>& b) {
	if (a.size() < b.size())
		return true;
	return false;
}

bool check(vector<int> res, vector<vector<string>> relation) {
	if (res.size() == 1) {
		set<string> tmp;
		int r = relation.size();
		for (int i = 0; i < r; ++i) {
			if (tmp.count(relation[i][res[0]]) == 0)
				tmp.insert(relation[i][res[0]]);
			else
				return false;
		}
	}
	else {
		set<vector<string>> tmp;
		int r = relation.size();
		for (int i = 0; i < r; ++i) {
			vector<string> s;
			for (int j = 0; j < res.size(); ++j) {
				s.push_back(relation[i][res[j]]);
			}
			if (tmp.count(s) == 0)
				tmp.insert(s);
			else
				return false;
		}
	}

	return true;
}

void dfs(int idx, vector<int> res, vector<vector<string>> relation) {
	if (check(res, relation)) {
		tmpRes.push_back(res);
		return;
	}

	int c = relation[0].size();
	for (int i = idx + 1; i < c; ++i) {
		res.push_back(i);
		dfs(i, res, relation);
		res.pop_back();
	}
}

int solution(vector<vector<string>> relation) {
	int c = relation[0].size();
	vector<int> res;
	for (int i = 0; i < c; ++i) {
		res.push_back(i);
		dfs(i, res, relation);
		res.pop_back();
	}

	//dfs�� ������� ���⶧���� �ߺ��Ǵ� �� ���� �� ����
	//ex. {0}, {1,3}, {3}
	//�켱 ������ �����ͺ��� ����
	sort(tmpRes.begin(), tmpRes.end(), cmp);

	//�ߺ��Ǵ� �� ����
	//ex. tmpRes = {{0}, {3}, {1,2}, {1,3}, {2,3}}�� ��� -> {1,3}, {2,3} �����ؾ���
	//for�� ���鼭 �ߺ��Ǵ� �� �����ϱ�
	for(int i = 0; i < tmpRes.size(); ++i){
		for (int j = i + 1; j < tmpRes.size(); ++j) {
			int cnt = 0;
			for (int k = 0; k < tmpRes[i].size(); ++k) {
				for (int l = 0; l < tmpRes[j].size(); ++l) {
					if (tmpRes[i][k] == tmpRes[j][l])
						cnt++;
				}
			}

			//tmpRes[i]�� ��� ���� tmpRes[j]�� �����ִ� ��� -> ����
			if (cnt == tmpRes[i].size()) {
				tmpRes.erase(tmpRes.begin() + j, tmpRes.begin() + j + 1);
				j--;
			}
		}
	}

	return tmpRes.size();
}

int main() {
	cout << solution({ {"100","ryan","music","2" }, { "200","apeach","math1","4" }, { "300","tube","computer1","3" }, { "400","con","computer","5" }, { "500","muzi","music","6" }, { "600","apeach","music3","7" } } );

	return 0;
}