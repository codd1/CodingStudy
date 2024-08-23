#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;		// ���� ����
	int M;		// ��緹�� ����

	cin >> N >> M;

	vector<int> lecture(N);
	vector<int> bluray(M, 0);
	int start = 0;
	int end = 0;
	int median = 0;

	for (int i = 0; i < N; i++) { 
		cin >> lecture[i];

		if (lecture[i] > start) {	// ���� ������ �ִ��� ã�Ƽ� start�� ����
			start = lecture[i];
		}

		end += lecture[i];
	}

	int bluray_index = 0;
	bool isPossible = true;

	while (start <= end) {
		bluray.assign(M, 0);			// ��� 0���� �ʱ�ȭ, ������ �����鵵 �ʱ�ȭ
		bluray_index = 0;				
		isPossible = true;
		median = (start + end) / 2;		// ���� Ž���� ���� �߾Ӱ� ã��
	
		for (int i = 0; i < N; i++) {
			if ((bluray[bluray_index] + lecture[i]) > median) {
				bluray_index++;

				if (bluray_index == M) {		// ��緹�� ������ ���Ǻ��� ������ ���,
					start = median + 1;			// start ���� median +1 ������ �����Ѵ�. (���ǿ� �������� �ʱ� ������)
					isPossible = false;
					break;
				}
			}
			bluray[bluray_index] += lecture[i];
		}

		if (isPossible) {		// ���� �����ϴٸ�,
			end = median - 1;	// end ���� median -1 ������ �����Ѵ�. (�ּ� ���� ã���Ƿ� median �̻��� �� �ʿ� �����ϱ�)
		}
	}

	cout << start << endl;

	return 0;
}