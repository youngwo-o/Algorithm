#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
	Trie* next[26];
	int cnt[26]{};

public:
	Trie() {
		for (int i = 0; i < 26; ++i)
			next[i] = NULL;
	}

	void insert(const char* key) {
		if (*key == '\0') return;

		int curr = *key - 'a';
		cnt[curr]++;

		if (next[curr] == NULL)
			next[curr] = new Trie();

		next[curr]->insert(key + 1);
	}

	int find(const char* key, int res) {
		if (*key == '\0') return res - 1;

		int curr = *key - 'a';
		if (cnt[curr] == 1)
			return res;

		return next[curr]->find(key + 1, res + 1);
	}
};

int solution(vector<string> words) {
	int answer = 0;
	Trie t;

	for (auto word : words)
		t.insert(word.c_str());
	for (auto word : words)
		answer += t.find(word.c_str(), 1);

	return answer;
}

int main() {
	solution({ "go", "gone", "guild" });

	return 0;
}