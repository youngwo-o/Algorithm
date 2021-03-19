#include <bits/stdc++.h>

using namespace std;

int stringToTime(string s) {
	int h = stoi(s.substr(0, 2)) * 60;
	int m = stoi(s.substr(3, 2));
	return h + m;
}

string solution(string m, vector<string> musicinfos) {
	int maxPlayTime = 0;
	string ans = "";
	for (auto& info : musicinfos) {
		vector<string> res;
		stringstream ss(info);
		string token;
		while (getline(ss, token, ',')) { //','�� �����ڷ� string ������
			res.push_back(token);
		}

		int playTime = stringToTime(res[1]) - stringToTime(res[0]); //�ʴ����� �ٲ㼭 ����ð� ����
		string melody = res[3], tmp = res[3];
		int cnt = 0;
		for (int i = 0; i < melody.size(); ++i) {
			if (melody[i] == '#') cnt++;
		}
		int melodyLen = melody.length() - cnt; //���� ���� ��

		string newMelody = "";
		if (playTime <= melodyLen) { //����ð����� ��ε� ���̰� ũ�ų� ���� ���
			cnt = 0;
			for (int i = 0; i < melody.length(); ++i) {
				if (cnt == playTime) break; //���ο� ��ε���̰� ����ð��� ������ ��� ������
				if (i  + 1 != melody.size() && melody[i + 1] == '#') { //#�� ���� ���� ���
					newMelody += melody.substr(i, 2); //�ϳ��� ������ ó��
					i++;
				}
				else newMelody += melody[i];
				cnt++;
			}
		}
		else { //����ð����� ��ε� ���̰� ���� ���
			int idx = 0;
			newMelody = melody; //���� ��ε� ���ٿ�����
			while (melodyLen < playTime) { //���ο� ��ε� ���̰� ����ð��� ������������
				if (idx  + 1 != melody.size() && melody[idx + 1] == '#') { //#�� ���� ���� ���
					newMelody += melody.substr(idx, 2); //�ϳ��� ������ ó��
					idx++;
				}
				else newMelody += melody[idx];
				idx++;
				melodyLen++;
				if (idx >= melody.length()) idx = 0;
			}
		}

		int found = -1;
		while (1) { //���ο� ��ε𿡼� ����� ��ε� ã��
			found = newMelody.find(m, found + 1);
			if (found == string::npos) break; //�� �̻� ����� ��ε�� ���� ���ڿ��� ���� ��� ������
			else {
				if (newMelody[found + m.length()] != '#') { //���� ��ġ (�ڿ� #�� ���� ���� ���)
					if (maxPlayTime < playTime) {
						maxPlayTime = playTime;
						ans = res[2];
					}
				}
			}
		}
	}

	if (ans.empty()) ans = "(None)";

	return ans;
}