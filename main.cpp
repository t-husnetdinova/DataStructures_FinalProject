/* NAME: Tammy Husnetdinova
CLASS: CSCI 2421-001
ASSIGNMENT: FINAL PROJECT
DUE DATE: 12/06/18
 */

//preprocessor directives
#include <iostream>
#include <string>
#include "Actor.h"
#include "Movie.h"
#include "Node.h"
#include "BSTree.hpp"
#include "Functions.h"
using namespace std;

//MAKE SURE TO SUBMIT:
    //ALL SOURCE FILES
    //ACTUAL CSV FILES
    //MAKEFILE
    // README
    //DESIGN DOCUMENT (UPDATE)

int main()
{
    //declarations area
    int choice = 0;

    //main BSTs (to read into from .csv files)
    BSTree<Movie, string> *movieTree = new BSTree<Movie, string>;
    BSTree<Actor, string> *actorTree = new BSTree<Actor, string>;

    //tell user what program is about before showing menu
    cout << "Welcome to my movie and actor database!" << endl;
    cout << "There are a few cool things you can do here, check them out:" << endl;

    //call main menu function
    mainMenu(movieTree, actorTree, choice);

    return 0;
}