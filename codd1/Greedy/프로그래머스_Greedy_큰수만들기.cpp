#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    char digit;

    for (int i = 0; i < number.size(); i++) {
        digit = number[i];

        // 스택의 마지막 숫자가 현재 숫자보다 작고, 제거할 횟수가 남아있다면
        while (!answer.empty() && answer.back() < digit && k > 0) {
            answer.pop_back();   // 스택의 마지막 숫자를 제거
            k--;                // 제거 횟수 감소
        }

        answer += digit;
    }

    // 탐색을 끝냈지만 제거할 횟수가 남아 있다면 뒤에서부터 제거
    while (k > 0) {
        answer.pop_back();
        k--;
    }

    // 스택에 남은 숫자들을 합쳐서 결과 반환
    return answer;
}


int main() {
    cout << solution("1924", 2) << endl;            // "94"
    cout << solution("4177252841", 4) << endl;      // "775841"
}