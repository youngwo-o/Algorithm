#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Trie {
	bool term; //단어의 끝임을 표시
	int count; //개수 저장
	Trie* next[26];

	Trie(): term(false), count(1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; ++i) {
			if (next[i])
				delete next[i];
		}
	}

	//새로운 문자열 추가
	void insert(const char* key) {
		if (*key == '\0')
			term = true;
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			else
				next[curr]->count++;

			next[curr]->insert(key + 1);
		}
	}

	//문자열을 접두어로 갖고 있는지 확인
	int find(const char* key) {
		if (*key == '?') {
			int tmp = 0;
			for (int i = 0; i < 26; ++i) {
				if (next[i] != NULL)
					tmp += next[i]->count;
			}
			return tmp;
		}

		int curr = *key - 'a';
		if (next[curr] == NULL)
			return 0;
		if (*(key + 1) == '?')
			return next[curr]->count;
		
		return next[curr]->find(key + 1);
	}
};

Trie* root[10001];
Trie* reRoot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
	//words로 Trie 트리 생성
	for (int i = 0; i < words.size(); ++i) {
		string s = words[i];

		const char* c = s.c_str();
		if (root[s.size()] == NULL)
			root[s.size()] = new Trie();
		root[s.size()]->insert(c);

		string reS = s;
		reverse(reS.begin(), reS.end());
		
		const char* reC = reS.c_str();
		if (reRoot[reS.size()] == NULL)
			reRoot[reS.size()] = new Trie();
		reRoot[reS.size()]->insert(reC);
	}

	vector<int> answer;

	for (int i = 0; i < queries.size(); ++i) {
		string q = queries[i];

		//접미사가 ?인 경우
		if (q[q.size() - 1] == '?') {
			const char*c = q.c_str();
			//글자수에 해당하는 word가 없는 경우
			if (root[q.size()] == NULL)
				answer.push_back(0);
			//글자수에 해당하는 word가 있는 경우
			else
				//글자수에 맞는 word 중에서 해당 문자열 찾기
				answer.push_back(root[q.size()]->find(c));
		}
		//접두사가 ?인 경우 -> 거꾸로 저장한 Tire 자료구조에서 찾기
		else {
			string reQ = q;
			reverse(reQ.begin(), reQ.end());

			const char* reC = reQ.c_str();
			if (reRoot[reQ.size()] == NULL)
				answer.push_back(0);
			else
				answer.push_back(reRoot[reQ.size()]->find(reC));
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

	vector<int> ans = solution(words, queries);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}

	return 0;
}