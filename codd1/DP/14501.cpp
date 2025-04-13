#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> input(N + 1);		// �������
	vector<int> DP(N + 1, 0);		// ���

	int T, P;	// T: ��� �ð�(��), P: ��� ���
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;

		input[i] = make_pair(T, P);
	}

	for (int i = 1; i <= N; i++) {
		if (input[i].first == 1) {		// T == 1
			DP[i] = max(DP[i], DP[i - 1] + input[i].second);	// ��� �ð��� 1���� ���, max(DP[N], ���� �ִ� ��(DP[N-1])�� ������ ��� ���̸� ���� ��)
		}
		else {
			DP[i] = max(DP[i], DP[i - 1]);

			if (i + input[i].first <= N + 1) {		// �޸� �ʰ� ����
				// N + T - 1 = ���� ��¥�� ���� ��� �ð���ŭ ���� ��
				// DP[N + T - 1] = max(DP[N + T - 1], ������ ��� ���� + ���������� ��� ���� �ִ�)
				DP[i + input[i].first - 1] = max(DP[i + input[i].first - 1], input[i].second + DP[i - 1]);
			}
		}
	}

	cout << DP[N];

	return 0;
}