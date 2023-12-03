#include <iostream>
#include <vector>
#include <algorithm>
#include "Packet.h"

using namespace std;

const int MAX_KEYS = 5;

struct Node{
    vector<int> record_ids;
    vector<Packet> packets;
    Packet data;

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

    void splitNode(Node* parent, Node* node, int index);

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
        root->record_ids.push_back(record_id);
        root->packets.push_back(packet);
        root->data = packet;
    }
    else{
        if (root->record_ids.size() >= MAX_KEYS){
            Node* new_root = new Node();
            new_root->children.push_back(root);
            splitNode(new_root, root, 0);
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
        node->record_ids.push_back(record_id);
        node->packets.push_back(packet);
        sort(node->record_ids.begin(), node->record_ids.end());
    }
    else{
        int i = 0;
        while (i < node->record_ids.size() && record_id > node->record_ids.at(i)){
            i++;
        }
        if (i < node->children.size() && node->children.at(i)->record_ids.size() >= MAX_KEYS){
            splitNode(node, node->children.at(i), i);
            if (record_id > node->record_ids.at(i)){
                i++;
            }
        }
        insertHelper(node->children.at(i), record_id, packet);
    }
}

void BTree::splitNode(Node *parent, Node *node, int index){
    Node* new_node = new Node();
    int mid = MAX_KEYS / 2;
    int median = node->record_ids[mid];

    new_node->record_ids.assign(node->record_ids.begin() + mid + 1, node->record_ids.end());
    node->record_ids.erase(node->record_ids.begin() + mid, node->record_ids.end());

    if (!node->isLeaf()){
        new_node->children.assign(node->children.begin() + mid + 1, node->children.end());
        node->children.erase(node->children.begin() + mid + 1, node->children.end());
    }

    if (parent != nullptr){
        auto it = std::upper_bound(parent->record_ids.begin(), parent->record_ids.end(), median);
        int pos = it - parent->record_ids.begin();

        parent->record_ids.insert(parent->record_ids.begin() + pos, median);
        parent->children.insert(parent->children.begin() + pos + 1, new_node);

        new_node->parent = parent;
    }
    node->parent = parent;
}


Node *BTree::searchHelper(Node *node, int record_id){
    if(node == nullptr){
        return nullptr;
    }

    int i = 0;
    while(i < node->record_ids.size() && record_id > node->record_ids.at(i)){
        i++;
    }

    if(i < node->record_ids.size() && record_id == node->record_ids.at(i)){
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
            for (int i = 0; i < node->children.size(); i++){
                inorderTraversal(node->children.at(i));

                if (i < node->record_ids.size()){
                    cout << node->record_ids.at(i) << " ";
                }
            }
        }
        else{
            for (int i = 0; i < node->record_ids.size(); i++){
                cout << node->record_ids.at(i) << " ";
            }
        }
    }
}

//int main(){
//    BTree btree;
//
//    btree.insert(1, "Country1", "Buyer1", "Origin1", "State1", "SellerCountry1", "Seller1", "SellerOrigin1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", "5", 10, "Credit", 80, 1000);
//    btree.insert(2, "Country2", "Buyer2", "Origin2", "State2", "SellerCountry2", "Seller2", "SellerOrigin2", "SellerState2", 25, "Female", "Slave2", "White", "2023-01-02", "8", 5, "Cash", 90, 1200);
//    btree.insert(5000, "Country3", "Buyer3", "Origin3", "State3", "SellerCountry3", "Seller3", "SellerOrigin3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", "10", 15, "Credit", 85, 800);
//    btree.insert(9600, "Country1", "Buyer1", "Origin1", "State1", "SellerCountry1", "Seller1", "SellerOrigin1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", "5", 10, "Credit", 80, 1000);
//    btree.insert(2000, "Country2", "Buyer2", "Origin2", "State2", "SellerCountry2", "Seller2", "SellerOrigin2", "SellerState2", 25, "Female", "Slave2", "White", "2023-01-02", "8", 5, "Cash", 90, 1200);
//    btree.insert(1221, "Country3", "Buyer3", "Origin3", "State3", "SellerCountry3", "Seller3", "SellerOrigin3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", "10", 15, "Credit", 85, 800);
//    btree.insert(8411, "Country1", "Buyer1", "Origin1", "State1", "SellerCountry1", "Seller1", "SellerOrigin1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", "5", 10, "Credit", 80, 1000);
//    btree.insert(6501, "Country2", "Buyer2", "Origin2", "State2", "SellerCountry2", "Seller2", "SellerOrigin2", "SellerState2", 25, "Female", "Slave2", "White", "2023-01-02", "8", 5, "Cash", 90, 1200);
//    btree.insert(10, "Country3", "Buyer3", "Origin3", "State3", "SellerCountry3", "Seller3", "SellerOrigin3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", "10", 15, "Credit", 85, 800);
//
//    btree.inorder();
//
//    int search_id = 10;
//    btree.search(search_id);
//
//    return 0;
//}