#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;		// N: 수의 개수, M: 수의 변경이 일어나는 횟수, K: 구간의 합을 구하는 횟수
	cin >> N >> M >> K;

	int k;		// 트리 배열의 크기를 결정하는 데 필요한 변수
	int i = 1;

	while (1) {
		if (pow(2, i) >= N) {	// 2^k >= N을 만족하는 k의 최솟값 구하기
			k = i;
			break;
		}
		i++;
	}

	int tree_size = pow(2, i) * 2;
	vector<int> tree(tree_size);

	return 0;
}