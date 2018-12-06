/* NAME: Tammy Husnetdinova
CLASS: CSCI 2421-001
ASSIGNMENT: FINAL PROJECT
DUE DATE: 12/06/18
 */

//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implement

//I added a findAnotherNode function for fields that will have more than one result
//this would make sense when we are searching for something: some titles or names will reappear
//we want to user to see all their options/search finds for that title/name
//COLLABORATION NOTE: I discussed this heavily with Erik, who explained how to call the function recursively, in
//case we have more than one name pop up, and why it makes sense to add this to make life easier later
//right now, the original, provided findNode only finds the first instance of the field searched for
//and that's okay for some criterion, but we always want to check whether there are more records

//I also added a function to move a tree to a stack, which would then be called to move from one tree to another
//this would allow me to simply push the full stack of nodes of the original tree into a new tree (but sorted on a new key)
//COLLABORATION NOTE: I also discussed this logic with Erik, who provided the link to a pseudocode outline of how to do this
//the link is in the function itself


#ifndef BSTREEINT_H
#define BSTREEINT_H
#include <iostream>
#include <stack>
#include "Node.h"
using namespace std;

// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BSTree {
private:
    Node<DATATYPE, KEYTYPE> * root;
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
	void printInorder(Node<DATATYPE, KEYTYPE> * node);
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * findAnotherNode(Node<DATATYPE, KEYTYPE> * anotherNode, Node<DATATYPE, KEYTYPE> * originalNode, KEYTYPE key);
public:
    BSTree<DATATYPE, KEYTYPE>();
    ~BSTree<DATATYPE, KEYTYPE>();
    Node<DATATYPE, KEYTYPE> * Root() { return root; }
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;}
    void addNode(KEYTYPE key, DATATYPE &data);
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
    Node<DATATYPE, KEYTYPE> * findAnotherNode(Node<DATATYPE, KEYTYPE> *anotherNode, KEYTYPE key);
	void printInorder();
	void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key);
	Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
	Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);
	void treeToStack(stack<Node<DATATYPE, KEYTYPE>*> &sOut);
    void clearTree();
};

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
//#include "BSTree.h"

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::clearTree()
{
    freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
	//Student must fill in

	//if it's not the leaf, just return out of the if statement
    if(!leaf)
    {
        return;
    }//if

    //if the leaf is not left or right, then delete it
    if(leaf->Left() == nullptr && leaf->Right() == nullptr)
    {
        delete leaf;
    }//if
    else
    {
        //recursive call of the leaf's left
        if(leaf->Left())
        {
            freeNode(leaf->Left());
        }//if
        //recursive call of the leaf's right
        if(leaf->Right())
        {
            freeNode(leaf->Right());
        }//if
        //now delete the leaf
        delete leaf;
    }//else
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if(Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>();
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);
	}
	else
		addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
	//Student must fill in
	//Don't forget to set your key, Parent, then left or right
	//Based on the case you use you will addNode recursively to the left or right
 
	//First check if root is null
	if(Root() == nullptr)
	{	//make a new node
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>();
		//set the key and data
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		//set the root
		root->setParent(root);
	}//if
	//Otherwise
    //Check to see if the key is < the leaf's key
	else if(key < leaf->Key())
    {
	    // if left is not null then
	    if(leaf->Left() != nullptr)
        {
            //Add the node to the left (recursively)
            addNode(key,leaf->Left(), data);
        }
        else
        {
            // Otherwise make new node and attach it to the left
            //make a new node
            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>();
            //set the key and data
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setLeft(newNodePtr);
            newNodePtr->setParent(leaf);
        }
	}
    //Check to see if the key >= leaf's key
    else if(key >= leaf->Key())
    {
        // if leaf's right is not null then
        if(leaf->Right() != nullptr)
        {
            //Add the node to the right (recursively)
            addNode(key, leaf->Right(), data);
        } else
        {
            // Otherwise make new node and attach it to the right
            //make a new node
            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>();
            //set the key and data
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setRight(newNodePtr);
            newNodePtr->setParent(leaf);
        }
    }
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
	//Student must fill in
	// trap nullptr first in case we've hit the end unsuccessfully.
	// success base case
    //Greater than (Right), Less than (Left)
    if(node != nullptr)
    {
        if(node->Key() == key)
        {
            return node;
        }
        else if(node->Key() < key)
        {
            return findNode(key, node->Right());
        }
        else
        {
            return findNode(key, node->Left());
        }
    } else
        return nullptr;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
	printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
	//Student must fill in.  Use recursive algorithm.
	//Note that this prints using an Inorder, Depth-first search
	//but you may want to do something else when "visiting" the node....
	//like moving visited data to another data structure
	//Don't forget your base case!
	if(node != nullptr)
    {
		//print left node recursively
        printInorder(node->Left());

        //print itself
        node->Data().print();
        cout << endl;

        //print right node recursively
        printInorder(node->Right());
    }
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
	out << data.number << "\t" << data.name << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		aRoot->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findAnotherNode(Node<DATATYPE, KEYTYPE> *anotherNode, KEYTYPE key)
{
    //call private findAnotherNode
    return findAnotherNode(anotherNode, anotherNode, key);
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findAnotherNode(Node<DATATYPE, KEYTYPE> * anotherNode, Node<DATATYPE, KEYTYPE> * originalNode, KEYTYPE key)
{
    //if it's nullptr, then we have no more nodes with same info, return nothing
    if(anotherNode == nullptr)
    {
        return nullptr;
    }//if
    //else if that other node is not the key, also return nothing
    else if(anotherNode->Key() != key)
    {
        return nullptr;
    }//else if
    //else (we must have more additional nodes)
    else
    {
        //if another node is the key and it's not the original
        //there must only be one more that matches key
        if(anotherNode->Key() == key && anotherNode != originalNode)
        {
            return anotherNode;
        }//if
        //otherwise, there must be more than one additional node that matches the key
        //so we call the function recursively to keep finding more nodes that match key
        else
        {
            return findAnotherNode(anotherNode->Right(), originalNode, key);
        }//else
    }//else
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::treeToStack(stack<Node<DATATYPE, KEYTYPE>*> &sOut)
{
    //sources used:
    //https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

    //create an empty stack that we will be working on in this function
    stack<Node<DATATYPE, KEYTYPE>*> s;

    //make temp pointer to the root of the tree to access it
    //once we have the root, we have the whole tree
    //initialize current node as root
    Node<DATATYPE, KEYTYPE> *currentPtr;
    currentPtr = root;

    //if current isn't null or stack isn't empty
    while(currentPtr != nullptr || !s.empty())
    {
        while(currentPtr != nullptr)
        {
            //push currentPtr into the stack
            s.push(currentPtr);
            //set currentPtr = left until current is null
            currentPtr = currentPtr->Left();
        }

        //else currentPtr is nullptr
        currentPtr = s.top(); //currentPtr points to top of stack (first thing in the stack)
        //remove items from the stack one by one
        s.pop();
        sOut.push(currentPtr);

        //make sure to visit right subtree
        currentPtr = currentPtr->Right();
    }
}

#endif  //BST