#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int answer_size = std::max(arr1.size(), arr2.size());
    vector<vector<int>> answer(answer_size);

    int calc = 0;
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            for (int k = 0, l = 0; k < answer_size;) {
                calc += arr1[i][l] * arr2[k][j];

                if (k < arr2[j].size() - 1) {
                    k++;
                }
                if (l < arr1[i].size() - 1) {
                    l++;
                }
                //printf("calc += %d * %d = %d\n", arr1[i][k], arr2[k][j], calc);
            }

            answer[i].push_back(calc);
            calc = 0;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> arr1 = { {1,1},{2,3} };
    vector<vector<int>> arr2 = { {3,5} };

    vector<vector<int>> answer = solution(arr1, arr2);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}