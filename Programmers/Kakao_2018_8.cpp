#include <bits/stdc++.h>

using namespace std;

int solution(string dartResult) {
	int ans[3] = { 0, 0, 0 };

	int cnt = 0;
	for (int i = 0, len = dartResult.length(); i < len; ++i) {
		char c1 = dartResult[i];
		char c2 = dartResult[i + 1];

		if (isdigit(c1)) {
			int num = c1 - '0';

			if (isdigit(c2)) {
				num = 10;
				i++;
			}

			char bonus = dartResult[i + 1];
			char option = dartResult[i + 2];
			
			if (bonus == 'S')
				ans[cnt] = pow(num, 1);
			else if (bonus == 'D')
				ans[cnt] = pow(num, 2);
			else if (bonus == 'T')
				ans[cnt] = pow(num, 3);

			if (ispunct(option)) {
				if (option == '*') {
					if (cnt != 0)
						ans[cnt - 1] *= 2;
					ans[cnt] *= 2;
				}
				else if (option == '#') 
					ans[cnt] *= -1;

				i++;
			}

			i++;
			cnt++;
		}
	}

	return ans[0] + ans[1] + ans[2];
}