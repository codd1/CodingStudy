#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
	vector<int> tree(tree_size);

	return 0;
}