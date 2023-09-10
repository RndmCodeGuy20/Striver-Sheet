/**
 * Created by SHANTANU on 11-08-2023.
 * Topic - Delete from BST
*/
#include <bits/stdc++.h>
#include "./BST.h"

using namespace std;

class Solution {
private:
    int Height(Node *ptr) {
        int LH, RH;

        if (!ptr) return 0;
        LH = Height(ptr->left);
        RH = Height(ptr->right);

        return LH > RH ? LH + 1 : RH + 1;
    }

    Node *InorderPredecessor(Node *ptr) {
        while (ptr && ptr->right) ptr = ptr->right;

        return ptr;
    }

    Node *InorderSuccessor(Node *ptr) {
        while (ptr && ptr->left) ptr = ptr->left;

        return ptr;
    }

public:
    Node *Delete(Node *ptr, int target) {
        if (!ptr) return nullptr;

        if (!ptr->left && !ptr->right) return nullptr;

        if (target < ptr->data) ptr->left = Delete(ptr->left, target);
        else if (target > ptr->data) ptr->right = Delete(ptr->right, target);
        else {
            if (Height(ptr->left) > Height(ptr->right)) {
                Node *q = InorderPredecessor(ptr->left);
                ptr->data = q->data;
                ptr->left = Delete(ptr->left, q->data);
            } else {
                Node *q = InorderSuccessor(ptr->right);
                ptr->data = q->data;
                ptr->right = Delete(ptr->right, q->data);
            }
        }
    }
};

int main() {


    return 0;
}