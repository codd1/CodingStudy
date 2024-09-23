#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> dist[1001];		// 도시는 최대 1000개, 기본 내림차순 정렬

int main() {
	int n, m, k;	// n: 도시 개수, m: 도로의 수, k: k번째 최단 경로 구하기
	cin >> n >> m >> k;

	vector <vector<pair<int, int>>> nodes(n + 1);

	int start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;

		nodes[start].push_back(make_pair(end, cost));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	// 오름차순 정렬

	// 시작 도시가 1로 고정
	dist[1].push(0);
	q.push(make_pair(0, 1));
	pair<int,int> top = q.top();

	while (!q.empty()) {
		top = q.top();
		q.pop();

		for (int i = 0; i < nodes[top.second].size(); i++) {
			if (dist[nodes[top.second][i].first].size() < k) {	// distance[연결된 노드]의 크기가 k보다 작다면 새로운 경로 그냥 추가
				dist[nodes[top.second][i].first].push(top.first + nodes[top.second][i].second);
				q.push(make_pair(top.first + nodes[top.second][i].second, nodes[top.second][i].first));
			}
			// distance[연결된 노드]의 크기가 k이면서, distance[연결된 노드]의 최대 경로와 비교했을 때 신규 경로가 더 작다면
			else if (dist[nodes[top.second][i].first].top() > top.first + nodes[top.second][i].second) {
				dist[nodes[top.second][i].first].pop();		// 기존의 최대 거리 경로를 삭제하고
				dist[nodes[top.second][i].first].push(top.first + nodes[top.second][i].second);	// 더 작은 경로 업데이트
				q.push(make_pair(top.first + nodes[top.second][i].second, nodes[top.second][i].first));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {	// 크기가 k보다 작다면 k번째 경로가 존재하지 않는 것이므로 -1 출력
			cout << -1 << "\n";
		}
		else {
			cout << dist[i].top() << "\n";	// top에 가장 큰 경로가 들어가므로(k번째 경로) top 출력
		}
	}

	return 0;
}