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
	D[1] = 1;		// ����� 1���� ���, ����� ���� ������ �ϳ��� ���� �� �ϴ� ��� 1���̴�.
	D[2] = 1;		// ����� 2���� ���, ����� ���� ���� ������ ��ȯ�ϴ� ��� 1���̴�.
	D[3] = 2;		// ����� 3���� ���, ����� ���� B A C / C A B 2���̴�.

	for (int i = 4; i <= N; i++) {
		D[i] = (i - 1) * ((D[i - 1] % REMAINDER) + (D[i - 2] % REMAINDER) % REMAINDER);		// ��ȭ��
	}

	cout << D[N] % REMAINDER;

	return 0;
}