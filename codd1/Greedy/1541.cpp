#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;

	int num = 0;
	int sum = 0;

	bool is_minus = false;

	for (int i = 0; i < str.size(); i++) {
		while (isdigit(str[i])) {		// 숫자라면 계속 반복
			num = num * 10 + (str[i] - '0');
			i++;
		}

		if (is_minus) {		// '-'가 나온 후라면 계속 빼기만 하면된다.
			sum -= num;		// 예를 들어, 100-40+50+74-30+29-45+43+11라면 100-(40+50+74)-(30+29)-(45+43+11) 이렇게 빼기 계산만 하게
							// 묶을 수 있기 때문에 한 번 빼기가 나오면 그 이후로는 빼기만 하면 된다.
		}
		else {		// 아직 '-'가 나오기 전이라면 계속 더한다.
			sum += num;
		}

		if (str[i] == '-') {
			is_minus = true;
		}

		num = 0;
	}

	cout << sum << endl;

	return 0;
}