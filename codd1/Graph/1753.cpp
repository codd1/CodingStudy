#include <iostream>
#include <vector>
#include <queue>
#include <climits>		// INT_MAX
#include <algorithm>	// min_element

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;	// V: 노드의 개수, E: 엣지의 개수, K: 출발 노드의 번호
	cin >> V >> E >> K;

	int INF = INT_MAX;
	vector<vector<pair<int, int>>> nodes(V + 1);
	vector<int> distance(V + 1, INF);	// 모든 노드의 최단 거리를 큰 값으로 초기화 (문제에서 가중치는 10 이하라고 했으므로 11로 설정)
	vector<bool> visited(V + 1, false);

	distance[K] = 0;	// 시작 노드는 거리가 0

	int u, v, w;	// u에서 v로 가는 가중치 w인 엣지
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		nodes[u].push_back(make_pair(v, w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	// pair<int,int>의 첫 번째 요소를 기준으로 비교해 오름차순 정렬 (첫 번째 요소가 같을 경우 두 번째 요소로 비교)

	q.push(make_pair(0, K));	// 첫 번째 요소를 기준으로 비교하기 때문에 가중치를 first 값으로 넣음
	pair<int,int> top = q.top();

	while (!q.empty()) {
		top = q.top();
		q.pop();

		if (visited[top.second] == false) {
			for (int j = 0; j < nodes[top.second].size(); j++) {
				// min(선택 노드의 최단 거리 배열의 값 + 엣지 가중치, 연결 노드의 최단 거리 배열의 값)
				distance[nodes[top.second][j].first] = std::min(distance[top.second] + nodes[top.second][j].second, distance[nodes[top.second][j].first]);
				q.push(make_pair(distance[nodes[top.second][j].first], nodes[top.second][j].first));
			}
		}

		visited[top.second] = true;
	}

	for (int i = 1; i <= V; i++) {
		if (distance[i] == INF) {	// 시작 노드에서 방문이 불가능한 노드
			cout << "INF" << "\n";
		}
		else {
			cout << distance[i] << "\n";
		}
	}

	return 0;
}