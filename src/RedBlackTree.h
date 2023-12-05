#include <iostream>
#include <string>
#include <map>
#include "Packet.h"
using namespace std;

enum Color { RED, BLACK };

class RBNode {
public:
    int record_id;

    Packet data;

    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    // Constructor
    RBNode(int record_id, Packet p) : 
        record_id(record_id),
        data(p),
        color(RED),
        left(nullptr),
        right(nullptr),
        parent(nullptr) {}
};

class RedBlackTree {
private:
    RBNode* root;
    RBNode* NIL;

    void leftRotate(RBNode* x);
    void rightRotate(RBNode* y);
    void insertFixup(RBNode* z);
    RBNode* minimum(RBNode* x);

    RBNode* searchRecord(int record_id);
    void inorderTraversal(RBNode* node);
    void statesInorderTraversal(RBNode* node, map<string, int>& mp);

public:
    RedBlackTree();
    ~RedBlackTree();
    void destroyTree(RBNode* node);
    void insert(int record_id, Packet packet);
    void search(int record_id);
    void inorder();
    map<string, int> statesInorder();
};

RedBlackTree::RedBlackTree() {
    Packet blank;
    NIL = new RBNode(0, blank);
    NIL->color = BLACK;
    root = NIL;
}

RedBlackTree::~RedBlackTree() {
    destroyTree(root);
    delete NIL;
}
void RedBlackTree::destroyTree(RBNode* node) {
    if (node != NIL) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void RedBlackTree::leftRotate(RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;

    if (y->left != NIL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NIL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;

    if (x->right != NIL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NIL) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void RedBlackTree::insertFixup(RBNode* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode* y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            RBNode* y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int record_id, Packet packet) {
    RBNode* z = new RBNode(record_id, packet);

    RBNode* y = NIL;
    RBNode* x = root;

    while (x != NIL) {
        y = x;
        if (z->record_id < x->record_id) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NIL) {
        root = z;
    } else if (z->record_id < y->record_id) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = NIL;
    z->right = NIL;
    z->color = RED;

    insertFixup(z);
}

RBNode* RedBlackTree::searchRecord(int record_id) {
    RBNode* current = root;

    while (current != NIL && current->record_id != record_id) {
        if (record_id < current->record_id) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Return nullptr if the record with the specified record_id is not found
    return current == NIL ? nullptr : current;
}

void RedBlackTree::inorderTraversal(RBNode* node) {
    if (node != NIL) {
        inorderTraversal(node->left);
        //cout << "ID: " << node->record_id << endl;
        inorderTraversal(node->right);
    }
}

void RedBlackTree::statesInorderTraversal(RBNode* node, map<string, int>& mp){
    if (node != NIL) {
        inorderTraversal(node->left, mp);
        if (!mp[node->data.buyer_state]) mp[node->data.buyer_state] = 1;
        else mp[node->data.buyer_state]++;
        inorderTraversal(node->right, mp);
    }
}

RBNode* RedBlackTree::minimum(RBNode* x) {
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}

void RedBlackTree::search(int record_id) {
    RBNode* node = searchRecord(record_id);

    if(node != nullptr){
        cout << "Record with ID " << record_id << " found!" << endl;
    }
    else{
        cout << "Record with ID " << record_id << " not found." << endl;
    }
}

void RedBlackTree::inorder() {
    inorderTraversal(root);
}

map<string, int> RedBlackTree::statesInorder(){
    map<string, int> mp;
    statesInorderTraversal(root, mp);
    return mp;
}
