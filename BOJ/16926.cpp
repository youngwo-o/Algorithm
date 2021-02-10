#include <bits/stdc++.h>

using namespace std;

int N, M, R, num;
int** arr;

void rotate() {
	int d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //���� ��ġ�� ������ ���� �ε����� ���� ��Ÿ ��

	//(i, i)�� �������� ȸ����Ű��
	for (int i = 0; i < num; ++i) {
		int tmp = arr[i][i];

		int cnt = 0;
		int r = i, c = i;

		while (cnt < 4) { //������ 4�� �ٲ𶧱���
			int nr = r + d[cnt][0];
			int nc = c + d[cnt][1];

			//���� ���̾��� ������ ����� �ʴ� ���
			if (nr >= i && nr < N - i && nc >= i && nc < M - i) {
				arr[r][c] = arr[nr][nc];
				r = nr;
				c = nc;
			}
			//������ ����� ���� �ٲٱ�
			else cnt++;
		}

		arr[i + 1][i] = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;
	arr = new int*[N];
	for (int i = 0; i < N; ++i) {
		arr[i] = new int[M];
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	num = min(N, M) / 2;

	for (int i = 0; i < R; ++i) {
		rotate();
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << arr[i][j] << " ";
		cout << "\n";
	}

	return 0;
}