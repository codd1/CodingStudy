#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;

    int x_index = 0;    // x의 인덱스
    int x = 0;          // x가 나온 횟수
    int not_x = 0;      // x가 아닌 다른 글자들이 나온 횟수

    for (int i = 0; i < s.size(); i++) {
        if (s[x_index] == s[i]) {
            x++;
        }
        else {
            not_x++;
        }

        if (x == not_x) {   // x와 x가 아닌 다른 글자들이 나온 횟수가 같은 경우,
            answer++;

            x = 0;
            not_x = 0;
            x_index = i + 1;
        }
        //printf("%d - x = %d, not_x = %d\n",i, x, not_x);
    }

    if (x != 0 || not_x != 0 || s.size() % 2 == 1) {    // 남는 문자열이 있다면 answer++
        answer++;
    }

    return answer;
}