#include <bits/stdc++.h>

using namespace std;

int x, n;
int lego[1000000];

void solution() {
	int left = 0, right = n - 1, len = 0;
	while (left < right) {
		len = lego[left] + lego[right];

		if (len == x) break;
		else if (len > x)  right--;
		else if (len < x) left++;
	}

	//�̺�Ž��
	/*int left, right;
	//������ ũ�Ⱑ x�� ���ݺ��� ���� ��������
	for (int i = 0; i < n && lego[i] <= x / 2; ++i) {
		//���� ���� ������ ũ�� = lego[i]
		//�̺�Ž������ ������ ū ���� ������ ũ�� ã��
		left = i + 1, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			int len = lego[i] + lego[mid];

			if (len == x) {
				left = i, right = mid;
				i = n; //for�� ���������� ����
				break;
			}
			else if (len > x) right = mid - 1;
			else left = mid + 1;
		}
	}*/

	if (left >= right)
		cout << "danger\n";
	else
		cout << "yes " << lego[left] << " " << lego[right] << "\n";
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie();
	cout.tie();

	while (cin >> x >> n) {
		x *= 10000000;

		for (int i = 0; i < n; ++i) {
			cin >> lego[i];
		}
		sort(lego, lego + n);

		solution();
	}

	return 0;
}