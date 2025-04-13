#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<tuple<int, int, int>> temp_answer;

    // k ���� ���ҷ� �ִ� ���, ã�Ƽ� �ٷ� ����
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

    // 0�� �ε������� (���ʺ���) �����̵� ������� Ȯ��
    while (end < sequence.size()) {
        if (sum < k) {
            end++;
            sum += sequence[end];
        }
        else if (sum == k) {
            temp_answer.push_back(make_tuple(end - start + 1, start, end));     // ������ ũ��, ���� �ε���, ������ �ε���

            end++;
            sum += sequence[end];
        }
        else {
            sum -= sequence[start];

            start++;
        }
    }

    sort(temp_answer.begin(), temp_answer.end());       // ������ ũ�⸦ �������� �������� ����

    answer.push_back(get<1>(temp_answer[0]));
    answer.push_back(get<2>(temp_answer[0]));

    return answer;
}