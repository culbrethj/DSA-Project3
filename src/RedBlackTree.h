#include <iostream>
#include <string>
#include <unordered_map>
#include "Packet.h"
using namespace std;

// Enumeration for node color in Red-Black Tree
enum Color { RED, BLACK };

// Class representing a node in the Red-Black Tree
class RBNode {
public:
    int record_id;   // Unique identifier for the record
    Packet data;     // Data associated with the record (assuming Packet is a class or struct)

    Color color;      // Color of the node (either RED or BLACK)
    RBNode* left;     // Pointer to the left child
    RBNode* right;    // Pointer to the right child
    RBNode* parent;   // Pointer to the parent node

    // Constructor for creating a node with given record_id and data
    RBNode(int record_id, Packet p) : 
        record_id(record_id),
        data(p),
        color(RED), // New nodes are initially colored as RED
        left(nullptr),
        right(nullptr),
        parent(nullptr) {}
};

// Class representing a Red-Black Tree
class RedBlackTree {
private:
    RBNode* root; // Pointer to the root of the tree
    RBNode* NIL; // Sentinel node representing the NULL or leaf nodes

    // Private helper functions for tree operations
    void leftRotate(RBNode* x);
    void rightRotate(RBNode* y);
    void insertFixup(RBNode* z);
    RBNode* minimum(RBNode* x);

    RBNode* searchRecord(int record_id);
    void inorderTraversal(RBNode* node);
    void statesInorderTraversal(RBNode* node, unordered_map<string, int>& mp);
    void agesInorderTraversal(RBNode* node, long long int& total, int& count);

public:
    // Constructor and Destructor for initializing the Red-Black Tree
    RedBlackTree();
    ~RedBlackTree();

    // Public function to destroy the tree starting from a given node
    void destroyTree(RBNode* node);

    // Public function to insert a new record with given record_id and packet data
    void insert(int record_id, Packet packet);

    // Public function to search for a record with a given record_id
    void search(int record_id);

    // Public function to perform an inorder traversal of the tree
    void inorder();

    // Public function to count the occurrences of each state in the tree
    unordered_map<string, int> statesInorder();
    double agesInorder();
};

// Constructor for the Red-Black Tree
RedBlackTree::RedBlackTree() {
    Packet blank;
    NIL = new RBNode(0, blank);
    NIL->color = BLACK;
    root = NIL;
}
// Destructor
RedBlackTree::~RedBlackTree() {
    destroyTree(root);
    delete NIL;
}

// Helper function to destroy the tree starting from a given node
void RedBlackTree::destroyTree(RBNode* node) {
    if (node != NIL) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
// Helper function to perform a left rotation on the given node
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

// Helper function to perform a right rotation on the given node
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

// Helper function to fix the Red-Black Tree properties after insertion
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

// Public function to insert a new record with given record_id and packet data
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
// Helper function to search for a record with a given record_id
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

// Helper function to perform an inorder traversal of the tree
void RedBlackTree::inorderTraversal(RBNode* node) {
    if (node != NIL) {
        inorderTraversal(node->left);
        //cout << "ID: " << node->record_id << endl;
        inorderTraversal(node->right);
    }
}

// Helper function to perform an inorder traversal of the tree and count occurrences of each state
void RedBlackTree::statesInorderTraversal(RBNode* node, unordered_map<string, int>& mp){
    if (node != NIL) {
        statesInorderTraversal(node->left, mp);
        if (!mp[node->data.buyer_state]) mp[node->data.buyer_state] = 1;
        else mp[node->data.buyer_state]++;
        statesInorderTraversal(node->right, mp);
    }
}

void RedBlackTree::agesInorderTraversal(RBNode* node, long long int& total, int& count){
    if (node != NIL) {
        agesInorderTraversal(node->left, total, count);
        total += node->data.slave_age;
        count++;
        agesInorderTraversal(node->right, total, count);
    }
}

// Helper function to find the minimum node in the subtree rooted at x
RBNode* RedBlackTree::minimum(RBNode* x) {
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}

// Public function to search for a record with a given record_id
void RedBlackTree::search(int record_id) {
    RBNode* node = searchRecord(record_id);

    if(node != nullptr){
        cout << "Record with ID " << record_id << " found!" << endl;
    }
    else{
        cout << "Record with ID " << record_id << " not found." << endl;
    }
}
// Public function to perform an inorder traversal of the tree
void RedBlackTree::inorder() {
    inorderTraversal(root);
}
// Public function to count the occurrences of each state in the tree
unordered_map<string, int> RedBlackTree::statesInorder(){
    unordered_map<string, int> mp;
    statesInorderTraversal(root, mp);
    return mp;
}

double RedBlackTree::agesInorder(){
    long long int sum = 0;
    int count = 0;
    agesInorderTraversal(root, sum, count);
    return sum / count;
}