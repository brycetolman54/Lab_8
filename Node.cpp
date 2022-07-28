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