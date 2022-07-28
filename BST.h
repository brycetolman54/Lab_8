//
// Created by bat20 on 7/25/2022.
//

#ifndef LAB_7_BST_H
#define LAB_7_BST_H

#include "BSTInterface.h"
#include "Node.h"


class BST : public BSTInterface {
private:
    Node* root;
    Node* current;
public:
    BST() {
        root = NULL;
        current = root;
    }
    ~BST() {
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

    void Case2(Node*& node);

    void Case3(Node*& node);

    void Case4(Node*& node);

    void Case5(Node*& node);

};


#endif //LAB_7_BST_H
