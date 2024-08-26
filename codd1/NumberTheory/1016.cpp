#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long min, max;

	cin >> min >> max;

	vector<int> num(1000001, 0);
	int count = 0;					// ������������ �ƴ� ���� ã�´�. (= �������� ������ �������� ��)

	long long multiple = 2;

	for (long long i = 2; i * i <= max; i++) {
		long long pow = i * i;
		long long start = min / pow;

		if (min % pow != 0) {
			start++;
		}

		for (long long j = start; pow * j <= max; j++) {
			num[(j * pow) - min] = 1;
		}
	}

	for (int i = 0; i <= max - min; i++) {
		if (!num[i]) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}