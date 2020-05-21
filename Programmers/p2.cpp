#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
   if(n == 1)
       answer.push_back(0);
    else {
        vector<int> pre = solution(n - 1);
        for(int i = 0; i < pre.size(); ++i) {
            answer.push_back(pre[i]);
        }
        answer.push_back(0);
        for(int i = pre.size() - 1; i >= 0; --i) {
            answer.push_back(1 - pre[i]);
        }
    }
    
    return answer;
}