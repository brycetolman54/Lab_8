//
// Created by bat20 on 7/25/2022.
//

#include "BST.h"

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node* BST::getRootNode() const {
    return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data) {
    if(root == NULL) {
        root = new Node(data);
        current = root;
        return true;
    }
    if(current->getData() == data) {
        current = root;
        return false;
    }
    if(data > current->getData()) {
        if(current->rightChild == NULL) {
            current->rightChild = new Node(data);
            current = root;
            return true;
        }
        else {
            current = current->getRightChild();
            return add(data);
        }
    }
    if(data < current->getData()) {
        if(current->leftChild == NULL) {
            current->leftChild = new Node(data);
            current = root;
            return true;
        }
        else {
            current = current->getLeftChild();
            return add(data);
        }
    }
    return false;
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data) {
    if(data > current->getData()) { // If the data point is on the right side
        if(current->rightChild == NULL) { // If you reached a leaf without finding the data point
            current = root;
            return false;
        }
        if(data == current->rightChild->getData()) { // If the one on the right needs to be deleted
            if(current->rightChild->leftChild == NULL) { // If the one being deleted does not have a child on the left
                if(current->rightChild->rightChild == NULL) { // If the one being deleted has no children
                    Case1(current->rightChild);
                    return true;
                }
                else { // If the one being deleted has a child on the right
                    Case2(current->rightChild);
                    return true;
                }
            }
            else { // If the one being deleted does have a child on the left
                if(current->rightChild->rightChild == NULL) { // If the one being deleted does not have a child on the right
                    Case3(current->rightChild);
                    return true;
                }
                if(current->rightChild->leftChild->rightChild == NULL) { // If the child on the left has no children on the right
                    Case4(current->rightChild);
                    return true;
                }
                else { // If the child on the left has at least one child
                    Case5(current->rightChild);
                    return true;
                }
            }
        }
        else { // If the child on the right is not the one being deleted, but it is further down the line
            current = current->rightChild;
            return remove(data);
        }
    }
    else if(data < current->getData()) { // If the data point is on the left side
        if(current->leftChild == NULL) { // If you reached a leaf without finding the data point
            current = root;
            return false;
        }
        if(data == current->leftChild->getData()) { // If the one on the left needs to be deleted
            if(current->leftChild->leftChild == NULL) { // If the one being deleted does not have a child on the left
                if(current->leftChild->rightChild == NULL) { // If the one being deleted has no children
                    Case1(current->leftChild);
                    return true;
                }
                else { // If the one being deleted has a child on the right
                    Case2(current->leftChild);
                    return true;
                }
            }
            else { // If the one being deleted does have a child on the left
                if(current->leftChild->rightChild == NULL) { // If the one being deleted does not have a child on the right
                    Case3(current->leftChild);
                    return true;
                }
                if(current->leftChild->leftChild->rightChild == NULL) { // If the child on the left has no children on the right
                    Case4(current->leftChild);
                    return true;
                }
                else { // If the child on the left has at least one child
                    Case5(current->leftChild);
                    return true;
                }
            }
        }
        else { // If the child on the left is not the one being deleted, but it is further down the line
            current = current->leftChild;
            return remove(data);
        }
    }
    else if(current->getData() == data){ // If the data point is the root
        if(current->rightChild == NULL && current->leftChild == NULL) { // If it is the last node
            Case1(root);
            return true;
        }
        else if(current->leftChild == NULL) { // If the one being deleted does not have a child on the left
            Case2(root);
            return true;
        }
        else { // If the one being deleted does have a child on the left
            if(current->leftChild->rightChild == NULL) { // If the child on the left has no children on the right
                Case4(root);
                return true;
            }
            else { // If the child on the left has at least one child on the right
                Case5(root);
                return true;
            }
        }
    }
    return false;
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear() {
    delete root;
    root = NULL;
}

void BST::Case1(Node*& node) {
    delete node;
    node = NULL;
    current = root;
}

void BST::Case2(Node*& node) {
    Node* holder = node;
    node = node->rightChild;
    holder->rightChild = NULL;
    delete holder;
    current = root;
}

void BST::Case3(Node*& node) {
    Node* holder = node;
    node = node->leftChild;
    holder->leftChild = NULL;
    delete holder;
    current = root;
}

void BST::Case4(Node*& node) {
    node->leftChild->rightChild = node->rightChild;
    Node* holder = node;
    node = node->leftChild;
    holder->rightChild = NULL;
    holder->leftChild = NULL;
    delete holder;
    current = root;
}

void BST::Case5(Node*& node) {
    Node* child = node->leftChild;
    Node* child2 = node->leftChild->rightChild;
    while(child2->rightChild != NULL) {
        child = child->rightChild;
        child2 = child2->rightChild;
    }
    child->rightChild = child2->leftChild;
    child2->leftChild = node->leftChild;
    child2->rightChild = node->rightChild;
    Node* holder = node;
    node = child2;
    holder->rightChild = NULL;
    holder->leftChild = NULL;
    delete holder;
    current = root;
}