#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {		// 두 값의 second가 같을 경우
		return a.first < b.first;	// first를 기준으로 오름차순 정렬
	}
	return a.second < b.second;
}

int main() {
	int N;			// 회의의 수
	int count = 0;	// 진행할 수 있는 회의의 갯수
	vector<pair<int, int>> meeting;		// map은 중복 입력이 안됨

	cin >> N;

	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		meeting.push_back(make_pair(start, end));
	}

	sort(meeting.begin(), meeting.end(), compareBySecond);	// second를 기준으로 오름차순 정렬

	int previous_end = 0;		// 이전에 종료된 회의 시간
	for (auto i = meeting.begin(); i != meeting.end(); i++) {
		start = i->first;

		if (previous_end <= start) {	// 다음 회의 시작 시간이 이전에 종료된 회의 시간보다 크거나 같다면
			count++;					// 회의를 진행할 수 있고
			previous_end = i->second;	// 회의가 진행되므로 종료될 회의 시간으로 바꿔준다.
		}
	}

	cout << count << endl;

	return 0;
}