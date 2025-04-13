#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<float, int> a, pair<float, int> b) {
    if (a.first == b.first) {     // 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
        return a < b;
    }
    else {
        return b < a;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail_ratio;

    float try_sum = 0.f;
    float fail_sum = 0.f;
    float calc = 0.f;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < stages.size(); j++) {
            if (i <= stages[j]) {
                try_sum++;

                if (i == stages[j]) {
                    fail_sum++;
                }
            }
        }

        if (try_sum == 0.f) {
            calc = 0;
        }
        else {
            calc = fail_sum / try_sum;
        }

        fail_ratio.push_back(make_pair(calc, i));

        try_sum = 0.f;
        fail_sum = 0.f;
    }

    sort(fail_ratio.begin(), fail_ratio.end(), compare);

    for (int i = 0; i < N; i++) {
        answer.push_back(fail_ratio[i].second);
    }

    return answer;
}

int main() {
    int N;
    vector<int> stages;
    vector<int> answer;

    N = 5;
    stages.assign({ 2, 1, 2, 6, 2, 4, 3, 3 });
    answer.assign({ 3,4,2,1,5 });

    if (answer == solution(N, stages)) {
        cout << "correct!" << endl;
    }
    else {
        cout << "falut" << endl;
    }

    N = 4;
    stages.assign({ 4,4,4,4,4 });
    answer.assign({ 4,1,2,3 });

    if (answer == solution(N, stages)) {
        cout << "correct!" << endl;
    }
    else {
        cout << "falut" << endl;
    }
}