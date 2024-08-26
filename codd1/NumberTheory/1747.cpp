#include <iostream>
#include <vector>
#include <string>
#include <cmath>	// pow()

using namespace std;

int main() {
	int N;		// N���� ũ�ų� ����, �Ҽ��̸鼭 �Ӹ������ �� �߿��� ���� ���� �� ���ϱ�

	cin >> N;	// (1 �� N �� 1,000,000)

	vector<int> prime(1004000, 1);	// ������ �ִ��� 1003001�̱� ������ ������ 1004000���� ����.
	prime[0] = 0;
	prime[1] = 0;

	// �Ҽ��� ���� �ϱ�
	int multiple = 2;
	for (int i = 2; i < prime.size(); i++) {
		multiple = 2;
		while (i * multiple < prime.size()) {
			prime[i * multiple] = 0;
			multiple++;
		}
	}

	bool isPalindrome = true;	// �Ҽ��̸鼭 �Ӹ���� ������?
	string num;

	for (int i = 2; i < prime.size(); i++) {
		if (prime[i] == 1) {	// �Ҽ��� �� �߿�
			num = to_string(i);
			isPalindrome = true;

			for (int j = 0; j < num.size() / 2; j++) {		// �Ӹ���� ������ Ȯ��
				if (num[j] == num[num.size() - (j + 1)]) {
					continue;
				}
				prime[i] = 0;
				isPalindrome = false;
				break;
			}

			if (isPalindrome && i >= N) {	// �Ҽ��̸鼭 �Ӹ���� ���̰� N �̻��̶�� ��� �� ����
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}