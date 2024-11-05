#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";

    if (n <= 2) {
        answer = to_string(n);

        return answer;
    }

    while (n > 0) {
        //printf("%d -> n % 3 = %d\n", n, n%3);
        switch (n % 3) {
        case 1:
            answer += "1";
            n -= 1;
            break;
        case 2:
            answer += "2";
            n -= 2;
            break;
        case 0:
            answer += "4";
            n -= 3;         // 124 나라에서는 0이라는 숫자가 존재하지 않기 때문에 0이 나왔을 때 자리 올림으로 해결 (몫에서 -1)
            break;
        }

        n /= 3;
    }

    reverse(answer.begin(), answer.end());      // 마지막 자리부터 계산했기 때문에 마지막에 string reverse

    return answer;
}