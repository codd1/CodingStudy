#include <iostream>
#include <vector>

#define REMAINDER 1'000'000'000

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> D(N + 1);
	D[1] = 0;		// ����� 1���� ���, ����� ���� ������ �ϳ��� ���� �� �ϴ� ��� 1���̴�.
	
	if (N >= 2) {		// D�� ũ�Ⱑ N + 1�̱� ������ �޸� �ʰ��� �����ϱ� ���� ó��
		D[2] = 1;		// ����� 2���� ���, ����� ���� ���� ������ ��ȯ�ϴ� ��� 1���̴�.
	}

	for (int i = 3; i <= N; i++) {
		D[i] = (i - 1) * ((D[i - 1] % REMAINDER) + (D[i - 2] % REMAINDER) % REMAINDER);		// ��ȭ��
	}

	cout << D[N] % REMAINDER;

	return 0;
}