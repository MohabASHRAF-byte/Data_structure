//
// Created by amoha on 6/13/2023.
//

#ifndef COMPETITIVE_PROGRAMMING_BST_H
#define COMPETITIVE_PROGRAMMING_BST_H

#include <bits/stdc++.h>

using namespace std;
#define  el "\n"

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int d) {
        this->data = d;
        this->left = this->right = nullptr;
    }

    Node() {
        this->left = this->right = nullptr;
    }
};

class BST {
    Node *root;
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
    Node* findParent(int val, Node*);
    Node* findNode(int val);
    int findMin(Node*);
public:
    BST();
    void insert(int);
    void traverse(int);
    bool contains(int val);
    void remove(int val);
    int height(int val);
};


#endif //COMPETITIVE_PROGRAMMING_BST_H
