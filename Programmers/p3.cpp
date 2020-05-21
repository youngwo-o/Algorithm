#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	int alphabet[26] = { 0 };
	for (int i = 0; i < skill.size(); ++i) {
		alphabet[skill[i] - 'A'] = 1;
	}

	for (int i = 0; i < skill_trees.size(); ++i) {
		vector<char> tmp;

		for (int j = 0; j < skill_trees[i].size(); ++j) {
			if (alphabet[skill_trees[i][j] - 'A']) {
				tmp.push_back(skill_trees[i][j]);
			}
		}

		int check = 0;
		for (int j = 0; j < tmp.size(); ++j) {
			if (skill[j] != tmp[j]) {
				check = 1;
				break;
			}
		}

		if (check == 0)
			answer++;
	}

	return answer;
}