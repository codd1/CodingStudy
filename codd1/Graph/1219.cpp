#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, start_city, end_city, M;	// N: 도시의 수, M: 교통 수단의 개수
	cin >> N >> start_city >> end_city >> M;

	long MIN = LONG_MIN;		// 변형된 벨만 포드 구현으로, INF가 아닌 MIN을 사용한다.
	long MAX = LONG_MAX;
	typedef tuple<int, int, int> edge;
	vector<edge> nodes(M);
	vector<long> distance(N + 1, MIN);
	vector<long> profit(N + 1);	// 해당 도시에서 버는 이익

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
				distance[end] = MAX;		// MAX라는 것은 양수 사이클과 연결된 도시라는 뜻이다.
			}
			else if (distance[end] < distance[start] + profit[end] - cost) {
				distance[end] = distance[start] + profit[end] - cost;
				if (i >= N - 1) {			// N - 1 반복 이후의 업데이트라면
					distance[end] = MAX;	// 양수 사이클에 연결된 노드로 보고 MAX 값으로 업데이트
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