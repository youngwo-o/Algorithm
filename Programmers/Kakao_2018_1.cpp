#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	vector<string> lru;

	for (auto city : cities) {
		//�ҹ��ڷ� ����
		transform(city.begin(), city.end(), city.begin(), ::tolower);

		auto it = find(lru.begin(), lru.end(), city);

		//ĳ�� ��Ʈ
		if (it != lru.end()) {
			answer += 1;
			lru.erase(it);
		}
		//ĳ�� �̽�
		else {
			answer += 5;
			
			if (cacheSize == lru.size() && cacheSize != 0) {
				//�ֱٿ� ���� ������ ���� ĳ�� �����
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