#include <vector>
#include <string>
//#include <cmath>
//#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; ++i) {
		int res = arr1[i] | arr2[i];
		string ans = "";
		//int p = pow(2, n - 1);
		for (int j = 0; j < n; ++j) {
			//���� ������ 2���� ���ϱ�
			/*if (res >= p) {
				res -= p;
				answer[i] += '#';
			}
			else
				answer[i] += ' ';

			p /= 2;*/

			if (res % 2 == 0)
				ans += '#';
			else
				ans += ' ';

			//��Ʈ ������ Ȱ��!!
			res = res >> 1;
		}
	}

	return answer;
}