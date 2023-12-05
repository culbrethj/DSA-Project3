#include <iostream>
#include <vector>
#include <algorithm>
#include "Packet.h"

using namespace std;

//I chose 5 as N for the B Tree because I felt it would provide enough differences compared to the RB Tree.
const int MAX_KEYS = 5;

struct Node{
    //I am using a vector of pairs, I keep the IDs as ints and the Packets are all of the information of the slave
    vector<pair<int, Packet>> id_and_key;

    vector<Node*> children;
    Node* parent;

    Node();
    bool isLeaf() const;
};

class BTree{
private:
    Node* root;

public:
    BTree();
    //These are the main functions that will be implemented for the program to run.
    void insert(int record_id, Packet packet);

    void search(int record_id);
    void inorder();

private:
    //these are the helper functions to the main fucntions.
    //insert just inserts each Row of the Excel sheet into the tree with all the slave information
    void insertHelper(Node* node, int record_id, Packet packet);

    //splitNode handles overflow when the number of keys has exceeded N
    void splitNode(Node* parent, Node* node, Packet packet);

    //search just sorts through the tree and finds the desired ID
    Node* searchHelper(Node* node, int record_id);
    //inorder traversal does a traversal through each node and prints out the ID (We have made a comment on it as to
    //why we are not printing anything, so read that)
    void inorderTraversal(Node* node);
};

//checks if the desired node has any children
bool Node::isLeaf() const{
    return children.empty();
}

Node::Node(){
    parent = nullptr;
}

//insert an ID and packet into tree
void BTree::insert(int record_id, Packet packet){
    //if there is no node, make a new one and insert an ID and packet
    if (root == nullptr){
        root = new Node();
        root->id_and_key.push_back(make_pair(record_id, packet));
    }
    //otherwise call insert helper
    else{
        //note that if the # of entries has exceeded the max number of keys splitNode is called to handle splitting.
        if (root->id_and_key.size() > MAX_KEYS){
            Node* new_root = new Node();
            new_root->children.push_back(root);
            splitNode(new_root, root, packet);
            root = new_root;
        }
        insertHelper(root, record_id, packet);
    }
}

//calls search helper and prints if the ID is found, prints not found otherwise
void BTree::search(int record_id){
    Node* node = searchHelper(root, record_id);

    if(node != nullptr){
        cout << "Record with ID " << record_id << " found!" << endl;
    }
    else{
        cout << "Record with ID " << record_id << " not found." << endl;
    }
}

void BTree::inorder(){
    inorderTraversal(root);
}

BTree::BTree() {
    root = nullptr;
}

//called from the main method insert()
void BTree::insertHelper(Node* node, int record_id, Packet packet){
    //if the node is a leaf (has no children), then add a key (ID and packet)
    if (node->isLeaf()){
        node->id_and_key.push_back(make_pair(record_id, packet));
        //after inserting the key, sort the keys in the node by the ID of the keys.
        sort(node->id_and_key.begin(), node->id_and_key.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        if (node->id_and_key.size() > MAX_KEYS){
            Node* parent = node->parent;
            splitNode(parent, node, packet);
        }
    }
    else{
        size_t i = 0;
        while (i < node->id_and_key.size() && record_id > node->id_and_key.at(i).first){
            ++i;
        }
        insertHelper(node->children.at(i), record_id, packet);
    }
}

void BTree::splitNode(Node* parent, Node* node, Packet packet) {
    Node* new_node = new Node();
    int mid = MAX_KEYS / 2;
    int median = node->id_and_key[mid].first;

    new_node->id_and_key.assign(node->id_and_key.begin() + mid + 1, node->id_and_key.end());
    node->id_and_key.erase(node->id_and_key.begin() + mid, node->id_and_key.end());

    if (!node->isLeaf()) {
        new_node->children.assign(node->children.begin() + mid + 1, node->children.end());
        node->children.erase(node->children.begin() + mid + 1, node->children.end());

        for (auto child : new_node->children) {
            child->parent = new_node;
        }
    }

    if (parent != nullptr){
        size_t i = 0;
        while (i < parent->id_and_key.size() && median > parent->id_and_key.at(i).first) {
            ++i;
        }

        parent->id_and_key.insert(parent->id_and_key.begin() + i, make_pair(median, packet));
        parent->children.insert(parent->children.begin() + i + 1, new_node);

        new_node->parent = parent;
    }
    else{
        Node* new_root = new Node();
        new_root->id_and_key.push_back(make_pair(median, packet));
        new_root->children.push_back(node);
        new_root->children.push_back(new_node);

        node->parent = new_root;
        new_node->parent = new_root;

        root = new_root;
    }
    node->parent = parent;
}


Node *BTree::searchHelper(Node *node, int record_id){
    if(node == nullptr){
        return nullptr;
    }

    size_t i = 0;
    while(i < node->id_and_key.size() && record_id > node->id_and_key.at(i).first){
        i++;
    }

    if(i < node->id_and_key.size() && record_id == node->id_and_key.at(i).first){
        return node;
    }
    else if(node->isLeaf()){
        return nullptr;
    }
    else{
        return searchHelper(node->children.at(i), record_id);
    }
}

//for this program we are not ouputting the inorder traversal in order to keep the console not too crowded.
//the inorder traversal would print 9600 IDs which would make our menu driven program look bad. But here is the
//implementation
void BTree::inorderTraversal(Node *node){
    if (node != nullptr){
        if (!node->isLeaf()){
            for (size_t i = 0; i < node->children.size(); i++){
                inorderTraversal(node->children.at(i));

                if (i < node->id_and_key.size()) {
                    //cout << "ID: " << node->id_and_key.at(i).first << endl;
                }
            }
        }
        else{
            for (size_t i = 0; i < node->id_and_key.size(); i++){
                //cout << "ID: " << node->id_and_key.at(i).first << endl;
            }
        }
    }
}