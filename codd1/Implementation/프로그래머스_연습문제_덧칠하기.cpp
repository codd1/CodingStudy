#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int i = 0, j = 0;

    for (; section[i] + m - 1 <= n && i < section.size(); i++) {
        answer++;
        for (j = i; section[j] <= section[i] + m - 1 && j < section.size(); j++) {
            //cout << section[j] << " <= " << section[i]+m-1<<endl;
        }

        j -= 1;     // 안의 반복문에서 마지막에 나오면서 j++ 했으므로 다시 -1 해준다.
        i = j;
    }

    if (i < section.size()) {       // 아직 구역이 하나 남아있다면 칠해야하는 횟수 추가
        answer++;
    }

    return answer;
}