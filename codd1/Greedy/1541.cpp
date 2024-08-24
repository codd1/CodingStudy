#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;

	int num = 0;
	int sum = 0;

	bool is_minus = false;

	for (int i = 0; i < str.size(); i++) {
		while (isdigit(str[i])) {		// ���ڶ�� ��� �ݺ�
			num = num * 10 + (str[i] - '0');
			i++;
		}

		if (is_minus) {		// '-'�� ���� �Ķ�� ��� ���⸸ �ϸ�ȴ�.
			sum -= num;		// ���� ���, 100-40+50+74-30+29-45+43+11��� 100-(40+50+74)-(30+29)-(45+43+11) �̷��� ���� ��길 �ϰ�
							// ���� �� �ֱ� ������ �� �� ���Ⱑ ������ �� ���ķδ� ���⸸ �ϸ� �ȴ�.
		}
		else {		// ���� '-'�� ������ ���̶�� ��� ���Ѵ�.
			sum += num;
		}

		if (str[i] == '-') {
			is_minus = true;
		}

		num = 0;
	}

	cout << sum << endl;

	return 0;
}