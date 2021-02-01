#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	vector<string> lru;

	for (auto city : cities) {
		//소문자로 통일
		transform(city.begin(), city.end(), city.begin(), ::tolower);

		auto it = find(lru.begin(), lru.end(), city);

		//캐시 히트
		if (it != lru.end()) {
			answer += 1;
			lru.erase(it);
		}
		//캐시 미스
		else {
			answer += 5;
			
			if (cacheSize == lru.size() && cacheSize != 0) {
				//최근에 가장 사용되지 않은 캐시 지우기
				lru.erase(lru.end());
			}
		}

		if (cacheSize != 0)
			lru.insert(lru.begin(), city);
	}

	return answer;
}

int main() {
	//cout << solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" });

	return 0;
}