#include <iostream>
#include <cctype>		// isupper(), islower()
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int find_func(vector<int>& union_find, int num) {
	if (union_find[num] != num) {
		return find_func(union_find, union_find[num]);
	}
	else {
		return union_find[num];
	}
}

void union_func(vector<int>& union_find, int num1, int num2) {
	num1 = find_func(union_find, num1);
	num2 = find_func(union_find, num2);

	if (num1 != num2) {
		union_find[num2] = num1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> union_find(N + 1);
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	for (int i = 0; i < N; i++) {		// 유니온파인드 초기화
		union_find[i] = i;
	}

	char weight;
	int total_cable = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> weight;

			if (islower(weight)) {		// 소문자일 경우,
				weight = weight - 96;		// a, b, c => 1, 2, 3
			}
			else if (isupper(weight)) {	// 대문자일 경우,
				weight = weight - 38;		// A, B, C => 27, 28, 29
			}
			else {
				weight = weight - '0';	// 숫자일 경우
			}
			
			if (weight > 0) {
				pq.push(make_tuple(weight, i, j));		// weight 기준으로 정렬해야하므로 weight, i, j 순서로 push
				total_cable += weight;		// 찾아야하는 값이 최소한으로 필요한 랜선 길이이므로 총합에서 최소 신장 트리의 결괏값을 빼면 된다.
			}
		}
	}

	tuple<int, int, int> top = pq.top();
	int result = 0;
	int connected_edge = 0;

	while (connected_edge < N - 1 && !pq.empty()) {
		top = pq.top();

		if (find_func(union_find, get<1>(top)) != find_func(union_find, get<2>(top))) {
			union_func(union_find, get<1>(top), get<2>(top));
			result += get<0>(top);

			connected_edge++;
		}

		pq.pop();
	}

	if (connected_edge == N - 1) {
		cout << total_cable - result << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}