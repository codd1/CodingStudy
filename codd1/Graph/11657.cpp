#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M;	// N: 도시 개수, M: 버스 개수
	cin >> N >> M;

	long INF = LONG_MAX;
	typedef tuple<long, long, long> edge;
	vector<edge> nodes(M);
	vector<long> distance(N + 1, INF);
	distance[1] = 0;	// 시작 도시: 1

	long start, end, weight;
	for (long i = 0; i < M; i++) {
		cin >> start >> end >> weight;

		nodes[i] = make_tuple(start, end, weight);
	}
	
	for (long i = 1; i < N; i++) {		// 반복 횟수는 N - 1
		for (long j = 0; j < M; j++) {
			start = get<0>(nodes[j]);
			end = get<1>(nodes[j]);
			weight = get<2>(nodes[j]);

			if (distance[start] != INF && distance[end] > distance[start] + weight) {
				distance[end] = distance[start] + weight;
			}
		}
	}

	// 음수 사이클 확인을 위해 모든 엣지를 한 번씩 다시 사용해 업데이트 되는 노드가 발생하는지 확인
	vector<long> distance2(N + 1, INF);
	distance2 = distance;

	for (long i = 1; i < N; i++) {		// 여기서의 반복 횟수는 N
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
		if (distance[i] != distance2[i]) {	// 업데이트가 발생했다면
			cout << -1 << "\n";				// 음수 사이클이 존재하므로, -1 출력 후 종료

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