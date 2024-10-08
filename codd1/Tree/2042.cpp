#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void initializeTree(vector<long long>& tree, long long tree_size, long long num1, long long num2) {
	long long index = (tree_size / 2 - 1) + num1;
	long long diff = num2 - tree[index];

	// ���� ��: tree[N] = tree[2N] + tree[2N + 1]
	while (index > 0) {
		tree[index] += diff;
		index /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M, K;		// N: ���� ����, M: ���� ������ �Ͼ�� Ƚ��, K: ������ ���� ���ϴ� Ƚ��
	cin >> N >> M >> K;

	long long i = 1;	// Ʈ�� �迭�� ũ�⸦ �����ϴ� �� �ʿ��� ����

	while (pow(2, i) < N) {
		i++;
	}

	long long tree_size = pow(2, i) * 2;
	vector<long long> tree(tree_size);

	for (long long i = tree_size / 2, j = 0; j < N; i++, j++) {
		cin >> tree[i];
	}

	// Ʈ�� �ʱ�ȭ
	for (int i = tree_size / 2 - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	
	int type;	// 1 �Ǵ� 2
	long long num1, num2;
	long long start, end;
	long long sum = 0;

	for (int i = 0; i < M + K; i++) {
		cin >> type >> num1 >> num2;

		if (type == 1) {		// num1�� num2�� ����
			initializeTree(tree, tree_size, num1, num2);
		}
		else if (type == 2) {	// num1 ~ num2 ������ �� ���
			start = num1 + (tree_size / 2 - 1);
			end = num2 + (tree_size / 2 - 1);

			while (start <= end) {
				if (start % 2 == 1) {
					sum += tree[start];
				}

				if (end % 2 == 0) {
					sum += tree[end];
				}

				start = (start + 1) / 2;
				end = (end - 1) / 2;
			}

			cout << sum << "\n";

			sum = 0;
		}
	}

	return 0;
}