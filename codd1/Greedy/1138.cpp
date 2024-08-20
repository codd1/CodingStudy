#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;

	cin >> N;

	vector<int> order(N+1);
	vector<int> v(N+1);

	for (int i = 1; i <= N; i++) {
		cin >> order[i];
	}

	for (int i = N; i > 0; i--) {
		v.insert(v.begin() + order[i], i);
	}

	for (int i = 0; i < N; i++) {
		if (v[i] != 0) {
			cout << v[i] << " ";
		}
	}

	return 0;
}