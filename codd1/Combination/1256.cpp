#include <iostream>

#define K_MAX 1'000'000'000

using namespace std;

long long D[201][201] = { 0, };		// ������ ����� ��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;	// N: "a" ����, M: "z" ����
	cin >> N >> M;

	for (int i = 0; i <= 200; i++) {
		D[i][i] = 1;
		D[i][1] = i;
		D[i][0] = 1;
	}

	for (int i = 1; i <= 200; i++) {		// N + M
		for (int j = 1; j <= i; j++) {		// ���� ���� ������ ��ü ����(=N+M)�� ���� �� ����
			D[i][j] = D[i - 1][j] + D[i - 1][j - 1];	// ��ȭ��

			if (D[i][j] > K_MAX || D[i][j] < 0) {		// �����÷ο� ������ ���� ó�� (K_MAX�� �������� �־��� ����)
				D[i][j] = K_MAX;
			}
		}
	}

	int K;		// �� ��° ���ڿ��� ǥ���ؾ� �ϴ���?
	cin >> K;

	if (D[N + M][M] < K) {		// ���� �Կ����� ������ ���ϵǾ� �ִ� ���ڿ��� ������ K���� ������ -1�� ����Ѵ�.
		cout << -1;

		return 0;
	}

	long long T;		// ���� �ڸ� ������ a�� �������� �� ���� ���ڷ� ���� �� �ִ� ��� ����� ��

	// T�� K�� ���� ���� ����

	int remainer_z = M;				// ���� z ����
	int remainer_total = N + M;		// ���� �� ���� ����

	remainer_total--;	// ó���� ��¶�� ���� �ϳ��� �����ϹǷ� 1�� ���� ����
	T = D[remainer_total][remainer_z];

	for (int i = 0; i < N + M; i++) {
		/*
			D[A][B] = ���� �� ���� ����(A)���� ���� z ����(B)�� ���� ����� ��

			���� ���ڵ�� ���� �� �ִ� ����� ���� K �̻��̶��,
			���������� �ռ� ���ڿ��鸸���ε� K��° ���ڿ��� ������ �� ����.
		*/
		if (D[remainer_total][remainer_z] >= K) {
			cout << "a";
		}
		else {		// D[remainer_total][remainer_z] < K
			cout << "z";

			remainer_z--;	// z�� �ϳ� Ȯ���������Ƿ� ���� z �� ������ ���δ�.
			K = K - T;		// K �� ������Ʈ
		}

		remainer_total--;	// ���� �ϳ��� Ȯ���������Ƿ� ���� ���� �� ������ ���δ�.
		T = D[remainer_total][remainer_z];		// �ٲ� ������ T �� ������Ʈ
	}

	return 0;
}