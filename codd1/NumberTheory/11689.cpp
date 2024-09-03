#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long n;		// �ڿ��� n (�Է°�)
	cin >> n;

	long result = n;		// ���μ��� ����

	for (long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {		// i�� ���μ����� Ȯ�� �� �´ٸ�,
			result = result - result / i;	// result �� ������Ʈ (���Ϸ� ��)

			while (n % i == 0) {	// n�� ���� ���μ� �����
				n /= i;
			}
		}
	}

	if (n > 1) {	// ���� ���μ��� �����ִٸ�,
		result = result - result / n;	// ������ ��굵 �ؾ� ��.
	}

	cout << result << endl;

	return 0;
}