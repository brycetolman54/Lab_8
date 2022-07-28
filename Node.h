//
// Created by bat20 on 7/25/2022.
//

#ifndef LAB_7_NODE_H
#define LAB_7_NODE_H

#include "NodeInterface.h"

class Node : public NodeInterface {
private:
    int value;
public:
    Node* leftChild;
    Node* rightChild;

    Node(int data) {
        value = data;
        leftChild = NULL;
        rightChild = NULL;
    }
    ~Node() {
        delete leftChild;
        delete rightChild;
        leftChild = NULL;
        rightChild = NULL;
    }

    /*
    * Returns the data that is stored in this node
    *
    * @return the data that is stored in this node.
    */
    int getData() const;

    /*
    * Returns the left child of this node or null if it doesn't have one.
    *
    * @return the left child of this node or null if it doesn't have one.
    */
    Node* getLeftChild() const;

    /*
    * Returns the right child of this node or null if it doesn't have one.
    *
    * @return the right child of this node or null if it doesn't have one.
    */
    Node* getRightChild() const;

};


#endif //LAB_7_NODE_H
