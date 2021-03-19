#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

vector<int> adj[MAX];
int before[MAX], hold[MAX];
bool visited[MAX];

void dfs(int idx) {
	if (visited[idx]) return; //이미 방문한 곳인 경우 리턴

	if (!visited[before[idx]]) { //현재 노드 이전에 방문해야할 노드를 아직 방문하지 않았다면
		hold[before[idx]] = idx; //현재 노드 저장하고 리턴
		return;
	}

	visited[idx] = true;
	dfs(hold[idx]); //현재 노드 다음에 방문해야할 노드 방문

	for (int next : adj[idx]) dfs(next); //현재 노드와 연결되어 있는 노드 방문
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	for (auto& p : path) {
		adj[p[0]].push_back(p[1]); //양방향 연결
		adj[p[1]].push_back(p[0]);
	}

	for (auto& o : order) before[o[1]] = o[0]; //o[1] 이전에 방문해야할 노드는 o[0] 이다.

	if (before[0]) return false; //시작 노드 이전에 방문해야할 노드가 있다면 return false;

	visited[0] = true;
	for (int next : adj[0]) dfs(next); //시작 노드와 연결되어 있는 노드 방문

}