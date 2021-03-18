#include <bits/stdc++.h>

using namespace std;

vector<int> startTime, endTime;

void stringToTime(string line) { //string�� ms�� ��ȯ
	string h, m, s, ms;
	int ih, im, is, proc;

	line.pop_back();
	h = line.substr(11, 2);
	m = line.substr(14, 2);
	s = line.substr(17, 2);
	ms = line.substr(20, 3);
	proc = stof(line.substr(24, 5)) * 1000;

	ih = stoi(h) * 60 * 60 * 1000;
	im = stoi(m) * 60 * 1000;
	is = stoi(s) * 1000 + stoi(ms);

	startTime.push_back(ih + im + is - proc + 1);
	endTime.push_back(ih + im + is);
}

int solution(vector<string> lines) {
	int answer = 0;

	for (auto line : lines) {
		stringToTime(line);
	}

	//lines�� ����Ϸ� �ð��� �������� �������� ���ĵǾ�����
	//--> ���� �Ϸ� �ð� + 1000 ������ ������ ��û�� ��� 1�ʰ� ó���ϴ� ��û�� ����
	for (int i = 0; i < lines.size(); ++i) {
		int end = endTime[i] + 1000;
		int cnt = 0;

		for (int j = i; j < lines.size(); ++j) {
			if (startTime[j] < end) cnt++;
		}

		answer = max(answer, cnt);
	}

	return answer;
}