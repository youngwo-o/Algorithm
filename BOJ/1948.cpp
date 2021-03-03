#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 10001

using namespace std;

int n, m, sCity, eCity;
vector<pii> info[MAX], info_rev[MAX];
int entry[MAX];

void solution() {
	int ans = 0;

	queue<pii> q;
	vector<int> dist(MAX, -1);

	q.push({ sCity, 0 });
	dist[sCity] = 0;

	//��� ���ÿ� ���� �ִ� �Ÿ� ���ϱ�
	while (!q.empty()) {
		int curCity = q.front().first;
		int curDist = q.front().second;
		q.pop();

		for (auto next : info[curCity]) {
			int nextCity = next.first;
			int nextDist = curDist + next.second;
			
			dist[nextCity] = max(dist[nextCity], nextDist); //�ִ�Ÿ� ���ϱ�
			entry[nextCity]--; //�켱������ ���ľ��� ���� 1 ����

			if (entry[nextCity] == 0) //�켱������ ���ľ��� ��� ���ø� �湮�� ���
				q.push({ dist[nextCity], nextCity }); //���� ���÷� �̵��� �� ����
		}
	}

	set<pii> ansRoad;
	queue<pii> q2;
	vector<int> visited(MAX, 0);

	//���� ���ÿ������� ��Ʈ��ŷ
	q2.push({ eCity, 0 });
	visited[eCity] = 1;

	while (!q2.empty()) {
		int curCity = q2.front().first;
		int curDist = q2.front().second;
		q2.pop();

		for (auto next : info_rev[curCity]) {
			int nextCity = next.first;
			int nextDist = curDist + next.second;

			//���絵�ÿ��� ���� ���ñ����� �Ÿ� + ���� ���ÿ��� ���� ���ñ����� �Ÿ� = ���� ���ñ����� �ִ� �Ÿ�
			//�ִ�Ÿ��� �� �� �ִ� ����� ���
			if (nextDist + dist[nextCity] == dist[eCity]) {
				ansRoad.insert({ curCity, nextCity }); //��� ���� ����
				if (!visited[nextCity]) { //�湮���� �ʾ��� ��츸
					visited[nextCity] = 1;
					q2.push({ nextDist, nextCity });
				}
			}
		}
	}

	cout << dist[eCity] << "\n" << ansRoad.size() << "\n";
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int s, e, t;
		cin >> s >> e >> t;
		info[s].push_back({ e, t });
		info_rev[e].push_back({ s, t });
		entry[e]++; //�������� (��� ���δ� �Ϲ�����, e�� ���ø� ������ �켱������ ���İ����ϴ� ������ ����)
	}
	cin >> sCity >> eCity;

	solution();

	return 0;
}