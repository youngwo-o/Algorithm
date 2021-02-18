#include <bits/stdc++.h>
#define change(idx) light[idx] = (light[idx] == '0' ? '1' : '0');

using namespace std;

int N;
string light, res;

int solution(int push0) {
	int ans = 0;

	if (push0) {
		change(0);
		change(1);
		ans++;
	}

	//i - 1�� ����ġ�� i�� ����ġ�� on/off�� ���� ������
	for (int i = 1; i <= N; ++i) {
		//���� i - 1�� ����ġ�� ������� i - 1�� ����ġ�� �ٸ� ���
		if (light[i - 1] != res[i - 1]) {
			if (i == N) //i�� N�� ��� ����ġ ���¸� �ٲ� �� ���� ������ -1 ����
				return -1;

			ans++;
			if (i - 1 >= 0) change(i - 1);
			change(i);
			if(i  + 1 < N) change(i + 1);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> light >> res;

	int ans = INT_MAX;
	string tmp = light;
	int res1 = solution(0); //0�� ����ġ�� ���� ���� ���
	light = tmp;
	int res2 = solution(1); //0�� ����ġ�� Ű�� ���
	if (res1 == -1 && res2 == -1)
		ans = -1;
	else if(res1 != -1) ans = min(ans, res1);
	else if (res2 != -1) ans = min(ans, res2);

	cout << ans;

	return 0;
}