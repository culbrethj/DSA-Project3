#include <iostream>
#include <string>
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
    RBNode* search(int record_id);
    RBNode* minimum(RBNode* x);
    void transplant(RBNode* u, RBNode* v);
    void deleteFixup(RBNode* x);

public:
    RedBlackTree();
    ~RedBlackTree();
    void destroyTree(RBNode* node);
    RBNode* getRoot() const {
        return root;
    }
    void insert(int record_id, Packet packet);
    RBNode* searchRecord(int record_id);
    void inorderTraversal(RBNode* node);
    void deleteRecord(int record_id);
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
        cout << "Record ID: " << node->record_id << endl;
        inorderTraversal(node->right);
    }
}

RBNode* RedBlackTree::minimum(RBNode* x) {
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}

void RedBlackTree::transplant(RBNode* u, RBNode* v) {
    if (u->parent == NIL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RedBlackTree::deleteFixup(RBNode* x) {
        while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBNode* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            RBNode* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RedBlackTree::deleteRecord(int record_id) {
    RBNode* z = searchRecord(record_id);
    if (z == NIL) {
        cout << "Record not found." << endl;
        return;
    }

    RBNode* y = z;
    RBNode* x;
    Color y_original_color = y->color;

    if (z->left == NIL) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;

    if (y_original_color == BLACK) {
        deleteFixup(x);
    }
}

// int main() {
//     RedBlackTree rbTree;

//     // Example of inserting records
//     rbTree.insert(1, "Country1", "Buyer1", "Origin1", "State1", "SellerCountry1", "Seller1", "SellerOrigin1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", "5", 10, "Credit", 80, 1000);
//     rbTree.insert(2, "Country2", "Buyer2", "Origin2", "State2", "SellerCountry2", "Seller2", "SellerOrigin2", "SellerState2", 25, "Female", "Slave2", "White", "2023-01-02", "8", 5, "Cash", 90, 1200);
//     rbTree.insert(3, "Country3", "Buyer3", "Origin3", "State3", "SellerCountry3", "Seller3", "SellerOrigin3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", "10", 15, "Credit", 85, 800);

//     // Example of searching for a record
//     RBNode* foundRecord = rbTree.searchRecord(2);
//     if (foundRecord != nullptr) {
//         cout << "Record found: " << foundRecord->BuyerFullName << endl;
//     } else {
//         cout << "Record not found." << endl;
//     }

//     // Example of deleting a record
//     //rbTree.deleteRecord(2);

//     // Example of searching for a deleted record
//     foundRecord = rbTree.searchRecord(2);
//     if (foundRecord != nullptr) {
//         cout << "Record found: " << foundRecord->BuyerFullName << endl;
//     } else {
//         cout << "Record not found." << endl;
//     }

//     cout << "Inorder Traversal:" << endl;
//     rbTree.inorderTraversal(rbTree.getRoot());

//     return 0;
// }
