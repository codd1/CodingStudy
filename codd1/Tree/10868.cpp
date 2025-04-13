#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>	// min()
#include <climits>		// INT_MAX

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int index = 0;
	for (; pow(2, index) < N; index++) {
	}

	int tree_size = pow(2, index) * 2;
	vector<int> tree(tree_size, INT_MAX);

	for (int i = 0, j = tree_size / 2; i < N; i++, j++) {
		cin >> tree[j];
	}

	for (int i = tree_size / 2 - 1; i > 0; i--) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);	// 자식 노드 중 더 최소값으로 업데이트
	}

	int a, b;
	int start, end;
	int min = INT_MAX;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		start = tree_size / 2 - 1 + a;
		end = tree_size / 2 - 1 + b;

		while (start <= end) {
			if (start % 2 == 1) {
				if (tree[start] < min) {
					min = tree[start];
				}
			}

			if (end % 2 == 0) {
				if (tree[end] < min) {
					min = tree[end];
				}
			}

			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}

		cout << min << "\n";

		min = INT_MAX;
	}

	return 0;
}
