#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringToTime(string s) {
	int res = 0;

	int h1 = (s[0] - '0') * 10;
	int h2 = s[1] - '0';
	res += (h1 + h2) * 60;

	int m1 = (s[3] - '0') * 10;
	int m2 = s[4] - '0';
	res += (m1 + m2);

	return res;
}

string timeToString(int t) {
	string res = "";

	int h = t / 60;
	int m = t % 60;

	res += ((h / 10) + '0');
	res += ((h % 10) + '0');
	res += ':';
	res += ((m / 10) + '0');
	res += ((m % 10) + '0');

	return res;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	vector<int> time;
	for (auto s : timetable) {
		//���ڿ��� ������ ����
		//ex. "09:00" -> 540��
		int minute = stringToTime(s);

		time.push_back(minute);
	}
	//�ð��� ������������ ����
	sort(time.begin(), time.end());

	int startTime = stringToTime("09:00");
	int endTime = startTime + ((n - 1) * t);

	int check, lastTime;
	//��Ʋ ���� �ð����� Ż �� �ִ� ����� �� Ž��
	for (int i = startTime; i <= endTime; i += t) {
		//upper_bound val�� ó�� �ʰ��ϴ� �ε��� ����
		//���� ��Ʋ ���� �ð��� Ż �� �ִ� ����� ��
		int waitNum = upper_bound(time.begin(), time.end(), i) - time.begin();

		//���� Ż ����� ���� �� ��Ʋ�� Ż �� �ִ� �ִ� ũ�� ������ ���� ���
		//�ڸ��� ���� ���
		if (waitNum < m) {
			check = 1;
			lastTime = i; //���� ������ ��Ʋ �ð� ����
			time.erase(time.begin(), time.begin() + waitNum);
		}
		//���� Ż ����� ���� �� ��Ʋ�� Ż �� �ִ� �ִ� ũ�� ���� ���ų� �� ū ���
		//�ڸ��� ���� �ʴ� ���
		else {
			check = 2;
			lastTime = time[m - 1]; //��Ʋ�� ź ������ ����� �ð� ����
			time.erase(time.begin(), time.begin() + m);
		}
	}

	int res;
	//�ڸ��� ���� ��� -> ���� ������ ��Ʋ �ð�
	if (check == 1)
		res = lastTime;
	//�ڸ��� ���� �ʴ� ��� -> ��Ʋ�� ź ������ ����� �ð����� 1�� ���� �ð�
	else if (check == 2)
		res = lastTime - 1;

	answer = timeToString(res);

	return answer;
}