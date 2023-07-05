//
// Created by SHANTANU on 04-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    vector<Node *> neighbours;

    Node(int data) {
        this->data = data;
    }
};

class Solution {
    Node *cloneGraph(Node *node) {
        unordered_map<Node *, Node *> map;
        queue<Node *> Q;
        Node *ptr, *newNode;
        unordered_map<Node *, bool> visited;

        Q.push(node);
        ptr = new Node(node->data);
        map[node] = ptr;

        while (!Q.empty()) {
            ptr = Q.front();
            Q.pop();

            if (visited[ptr]) break;

            for (auto &nd: ptr->neighbours) {
                if (map.find(nd) == map.end()) {
                    newNode = new Node(nd->data);
                    map[nd] = newNode;
                }
                map[ptr]->neighbours.push_back(newNode);
                Q.push(nd);
            }

            visited[ptr] = true;
        }

        return map[node];
    }
};

int main() {


    return 0;
}