/* NAME: Tammy Husnetdinova
CLASS: CSCI 2421-001
ASSIGNMENT: FINAL PROJECT
DUE DATE: 12/06/18
 */

//preprocessor directives
#ifndef HUSNETDINOVAPROJECT_FUNCTIONS_H
#define HUSNETDINOVAPROJECT_FUNCTIONS_H
#include <iostream>
#include <string>
#include "Movie.h"
#include "Actor.h"
#include "BSTree.hpp"
using namespace std;

//menu function to keep things clean in main
//these will display menu choices and take int input
//every menu and submenu has been tested and works as expected
int mainMenu(BSTree<Movie, string> *movieTree, BSTree<Actor, string> *actorTree, int choice);

//these functions will read into each database from the csv files
//important to keep these databases separate, in separate trees
void readIntoMovieDatabase(BSTree<Movie, string> *movieTree, string filename);
void readIntoActorDatabase(BSTree<Actor, string> *actorTree, string filename2);

//these functions will let user add a new movie or actor to database
//complete with each field that each database come with (name, year, etc)
void addToMovieDatabase(BSTree<Movie, string> *movieTree);
void addToActorDatabase(BSTree<Actor, string> *actorTree);

//these function will let user modify an existing movie or actor in databases
//first use the findNode function to find the name(string) we want to modify
//then let the user modify each field under that entry (if they choose to)
void modifyMovie(BSTree<Movie, string> *movieTree);
void modifyActor(BSTree<Actor, string> *actorTree);

//these functions will let user delete an existing movie or actor in databases
//first use the findNode function to find the name(string) we want to delete
//use deleteNode function to get rid of that node
//the way this is written in the template (I didn't alter this function), it only deletes the first instance (not all)
void deleteMovie(BSTree<Movie, string> *movieTree);
void deleteActor(BSTree<Actor, string> *actorTree);

//these are sorting functions with original trees and new trees as parameters
//because I will be putting the data into the new tree that is sorted on the desired key
//also want to keep in mind that I will need to delete the container when it's no longer in use
//keeping/saving ALL my re-sorted containers will cause unnecessary memory use
//synopsis, winner, and award aren't really sortable (either too long to care, boolean, or appears too many times to be efficient)
void sortMovieOnYear(BSTree<Movie, string> *movieTree);
void sortMovieOnNomination(BSTree<Movie, string> *movieTree);
void sortMovieOnRating(BSTree<Movie, string> *movieTree);
void sortMovieOnRelease(BSTree<Movie, string> *movieTree);
void sortMovieOnDuration(BSTree<Movie, string> *movieTree);
void sortMovieOnGenre1(BSTree<Movie, string> *movieTree);
void sortMovieOnGenre2(BSTree<Movie, string> *movieTree);
void sortMovieOnMetacritic(BSTree<Movie, string> *movieTree);

void sortActorOnYear(BSTree<Actor, string> *actorTree);
void sortActorOnFilm(BSTree<Actor, string> *actorTree);

//these are my complete search functions
//searches should come up with 100 or less records, otherwise what's the point?
//can't really do a full search on synopsis or winner (that doesn't make sense)
//exact name and year make sense
void searchMovieName(BSTree<Movie, string> *movieTree);
void searchMovieYear(BSTree<Movie, string> *movieTree);
void searchMovieNomination(BSTree<Movie, string> *movieTree);
void searchMovieRating(BSTree<Movie, string> *movieTree);
void searchMovieRelease(BSTree<Movie, string> *movieTree);
void searchMovieDuration(BSTree<Movie, string> *movieTree);
void searchMovieGenre1(BSTree<Movie, string> *movieTree);
void searchMovieGenre2(BSTree<Movie, string> *movieTree);
void searchMovieMetacritic(BSTree<Movie, string> *movieTree);

void searchActorName(BSTree<Actor, string> *actorTree);
void searchActorYear(BSTree<Actor, string> *actorTree);
void searchActorFilm(BSTree<Actor, string> *actorTree);

//these are my partial search functions
//searches should come up with 100 or less records, otherwise what's the point?
//partial search will be a substring of something
//can't do partial search on boolean (doesn't make sense)
//also decided to not let user partial search any numerical values (duration, rating, metacritic, year)
void partialSearchMovieName(BSTree<Movie, string> *movieTree);
void partialSearchMovieRelease(BSTree<Movie, string> *movieTree);
void partialSearchMovieGenre1(BSTree<Movie, string> *movieTree);
void partialSearchMovieGenre2(BSTree<Movie, string> *movieTree);
void partialSearchMovieSynopsis(BSTree<Movie, string> *movieTree);

void partialSearchActorName(BSTree<Actor, string> *actorTree);
void partialSearchActorAward(BSTree<Actor, string> *actorTree);
void partialSearchActorFilm(BSTree<Actor, string> *actorTree);

//these functions will let the user print the databases to new csv formatted files (separate files)
void writeMovieReportToFile(BSTree<Movie, string> *movieTree, string outfile);
void writeActorReportToFile(BSTree<Actor, string> *actorTree, string outfile);

#endif //HUSNETDINOVAPROJECT_FUNCTIONS_H