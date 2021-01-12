#include <iostream>

using namespace std;

int main() {
	long long s;
	cin >> s;

	long long sum = 0;
	int n = 1;
	while (1) {
		sum += n;
		n++;

		if (sum > s) {
			n -= 2;
			break;
		}
	}

	cout << n << "\n";

	return 0;
}