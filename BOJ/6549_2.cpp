#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int num[100001];
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}

		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			while (!s.empty() && num[i] < num[s.top()]) {
				long long h = num[s.top()];
				s.pop();

				long long w = i;
				if (!s.empty())
					w = i - s.top() - 1;
	
				ans = max(ans, h * w);
			}

			s.push(i);
		}


		while (!s.empty()) {
			long long h = num[s.top()];
			s.pop();

			long long w = n;

			if (!s.empty())
				w = n - s.top() - 1;

			ans = max(ans, h * w);
		}

		cout << ans << "\n";
	}

	return 0;
}