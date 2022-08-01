//
// Created by bat20 on 7/28/2022.
//

#ifndef LAB_8_AVL_H
#define LAB_8_AVL_H

#include <cstdlib>
#include <vector>
#include <iostream>
#include "AVLInterface.h"
#include "NodeInterface.h"
#include "Node.h"


class AVL : public AVLInterface {
private:
    Node* root;
    Node* current;
    vector<Node*> recursiveNodes;
public:
    AVL() {
        root = NULL;
        current = root;
    }
    ~AVL() {
        delete root;
    }

    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface

    /*
    * Returns the root node for this tree
    *
    * @return the root node for this tree.
    */
    Node* getRootNode() const;

    /*
    * Attempts to add the given int to the BST tree
    *
    * @return true if added
    * @return false if unsuccessful (i.e. the int is already in tree)
    */
    bool add(int data);

    /*
    * Attempts to remove the given int from the BST tree
    *
    * @return true if successfully removed
    * @return false if remove is unsuccessful(i.e. the int is not in the tree)
    */
    bool remove(int data);

    /*
    * Removes all nodes from the tree, resulting in an empty tree.
    */
    void clear();

    void Case1(Node*& node);

    void Case2(Node*& node, bool Root = false);

    void Case3(Node*& node, bool Root = false);

    void Case4(Node*& node, bool Root = false);

    void Case5(Node*& node, bool Root = false);

    void rightRotation(Node*& parent, bool side); // True = left, false = right

    void leftRotation(Node*& parent, bool side);

    void rootLeftRotation(Node*& n, Node*& k);

    void rootRightRotation(Node*& n, Node*& k);

    void checkBalance(Node*& parent, Node*& child);

    void checkRootBalance(Node*& parent);

    void updateAll(vector<Node*>& nodes);

    void printNodes(vector<Node*>& nodes);
};


#endif //LAB_8_AVL_H
