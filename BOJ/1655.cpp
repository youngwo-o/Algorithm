#include <cstdio>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> maxHeap; //left
priority_queue<int, vector<int>, greater<int>> minHeap; //right

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int num;
		scanf("%d", &num);

		if (maxHeap.size() == minHeap.size()) {
			if (maxHeap.size() == 0) 
				maxHeap.push(num);
			else {
				if (minHeap.top() < num) {
					int tmp = minHeap.top();
					minHeap.pop();
					minHeap.push(num);
					maxHeap.push(tmp);
				}
				else
					maxHeap.push(num);
			}
		}
		else {
			if (maxHeap.top() > num) {
				int tmp = maxHeap.top();
				maxHeap.pop();
				maxHeap.push(num);
				minHeap.push(tmp);
			}
			else
				minHeap.push(num);
		}

		printf("%d\n", maxHeap.top());
	}
	
	return 0;
}