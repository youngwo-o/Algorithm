#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, d, k, c;
int s[30000];

//two pointer, sliding window
int solution() {
	map<int,int> select;

	int cnt = 0, result = 0;
	int low = 0, high = 0;
	while (low < n) {
		//to continue
		if (high == n)
			high = 0;

		//select k sushi
		if (cnt == k) {
			if (result <= select.size()) {
				result = select.size();

				//if c is not selected, add 1 to result
				if (select.count(c) == 0)
					result++;
			}

			if (select[s[low]] == 1)
				select.erase(select.find(s[low++]));
			else
				select[s[low++]]--; 

			cnt--;
		}
		else {
			if (select.count(s[high]) == 0)
				select.insert(make_pair(s[high], 1));
			else
				select[s[high]]++;

			high++;
			cnt++;
		}
	}

	return result;
}

int main() {
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	cout << solution();

	return 0;
}