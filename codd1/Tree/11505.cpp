#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MOD 1'000'000'007		// �������� �־��� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M, K;
	cin >> N >> M >> K;

	long long i = 0;
	for (; pow(2, i) < N; i++) {
	}

	long long tree_size = pow(2, i) * 2;
	vector<long long> tree(tree_size, 1);
	vector<long long> choose;

	for (long long i = tree_size / 2, j = 0; j < N; i++, j++) {
		cin >> tree[i];
	}

	for (long long i = tree_size / 2 - 1; i > 0; i--) {
		//tree[i] = tree[i*2] * tree[i*2+1];

		// (A * B) % C = (A % C) * (B % C) % C;
		tree[i] = (tree[i * 2] % MOD) * (tree[i * 2 + 1] % MOD) % MOD;
	}

	long long type, num1, num2;
	long long start, end;
	long long result = 1;

	for (long long i = 0; i < M + K; i++) {
		cin >> type >> num1 >> num2;

		start = tree_size / 2 - 1 + num1;
		end = tree_size / 2 - 1 + num2;

		if (type == 1) {	// num1�� num2�� �ٲ۴�
			tree[start] = num2;

			for (long long i = start / 2; i > 0; i /= 2) {	// �ٲ� ���� ���� Ʈ�� ������Ʈ
				tree[i] = (tree[i * 2] % MOD) * (tree[i * 2 + 1] % MOD) % MOD;
			}

		}
		else if (type == 2) {	// num1���� num2������ ���� ���Ѵ�
			while (start <= end) {
				if (start % 2 == 1) {
					choose.push_back(tree[start] % MOD);	// ����
				}

				if (end % 2 == 0) {
					choose.push_back(tree[end] % MOD);		// ����
				}

				start = (start + 1) / 2;
				end = (end - 1) / 2;
			}

			for (long long i = 0; i < choose.size(); i++) {
				result = result * choose[i] % MOD;			// ���� ���� ���� MOD ���� �ʿ� (�����÷ο� ����)
			}

			cout << result % MOD << "\n";

			result = 1;
			choose.resize(0);
		}
	}

	return 0;
}
