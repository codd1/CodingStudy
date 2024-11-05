#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<tuple<int, int, int>> temp_answer;

    // k 값이 원소로 있는 경우, 찾아서 바로 리턴
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] == k) {
            answer.push_back(i);
            answer.push_back(i);

            return answer;
        }
    }

    int start = 0;
    int end = 1;
    int sum = sequence[start] + sequence[end];

    // 0번 인덱스부터 (앞쪽부터) 슬라이딩 윈도우로 확인
    while (end < sequence.size()) {
        if (sum < k) {
            end++;
            sum += sequence[end];
        }
        else if (sum == k) {
            temp_answer.push_back(make_tuple(end - start + 1, start, end));     // 수열의 크기, 시작 인덱스, 마지막 인덱스

            end++;
            sum += sequence[end];
        }
        else {
            sum -= sequence[start];

            start++;
        }
    }

    sort(temp_answer.begin(), temp_answer.end());       // 수열의 크기를 기준으로 오름차순 정렬

    answer.push_back(get<1>(temp_answer[0]));
    answer.push_back(get<2>(temp_answer[0]));

    return answer;
}