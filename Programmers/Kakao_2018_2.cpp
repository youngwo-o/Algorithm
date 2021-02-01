#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n, "");

	for (int i = 0; i < n; ++i) {
		int res = arr1[i] | arr2[i];

		int p = pow(2, n - 1);
		for(int j = 0; j < n; ++j) {
			if (res >= p) {
				res -= p;
				answer[i] += '#';
			}
			else
				answer[i] += ' ';

			p /= 2;
		}
	}

	return answer;
}

int main() {
	
	return 0;
}