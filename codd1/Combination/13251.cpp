#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long M, K;

	cin >> M;

	vector<long long> N(M);
	double N_sum = 0;		// ��� ���൹�� ���� ����

	for (int i = 0; i < M; i++) {
		cin >> N[i];

		N_sum += N[i];
	}

	cin >> K;

	double sum = 1.0;		// �� ���൹ ������ Ȯ��
	double result = 0.0;

	/*
		3
		5 6 7
		2

		5�� ���൹ �� ���� Ȯ�� = 5/18 * 4/17 = A
		6�� ���൹ �� ���� Ȯ�� = 6/18 * 5/17 = B
		7�� ���൹ �� ���� Ȯ�� = 7/18 * 6/17 = C

		result = A + B + C
	*/

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			sum *= (N[i] - j) / (N_sum - j);
		}
		
		result += sum;

		sum = 1.0;
	}

	cout.precision(16);		// �Ҽ��� 16��° �ڸ����� ���

	cout << result << "\n";

	return 0;
}