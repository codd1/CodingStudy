#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> temp;

    sort(score.begin(), score.end());

    int min;
    for (int i = score.size() - 1; i >= 0; i--) {
        temp.push_back(score[i]);

        if (temp.size() == m) {
            min = *min_element(temp.begin(), temp.end());

            answer += min * m;

            temp.resize(0);
        }

    }

    return answer;
}