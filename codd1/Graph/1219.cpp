#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, start_city, end_city, M;	// N: ������ ��, M: ���� ������ ����
	cin >> N >> start_city >> end_city >> M;

	long MIN = LONG_MIN;		// ������ ���� ���� ��������, INF�� �ƴ� MIN�� ����Ѵ�.
	long MAX = LONG_MAX;
	typedef tuple<int, int, int> edge;
	vector<edge> nodes(M);
	vector<long> distance(N + 1, MIN);
	vector<long> profit(N + 1);	// �ش� ���ÿ��� ���� ����

	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		nodes[i] = make_tuple(start, end, cost);
	}

	for (int i = 0; i < N; i++) {
		cin >> profit[i];
	}

	distance[start_city] = profit[start_city];

	for (int i = 0; i <= N + 50; i++) {
		for (int j = 0; j < M; j++) {
			start = get<0>(nodes[j]);
			end = get<1>(nodes[j]);
			cost = get<2>(nodes[j]);

			if (distance[start] == MIN) {
				continue;
			}
			else if (distance[start] == MAX) {
				distance[end] = MAX;		// MAX��� ���� ��� ����Ŭ�� ����� ���ö�� ���̴�.
			}
			else if (distance[end] < distance[start] + profit[end] - cost) {
				distance[end] = distance[start] + profit[end] - cost;
				if (i >= N - 1) {			// N - 1 �ݺ� ������ ������Ʈ���
					distance[end] = MAX;	// ��� ����Ŭ�� ����� ���� ���� MAX ������ ������Ʈ
				}
			}
		}
	}

	if (distance[end_city] == MIN) {
		cout << "gg" << "\n";
	}
	else if (distance[end_city] == MAX) {
		cout << "Gee" << "\n";
	}
	else {
		cout << distance[end_city] << "\n";
	}

	return 0;
}