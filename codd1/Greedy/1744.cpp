#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;		// ������ ũ��
	cin >> N;

	vector<int> sequence(N);	// ����
	priority_queue<int> pqueue_asc;		// �������� (����� ����)
	priority_queue<int, vector<int>, greater<int>> pqueue_desc;		// �������� (���� ~ 0���� ����)

	for (int i = 0; i < N; i++) {
		cin >> sequence[i];

		if (sequence[i] > 0) {
			pqueue_asc.push(sequence[i]);
		}
		else {
			pqueue_desc.push(sequence[i]);
		}
	}

	int top = 0;			// �켱���� ť�� top
	int multiplied_num = 0;	// ���� �� (���� top)
	int sum = 0;

	// ����� ����� �켱���� ť (1 ~ N)
	while (!pqueue_asc.empty()) {
		top = pqueue_asc.top();
		pqueue_asc.pop();

		if (top > 1 && !pqueue_asc.empty()) {
			multiplied_num = pqueue_asc.top();		// top���� �� �������� ���� ���� �����´�.

			if (multiplied_num == 1) {		// ���� ���� 1�� ���, ���ϴ� �ͺ��� ���� ���ϴ� �� �� ū �ִ��� ������ ������ ������ X.
				sum += top;
			}
			else {
				sum += top * multiplied_num;	// top�� �� �������� ���� �� (1�� �ƴ�)�� ���ϸ� �ִ��� �����Ƿ� ���Ѵ�.
				pqueue_asc.pop();
			}
		}
		else {		// top == 1�� ���, top�� pqueue_asc���� ������ ���� ���
			sum += top;
		}
	}

	// 0�� ������ ����� �켱���� ť (-N ~ 0)
	while (!pqueue_desc.empty()) {
		top = pqueue_desc.top();
		pqueue_desc.pop();

		if (top < 0 && !pqueue_desc.empty()) {
			multiplied_num = pqueue_desc.top();
			pqueue_desc.pop();

			sum += top * multiplied_num;		// pqueue_asc�� �޸�, ���� ��(multiplied_num)�� 0�̵� �����̵� ��¶��
												// ���ϴ°� �� ū �ִ��� �����Ƿ� ���Ѵ�.
		}
		else {		// top == 0�� ���, top�� pqueue_desc���� ������ ���� ���
			sum += top;
		}
	}

	cout << sum << endl;

	return 0;
}