#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// N개의 최소공배수 구하는 법: (num1 * num2 / (num1과 num2의 최대공약수))를 반복한다. 여기서 나온 값과 다음 num3과 계산, ...

int calculate(int num1, int num2) {
    if (num1 % num2 == 0 || num2 >= num1) {
        return num2;
    }

    return calculate(num2, num1 % num2);
}

int solution(vector<int> arr) {
    int answer = 0;

    int max = std::max(arr[0], arr[1]);
    int min = std::min(arr[0], arr[1]);

    int multiple = arr[0] * arr[1];
    int prev_result = multiple / calculate(max, min);

    for (int i = 2; i < arr.size(); i++) {
        max = std::max(arr[i], prev_result);
        min = std::min(arr[i], prev_result);

        prev_result = (max * min) / calculate(max, min);
    }

    answer = prev_result;

    return answer;
}

int main() {
    vector<int> arr = { 3, 5, 9, 10 };

    cout << solution(arr) << endl;
}