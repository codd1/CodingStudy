#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;		// 카드 묶음 수
	cin >> N;

	vector<int> card(N);		// 카드 묶음 각각의 크기
	priority_queue<int, vector<int>, greater<int>> pqueue;		// 오름차순(=top에 작은 숫자)
	vector<int> result(N, 0);	// result의 모든 값을 더하면 답이 된다.

	for (int i = 0; i < N; i++) {
		cin >> card[i];
		pqueue.push(card[i]);
	}

	int A = 0;		// 더할 카드1
	int B = 0;		// 더할 카드2
	int sum = 0;	// 이번에 더한 값
	int i = 0;		// result 인덱스

	while (pqueue.size() > 1) {
		A = pqueue.top();
		pqueue.pop();

		B = pqueue.top();
		pqueue.pop();
		
		sum = A + B;

		pqueue.push(sum);		// A+B 값 그대로 다음 top과 더하는게 아니라,
								// A+B 값도 다시 정렬해서 더하게끔 한다.
		result[i++] = sum;
	}

	int total_sum = 0;
	for (int i = 0; i < N; i++) {
		total_sum += result[i];
	}

	cout << total_sum << endl;

	return 0;
}