//
// Created by amoha on 6/13/2023.
//


#include "BST.h"

void BST::insert(int number) {
    if (contains(number))
        return;
    Node *newNode = new Node(number);
    Node *temp = this->root;
    if (!this->root) {
        this->root = newNode;
        return;
    }
    while (true) {
        if (number > temp->data) {
            if (temp->right == nullptr) {
                temp->right = newNode;
                break;
            } else
                temp = temp->right;
        } else {
            if (temp->left == nullptr) {
                temp->left = newNode;
                break;
            } else
                temp = temp->left;
        }
    }
}
void BST::traverse(int order) {
    Node *temp = this->root;
    if (order == 1)inorder(temp);
    else if (order == 2)preorder(temp);
    else postorder(temp);
}
void BST::inorder(Node *temp) {
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void BST::preorder(Node *temp) {
    if (!temp)
        return;
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}
void BST::postorder(Node *temp) {
    if (!temp)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}
BST::BST() {
    this->root = nullptr;
}
bool BST::contains(int val) {
    Node *temp = this->root;
    while (temp) {
        if (temp->data == val)
            return true;
        temp = (val > temp->data ? temp->right : temp->left);
    }
    return false;
}
void BST::remove(int val) {
    Node *temp = this->root;
    Node *par = findParent(val, temp);
    Node *node = findNode(val);
    // case of leaf node
    if (!node->left && !node->right) {
        if (val == this->root->data) {
            this->root = nullptr;
            return;
        }
        if (val > par->data)
            par->right = nullptr;
        else
            par->left = nullptr;
        delete node;
        node = nullptr;
    }
        // case of two childs
    else if (node->left && node->right) {
        int value = findMin(node->right);
        remove(value);
        node->data = value;
    }
        // case of one child
    else if (node->left or node->right) {
        if (val == this->root->data) {
            if (val > this->root->data) this->root = this->root->right;
            else this->root = this->root->left;
        }
            // right
        else if (val > par->data) {
            if (node->right)par->right = node->right;
            else par->right = node->left;
        }//left
        else {
            if (node->right) par->left = node->right;
            else par->left = node->left;
        }
    }


}
Node *BST::findParent(int val, Node *node) {
    if (!contains(val))
        return nullptr;
    Node *a = nullptr, *b = this->root;
    while (true) {
        if (b->data == val)
            return a;
        if (val > b->data and b->right) {
            a = b;
            b = b->right;
        } else if (b->left) {
            a = b;
            b = b->left;
        }
    }

}
Node *BST::findNode(int val) {
    if (!contains(val))
        return nullptr;
    Node *tmp = this->root;
    while (true) {
        if (val == tmp->data)
            return tmp;
        if (val > tmp->data and tmp->right)
            tmp = tmp->right;
        else if (tmp->left)
            tmp = tmp->left;
    }


    return nullptr;
}
int BST::findMin(Node *temp) {
    while (temp) {
        if (temp->left) {
            temp = temp->left;
        } else
            break;
    }
    return temp->data;
}
int BST::height(int val) {
    if (!contains(val))
        return -1;
    Node *temp = this->root;
    int cnt = -1;
    while (temp) {
        cnt++;
        if (temp->data == val)
            return cnt;
        temp = (val > temp->data ? temp->right : temp->left);
    }

    return 0;
}
