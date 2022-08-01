//
// Created by bat20 on 7/28/2022.
//

#include "AVL.h"

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node* AVL::getRootNode() const {
    return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool AVL::add(int data) {
    if(recursiveNodes.size() == 0) {
        recursiveNodes.emplace_back(root);
    }
    if(root == NULL) {
        root = new Node(data);
        current = root;
        recursiveNodes.clear();
        return true;
    }
    if(current->getData() == data) {
        current = root;
        recursiveNodes.clear();
        return false;
    }
    if(data > current->getData()) {
        if(current->rightChild == NULL) {
            current->rightChild = new Node(data);
            recursiveNodes.emplace_back(current->rightChild);
            updateAll(recursiveNodes);
            current = root;
            return true;
        }
        else {
            current = current->getRightChild();
            recursiveNodes.emplace_back(current);
            return add(data);
        }
    }
    if(data < current->getData()) {
        if(current->leftChild == NULL) {
            current->leftChild = new Node(data);
            recursiveNodes.emplace_back(current->leftChild);
            updateAll(recursiveNodes);
            current = root;
            return true;
        }
        else {
            current = current->getLeftChild();
            recursiveNodes.emplace_back(current);
            return add(data);
        }
    }
    recursiveNodes.clear();
    return false;
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
// Add the functions that you created in the appropriate places in the remove function to update the tree with every removal
bool AVL::remove(int data) {
    if(data > current->getData()) { // If the data point is on the right side
        if(recursiveNodes.size() == 0) {
            recursiveNodes.emplace_back(root);
        }
        if(current->rightChild == NULL) { // If you reached a leaf without finding the data point
            current = root;
            recursiveNodes.clear();
            return false;
        }
        if(data == current->rightChild->getData()) { // If the one on the right needs to be deleted
            if(current->rightChild->leftChild == NULL) { // If the one being deleted does not have a child on the left
                if(current->rightChild->rightChild == NULL) { // If the one being deleted has no children
                    Case1(current->rightChild);
                    updateAll(recursiveNodes);
                    return true;
                }
                else { // If the one being deleted has a child on the right
                    Case2(current->rightChild);
                    updateAll(recursiveNodes);
                    return true;
                }
            }
            else { // If the one being deleted does have a child on the left
                if(current->rightChild->rightChild == NULL) { // If the one being deleted does not have a child on the right
                    Case3(current->rightChild);
                    updateAll(recursiveNodes);
                    return true;
                }
                if(current->rightChild->leftChild->rightChild == NULL) { // If the child on the left has no children on the right
                    Case4(current->rightChild);
                    updateAll(recursiveNodes);
                    return true;
                }
                else { // If the child on the left has at least one child
                    // Save a spot for the eventual node
                    // In the function:
                    //      Push back the leftChild of the node (before the while loop)
                    //      For each while loop, add the new child2 to the vector (inside the loop)
                    //      Put the last child2 (the one you move) to the blank spot in the vector that you saved
                    Case5(current->rightChild);
                    updateAll(recursiveNodes);
                    return true;
                }
            }
        }
        else { // If the child on the right is not the one being deleted, but it is further down the line
            current = current->rightChild;
            recursiveNodes.emplace_back(current);
            return remove(data);
        }
    }
    else if(data < current->getData()) { // If the data point is on the left side
        if(recursiveNodes.size() == 0) {
            recursiveNodes.emplace_back(root);
        }
        if(current->leftChild == NULL) { // If you reached a leaf without finding the data point
            current = root;
            recursiveNodes.clear();
            return false;
        }
        if(data == current->leftChild->getData()) { // If the one on the left needs to be deleted
            if(current->leftChild->leftChild == NULL) { // If the one being deleted does not have a child on the left
                if(current->leftChild->rightChild == NULL) { // If the one being deleted has no children
                    Case1(current->leftChild);
                    updateAll(recursiveNodes);
                    return true;
                }
                else { // If the one being deleted has a child on the right
                    Case2(current->leftChild);
                    updateAll(recursiveNodes);
                    return true;
                }
            }
            else { // If the one being deleted does have a child on the left
                if(current->leftChild->rightChild == NULL) { // If the one being deleted does not have a child on the right
                    Case3(current->leftChild);
                    updateAll(recursiveNodes);
                    return true;
                }
                if(current->leftChild->leftChild->rightChild == NULL) { // If the child on the left has no children on the right
                    Case4(current->leftChild);
                    updateAll(recursiveNodes);
                    return true;
                }
                else { // If the child on the left has at least one child
                    Case5(current->leftChild);
                    updateAll(recursiveNodes);
                    return true;
                }
            }
        }
        else { // If the child on the left is not the one being deleted, but it is further down the line
            current = current->leftChild;
            recursiveNodes.emplace_back(current);
            return remove(data);
        }
    }
    else if(current->getData() == data){ // If the data point is the root
        if(current->rightChild == NULL && current->leftChild == NULL) { // If it is the last node
            Case1(root);
            updateAll(recursiveNodes);
            return true;
        }
        else if(current->leftChild == NULL) { // If the one being deleted does not have a child on the left
            Case2(root, true);
            updateAll(recursiveNodes);
            return true;
        }
        else { // If the one being deleted does have a child on the left
            if(current->leftChild->rightChild == NULL) { // If the child on the left has no children on the right
                Case4(root, true);
                updateAll(recursiveNodes);
                return true;
            }
            else { // If the child on the left has at least one child on the right
                Case5(root, true);
                updateAll(recursiveNodes);
                return true;
            }
        }
    }
    recursiveNodes.clear();
    return false;
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void AVL::clear() {
    delete root;
    root = NULL;
}

void AVL::Case1(Node*& node) {
    delete node;
    node = NULL;
    current = root;
}

void AVL::Case2(Node*& node, bool Root) {
    Node* holder = node;
    node = node->rightChild;
    holder->rightChild = NULL;
    delete holder;
    if(Root) {
        root = node;
    }
    current = root;
    recursiveNodes.emplace_back(node);
}

void AVL::Case3(Node*& node, bool Root) {
    Node* holder = node;
    node = node->leftChild;
    holder->leftChild = NULL;
    delete holder;
    if(Root) {
        root = node;
    }
    current = root;
    recursiveNodes.emplace_back(node);
}

void AVL::Case4(Node*& node, bool Root) {
    node->leftChild->rightChild = node->rightChild;
    Node* holder = node;
    node = node->leftChild;
    holder->rightChild = NULL;
    holder->leftChild = NULL;
    delete holder;
    if(Root) {
        root = node;
    }
    current = root;
    recursiveNodes.emplace_back(node);
}

void AVL::Case5(Node*& node, bool Root) {
    int place = recursiveNodes.size();
    recursiveNodes.emplace_back(nullptr);
    Node* child = node->leftChild;
    recursiveNodes.emplace_back(child);
    Node* child2 = node->leftChild->rightChild;
    while(child2->rightChild != NULL) {
        recursiveNodes.emplace_back(child2);
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
    if(Root) {
        root = node;
    }
    current = root;
    recursiveNodes.at(place) = node;
}

void AVL::rightRotation(Node*& parent, bool side) {
    if(side) {
        Node* n = parent->leftChild;
        Node* k = n->leftChild;
        n->leftChild = k->rightChild;
        parent->leftChild = k;
        k->rightChild = n;
        n->updateHeight();
        k->updateHeight();
        parent->updateHeight();
    }
    else {
        Node* n = parent->rightChild;
        Node* k = n->leftChild;
        n->leftChild = k->rightChild;
        parent->rightChild = k;
        k->rightChild = n;
        n->updateHeight();
        k->updateHeight();
        parent->updateHeight();
    }
}

void AVL::leftRotation(Node*& parent, bool side) {
    if(side) {
        Node* n = parent->leftChild;
        Node* k = n->rightChild;
        n->rightChild = k->leftChild;
        parent->leftChild = k;
        k->leftChild = n;
        n->updateHeight();
        k->updateHeight();
        parent->updateHeight();
    }
    else {
        Node* n = parent->rightChild;
        Node* k = n->rightChild;
        n->rightChild = k->leftChild;
        parent->rightChild = k;
        k->leftChild = n;
        n->updateHeight();
        k->updateHeight();
        parent->updateHeight();
    }
}

void AVL::rootLeftRotation(Node*& n, Node*& k) {
    Node* holder = k;
    n->rightChild = k->leftChild;
    holder->leftChild = n;
    root = holder;
    n->updateHeight();
    root->updateHeight();
    current = root;
}

void AVL::rootRightRotation(Node*& n, Node*& k) {
    Node* holder = k;
    n->leftChild = k->rightChild;
    holder->rightChild = n;
    root = holder;
    n->updateHeight();
    root->updateHeight();
    current = root;
}

void AVL::checkBalance(Node*& parent, Node*& child) {
    bool side = false;
    if(parent->leftChild == child) { // Find out what side the child is on for the rotation functions
        side = true;
    }
    if(child->rightChild == NULL && child->leftChild == NULL) { // If the child has no children, no balance is needed
        return;
    }
    else if(child->getBalance() == -2 && child->leftChild->getBalance() == 1) { // First case double rotation (left,right)
        leftRotation(child, true);
        rightRotation(parent, side);
    }
    else if(child->getBalance() == 2 && child->rightChild->getBalance() == -1) { // Second case double rotation (right,left)
        rightRotation(child, false);
        leftRotation(parent, side);
    }
    else if(child->getBalance() == -2) { // First case single rotation (right)
        rightRotation(parent, side);
    }
    else if(child->getBalance() == 2) { // Second case single rotation (left)
        leftRotation(parent, side);
    }
}

void AVL::checkRootBalance(Node*& parent) {
    if(parent->rightChild == NULL && parent->leftChild == NULL) { // No children, no balance needed
        return;
    }
    else if(parent->getBalance() == -2 && parent->leftChild->getBalance() == 1) { // First case double rotation (left, right)
        leftRotation(parent, true);
        rootRightRotation(parent,parent->leftChild);
    }
    else if(parent->getBalance() == 2 && parent->rightChild->getBalance() == -1) { // Second case double rotation (right, left)
        rightRotation(parent, false);
        rootLeftRotation(parent, parent->rightChild);
    }
    else if(parent->getBalance() == -2) { // First case single rotation (right)
        rootRightRotation(parent, parent->leftChild);
    }
    else if(parent->getBalance() == 2) { // Second case single rotation (left)
        rootLeftRotation(parent, parent->rightChild);
    }
}

void AVL::updateAll(vector<Node*>& nodes) {
    while(!nodes.empty()) {
        nodes.back()->updateHeight();
        if(nodes.size() != 1) {
            checkBalance(nodes.at(nodes.size() - 2), nodes.back());
        }
        else {
            checkRootBalance(nodes.back());
        }
        nodes.pop_back();
    }
}

void AVL::printNodes(vector<Node*>& nodes) {
    for(auto i : nodes) {
        cout << i->getData() << " ";
    }
}