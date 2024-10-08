#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void initializeTree(vector<int>& tree, int tree_size, int num1, int num2) {
	if (num1 != 0) {		// �� ó�� �Լ� ȣ���� �� num1 == 0�̱� ����
		tree[tree_size / 2 - 1] = num2;
	}

	// ���� ��: tree[N] = tree[2N] + tree[2N + 1]
	for (int i = tree_size / 2 - 1; i >= 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;		// N: ���� ����, M: ���� ������ �Ͼ�� Ƚ��, K: ������ ���� ���ϴ� Ƚ��
	cin >> N >> M >> K;

	int k;		// Ʈ�� �迭�� ũ�⸦ �����ϴ� �� �ʿ��� ����
	int i = 1;

	while (1) {
		if (pow(2, i) >= N) {	// 2^k >= N�� �����ϴ� k�� �ּڰ� ���ϱ�
			k = i;
			break;
		}
		i++;
	}

	int tree_size = pow(2, i) * 2;
	vector<int> tree(tree_size, 0);

	i = tree_size / 2;
	for (int j = 0; j < N; j++, i++) {
		cin >> tree[i];
	}

	initializeTree(tree, tree_size, 0, 0);

	int type1_count = 0;		// M���� �Ǹ� ����
	int type2_count = 0;		// K���� �Ǹ� ����
	
	int type;	// 1 �Ǵ� 2
	int num1, num2;
	int start, end;
	vector<int> result;
	int sum = 0;

	while (type1_count < M || type2_count < K) {
		cin >> type >> num1 >> num2;

		if (type == 1) {
			initializeTree(tree, tree_size, num1, num2);
			type1_count++;
		}
		else if (type == 2) {
			start = num1 + (tree_size / 2 - 1);
			end = num2 + (tree_size / 2 - 1);

			while (start <= end) {
				if (start % 2 == 1) {
					result.push_back(start);
				}

				if (end % 2 == 0) {
					result.push_back(end);
				}

				start = (start + 1) / 2;
				end = (end - 1) / 2;
			}

			for (int i = 0; i < result.size(); i++) {
				sum += tree[result[i]];
			}

			cout << sum << "\n";
			type2_count++;

			sum = 0;
			fill(result.begin(), result.end(), 0);
		}
	}

	return 0;
}