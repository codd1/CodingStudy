#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_func(vector<int>& nodes, int num) {
	if (num != nodes[num]) {
		return find_func(nodes, nodes[num]);
	}
	else {
		return num;
	}
}

void union_func(vector<int>& nodes, int a, int b) {
	a = find_func(nodes, a);
	b = find_func(nodes, b);

	if (a != b) {
		nodes[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;		// N: 사람 수, M: 파티 수
	cin >> N >> M;

	vector<int> nodes(N + 1);	// 1 ~ N

	for (int i = 1; i <= N; i++) {
		nodes[i] = i;
	}

	int known_truth_num;	// 진실을 아는 사람 수
	cin >> known_truth_num;

	if (known_truth_num == 0) {		// 진실을 아는 사람이 없다면,
		cout << M << "\n";			// 모든 파티에서 거짓말을 해도되기 때문에 파티 수를 출력하고 종료

		return 0;
	}

	vector<int> known_truth(known_truth_num);

	for (int i = 0; i < known_truth_num; i++) {
		cin >> known_truth[i];
	}

	vector<vector<int>> party(M);	// 파티 정보
	int first;				// 파티에 참가하는 첫 번째 사람
	int party_people_num;	// 파티에 참여하는 사람 수

	for (int i = 0; i < M; i++) {
		cin >> party_people_num;

		party[i].resize(party_people_num, 0);

		if (party_people_num == 1) {	// 파티에 참여하는 사람이 1명일 경우, union 불필요
			cin >> party[i][0];			// party에 값은 저장해야 함.
			continue;
		}

		for (int j = 0; j < party_people_num; j++) {
			cin >> party[i][j];

			if (j == 0) {
				first = party[i][j];

				continue;	// 파티에 참여하는 인원이 1명일 경우, union 불필요
			}

			union_func(nodes, first, party[i][j]);	// 한 파티에 참여하는 인원이 2명 이상일 경우 union 연산 수행
		}
	}

	int count = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < known_truth.size(); j++) {
			if (find_func(nodes, party[i][0]) == find_func(nodes, known_truth[j])) {
				count++;		// 거짓말을 못 치는 경우를 구한 후 마지막에 파티 수에서 뺀다.

				break;
			}
		}
	}

	cout << M - count << "\n";

	return 0;
}