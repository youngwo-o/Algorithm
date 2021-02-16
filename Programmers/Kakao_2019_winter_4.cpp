#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> room;

long long find(long long n) {
	if (!room[n])
		return n;

	return room[n] = find(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (auto n : room_number) {
		int res = find(n);
		answer.push_back(res);
		room[res] = res + 1; //해당 key(방)의 value 값을 참조 할 수 있도록
	}
	
	return answer;
}