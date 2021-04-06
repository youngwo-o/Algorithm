#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> ans;
	int maxDay = 0;
	for (int i = 0; i < progresses.size(); ++i) {
		int p = progresses[i];
		int s = speeds[i];

		int day = (100 - p) / s;
		if ((100 - p) % s > 0) ++day;

		if (ans.empty() || maxDay < day) ans.push_back(1);
		else ++ans.back();

		if (maxDay < day) maxDay = day;
	}
	return ans;
}