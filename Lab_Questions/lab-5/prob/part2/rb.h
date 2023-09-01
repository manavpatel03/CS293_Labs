/*
Mr KG, finds red-black trees very pointless and unnecessarily difficult. 
Hence, he turns his attention to 2-3-4 trees. 
Our job, in this part of the lab, is to show Mr. KG that red-black trees are just as powerful as 2-3-4 trees.

So, what is a 2-3-4 tree?
A 2-3-4 tree (also called a 2-4 tree) is a self-balancing data structure.
The numbers mean a tree where every node with children (internal node) has either 
two, three, or four child nodes:

- 2-node has one data element, and if internal, has two child nodes;
- 3-node has two data elements, and if internal, has three child nodes;
- 4-node has three data elements, and if internal, has four child nodes;

The key properties we consider are as follows:
Every node (leaf or internal) is a 2-node, 3-node or a 4-node, and holds one, two, or three data elements, respectively.
All leaves are at the same depth (the bottom level). (Path from root to any leaf is of same length)
All data is kept in sorted order (within a node as well as in the entire tree), much like a binary search tree

This would be a good time to think about how insertions (and if you're feeling bold, deletions) happen in 2-3-4 trees.
Some of you may think, at this stage, that 2-3-4 trees are more organised than red black trees
while others may believe red black trees have a colourful edge to them (no pun intended).

But here is the key idea we will explore.
2-3-4 trees are isomorphic to red–black trees, meaning that they are EQUIVALENT data structures. 
(What does even equivalence of data structures mean?)
In other words, for every 2-3-4 tree, there exists at least one and at most one red–black tree 
with data elements in the same order. 
Moreover, insertion and deletion operations on 2–3–4 trees that cause node expansions, 
splits and merges are equivalent to the color-flipping and rotations in red–black trees.

This mind blowing result allows us to implement one as the other. 
Hence, instead of implementing a 2-3-4 tree from scratch, which is quite difficult,
let us exploit the idea that red black trees are equivalent to 2-3-4 trees
and the fact that we have an implementation of red black trees (cue part 1),
and implement a 2-3-4 tree as a red black tree.

The previous part of the lab has been reused here. 
Reuse your (hopefully) working implementation of red black trees to make a 2-3-4 tree.
The 2-3-4 tree class has an insert, convert and the constructor to be implemented only
while the only data member is a red-black tree. 

The insert function inserts an element into our 2-3-4 tree, such that all properties above are satisfied
The convert function returns the structural 2-3-4 tree where every node is either a 2-node,3-node or 4-node.
- Keys will be distinct for insertion

Hence, for all practical and theoretical purposes,
can we use red black trees and 2-3-4 trees interchangeably?

More Reading Material: https://azrael.digipen.edu/~mmead/www/Courses/CS280/Trees-Mapping2-3-4IntoRB.html

*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cassert>

// Structure to represent each
// node in a red-black tree
struct node {
	int d; // data
	int c; // 1-red, 0-black
	struct node* p; // parent
	struct node* r; // right-child
	struct node* l; // left child
};

class RedBlackTree
{
    // global root for the entire tree
    struct node* root;

    public:
    // Constructor
    RedBlackTree();

    // Helper Update Functions
    struct node* getRoot();
    void setRoot(struct node* newroot);

    // function to perform BST insertion of a node
    struct node* insert(struct node* trav,
                        struct node* temp);

    // Credits to Adrian Schneider
    // Function to pretty print the tree
    void printRBT(const std::string& prefix, bool isLeft);

    // Function performing right rotation
    // of the passed node
    void rightrotate(struct node* temp);

    // Function performing left rotation
    // of the passed node
    void leftrotate(struct node* temp);

    // This function fixes violations
    // caused by BST insertion
    void fixup(struct node* root, struct node* pt);

    // Function to print inorder traversal
    // of the fixated tree
    void inorder(struct node* trav);

};

struct BigNode
{
    // A, B and C are the actual data values in the node (Default Value = -1)		
    int A;
    int B;
    int C;

    // Child pointers (Default Value = NULL)
    BigNode *L, *M1, *M2, *R; 

    BigNode();
};

class TwoThreeFourTree
{
    RedBlackTree* tree;

    public:
    TwoThreeFourTree();
    void insert(int key);
    struct BigNode* convert();


};
