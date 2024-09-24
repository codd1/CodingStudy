#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M;	// N: ���� ����, M: ���� ����
	cin >> N >> M;

	long INF = LONG_MAX;
	typedef tuple<long, long, long> edge;
	vector<edge> nodes(M);
	vector<long> distance(N + 1, INF);
	distance[1] = 0;	// ���� ����: 1

	long start, end, weight;
	for (long i = 0; i < M; i++) {
		cin >> start >> end >> weight;

		nodes[i] = make_tuple(start, end, weight);
	}
	
	for (long i = 1; i < N; i++) {		// �ݺ� Ƚ���� N - 1
		for (long j = 0; j < M; j++) {
			start = get<0>(nodes[j]);
			end = get<1>(nodes[j]);
			weight = get<2>(nodes[j]);

			if (distance[start] != INF && distance[end] > distance[start] + weight) {
				distance[end] = distance[start] + weight;
			}
		}
	}

	// ���� ����Ŭ Ȯ���� ���� ��� ������ �� ���� �ٽ� ����� ������Ʈ �Ǵ� ��尡 �߻��ϴ��� Ȯ��
	vector<long> distance2(N + 1, INF);
	distance2 = distance;

	for (long i = 1; i < N; i++) {		// ���⼭�� �ݺ� Ƚ���� N
		for (long j = 0; j < M; j++) {
			start = get<0>(nodes[j]);
			end = get<1>(nodes[j]);
			weight = get<2>(nodes[j]);

			if (distance2[start] != INF && distance2[end] > distance2[start] + weight) {
				distance2[end] = distance2[start] + weight;
			}
		}
	}

	for (long i = 1; i <= N; i++) {
		if (distance[i] != distance2[i]) {	// ������Ʈ�� �߻��ߴٸ�
			cout << -1 << "\n";				// ���� ����Ŭ�� �����ϹǷ�, -1 ��� �� ����

			return 0;
		}
	}

	for (long i = 2; i <= N; i++) {
		if (distance[i] == INF) {
			cout << -1 << "\n";
		}
		else {
			cout << distance[i] << "\n";
		}
	}

	return 0;
}