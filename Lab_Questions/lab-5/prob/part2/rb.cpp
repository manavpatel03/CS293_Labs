#include "rb.h"

RedBlackTree::RedBlackTree()
{
	root = NULL;
}

struct node* RedBlackTree::getRoot()
{
	return root;
};

void RedBlackTree::setRoot(struct node* newroot)
{
	root = newroot;
}

// function to perform RBT insertion of a node
struct node* RedBlackTree::insert(struct node* trav,
					struct node* temp)
{
	// If the tree is empty,
	// return a new node

	// Otherwise recur down the tree
	

	// Return the (unchanged) node pointer
	return trav;
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(const std::string& prefix, bool isLeft)
{
    if( root != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "|__" );

        // print the value of the node
        std::cout << root->d << "(" << root->c << ")" << std::endl;
        node *curr = root;
        root = root->l;
        // enter the next tree level - left and right branch
        printRBT( prefix + (isLeft ? "│   " : "    "), true);
        root = curr->r;
        printRBT( prefix + (isLeft ? "│   " : "    "), false);
        root = curr;
    }
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(struct node* temp)
{
	
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(struct node* temp)
{
	
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(struct node* root, struct node* pt)
{
	
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(struct node* trav)
{
	if (trav == NULL)
		return;
	inorder(trav->l);
	printf("%d ", trav->d);
	inorder(trav->r);
}

BigNode::BigNode()
{
	A = -1;
	B = -1;
	C = -1;
	L = NULL;
	M1 = NULL;
	M2 = NULL;
    R = NULL;
}

TwoThreeFourTree::TwoThreeFourTree()
{
	tree = new RedBlackTree();
}

void TwoThreeFourTree::insert(int key)
{
	
}

struct BigNode* TwoThreeFourTree::convert()
{
	
}

void TTF(BigNode* root)
{
	if (!root)
        return;

    if (root->L) {
        TTF(root->L);
    }

    if (root->A != -1) {
        std::cout << root->A << " ";
    }

    if (root->M1) {
        TTF(root->M1);
    }

    if (root->B != -1) {
        std::cout << root->B << " ";
    }

    if (root->M2) {
        TTF(root->M2);
    }

    if (root->C != -1) {
        std::cout << root->C << " ";
    }

    if (root->R) {
        TTF(root->R);
    }
}

// driver code
int main()
{
	int n = 7;
	std :: cin >> n;
	int a[10000];
	TwoThreeFourTree* tree = new TwoThreeFourTree();

	for (int i = 0; i < n; i++) {
		std :: cin >> a[i];
		tree->insert(a[i]);
	}

	BigNode* newroot = tree->convert();
	TTF(newroot);
        std::cout<<std::endl;

	return 0;
}
