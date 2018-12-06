/* NAME: Tammy Husnetdinova
CLASS: CSCI 2421-001
ASSIGNMENT: FINAL PROJECT
DUE DATE: 12/06/18
 */

//To be used in conjunction with BSTree.h and BSTree.hpp
//If you modify this, please add your name and list any changes that you made
	//I made no changes to this file
#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
#include "Actor.h"
#include "Movie.h"
using namespace std;

//Placeholder for a composite data type

//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    KEYTYPE key;
    DATATYPE data;
    Node<DATATYPE, KEYTYPE> * left;
    Node<DATATYPE, KEYTYPE> * right;
    Node<DATATYPE, KEYTYPE> * parent;
public:
    //default constructor
    Node() {left = nullptr; right = nullptr; parent = nullptr;}; //initializes pointers
    //setters
    void setKey(KEYTYPE aKey) { key = aKey; }; //sets key
	void setData(DATATYPE aData) { data = aData; } //sets data
    void setLeft(Node<DATATYPE, KEYTYPE> * aLeft) { left = aLeft; }; //sets leftPtr
    void setRight(Node<DATATYPE, KEYTYPE> * aRight) { right = aRight; }; //sets rightPtr
    void setParent(Node<DATATYPE, KEYTYPE> * aParent) { parent = aParent; }; //sets parentPtr
    //getters
    KEYTYPE Key() { return key; }; //returns key
	DATATYPE Data() { return data; } //returns data
    Node<DATATYPE, KEYTYPE> * Left() { return left; }; //returns leftPtr
    Node<DATATYPE, KEYTYPE> * Right() { return right; };  //returns rightPtr
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; }; //returns parentPtr
};

#endif
