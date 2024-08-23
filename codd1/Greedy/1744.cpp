#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;		// 수열의 크기
	cin >> N;

	vector<int> sequence(N);	// 수열
	priority_queue<int> pqueue_asc;		// 내림차순 (양수만 저장)
	priority_queue<int, vector<int>, greater<int>> pqueue_desc;		// 오름차순 (음수 ~ 0까지 저장)

	for (int i = 0; i < N; i++) {
		cin >> sequence[i];

		if (sequence[i] > 0) {
			pqueue_asc.push(sequence[i]);
		}
		else {
			pqueue_desc.push(sequence[i]);
		}
	}

	int top = 0;			// 우선순위 큐의 top
	int multiplied_num = 0;	// 곱할 값 (다음 top)
	int sum = 0;

	// 양수만 저장된 우선순위 큐 (1 ~ N)
	while (!pqueue_asc.empty()) {
		top = pqueue_asc.top();
		pqueue_asc.pop();

		if (top > 1 && !pqueue_asc.empty()) {
			multiplied_num = pqueue_asc.top();		// top보다 그 다음으로 높은 값을 가져온다.

			if (multiplied_num == 1) {		// 다음 값이 1일 경우, 곱하는 것보다 각각 더하는 게 더 큰 최댓값이 나오기 때문에 곱하지 X.
				sum += top;
			}
			else {
				sum += top * multiplied_num;	// top과 그 다음으로 높은 값 (1이 아닌)을 곱하면 최댓값이 나오므로 곱한다.
				pqueue_asc.pop();
			}
		}
		else {		// top == 1인 경우, top이 pqueue_asc에서 마지막 값일 경우
			sum += top;
		}
	}

	// 0과 음수만 저장된 우선순위 큐 (-N ~ 0)
	while (!pqueue_desc.empty()) {
		top = pqueue_desc.top();
		pqueue_desc.pop();

		if (top < 0 && !pqueue_desc.empty()) {
			multiplied_num = pqueue_desc.top();
			pqueue_desc.pop();

			sum += top * multiplied_num;		// pqueue_asc와 달리, 다음 값(multiplied_num)이 0이든 음수이든 어쨋든
												// 곱하는게 더 큰 최댓값이 나오므로 곱한다.
		}
		else {		// top == 0일 경우, top이 pqueue_desc에서 마지막 값일 경우
			sum += top;
		}
	}

	cout << sum << endl;

	return 0;
}