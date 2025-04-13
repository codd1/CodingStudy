#include <iostream>

using namespace std;

void preorder(char tree[27][2], int now) {
	if (now == -1) {
		return;
	}

	cout << (char)(now + 'A');

	preorder(tree, tree[now][0]);	// 왼쪽 자식 노드 탐색
	preorder(tree, tree[now][1]);	// 오른쪽 자식 노드 탐색
}

void inorder(char tree[27][2], int now) {
	if (now == -1) {
		return;
	}

	inorder(tree, tree[now][0]);	// 왼쪽 자식 노드 탐색

	cout << (char)(now + 'A');

	inorder(tree, tree[now][1]);	// 오른쪽 자식 노드 탐색
}

void postorder(char tree[27][2], int now) {
	if (now == -1) {
		return;
	}

	postorder(tree, tree[now][0]);	// 왼쪽 자식 노드 탐색
	postorder(tree, tree[now][1]);	// 오른쪽 자식 노드 탐색

	cout << (char)(now + 'A');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 이진 트리의 노드 개수 (1<=N<=26)
	cin >> N;

	// 트리 구조 만들기
	char tree[27][2] = {'\0',};

	char parent, left, right;
	for (int i = 0; i < N; i++) {
		cin >> parent >> left >> right;

		parent = parent - 'A';		// index로 변환하기 위함

		if (left == '.') {			// 자식 노드가 없을 경우, -1로 저장
			tree[parent][0] = -1;
		}
		else {
			tree[parent][0] = left - 'A';
		}
		
		if (right == '.') {
			tree[parent][1] = -1;
		}
		else {
			tree[parent][1] = right - 'A';
		}
	}

	preorder(tree, 0);		// 전위 순회
	cout << "\n";

	inorder(tree, 0);		// 중위 순회
	cout << "\n";

	postorder(tree, 0);		// 후위 순회
	cout << "\n";

	return 0;
}