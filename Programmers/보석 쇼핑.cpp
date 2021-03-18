#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


vector<int> solution(vector<string> gems) {
	vector<int> answer(2);

	int start = 0, end = 0, min = gems.size();
	unordered_map<string, int> m;

	for (auto& g : gems) m[g]++; //각 보석의 개수
	int gemNum = m.size(); //보석 종류의 수
	m.clear();

	answer[0] = start + 1;
	answer[1] = end + 1;
	m[gems[0]]++; //0번 인덱스의 보석 포함

	while (1) {
		if (m.size() == gemNum) { //모든 종류의 보석을 포함하는 경우
			if (end - start < min) { //가장 짧은 구간인 경우
				min = end - start; //최소값 갱신
				answer[0] = start + 1;
				answer[1] = end + 1;
			}

			m[gems[start]]--; //현재 포함된 start 인덱스에 해당하는 보석 수 감소
			if (m[gems[start]] == 0) m.erase(gems[start]); //0인 경우 아예 제거
			start++; //다시 가장 짧은 구간 구하기 위해 start 증가
		}
		else if (end + 1 >= gems.size()) break;
		else m[gems[++end]]++; //다음 위치의 보석 포함시킨 후, end 증가
	}

	return answer;
}