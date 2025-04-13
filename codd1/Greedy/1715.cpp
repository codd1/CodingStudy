#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;		// ī�� ���� ��
	cin >> N;

	vector<int> card(N);		// ī�� ���� ������ ũ��
	priority_queue<int, vector<int>, greater<int>> pqueue;		// ��������(=top�� ���� ����)
	vector<int> result(N, 0);	// result�� ��� ���� ���ϸ� ���� �ȴ�.

	for (int i = 0; i < N; i++) {
		cin >> card[i];
		pqueue.push(card[i]);
	}

	int A = 0;		// ���� ī��1
	int B = 0;		// ���� ī��2
	int sum = 0;	// �̹��� ���� ��
	int i = 0;		// result �ε���

	while (pqueue.size() > 1) {
		A = pqueue.top();
		pqueue.pop();

		B = pqueue.top();
		pqueue.pop();
		
		sum = A + B;

		pqueue.push(sum);		// A+B �� �״�� ���� top�� ���ϴ°� �ƴ϶�,
								// A+B ���� �ٽ� �����ؼ� ���ϰԲ� �Ѵ�.
		result[i++] = sum;
	}

	int total_sum = 0;
	for (int i = 0; i < N; i++) {
		total_sum += result[i];
	}

	cout << total_sum << endl;

	return 0;
}