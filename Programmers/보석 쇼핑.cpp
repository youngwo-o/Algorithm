#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


vector<int> solution(vector<string> gems) {
	vector<int> answer(2);

	int start = 0, end = 0, min = gems.size();
	unordered_map<string, int> m;

	for (auto& g : gems) m[g]++; //�� ������ ����
	int gemNum = m.size(); //���� ������ ��
	m.clear();

	answer[0] = start + 1;
	answer[1] = end + 1;
	m[gems[0]]++; //0�� �ε����� ���� ����

	while (1) {
		if (m.size() == gemNum) { //��� ������ ������ �����ϴ� ���
			if (end - start < min) { //���� ª�� ������ ���
				min = end - start; //�ּҰ� ����
				answer[0] = start + 1;
				answer[1] = end + 1;
			}

			m[gems[start]]--; //���� ���Ե� start �ε����� �ش��ϴ� ���� �� ����
			if (m[gems[start]] == 0) m.erase(gems[start]); //0�� ��� �ƿ� ����
			start++; //�ٽ� ���� ª�� ���� ���ϱ� ���� start ����
		}
		else if (end + 1 >= gems.size()) break;
		else m[gems[++end]]++; //���� ��ġ�� ���� ���Խ�Ų ��, end ����
	}

	return answer;
}