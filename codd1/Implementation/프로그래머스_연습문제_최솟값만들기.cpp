#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int num1, int num2) {
    return num2 < num1;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());               // �������� ����
    sort(B.begin(), B.end(), compare);      // �������� ����

    for (int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }

    return answer;
}