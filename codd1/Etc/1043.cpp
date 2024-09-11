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

	int N, M;		// N: ��� ��, M: ��Ƽ ��
	cin >> N >> M;

	vector<int> nodes(N + 1);	// 1 ~ N

	for (int i = 1; i <= N; i++) {
		nodes[i] = i;
	}

	int known_truth_num;	// ������ �ƴ� ��� ��
	cin >> known_truth_num;

	if (known_truth_num == 0) {		// ������ �ƴ� ����� ���ٸ�,
		cout << M << "\n";			// ��� ��Ƽ���� �������� �ص��Ǳ� ������ ��Ƽ ���� ����ϰ� ����

		return 0;
	}

	vector<int> known_truth(known_truth_num);

	for (int i = 0; i < known_truth_num; i++) {
		cin >> known_truth[i];
	}

	vector<vector<int>> party(M);	// ��Ƽ ����
	int first;				// ��Ƽ�� �����ϴ� ù ��° ���
	int party_people_num;	// ��Ƽ�� �����ϴ� ��� ��

	for (int i = 0; i < M; i++) {
		cin >> party_people_num;

		party[i].resize(party_people_num, 0);

		if (party_people_num == 1) {	// ��Ƽ�� �����ϴ� ����� 1���� ���, union ���ʿ�
			cin >> party[i][0];			// party�� ���� �����ؾ� ��.
			continue;
		}

		for (int j = 0; j < party_people_num; j++) {
			cin >> party[i][j];

			if (j == 0) {
				first = party[i][j];

				continue;	// ��Ƽ�� �����ϴ� �ο��� 1���� ���, union ���ʿ�
			}

			union_func(nodes, first, party[i][j]);	// �� ��Ƽ�� �����ϴ� �ο��� 2�� �̻��� ��� union ���� ����
		}
	}

	int count = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < known_truth.size(); j++) {
			if (find_func(nodes, party[i][0]) == find_func(nodes, known_truth[j])) {
				count++;		// �������� �� ġ�� ��츦 ���� �� �������� ��Ƽ ������ ����.

				break;
			}
		}
	}

	cout << M - count << "\n";

	return 0;
}