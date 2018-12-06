*******************************************************
*  Name      :  Tammy Husnetdinova        
*  Student ID:  106228758               
*  Class     :  CSCI 2421           
*  Due Date  :  December 6, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

PLEASE RUN MAKE AND RUN PROGRAM USING ./P

The objective of this project is to create a simple 
database that handles multiple records, each possessing 
several fields. The user is free to modify, search, and 
delete existing records, add new records, perform 
complete and partial searches, and print out the updated 
database to a new .csv file. The project is implemented 
using binary search trees for the main and secondary 
data structures, separate classes to handle the data, 
and a text-based menu with submenus that allows the user 
to “choose their own adventure” in manipulating the data. 
EXTRA CRDIT NOTE: I did not attempt the extra credit
nominations file.
HELP/COLLABORATION NOTE: I have my full works-cited 
in my Design Document, as well as some links I used
in comments right where I used them. I discussed the 
project and outline heavily with Erik throughout the
month of working on it. We came up with a similar 
function to find additional nodes for searches (instead
of just the first found node), we had a similar method
of moving from one tree to another tree using a stack 
as the intermediate data structure before resorting.
I have additional comments on any sources Erik and I 
both looked at or shared with each other.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program where I 
create my 2 base trees for Actor and Movie databases.
Also where I call the main menu function. This is one 
of the emptiest and most satisfying mains.

Name:  Functions.cpp/.h
   Contains the implementations and declarations of all
functions used to manipulate the database, respectively.
The functions are fully outlined in my Design Document
and commented out in the files themselves. Brief over-
view of functions: read in from file, add, delete, 
modify, sort, complete and partial search, write out to
a new file, and main menu.  

Name: Node.h
   Defines and implements the Node class. This is a
templated file provided by the instructor. It includes
all necessary getters/setters and constructors. I did
not make any changes to this file.

Name: BSTree.hpp
   This file includes the BSTree.h; both files were
given with partial functionality by the instructor.
I filled in the necessary functions and added a few of
my own: findAnotherNode to have a search bring up more
than just the first node the findNode finds, treeToStack
to move the contents of a tree to a stack so it can be 
moved to another tree on a new key, and clearTree which 
clears the contents of the tree without deleting it (I
didn't end up needing to use this one, but might come 
in handy later). This is a templated file.

Name: Movie.h
   Defines and implements the Movie class. Holds all
the getters/setters, constructors, and overloaded <
(all with inline definitions).

Name: Actor.h 
   Defines and implements the Actor class. Holds all
the getters/setters, constructors, and overloaded <
(all with inline definitions).

*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion.  It was 
   compiled, run, and tested on csegrid.ucdenver.pvt.

