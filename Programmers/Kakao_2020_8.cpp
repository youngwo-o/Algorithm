#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

vector<int> adj[MAX];
int before[MAX], hold[MAX];
bool visited[MAX];

void dfs(int idx) {
	if (visited[idx]) return; //�̹� �湮�� ���� ��� ����

	if (!visited[before[idx]]) { //���� ��� ������ �湮�ؾ��� ��带 ���� �湮���� �ʾҴٸ�
		hold[before[idx]] = idx; //���� ��� �����ϰ� ����
		return;
	}

	visited[idx] = true;
	dfs(hold[idx]); //���� ��� ������ �湮�ؾ��� ��� �湮

	for (int next : adj[idx]) dfs(next); //���� ���� ����Ǿ� �ִ� ��� �湮
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	for (auto& p : path) {
		adj[p[0]].push_back(p[1]); //����� ����
		adj[p[1]].push_back(p[0]);
	}

	for (auto& o : order) before[o[1]] = o[0]; //o[1] ������ �湮�ؾ��� ���� o[0] �̴�.

	if (before[0]) return false; //���� ��� ������ �湮�ؾ��� ��尡 �ִٸ� return false;

	visited[0] = true;
	for (int next : adj[0]) dfs(next); //���� ���� ����Ǿ� �ִ� ��� �湮

}