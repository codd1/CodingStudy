#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Queue {
	vector<int> v;
	int temp = 0;

	void push(int X) {
		v.push_back(X);
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			temp = v[0];
			v.erase(v.begin());

			return temp;
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

	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return v[0];
		}
	}

	int back() {
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
	Queue queue;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str.compare("push") == 0) {
			cin >> num;

			queue.push(num);
		}
		else if (str.compare("pop") == 0) {
			cout << queue.pop() << endl;
		}
		else if (str.compare("size") == 0) {
			cout << queue.size() << endl;
		}
		else if (str.compare("empty") == 0) {
			cout << queue.empty() << endl;
		}
		else if (str.compare("front") == 0) {
			cout << queue.front() << endl;
		}
		else if (str.compare("back") == 0) {
			cout << queue.back() << endl;
		}
	}

	return 0;
}