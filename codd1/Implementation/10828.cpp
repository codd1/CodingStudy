#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stack {
	vector<int> v;
	int prev_top = 0;

	void push(int X) {
		v.push_back(X);
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			prev_top = top();
			v.erase(v.begin() + v.size() - 1);

			return prev_top;
		}
	}

	int size() {
		return v.size();
	}

	bool empty() {
		if (v.size() > 0) {
			return false;
		}
		else {
			return true;
		}
	}

	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return v[v.size() - 1];
		}
		
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;		// 주어지는 명령의 수
	cin >> N;

	string str;
	int num;

	Stack stack;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str.compare("push") == 0) {
			cin >> num;

			stack.push(num);
		}
		else if (str.compare("pop") == 0) {
			cout << stack.pop() << "\n";
		}
		else if (str.compare("size") == 0) {
			cout << stack.size() << "\n";
		}
		else if (str.compare("empty") == 0) {
			cout << stack.empty() << "\n";
		}
		else if (str.compare("top") == 0) {
			cout << stack.top() << "\n";
		}
	}

	return 0;
}