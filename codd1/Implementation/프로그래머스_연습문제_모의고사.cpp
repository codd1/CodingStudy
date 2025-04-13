#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> count(3, 0);
    vector<vector<int>> input(3);

    input[0].assign({ 1,2,3,4,5 });
    input[1].assign({ 2,1,2,3,2,4,2,5 });
    input[2].assign({ 3,3,1,1,2,2,4,4,5,5 });

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == input[0][i % 5]) {
            count[0]++;
        }

        if (answers[i] == input[1][i % 8]) {
            count[1]++;
        }

        if (answers[i] == input[2][i % 10]) {
            count[2]++;
        }
    }

    int max = *max_element(count.begin(), count.end());

    for (int i = 0; i < 3; i++) {
        if (count[i] == max) {
            answer.push_back(i + 1);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<int> exam_answers;
    vector<int> answer;

    exam_answers.assign({ 1,2,3,4,5 });
    answer.assign({ 1 });

    if (answer == solution(exam_answers)) {
        cout << "correct!" << endl;
    }
    else {
        cout << "falut" << endl;
    }
}