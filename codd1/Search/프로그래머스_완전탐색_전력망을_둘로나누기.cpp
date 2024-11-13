#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<bool>& visited, int tower, int count) {
    visited[tower] = true;
    count++;

    for (int i = 0; i < tree[tower].size(); i++) {
        if (visited[tree[tower][i]] == false) {
            count = dfs(tree, visited, tree[tower][i], count);
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;

    vector<vector<int>> tree(n + 1);
    vector<bool> visited(n + 1);

    for (int i = 0; i < wires.size(); i++) {
        tree[wires[i][0]].push_back(wires[i][1]);
        tree[wires[i][1]].push_back(wires[i][0]);
    }

    int tower1 = 0;
    int tower2 = 0;

    for (int i = 0; i < tree.size(); i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            visited[i] = true;
            visited[tree[i][j]] = true;

            tower1 = dfs(tree, visited, tree[i][j], 0);
            tower2 = dfs(tree, visited, i, 0);

            if (abs(tower1 - tower2) < answer) {
                answer = abs(tower1 - tower2);
            }

            fill(visited.begin(), visited.end(), false);
        }
    }

    return answer;
}