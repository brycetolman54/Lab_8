//
// Created by bat20 on 7/25/2022.
//

#include "Node.h"

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const {
    return value;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node* Node::getLeftChild() const {
    return leftChild;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node* Node::getRightChild() const {
    return rightChild;
}

int Node::getHeight() {
    return height;
}

void Node::updateHeight() {
    if(rightChild != NULL && leftChild != NULL) { // If it has both children
        if (rightChild->getHeight() > leftChild->getHeight()) {
            height = rightChild->getHeight() + 1;
        } else {
            height = leftChild->getHeight() + 1;
        }
    }
    else if(rightChild != NULL) { // If it only has the right child
        height = rightChild->getHeight() + 1;
    }
    else if(leftChild != NULL) { // If it only has the left child
        height = leftChild->getHeight() + 1;
    }
    else { // If it has no children
        height = 1;
    }
}

int Node::getBalance() {
    int rightHeight;
    int leftHeight;
    if(rightChild == NULL) {
        rightHeight = 0;
    }
    else {
        rightHeight = rightChild->height;
    }
    if(leftChild == NULL) {
        leftHeight = 0;
    }
    else {
        leftHeight = leftChild->height;
    }
    return rightHeight - leftHeight;
}