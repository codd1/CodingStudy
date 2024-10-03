#include <iostream>

using namespace std;

class Node {		// 트라이 자료 구조 저장용 클래스
public:
	Node* next[26];			// 알파벳 기준으로 크기 26인 배열 선언
	bool isEnd = false;		// 마지막 문자열 여부 표시

	Node() {
		fill(next, next + 26, nullptr);
	}

	~Node() {
		for (int i = 0; i < 26; i++) {
			if (next[i] != nullptr) {
				delete next[i];
			}
		}
	}

	void insert(char* key) {	// 문자열 삽입 함수
		if (*key == 0) {
			isEnd = true;
		}
		else {
			int nextIndex = *key - 'a';

			if (next[nextIndex] == nullptr) {		// key 변수에 해당하는 노드가 nullptr이라면
				next[nextIndex] = new Node();		// 신규 노드 생성
			}

			next[nextIndex]->insert(key + 1);		// 다음 문자열
		}
	}

	Node* find(char* key) {		// 문자열 찾기 함수
		if (*key == 0) {
			return this;		// 마지막 문자열이라면 해당 문자 리턴
		}
		
		int nextIndex = *key - 'a';

		if (next[nextIndex] == nullptr) {
			return nullptr;
		} 

		return next[nextIndex]->find(key + 1);		// 다음 문자열
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	// 트라이 자료 구조 구축 (집합 S)
	Node* root = new Node();
	char text[501];

	for (int i = 0; i < N; i++) {
		cin >> text;

		root->insert(text);
	}

	// 트라이 자료구조 검색
	Node* result;
	int count = 0;

	for (int i = 0; i < M; i++) {
		cin >> text;

		result = root->find(text);

		if (result && result->isEnd) {		// 마지막 노드가 존재하고, isEnd == true라면
			count++;						// 집합 S에 포함되는 문자열을 찾은 것이므로 카운팅
		}
	}

	cout << count << "\n";

	return 0;
}