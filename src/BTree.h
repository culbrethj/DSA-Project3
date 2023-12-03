#include <iostream>
#include <vector>
#include <algorithm>
#include "Packet.h"

using namespace std;

const int MAX_KEYS = 5;

struct Node{
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
    void insert(int record_id, Packet packet);

    void search(int record_id);
    void inorder();

private:
    void insertHelper(Node* node, int record_id, Packet packet);

    void splitNode(Node* parent, Node* node, Packet packet);

    Node* searchHelper(Node* node, int record_id);
    void inorderTraversal(Node* node);
};

bool Node::isLeaf() const{
    return children.empty();
}

Node::Node(){
    parent = nullptr;
}

void BTree::insert(int record_id, Packet packet){
    if (root == nullptr){
        root = new Node();
        root->id_and_key.push_back(make_pair(record_id, packet));
    }
    else{
        if (root->id_and_key.size() >= MAX_KEYS){
            Node* new_root = new Node();
            new_root->children.push_back(root);
            splitNode(new_root, root, packet);
            root = new_root;
        }
        insertHelper(root, record_id, packet);
    }
}

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

void BTree::insertHelper(Node *node, int record_id, Packet packet){
    if (node->isLeaf()){
        node->id_and_key.push_back(make_pair(record_id, packet));
        sort(node->id_and_key.begin(), node->id_and_key.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
    }
    else{
        size_t i = 0;
        while (i < node->id_and_key.size() && record_id > node->id_and_key.at(i).first){
            i++;
        }
        if (i < node->children.size() && node->children.at(i)->id_and_key.size() >= MAX_KEYS){
            splitNode(node, node->children.at(i), packet);
            if (record_id > node->id_and_key.at(i).first){
                i++;
            }
        }
        insertHelper(node->children.at(i), record_id, packet);
    }
}

void BTree::splitNode(Node *parent, Node *node, Packet packet){
    Node* new_node = new Node();
    int mid = MAX_KEYS / 2;
    int median = node->id_and_key[mid].first;

    new_node->id_and_key.assign(node->id_and_key.begin() + mid + 1, node->id_and_key.end());
    node->id_and_key.erase(node->id_and_key.begin() + mid, node->id_and_key.end());

    if (!node->isLeaf()){
        new_node->children.assign(node->children.begin() + mid + 1, node->children.end());
        node->children.erase(node->children.begin() + mid + 1, node->children.end());
    }

    if (parent != nullptr) {
        vector<int> ids;
        for (size_t i = 0; i < parent->id_and_key.size(); i++) {
            ids.push_back(parent->id_and_key.at(i).first);
        }

        auto it = std::upper_bound(ids.begin(), ids.end(), median);
        int pos = it - ids.begin();

        parent->id_and_key.insert(parent->id_and_key.begin() + pos, std::make_pair(median, packet));
        parent->children.insert(parent->children.begin() + pos + 1, new_node);

        new_node->parent = parent;
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

void BTree::inorderTraversal(Node *node){
    if (node != nullptr){
        if (!node->isLeaf()){
            for (size_t i = 0; i < node->children.size(); i++){
                inorderTraversal(node->children.at(i));

                if (i < node->id_and_key.size()) {
                    cout << "ID: " << node->id_and_key.at(i).first << ", State: " << node->id_and_key.at(i).second.buyer_state << " " << endl;
                }
            }
        }
        else{
            for (size_t i = 0; i < node->id_and_key.size(); i++){
                cout << "ID: " << node->id_and_key.at(i).first << ", State: " << node->id_and_key.at(i).second.buyer_state << " " << endl;
            }
        }
    }
}