#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree() {}

const ptr RedBlackTree::getRoot() const
{
	return root;
}

ptr RedBlackTree::insert(int data)
{
	ptr newnodePtr = new node(data);
	if (!root)
	{
		root = newnodePtr;
		root->color = 0; // set root color as black

		return newnodePtr;
	}
	insert(root, newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{
	// choose direction

	if (start->data < newnodePtr->data)
	{
		if (start->right == NULL)
		{
			start->right = newnodePtr;
			newnodePtr->color = 1;
			newnodePtr->parent = start->right;
		}
		else
			RedBlackTree::insert(start->right, newnodePtr);
		if (start->color == 1)
			RedBlackTree::fixup(start->right);
	}
	else if (start->data > newnodePtr->data)
	{
		if (start->left == NULL)
		{
			start->left = newnodePtr;
			newnodePtr->color = 1;
			newnodePtr->parent = start->left;
		}
		else
			RedBlackTree::insert(start->left, newnodePtr);
		if (start->color == 1)
			RedBlackTree::fixup(start->left);
	}
	// recurse down the tree

	return;
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string &prefix, bool isLeftChild) const
{
	if (!start)
		return;

	std::cout << prefix;
	std::cout << (isLeftChild ? "|--" : "|__");
	// print the value of the node
	std::cout << start->data << "(" << start->color << ")" << std::endl;
	// enter the next tree level - left and right branch
	printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
	printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(ptr loc)
{
	ptr temp = loc->parent->right;
	if (loc->parent->right == NULL)
	{
		loc->parent->right = loc;
		loc->parent->left = NULL;
	}
	else
	{
		loc->parent->right = loc;
		loc->parent->left = temp;
	}
	loc->data = loc->data + loc->parent->data;
	loc->parent->data = loc->data - loc->parent->data;
	loc->data = loc->data - loc->parent->data;
	if (loc->left == NULL && loc->parent->left != NULL)
	{
		loc->left = loc->parent->left;
		loc->left->parent = loc;
		loc->parent->left = NULL;
	}
	else if (loc->parent->left == NULL && loc->left != NULL)
	{
		loc->parent->left = loc->left;
		loc->left->parent = loc->parent;
		loc->left = NULL;
	}
	else if (loc->parent->left != NULL && loc->left != NULL)
	{
		temp = loc->left;
		loc->left = loc->parent->left;
		loc->parent->left = temp;
		loc->left->parent = loc;
		loc->parent->left->parent = loc->parent;
	}
	temp = loc->left;
	loc->left = loc->right;
	loc->right = temp;
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{
	ptr temp = loc->parent->left;
	loc->parent->left = loc;
	loc->parent->right = temp;
	loc->data = loc->data + loc->parent->data;
	loc->parent->data = loc->data - loc->parent->data;
	loc->data = loc->data - loc->parent->data;
	if (loc->right == NULL && loc->parent->right != NULL)
	{
		loc->right = loc->parent->right;
		loc->right->parent = loc;
		loc->parent->right = NULL;
	}
	else if (loc->parent->right == NULL && loc->right != NULL)
	{
		loc->parent->right = loc->right;
		loc->right->parent = loc->parent;
		loc->right = NULL;
	}
	else if (loc->parent->right != NULL && loc->right != NULL)
	{
		temp = loc->right;
		loc->right = loc->parent->right;
		loc->parent->right = temp;
		loc->right->parent = loc;
		loc->parent->right->parent = loc->parent;
	}
	temp = loc->right;
	loc->right = loc->left;
	loc->left = temp;
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{
	if (loc->parent->parent->right == loc->parent)
	{
		if (loc->parent->parent->left == NULL || loc->parent->parent->left->color == 0)
		{
			if (loc->parent->left == loc)
				rightrotate(loc);
			leftrotate(loc->parent);
			return;
		}
		if (loc->parent->parent->left->color == 1)
		{
			if (loc->parent->parent->left != NULL)
				loc->parent->parent->left->color = 0;
			loc->parent->color = 0;
			if (loc->parent->parent->parent == NULL)
			{
				loc->parent->parent->color = 0;
			}
			else if (loc->parent->parent->parent->color == 1)
			{
				fixup(loc->parent->parent);
			}
			else
			{
				loc->parent->parent->color = 1;
			}
			return;
		}
	}
	else
	{
		if (loc->parent->parent->right == NULL || loc->parent->parent->right->color == 0)
		{
			if (loc->parent->right == loc)
				leftrotate(loc);
			rightrotate(loc->parent);
			return;
		}
		if (loc->parent->parent->right->color == 1)
		{
			if (loc->parent->parent->right != NULL)
				loc->parent->parent->right->color = 0;
			loc->parent->color = 0;
			if (loc->parent->parent->parent == NULL)
			{
				loc->parent->parent->color = 0;
			}
			else if (loc->parent->parent->parent->color == 1)
			{
				fixup(loc->parent->parent);
			}
			else
			{
				loc->parent->parent->color = 1;
			}
			return;
		}
	}
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const
{
	if (!start)
		return;

	inorder(start->left);
	std::cout << start->data << " ";
	inorder(start->right);
}

// driver code
int main()
{
	int n;
	std ::cin >> n;
	assert(n < 10000 && n >= 0);
	int a[10000];
	RedBlackTree tree;

	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];

		// allocating memory to the node and initializing:
		// 1. color as red
		// 2. parent, left and right pointers as NULL
		// 3. data as i-th value in the array

		// calling function that performs rbt insertion of
		// this newly created node
		auto newnodePtr = tree.insert(a[i]);

		// calling function to preserve properties of rb
		// tree
	}
	tree.printRBT(tree.getRoot());

	return 0;
}
