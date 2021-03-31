#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int N;
int A[MAX];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	
	for (int i = 0; i < N; ++i) {
		if (v.empty()) v.push_back(A[i]);
		else {
			if (v.back() < A[i]) v.push_back(A[i]);
			else *lower_bound(v.begin(), v.end(), A[i]) = A[i];
			//lower_bound() => O(logN) (ÀÌºÐÅ½»ö)
		}
	}

	cout << v.size();
}