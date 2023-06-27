//
// Created by SHANTANU on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPossible(bool graph[101][101], int V, vector<int> &color, int index) {
        for (int i = 0; i < V; ++i) {
            if (graph[index][i] == 1 && color[i] == color[index]) return false;
        }
        return true;
    }

    bool colorGraph(bool graph[101][101], int m, int V, vector<int> &color, int index) {
        if (index == V) return true;

        for (int i = 0; i < m; ++i) {
            color[index] = i;
            if (isPossible(graph, V, color, index)) {
                if (colorGraph(graph, m, V, color, index + 1)) return true;
            }
            color[index] = 0;
        }
        return false;
    }

public:
    bool graphColoring(bool graph[101][101], int m, int V) {
        vector<int> color(V, 0);
        return colorGraph(graph, m, V, color, 0);
    }
};

int main() {

    Solution solution;
    bool graph[101][101] = {{0, 1, 1, 1},
                            {1, 0, 1, 0},
                            {1, 1, 0, 1},
                            {1, 0, 1, 0}};
    cout << solution.graphColoring(graph, 3, 4);


    return 0;
}