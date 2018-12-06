/* NAME: Tammy Husnetdinova
CLASS: CSCI 2421-001
ASSIGNMENT: FINAL PROJECT
DUE DATE: 12/06/18
 */

 //preprocessor directives
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "Functions.h"
#include "Actor.h"
#include "Movie.h"
#include "BSTree.hpp"
using namespace std;

//this function is for the bonus round menu option
//the code was taken from: https://stackoverflow.com/questions/33882822/output-letters-one-at-a-time-in-c
void type_text(const string& text);

void type_text(const string& text)
{
    // loop through each character in the text
    for(size_t i = 0; i < text.size(); ++i)
    {
        // output one character
        // flush to make sure the output is not delayed
        cout << text[i] << std::flush;

        // sleep 60 milliseconds
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int mainMenu(BSTree<Movie, string> *movieTree, BSTree<Actor, string> *actorTree, int choice)
{
    while(choice != 9)
    {
        //show first level menu
        cout << "1. Read into database from file." << endl;
        cout << "2. Add a record to a database." << endl;
        cout << "3. Search for and modify a record." << endl;
        cout << "4. Search for and delete a record." << endl;
        cout << "5. Sort database on a new field." << endl;
        cout << "6. Perform a complete search in database." << endl;
        cout << "7. Perform a partial search in database." << endl;
        cout << "8. Print updated database to file." << endl;
        cout << "9. Exit program." << endl;
        cout << "42. Bonus round!" << endl;

        //take user input for menu choice
        cin >> choice;
        cin.clear();
        cin.ignore(2, '\n');

        switch(choice)
        {
            case 1:
            {
               //declarations area
               string filename;
               string filename2;

               //ask user to choose the names of the files they would like to read from
               cout << "What file would you like to read into the database/tree?" << endl;
               cout << endl;
               cout << "Your choices are pictures.csv or actor-actress.csv" << endl;
               //ask for filename for Movies database and pass it into the function
               cout << "Please type in your filename for the Movies database: " << endl;
               cout << "(for example, pictures.csv)" << endl;
               cin >> filename;
               readIntoMovieDatabase(movieTree, filename);

               //ask for filename for Actors database and pass it into the function
               cout << "Please type in your filename for the Actors database: " << endl;
                cout << "(for example, actor-actress.csv)" << endl;
               cin >> filename2;
               readIntoActorDatabase(actorTree, filename2);

               //testing purposes (THIS WORKS)
               //movieTree->printInorder();
               //actorTree->printInorder();

               break;
            }
            case 2:
            {
                //tell user what's happening
                cout << "Which database would you like to add a record to?" << endl;

                while(choice != 3)
                {
                    //show second level menu
                    cout << "1. Movie database." << endl;
                    cout << "2. Actor database." << endl;
                    cout << "3. Go back." << endl;

                    //take user input for menu choice
                    cin >> choice;
                    cin.clear();
                    cin.ignore(2, '\n');

                    switch(choice)
                    {
                        case 1:
                        {
                            //call addToMovieDatabase function
                            addToMovieDatabase(movieTree);

                            cout << "Would you like to see the updated database (y/n)?" << endl;
                            char ch;
                            cin >> ch;
                            cin.ignore();

                            if(ch == 'y' || ch == 'Y')
                            {
                                movieTree->printInorder();
                            }
                            break;
                        }//case 1
                        case 2:
                        {
                            //call addToActorDatabase function
                            addToActorDatabase(actorTree);

                            cout << "Would you like to see the updated database (y/n)?" << endl;
                            char ch;
                            cin >> ch;
                            cin.ignore();

                            if(ch == 'y' || ch == 'Y')
                            {
                                actorTree->printInorder();
                            }
                            break;
                        }//case 2
                        case 3:
                        {
                            //go back a menu level
                            //don't cout anything, just a smooth transition
                            break;
                        }//case 3
                        default:{
                            cout << "Oh no! That's not a valid choice!" << endl;
                        }//default
                    }//switch
                }//while
                break;
            }//case 2
            case 3:
            {
                //tell user what's happening
                cout << "Which database would you like to modify a record in?" << endl;
                //testing

                do
                {
                    //show second level menu
                    cout << "1. Movie database." << endl;
                    cout << "2. Actor database." << endl;
                    cout << "3. Go back." << endl;

                    //take user input for menu choice
                    cin >> choice;
                    cin.clear();
                    cin.ignore(2, '\n');

                    switch(choice)
                    {
                        case 1:
                        {
                            //call modifyMovie function
                            modifyMovie(movieTree);

                            cout << "Would you like to see the updated database (y/n)?" << endl;
                            char ch;
                            cin >> ch;
                            cin.ignore();

                            if(ch == 'y' || ch == 'Y')
                            {
                                movieTree->printInorder();
                            }
                            break;
                        }//case 1
                        case 2:
                        {
                            //call modifyActor function
                            modifyActor(actorTree);

                            cout << "Would you like to see the updated database (y/n)?" << endl;
                            char ch;
                            cin >> ch;
                            cin.ignore();

                            if(ch == 'y' || ch == 'Y')
                            {
                                actorTree->printInorder();
                            }
                            break;
                        }//case 2
                        case 3:
                        {
                            //go back a menu level
                            //don't cout anything, just a smooth transition
                            break;
                        }//case 3
                        default:{
                            cout << "Oh no! That's not a valid choice!" << endl;
                        }//default
                    }//switch
                }//do
                while(choice != 3);
                break;
            }//case 3
            case 4:
            {
                //tell user what's happening
                cout << "Which database would you like to delete a record in?" << endl;

                while(choice != 3)
                {
                    //show second level menu
                    cout << "1. Movie database." << endl;
                    cout << "2. Actor database." << endl;
                    cout << "3. Go back." << endl;

                    //take user input for menu choice
                    cin >> choice;
                    cin.clear();
                    cin.ignore(2, '\n');

                    switch(choice)
                    {
                        case 1:
                        {
                            //call deleteMovie function
                            deleteMovie(movieTree);

                            cout << "Would you like to see the updated database (y/n)?" << endl;
                            char ch;
                            cin >> ch;
                            cin.ignore();

                            if(ch == 'y' || ch == 'Y')
                            {
                                movieTree->printInorder();
                            }
                            break;
                        }//case 1
                        case 2:
                        {
                            //call deleteActor database
                            deleteActor(actorTree);

                            cout << "Would you like to see the updated database (y/n)?" << endl;
                            char ch;
                            cin >> ch;

                            if(ch == 'y' || ch == 'Y')
                            {
                                actorTree->printInorder();
                            }
                            break;
                        }//case 2
                        case 3:
                        {
                            //go back a menu level
                            //don't cout anything, just a smooth transition
                            break;
                        }//case 3
                        default:{
                            cout << "Oh no! That's not a valid choice!" << endl;
                        }//default
                    }//switch
                }//while
                break;
            }//case 4
            case 5:
            {
                //tell user what's happening
                cout << "Which database would you like to re-sort on a new field?" << endl;

                while(choice != 3)
                {
                    //show second level menu
                    cout << "1. Movie database." << endl;
                    cout << "2. Actor database." << endl;
                    cout << "3. Go back." << endl;

                    //take user input for menu choice
                    cin >> choice;
                    cin.clear();
                    cin.ignore(2, '\n');

                    switch(choice)
                    {
                        case 1:
                        {
                            //re-sorting movie database
                            while(choice != 9)
                            {
                                //tell user that it's already sorted on name
                                cout << "(the database is currently sorted on name)" << endl;

                                //show third level menu
                                cout << "1. Sort on year." << endl;
                                cout << "2. Sort on nomination." << endl;
                                cout << "3. Sort on rating." << endl;
                                cout << "4. Sort on release." << endl;
                                cout << "5. Sort on duration." << endl;
                                cout << "6. Sort on genre 1." << endl;
                                cout << "7. Sort on genre 2." << endl;
                                cout << "8. Sort on metacritic." << endl;
                                cout << "9. Go back." << endl;

                                //take user input for menu choice
                                cin >> choice;
                                cin.clear();
                                cin.ignore(2, '\n');

                                switch(choice)
                                {
                                    case 1:
                                    {
                                        //call sortMovieOnYear function
                                        sortMovieOnYear(movieTree);
                                        break;
                                    }//case 1
                                    case 2:
                                    {
                                        //call sortMovieOnNomination function
                                        sortMovieOnNomination(movieTree);
                                        break;
                                    }//case 2
                                    case 3:
                                    {
                                        //call sortMovieOnRating function
                                        sortMovieOnRating(movieTree);
                                        break;
                                    }//case 3
                                    case 4:
                                    {
                                        //call sortMovieOnRelease function
                                        sortMovieOnRelease(movieTree);
                                        break;
                                    }//case 4
                                    case 5:
                                    {
                                        //call sortMovieOnDuration function
                                        sortMovieOnDuration(movieTree);
                                        break;
                                    }//case 5
                                    case 6:
                                    {
                                        //call sortMovieOnGenre1 function
                                        sortMovieOnGenre1(movieTree);
                                        break;
                                    }//case 6
                                    case 7:
                                    {
                                        //call sortMovieOnGenre2 function
                                        sortMovieOnGenre2(movieTree);
                                        break;
                                    }//case 7
                                    case 8:
                                    {
                                        //call sortMovieOnMetacritic function
                                        sortMovieOnMetacritic(movieTree);
                                        break;
                                    }//case 8
                                    case 9:
                                    {
                                        //go back a menu level
                                        //don't cout anything, just a smooth transition
                                        break;
                                    }//case 9
                                    default:{
                                        cout << "Oh no! That's not a valid choice!" << endl;
                                    }//default
                                }//switch
                            }//while
                            break;
                        }//case 1
                        case 2:
                        {
                            //re-sorting actor database
                            while(choice != 3)
                            {
                                //tell user that it's already sorted on name
                                cout << "The database is currently sorted on name." << endl;

                                //show third level menu
                                cout << "1. Sort on year." << endl;
                                cout << "2. Sort on film." << endl;
                                cout << "3. Go back." << endl;

                                //take user input for menu choice
                                cin >> choice;
                                cin.clear();
                                cin.ignore(2, '\n');

                                switch(choice)
                                {
                                    case 1:
                                    {
                                        //call sortActorOnYear function
                                        sortActorOnYear(actorTree);
                                        break;
                                    }//case 1
                                    case 2:
                                    {
                                        //call sortActorOnFilm function
                                        sortActorOnFilm(actorTree);
                                        break;
                                    }//case 4
                                    case 3:
                                    {
                                        //go back a menu level
                                        //don't cout anything, just a smooth transition
                                        break;
                                    }//case 5
                                    default:{
                                        cout << "Oh no! That's not a valid choice!" << endl;
                                    }//default
                                }//switch
                            }//while
                            break;
                        }//case 2
                        case 3:
                        {
                            //go back a menu level
                            //don't cout anything, just a smooth transition
                            break;
                        }//case 3
                        default:{
                            cout << "Oh no! That's not a valid choice!" << endl;
                        }//default
                    }//switch
                }//while
                break;
            }//case 5
            case 6:
            {
                //tell user what's happening
                cout << "Which database would you like to do a complete search in?" << endl;

                while(choice != 3)
                {
                    //show second level menu
                    cout << "1. Movie database." << endl;
                    cout << "2. Actor database." << endl;
                    cout << "3. Go back." << endl;

                    //take user input for menu choice
                    cin >> choice;
                    cin.clear();
                    cin.ignore(2, '\n');

                    switch(choice)
                    {
                        case 1:
                        {
                            while(choice != 10)
                            {
                                //remind user what kind of search we're doing
                                cout << "Now, in complete search submenu." << endl;

                                //show third level menu
                                cout << "1. Search for name." << endl;
                                cout << "2. Search for year." << endl;
                                cout << "3. Search for nomination." << endl;
                                cout << "4. Search for rating." << endl;
                                cout << "5. Search for release." << endl;
                                cout << "6. Search for duration." << endl;
                                cout << "7. Search for genre 1." << endl;
                                cout << "8. Search for genre 2." << endl;
                                cout << "9. Search for metacritic." << endl;
                                cout << "10. Go back." << endl;

                                //take user input for menu choice
                                cin >> choice;
                                cin.clear();
                                cin.ignore(2, '\n');

                                switch(choice)
                                {
                                    case 1:
                                    {
                                        //call searchMovieName function (THIS WORKS)
                                        searchMovieName(movieTree);
                                        break;
                                    }//case 1
                                    case 2:
                                    {
                                        //call searchMovieYear function
                                        searchMovieYear(movieTree);
                                        break;
                                    }//case 2
                                    case 3:
                                    {
                                        //call searchMovieNomination function
                                        searchMovieNomination(movieTree);
                                        break;
                                    }//case 3
                                    case 4:
                                    {
                                        //call searchMovieRating function
                                        searchMovieRating(movieTree);
                                        break;
                                    }//case 4
                                    case 5:
                                    {
                                        //call searchMovieRelease function
                                        searchMovieRelease(movieTree);
                                        break;
                                    }//case 5
                                    case 6:
                                    {
                                        //call searchMovieDuration function
                                        searchMovieDuration(movieTree);
                                        break;
                                    }//case 6
                                    case 7:
                                    {
                                        //call searchMovieGenre1 function
                                        searchMovieGenre1(movieTree);
                                        break;
                                    }//case 7
                                    case 8:
                                    {
                                        //call searchMovieGenre2 function
                                        searchMovieGenre2(movieTree);
                                        break;
                                    }//case 8
                                    case 9:
                                    {
                                        //call searchMovieMetacritic function
                                        searchMovieMetacritic(movieTree);
                                        break;
                                    }//case 9
                                    case 10:
                                    {
                                        //go back a menu level
                                        //don't cout anything, just a smooth transition
                                        break;
                                    }//case 10
                                    default:{
                                        cout << "Oh no! That's not a valid choice!" << endl;
                                    }//default
                                }//switch
                            }//while
                            break;
                        }//case 1
                        case 2:
                        {
                            while(choice != 4)
                            {
                                //remind user what kind of search we're doing
                                cout << "Now, in complete search submenu." << endl;

                                //show third level menu
                                cout << "1. Search for year." << endl;
                                cout << "2. Search for name." << endl;
                                cout << "3. Search for film." << endl;
                                cout << "4. Go back." << endl;

                                //take user input for menu choice
                                cin >> choice;
                                cin.clear();
                                cin.ignore(2, '\n');

                                switch(choice)
                                {
                                    case 1:
                                    {
                                        //call searchActorYear function
                                        searchActorYear(actorTree);
                                        break;
                                    }//case 1
                                    case 2:
                                    {
                                        //call searchActorName function (THIS WORKS)
                                        searchActorName(actorTree);
                                        break;
                                    }//case 2
                                    case 3:
                                    {
                                        //call searchActorFilm function
                                        searchActorFilm(actorTree);
                                        break;
                                    }//case 3
                                    case 4:
                                    {
                                        //go back a menu level
                                        //don't cout anything, just a smooth transition
                                        break;
                                    }//case 4
                                    default:{
                                        cout << "Oh no! That's not a valid choice!" << endl;
                                    }//default
                                }//switch
                            }//while
                            break;
                        }//case 2
                        case 3:
                        {
                            //go back a menu level
                            //don't cout anything, just a smooth transition
                            break;
                        }//case 3
                        default:{
                            cout << "Oh no! That's not a valid choice!" << endl;
                        }//default
                    }//switch
                }//while
                break;
            }//case 6
            case 7:
            {
                //tell user what's happening
                cout << "Which database would you like to do a partial search in?" << endl;

                while(choice != 3)
                {
                    //show second level menu
                    cout << "1. Movie database." << endl;
                    cout << "2. Actor database." << endl;
                    cout << "3. Go back." << endl;

                    //take user input for menu choice
                    cin >> choice;
                    cin.clear();
                    cin.ignore(2, '\n');

                    switch(choice)
                    {
                        case 1:
                        {
                            while(choice != 6)
                            {
                                //remind user what kind of search we're doing
                                cout << "Now, in partial search submenu." << endl;

                                //show third level menu
                                cout << "1. Search for name." << endl;
                                cout << "2. Search for release." << endl;
                                cout << "3. Search for genre 1." << endl;
                                cout << "4. Search for genre 2." << endl;
                                cout << "5. Search for synopsis." << endl;
                                cout << "6. Go back." << endl;

                                //take user input for menu choice
                                cin >> choice;
                                cin.clear();
                                cin.ignore(2, '\n');

                                switch(choice)
                                {
                                    case 1:
                                    {
                                        //call partialSearchMovieName function
                                        partialSearchMovieName(movieTree);
                                        break;
                                    }//case 1
                                    case 2:
                                    {
                                        //call partialSearchMovieRelease function
                                        partialSearchMovieRelease(movieTree);
                                        break;
                                    }//case 2
                                    case 3:
                                    {
                                        //call partialSearchMovieGenre1 function
                                        partialSearchMovieGenre1(movieTree);
                                        break;
                                    }//case 3
                                    case 4:
                                    {
                                        //call partialSearchMovieGenre2 function
                                        partialSearchMovieGenre2(movieTree);
                                        break;
                                    }//case 4
                                    case 5:
                                    {
                                        //call partialSearchMovieSynopsis function
                                        partialSearchMovieSynopsis(movieTree);
                                        break;
                                    }//case 5
                                    case 6:
                                    {
                                        //go back a menu level
                                        //don't cout anything, just a smooth transition
                                        break;
                                    }//case 6
                                    default:{
                                        cout << "Oh no! That's not a valid choice!" << endl;
                                    }//default
                                }//switch
                            }//while
                            break;
                        }//case 1
                        case 2:
                        {
                            while(choice != 4)
                            {
                                //remind user what kind of search we're doing
                                cout << "Now, in partial search submenu." << endl;

                                //show third level menu
                                cout << "1. Search for award." << endl;
                                cout << "2. Search for name." << endl;
                                cout << "3. Search for film." << endl;
                                cout << "4. Go back." << endl;

                                //take user input for menu choice
                                cin >> choice;
                                cin.clear();
                                cin.ignore(2, '\n');

                                switch(choice)
                                {
                                    case 1:
                                    {
                                        //call partialSearchActorAward function
                                        partialSearchActorAward(actorTree);
                                        break;
                                    }//case 1
                                    case 2:
                                    {
                                        //call partialSearchActorName function
                                        partialSearchActorName(actorTree);

                                        break;
                                    }//case 2
                                    case 3:
                                    {
                                        //call partialSearchActorFilm function
                                        partialSearchActorFilm(actorTree);
                                        break;
                                    }//case 4
                                    case 4:
                                    {
                                        //go back a menu level
                                        //don't cout anything, just a smooth transition
                                        break;
                                    }//case 5
                                    default:{
                                        cout << "Oh no! That's not a valid choice!" << endl;
                                    }//default
                                }//switch
                            }//while
                            break;
                        }//case 2
                        case 3:
                        {
                            //go back a menu level
                            //don't cout anything, just a smooth transition
                            break;
                        }//case 3
                        default:{
                            cout << "Oh no! That's not a valid choice!" << endl;
                        }//default
                    }//switch
                }//while
                break;
            }//case 7
            case 8:
            {
                //remind user what we're doing here
                cout << "Now, in final report submenu." << endl;
                cout << "Which database would you like to write to a file?" << endl;

                while(choice != 3)
                {
                    //show second level menu
                    cout << "1. Movie database." << endl;
                    cout << "2. Actor database." << endl;
                    cout << "3. Go back." << endl;

                    //take user input for choice
                    cin >> choice;
                    cin.ignore();

                    switch(choice)
                    {
                        case 1:
                        {
                            cout << "Writing updated movie database to new file." << endl;
                            cout << "What's the filename? (.csv)" << endl;

                            string outfile;
                            cin >> outfile;

                            //call writeMovieReportToFile function
                            writeMovieReportToFile(movieTree, outfile);
                            break;
                        }//case 1
                        case 2:
                        {
                            cout << "Writing updated mactor database to new file." << endl;
                            cout << "What's the filename? (.csv)" << endl;

                            string outfile;
                            cin >> outfile;

                            //call writeActorReportToFile function
                            writeActorReportToFile(actorTree, outfile);
                            break;
                        }//case 2
                        case 3:
                        {
                            //go back a menu level
                            //don't cout anything, just a smooth transition
                        }//case3
                        default:
                        {
                            cout << "Oh no! That's not a valid choice!" << endl;
                        }//default
                    }//switch
                }//while
                break;
            }//case 8
            case 9:
            {
                //tell user what's happening
                cout << "Now leaving database, goodbye!" << endl;
                break;
            }//case 9
            case 42:
            {
                type_text("And the Oscar goes to ...");
                cout << endl;

                cout << "                              ..." << endl;
                cout << "                      .,/(##%%%%%%%%%#/*.                                         " << endl;
                cout << "                    .(%&%&&%%%%##%%%%%%%%%%#/.                                     " << endl;
                cout << "                 .*%&%%%%%%%%%%%####%%%%&&&&&%(.                                   " << endl;
                cout << "                .*%&&&&&%%%%##%%##%%%%%%&&&&&&&&(*                                  " << endl;
                cout << "                #&&&&&&&&%%%%%%%########%%%&&&&&&*                                " << endl;
                cout << "             ./&&&&&&&&%%%%####(((/////((##%&&&@@&%*.                              " << endl;
                cout << "             *#%%%&%%%%%##(((//****,,,,,***//#%&&&&&(                              " << endl;
                cout << "             (#%%%%%%##((//*******,,,,,,,,,,*/(%&&&&%.                             " << endl;
                cout << "            .#%%#####((((//******,,,,,,,,,,,,**(%&&&&*                             " << endl;
                cout << "             ,%%#(####((((///*****,,,,,,,,,,,,**/(%&&*                            " << endl;
                cout << "            .*%%#((###(((///******,,,,,,,,,,,,,,*/#%&&&(                            " << endl;
                cout << "            ./%%#((((((((///******,,,,,,,,,,,,,,*/(#%&%#                            " << endl;
                cout << "            .*####(((((((///********,,,,,,,,,,,,*/((#%%%.                           " << endl;
                cout << "            ,(###(#((((///*********,,,,,,,,,,,,**((##%%.                           " << endl;
                cout << "            .(((((#((((////****/*********,,,,,,,*/(##%%.                           " << endl;
                cout << "             (#((((((((###(////////((//**,,,,,,,,/(####,.                          " << endl;
                cout << "            ,##((############/***((###%%#(/**/////(#(,*//                          " << endl;
                cout << "            ,###(#######((####(////(#((//**********(/,,**                          " << endl;
                cout << "            .##(/(####((######(**/**/((//****,,****//*,,.                          " << endl;
                cout << "             /#((((((///(#####(*,,****////*,,,,,,****/*,.                          " << endl;
                cout << "             ./#((((((//(#####(*,,,**////**,,,,,,******,                           " << endl;
                cout << "             .(((((((((#%%##((*,,,,,*/##//**,,,,**,,,,                            " << endl;
                cout << "              ,/(#(((#%%%%%%%##(//*****/##(/*/****,,,.                            " << endl;
                cout << "               .(#############((/**,,***//(///******.                             " << endl;
                cout << "                 *(#((##%&##(((//***/(/*/**//******.                             " << endl;
                cout << "                 ,##((######(/**,*****,,*******/****                           " << endl;
                cout << "                ,(########(((///*********/////**,,,*,                           " << endl;
                cout << "                (#######((((//**********//***,...*&%                          " << endl;
                cout << "                ,((#((((((//***,,*****//***....,(%&(.                        " << endl;
                cout << "                  /(#(((((//****,***////**... .,%&&&                        " << endl;
                cout << "                */(##((((///***//////*,..  .#&&&&%%&(.                      " << endl;
                cout << "               .*((######((((((((/*,... .(%&&&&%%%%&%,                     " << endl;
                cout << "            ,*##(########(((((//,.....*%&&&&&&&&&&&&&&(*                  " << endl;
                cout << "          */%&&&%((######(((((//,.....,(&&&&&&&&&&&&&&&&&&&%,.              " << endl;
                cout << "        *(&&&&&&&@#/(#########(*,,.....*&&&&&&&&&&&&&&&&&&&&&&&/           " << endl;
                cout << "./#&&&&@@&&&&@&////(#####(/,,,,....#&&@&&&&&&&&&&&&&&@@&&&&&&&&%%,         " << endl;
                cout << ".,#%&&&&@@@@@&&&&@@&////*/%%#/,,,,,...*#&&&&&&&&&&&&&&&&@@@@@&&&&&&&&&&&/.      " << endl;
                cout << "./&&&@&&&@@@@@&&&&@@@&//#%&&&&(*,,,,..,*&&&&&&&&&&&&&&&&&@@@@@@@&&&&&&&&&&&&(,    " << endl;
                cout << ".%&&&@@&&@@@@@@&&&@@@@%%&&&@@@&%%#/,..,#&&&&&&&&&&&&&&&&&&@@@@&&&&&&&&&&&&&&&&/" << endl;
                cout << ".(@&&@@@&@@@@@@&&@@@@@@&&&@@&&&&&@@@&%(#&&&&&&&&&&&&@@@@@@@@@@@&&&&&&&&&&&&&&&&&&*" << endl;
                cout << "(&@&&@&&@@@@@@@@@@@@@@&&&%@@@&%%@@@&%%&&&&&&&&&&&&&&&&&&&@@@@&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << ".&@@&&&&&@@@@@@@@&&@@&&&%%&@&%&@@&%##%&&&&&&&&&&&&&&&&&&&@@@&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << ",#@@&&&&@@@&@@@@@@&@@@&&%%&&&&@@%#((##&@&&&&&&&&&&&&&&&&@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "%&@@&&&@@@&@@@@@@&&@@&&&%&&&&&%&%(##%&&&&&&@@@@@@@&&&&@@@&&&&&@@&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << ".(&&@&&&&@@@@@@@@@@&@@&&&&&@@@&&&&%%&@&&&&@@@&@@@@&@@@@@&&&&&&@&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "(&&&&&&&&@&&@@@@@@@@@@&&&&@@&&%&&&&%&&&@&&@@@@@@@@&@@@&@@&&&&&&&&&&&&&&&&&&@&&&&&&&&&&&&" << endl;
                cout << ".%&&@&&&&&&@@@@@@@@@@@@&&@@&&&&&&&&&&@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&@@&&&&&&&&&&&&&" << endl;
                cout << "*&&@@&&&&&&@@@@@@@@@@@&&&@@&&@@&%%&@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&@@@&&&&&&&&&&&&&&" << endl;
                cout << "*%&&@&&&&&&@@@@@@@@@@@@&&@@&@@@@@&@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&@@&&&&&&&&&&&&&&&&" << endl;
                cout << "#&&&&&&&&&@@@@@@@@@@@@&&@@&@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&@@@&&&&&&&&&&&&&&&&&" << endl;
                cout << ".&&&&&&&&@@@@@@@@@@@@@@&&&&@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&@@@@&&&&&&&&&&&&&&&&&&" << endl;
                cout << "*@&@@&&&&@@@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&@@@@@&&&&&&&&&&&&&&&&&&" << endl;
                cout << ",#&&@@&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&@@@@@@&@@@@@&&&&&&&&&&&&" << endl;
                cout << "(&@@@@&&@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&@@@@@@@@@@@@@@&&&&&&&&&&&&" << endl;
                cout << "*&&@@@@&&@@@@@@@@@@@@@@@@@&@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&" << endl;
                cout << "/%&&@@@&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&" << endl;
                cout << ".&&&@@@@&&@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&" << endl;
                cout << ",#&&@@@@@&@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&" << endl;
                cout << "%&&@@@@@&&@@@@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&" << endl;
                cout << "./&&@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&" << endl;
                cout << "(&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&" << endl;
                cout << ",&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&" << endl;
                cout << "#&&@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&" << endl;
                cout << "&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&" << endl;
                cout << "&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&" << endl;
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&" << endl;
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&@@&&&&&" << endl;
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&@@&&&&&&" << endl;
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&@@@&&&&&&" << endl;
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&@@@@&&&&&&" << endl;
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&@@@@&&&&&&&" << endl;
                cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@@@@&&&&&&&" << endl;


                type_text("Congratulations, Dr. Augustine !!");
                cout << endl;
                break;

            }
            default:{
                cout << "Oh no! That's not a valid choice!" << endl;
            }//default
        }//switch
    }//while
    return choice;
}//menu

void readIntoMovieDatabase(BSTree<Movie, string> *movieTree, string filename)
{
    //declarations area
    Movie m;
    string temp = "0";
    string temp2 = "0";
    string temp3 = "0";
    string line = "0";
    ifstream infile;
    infile.open(filename);

    //to ignore whole first header line
    getline(infile, line);

    while(infile.good())
    {
        getline(infile, temp, ',' );
        //cout << "Name:" << temp << endl;
        m.setMovieName(temp);

        getline(infile, temp2, ',' );
        //cout << "Year:" << temp2 << endl;
        m.setMovieYear(stoi(temp2));

        getline(infile, temp2, ',' );
        //cout << "Nominations:" << temp2 << endl;
        m.setNominations(stoi(temp2));

        getline(infile, temp3, ',' );
        //cout << "Rating:" << temp3 << endl;
        m.setRating(stod(temp3));

        getline(infile, temp2, ',' );
        //cout << "Duration:" << temp2 << endl;
        m.setDuration(stoi(temp2));

        getline(infile, temp, ',' );
        //cout << "Genre1:" << temp << endl;
        m.setGenre1(temp);

        getline(infile, temp, ',' );
        //cout << "Genre2:" << temp << endl;
        m.setGenre2(temp);

        getline(infile, temp, ',' );
        //cout << "Release:" << temp << endl;
        m.setRelease(temp);

        getline(infile, temp2, ',' );
        //cout << "Metacritic:" << temp2 << endl;
        m.setMetacritic(stoi(temp2));

        getline(infile, temp, '\n');
        //cout << "Synopsis:" << temp << endl;
        m.setSynopsis(temp);

        //push into movie tree
        movieTree->addNode(m.getMovieName(), m);

    }
    //tell user they've successfully read their file into the Movies database
    cout << filename << " successfully read into the Movie database tree!" << endl;
    cout << endl;
}

void readIntoActorDatabase(BSTree<Actor, string> *actorTree, string filename2)
{
    //declarations area
    Actor a;
    string temp = "0";
    string temp2 = "0";
    string line = "0";
    ifstream infile;
    infile.open(filename2);

    //to ignore whole first header line
    getline(infile, line);

    while(infile.good())
    {
        getline(infile, temp2, ',');
        //cout << "Year:" << temp2 << endl;
        a.setActorYear(stoi(temp2));

        getline(infile, temp, ',');
        //cout << "Award:" << temp << endl;
        a.setAward(temp);

        getline(infile, temp2, ',');
        //cout << "Winner:" << temp2 << endl;
        a.setWinner(stoi(temp2));

        getline(infile, temp, ',');
        //cout << "Name:" << temp << endl;
        a.setActorName(temp);

        getline(infile, temp, '\n');
        //cout << "Film:" << temp << endl;
        a.setFilm(temp);

        //push into actor tree
        actorTree->addNode(a.getActorName(), a);
    }
    //tell user they've successfully read their file into the Actors database
    cout << filename2 << " successfully read into the Actor database tree!" << endl;
    cout << endl;
}

void addToMovieDatabase(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Movie newMovie;
    string temp = "0";
    int temp2 = 0;
    float temp3 = 0;

    //tell user what to do
    cout << "Let's add a new entry to the Movie database!" << endl;
    cout << "Please fill out the prompts for the new addition: " << endl;
    //prompt user to fill out new movie fields
    cout << "Name: " << endl;
    getline(cin, temp, '\n');
    newMovie.setMovieName(temp);
    cout << "Year: " << endl;
    cin >> temp2;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setMovieYear(temp2);
    cout << "Nominations: " << endl;
    cin >> temp2;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setNominations(temp2);
    cout << "Rating: " << endl;
    cin >> temp3;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setRating(temp3);
    cout << "Duration: " << endl;
    cin >> temp2;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setDuration(temp2);
    cout << "Genre1: " << endl;
    cin >> temp;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setGenre1(temp);
    cout << "Genre2: " << endl;
    cin >> temp;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setGenre2(temp);
    cout << "Release: " << endl;
    cin >> temp;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setRelease(temp);
    cout << "Metacritic: " << endl;
    cin >> temp2;
    cin.clear();
    cin.ignore(200, '\n');
    newMovie.setMetacritic(temp2);
    cout << "Synopsis: " << endl;
    getline(cin, temp, '\n');
    newMovie.setSynopsis(temp);

    //push new actor into the tree
    movieTree->addNode(newMovie.getMovieName(), newMovie);
}

void addToActorDatabase(BSTree<Actor, string> *actorTree)
{
    //declarations area
    Actor newActor;
    string temp = "0";
    int temp2 = 0;

    //tell user what to do
    cout << "Let's add a new entry to the Actor database!" << endl;
    cout << "Please fill out the prompts for the new addition: " << endl;
    //prompt user to fill out new movie fields
    cout << "Name: " << endl;
    getline(cin, temp, '\n');
    newActor.setActorName(temp);
    cout << "Year: " << endl;
    cin >> temp2;
    cin.clear();
    cin.ignore(200, '\n');
    newActor.setActorYear(temp2);
    cout << "Award: " << endl;
    getline(cin, temp, '\n');
    newActor.setAward(temp);
    cout << "Winner: " << endl;
    cin >> temp2;
    cin.clear();
    cin.ignore(200, '\n');
    newActor.setWinner(temp2);
    cout << "Film: " << endl;
    getline(cin, temp, '\n');
    newActor.setFilm(temp);

    //push new actor into the tree
    actorTree->addNode(newActor.getActorName(), newActor);
}

void modifyMovie(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Movie tempMovie;
    string temp;
    int temp2;
    double temp3;
    char choice;
    Node<Movie, string> * tempPtr = nullptr;

    //tell user what to do
    cout << "Let's modify an entry in the Movie database!" << endl;
    cout << "Please enter the Name of the movie you'd like to change: " << endl;
    getline(cin, temp, '\n');

    //set tempPtr equal to found node
    tempPtr = movieTree->findNode(temp);

    if(tempPtr != nullptr)
    {
        //tell user what to do
        cout << "First, choose whether you want to change the field. " << endl;
        cout << "If you do, then enter the new field data." << endl;
        cout << endl;

        //prompt user to fill out new movie fields

        //movie name stays same
        tempMovie.setMovieName(temp);

        cout << "Would you like to change the year (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New year: " << endl;
            cin >> temp2;
            cin.ignore();
            tempMovie.setMovieYear(temp2);
        }
        else
        {
            cout << "Keeping year the same." << endl;
            cout << endl;
            int currentYear;
            currentYear = tempPtr->Data().getMovieYear();
            tempMovie.setMovieYear(currentYear);

        }

        cout << "Would you like to change the number of nominations (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New nominations: " << endl;
            cin >> temp2;
            cin.ignore();
            tempMovie.setNominations(temp2);
        }
        else
        {
            cout << "Keeping number of nominations the same." << endl;
            cout << endl;
            int currentNominations;
            currentNominations = tempPtr->Data().getNominations();
            tempMovie.setNominations(currentNominations);
        }
        cout << "Would you like to change the rating (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New rating: " << endl;
            cin >> temp3;
            cin.ignore();
            tempMovie.setRating(temp3);
        }
        else
        {
            cout << "Keeping rating the same." << endl;
            cout << endl;
            double currentRating;
            currentRating = tempPtr->Data().getRating();
            tempMovie.setRating(currentRating);
        }

        cout << "Would you like to change the duration (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New duration: " << endl;
            cin >> temp2;
            cin.ignore();
            tempMovie.setDuration(temp2);
        }
        else
        {
            cout << "Keeping duration the same." << endl;
            cout << endl;
            int currentDuration;
            currentDuration = tempPtr->Data().getDuration();
            tempMovie.setDuration(currentDuration);
        }

        cout << "Would you like to change genre1 (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New genre1: " << endl;
            cin >> temp;
            cin.ignore();
            tempMovie.setGenre1(temp);
        }
        else
        {
            cout << "Keeping genre1 the same." << endl;
            cout << endl;
            string currentG1;
            currentG1 = tempPtr->Data().getGenre1();
            tempMovie.setGenre1(currentG1);
        }

        cout << "Would you like to change genre2 (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New genre2: " << endl;
            cin >> temp;
            cin.ignore();
            tempMovie.setGenre2(temp);
        }
        else
        {
            cout << "Keeping genre2 the same." << endl;
            cout << endl;
            string currentG2;
            currentG2 = tempPtr->Data().getGenre2();
            tempMovie.setGenre2(currentG2);
        }

        cout << "Would you like to change the release (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New release: " << endl;
            cin >> temp;
            cin.ignore();
            tempMovie.setRelease(temp);
        }
        else
        {
            cout << "Keeping release the same." << endl;
            cout << endl;
            string currentRelease;
            currentRelease = tempPtr->Data().getRelease();
            tempMovie.setRelease(currentRelease);

        }

        cout << "Would you like to change the metacritic (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New metacritic: " << endl;
            cin >> temp2;
            cin.ignore();
            tempMovie.setMetacritic(temp2);
        }
        else
        {
            cout << "Keeping metacritic the same." << endl;
            cout << endl;
            int currentMetacritic;
            currentMetacritic = tempPtr->Data().getMetacritic();
            tempMovie.setMetacritic(currentMetacritic);

        }

        cout << "Would you like to change the synopsis (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y')
        {
            cout << "New synopsis: " << endl;
            getline(cin, temp, '\n');
            tempMovie.setSynopsis(temp);
        }
        else
        {
            cout << "Keeping synopsis the same." << endl;
            cout << endl;
            string currentSynopsis;
            currentSynopsis = tempPtr->Data().getSynopsis();
            tempMovie.setSynopsis(currentSynopsis);
        }

        //set new fields
        tempPtr->setData(tempMovie);
    }
    else
    {
       cout << temp << " could not be found in the database!" << endl;
       cout << endl;
    }
}
void modifyActor(BSTree<Actor, string> *actorTree)
{
    //declarations area
    Actor tempActor;
    string temp;
    int temp2;
    char choice;
    Node<Actor, string> * tempPtr = nullptr;

    //tell user what to do
    cout << "Let's modify an entry in the Actor database!" << endl;
    cout << "Please enter the Name of the actor you'd like to change: " << endl;
    getline(cin, temp, '\n');

    //set tempPtr equal to found node
    tempPtr = actorTree->findNode(temp);

    if(tempPtr != nullptr)
    {
        //tell user what to do
        cout << "First, choose whether you want to change the field. " << endl;
        cout << "If you do, then enter the new field data." << endl;
        cout << endl;

        //actor name stays the same
        tempActor.setActorName(temp);

        cout << "Would you like to change the year (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 'y' || choice == 'Y')
        {
            cout << "New year: " << endl;
            cin >> temp2;
            cin.ignore();
            tempActor.setActorYear(temp2);
        }
        else
        {
            cout << "Keeping year the same." << endl;
            cout << endl;
            int currentYear;
            currentYear = tempPtr->Data().getActorYear();
            tempActor.setActorYear(currentYear);
        }

        cout << "Would you like to change the award (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 'y' || choice == 'Y')
        {
            cout << "New award: " << endl;
            cin >> temp;
            cin.ignore();
            tempActor.setAward(temp);
        }
        else
        {
            cout << "Keeping award the same." << endl;
            cout << endl;
            string currentAward;
            currentAward = tempPtr->Data().getAward();
            tempActor.setAward(currentAward);
        }

        cout << "Would you like to change the winner (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 'y' || choice == 'Y')
        {
            cout << "New winner: " << endl;
            cin >> temp2;
            cin.ignore();
            tempActor.setWinner(temp2);
        }
        else
        {
            cout << "Keeping winner the same." << endl;
            cout << endl;
            int currentWinner;
            currentWinner = tempPtr->Data().getWinner();
            tempActor.setWinner(currentWinner);
        }

        cout << "Would you like to change the film (y/n)?" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 'y' || choice == 'Y')
        {
            cout << "New film: " << endl;
            cin >> temp;
            cin.ignore();
            tempActor.setFilm(temp);
        }
        else
        {
            cout << "Keeping film the same." << endl;
            cout << endl;
            string currentFilm;
            currentFilm = tempPtr->Data().getFilm();
            tempActor.setFilm(currentFilm);
        }

        //set new fields
        tempPtr->setData(tempActor);
    }
    else
    {
        cout << temp << " could not be found in the database!" << endl;
        cout << endl;
    }
}

void deleteMovie(BSTree<Movie, string> *movieTree)
{
    //declarations area
    string temp;

    //tell user what to do
    cout << "Let's delete an entry in the Movie database!" << endl;
    cout << "First, we must find the entry to delete." << endl;
    cout << "Enter the name of the Movie you want to delete: " << endl;
    getline(cin, temp);

    movieTree->deleteNode(temp);
    cout << "Successfully deleted " << temp << " from the Movie database!" << endl;
}
void deleteActor(BSTree<Actor, string> *actorTree)
{
    //declarations area
    string temp;

    //tell user what to do
    cout << "Let's delete an entry in the Actor database!" << endl;
    cout << "First, we must find the entry to delete." << endl;
    cout << "Enter the name of the Actor you want to delete: " << endl;
    getline(cin, temp);

    actorTree->deleteNode(temp);
    cout << "Successfully deleted " << temp << " from the Actor database!" << endl;
}

void sortMovieOnYear(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeYear = new BSTree<Movie, int>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeYear->addNode(tempMovie.getMovieYear(), tempMovie);
    }
    cout << "Successfully re-sorted database on year!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeYear->printInorder();
    }
}

void sortMovieOnNomination(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeNomination = new BSTree<Movie, int>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeNomination->addNode(tempMovie.getNominations(), tempMovie);
    }
    cout << "Successfully re-sorted database on number of nominations!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeNomination->printInorder();
    }
}

void sortMovieOnRating(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, double> *movieTreeRating = new BSTree<Movie, double>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeRating->addNode(tempMovie.getRating(), tempMovie);
    }
    cout << "Successfully re-sorted database on rating!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeRating->printInorder();
    }
}

void sortMovieOnRelease(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, string> *movieTreeRelease = new BSTree<Movie, string>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeRelease->addNode(tempMovie.getRelease(), tempMovie);
    }
    cout << "Successfully re-sorted database on release month!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeRelease->printInorder();
    }
}

void sortMovieOnDuration(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeDuration = new BSTree<Movie, int>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeDuration->addNode(tempMovie.getDuration(), tempMovie);
    }
    cout << "Successfully re-sorted database on duration!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeDuration->printInorder();
    }
}

void sortMovieOnGenre1(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, string> *movieTreeGenre1 = new BSTree<Movie, string>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeGenre1->addNode(tempMovie.getGenre1(), tempMovie);
    }
    cout << "Successfully re-sorted database on genre1!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeGenre1->printInorder();
    }
}

void sortMovieOnGenre2(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, string> *movieTreeGenre2 = new BSTree<Movie, string>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeGenre2->addNode(tempMovie.getGenre2(), tempMovie);
    }
    cout << "Successfully re-sorted database on genre2!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeGenre2->printInorder();
    }
}

void sortMovieOnMetacritic(BSTree<Movie, string> *movieTree)
{
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeMetacritic = new BSTree<Movie, int>;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeMetacritic->addNode(tempMovie.getMetacritic(), tempMovie);
    }
    cout << "Successfully re-sorted database on metacritic score!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        movieTreeMetacritic->printInorder();
    }
}

void sortActorOnYear(BSTree<Actor, string> *actorTree)
{
    //declarations area
    Node<Actor ,string> *tempPtr;
    stack<Node<Actor, string>*> sOut;
    Actor tempActor;
    BSTree<Actor, int> *actorTreeYear = new BSTree<Actor, int>;

    actorTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempActor.setActorName(tempPtr->Data().getActorName());
        tempActor.setActorYear(tempPtr->Data().getActorYear());
        tempActor.setFilm(tempPtr->Data().getFilm());
        tempActor.setWinner(tempPtr->Data().getWinner());
        tempActor.setAward(tempPtr->Data().getAward());

        //push all the data into a new tree, which is sorted on a new field
        actorTreeYear->addNode(tempActor.getActorYear(), tempActor);
    }
    cout << "Successfully re-sorted database on year!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        actorTreeYear->printInorder();
    }
}

void sortActorOnFilm(BSTree<Actor, string> *actorTree)
{
    //declarations area
    Node<Actor ,string> *tempPtr;
    stack<Node<Actor, string>*> sOut;
    Actor tempActor;
    BSTree<Actor, string> *actorTreeFilm = new BSTree<Actor, string>;

    actorTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempActor.setActorName(tempPtr->Data().getActorName());
        tempActor.setActorYear(tempPtr->Data().getActorYear());
        tempActor.setFilm(tempPtr->Data().getFilm());
        tempActor.setWinner(tempPtr->Data().getWinner());
        tempActor.setAward(tempPtr->Data().getAward());

        //push all the data into a new tree, which is sorted on a new field
        actorTreeFilm->addNode(tempActor.getFilm(), tempActor);
    }
    cout << "Successfully re-sorted database on film!" << endl;

    cout << "Would you like to see the updated database (y/n)?" << endl;
    char ch;
    cin >> ch;
    cin.ignore();

    if(ch == 'y' || ch == 'Y')
    {
        actorTreeFilm->printInorder();
    }
}

void searchMovieName(BSTree<Movie, string> *movieTree)
{
    //declarations area
    string temp;
    Node<Movie, string> * tempPtr = nullptr;

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter the name of the movie you'd like to search for: " << endl;
    getline(cin, temp, '\n');

    //call find node function
    tempPtr = movieTree->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different movie name!" << endl;
        cout << endl;
    }//if
    //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr->Data().getRating() << endl;
        cout << "Duration: " << tempPtr->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr = movieTree->findAnotherNode(movieTree->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr->Data().getRating() << endl;
            cout << "Duration: " << tempPtr->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr = movieTree->findAnotherNode(tempPtr, temp);
        }//while
    }//else
}

void searchMovieYear(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
    //declarations area
    Node<Movie, string> *tempPtr;
    Node<Movie, int> *tempPtr2;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeYear = new BSTree<Movie, int>;
    int temp;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeYear->addNode(tempMovie.getMovieYear(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter the year of the movie you'd like to search for: " << endl;
    cin >> temp;
    cin.ignore();

    //call find node function
    tempPtr2 = movieTreeYear->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different movie year!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        /*
        //call findAnotherNode function to see if we have more matching results
        tempPtr = movieTreeYear->findAnotherNode(movieTreeYear->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr->Data().getRating() << endl;
            cout << "Duration: " << tempPtr->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr = movieTreeYear->findAnotherNode(tempPtr, temp);
        }//while
         */
    }//else
}

void searchMovieNomination(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeNomination = new BSTree<Movie, int>;
    int temp;
    Node<Movie, int> * tempPtr2;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeNomination->addNode(tempMovie.getNominations(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter the number of nominations of the movie you'd like to search for: " << endl;
    cin >> temp;
    cin.ignore();

    //call find node function
    tempPtr2 = movieTreeNomination->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different number of movie nominations!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = movieTreeNomination->findAnotherNode(movieTreeNomination->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr2->Data().getRating() << endl;
            cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr2->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr2 = movieTreeNomination->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchMovieRating(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, double> *movieTreeRating = new BSTree<Movie, double>;
    double temp;
    Node<Movie, double> * tempPtr2 = nullptr;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeRating->addNode(tempMovie.getRating(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter the rating of the movie you'd like to search for: " << endl;
    cin >> temp;
    cin.ignore();

    //testing
    //cout << temp;

    //call find node function
    tempPtr2 = movieTreeRating->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different rating for a movie!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = movieTreeRating->findAnotherNode(movieTreeRating->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr2->Data().getRating() << endl;
            cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr2->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr2 = movieTreeRating->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchMovieRelease(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, string> *movieTreeRelease = new BSTree<Movie, string>;
    string temp;
    Node<Movie, string> * tempPtr2 = nullptr;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeRelease->addNode(tempMovie.getRelease(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter the release month of the movie you'd like to search for: " << endl;
    getline(cin, temp, '\n');

    //call find node function
    tempPtr2 = movieTreeRelease->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different release month for a movie!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = movieTreeRelease->findAnotherNode(movieTreeRelease->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr2->Data().getRating() << endl;
            cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr2->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr2 = movieTreeRelease->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchMovieDuration(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeDuration = new BSTree<Movie, int>;
    int temp;
    Node<Movie, int> * tempPtr2 = nullptr;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeDuration->addNode(tempMovie.getDuration(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter the duration of the movie you'd like to search for: " << endl;
    cin >> temp;
    cin.ignore();

    //call find node function
    tempPtr2 = movieTreeDuration->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different duration for a movie!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = movieTreeDuration->findAnotherNode(movieTreeDuration->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr2->Data().getRating() << endl;
            cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr2->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr2 = movieTreeDuration->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchMovieGenre1(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
//declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, string> *movieTreeGenre1 = new BSTree<Movie, string>;
    string temp;
    Node<Movie, string> * tempPtr2 = nullptr;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeGenre1->addNode(tempMovie.getGenre1(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter genre1 of the movie you'd like to search for: " << endl;
    getline(cin, temp, '\n');

    //call find node function
    tempPtr2 = movieTreeGenre1->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different genre1 for a movie!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = movieTreeGenre1->findAnotherNode(movieTreeGenre1->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr2->Data().getRating() << endl;
            cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr2->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr2 = movieTreeGenre1->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchMovieGenre2(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, string> *movieTreeGenre2 = new BSTree<Movie, string>;
    string temp;
    Node<Movie, string> * tempPtr2 = nullptr;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeGenre2->addNode(tempMovie.getGenre2(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter genre2 of the movie you'd like to search for: " << endl;
    getline(cin, temp, '\n');

    //call find node function
    tempPtr2 = movieTreeGenre2->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different genre2 for a movie!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = movieTreeGenre2->findAnotherNode(movieTreeGenre2->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr2->Data().getRating() << endl;
            cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr2->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr2 = movieTreeGenre2->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchMovieMetacritic(BSTree<Movie, string> *movieTree)
{
    //first, sort the movie on the correct field by calling sorting function
    //declarations area
    Node<Movie, string> *tempPtr;
    stack<Node<Movie, string>*> sOut;
    Movie tempMovie;
    BSTree<Movie, int> *movieTreeMetacritic = new BSTree<Movie, int>;
    int temp;
    Node<Movie, int> * tempPtr2 = nullptr;

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempMovie.setMovieName(tempPtr->Data().getMovieName());
        tempMovie.setMovieYear(tempPtr->Data().getMovieYear());
        tempMovie.setNominations(tempPtr->Data().getNominations());
        tempMovie.setRating(tempPtr->Data().getRating());
        tempMovie.setDuration(tempPtr->Data().getDuration());
        tempMovie.setGenre1(tempPtr->Data().getGenre1());
        tempMovie.setGenre2(tempPtr->Data().getGenre2());
        tempMovie.setRelease(tempPtr->Data().getRelease());
        tempMovie.setMetacritic(tempPtr->Data().getMetacritic());
        tempMovie.setSynopsis(tempPtr->Data().getSynopsis());

        //push all the data into a new tree, which is sorted by a new field
        movieTreeMetacritic->addNode(tempMovie.getMetacritic(), tempMovie);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Movie database!" << endl;
    cout << "Please enter the metacritic score of the movie you'd like to search for: " << endl;
    cin >> temp;
    cin.ignore();

    //call find node function
    tempPtr2 = movieTreeMetacritic->findNode(temp);

    //if movie isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Movie database!" << endl;
        cout << "Please try looking for a different metacritic score for a movie!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found movie
        cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
        cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
        cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
        cout << "Rating: " << tempPtr2->Data().getRating() << endl;
        cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
        cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
        cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
        cout << "Release: " << tempPtr2->Data().getRelease() << endl;
        cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
        cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = movieTreeMetacritic->findAnotherNode(movieTreeMetacritic->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found movie
            cout << "Name: " << tempPtr2->Data().getMovieName() << endl;
            cout << "Year: " << tempPtr2->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempPtr2->Data().getNominations() << endl;
            cout << "Rating: " << tempPtr2->Data().getRating() << endl;
            cout << "Duration: " << tempPtr2->Data().getDuration() << endl;
            cout << "Genre1: " << tempPtr2->Data().getGenre1() << endl;
            cout << "Genre2: " << tempPtr2->Data().getGenre2() << endl;
            cout << "Release: " << tempPtr2->Data().getRelease() << endl;
            cout << "Metacritic: " << tempPtr2->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempPtr2->Data().getSynopsis() << endl;
            cout << endl;

            tempPtr2 = movieTreeMetacritic->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchActorName(BSTree<Actor, string> *actorTree)
{
    //declarations area
    string temp;
    Node<Actor, string> * tempPtr = nullptr;

    //tell user what to do
    cout << "Let's search for an entry in the Actor database!" << endl;
    cout << "Please enter the name of the actor you'd like to search for: " << endl;
    getline(cin, temp, '\n');

    //call find node function
    tempPtr = actorTree->findNode(temp);

    //if actor isn't found, then tell user so
    if(tempPtr == nullptr)
    {
        cout << temp << " was not found in the Actor database!" << endl;
        cout << "Please try looking for a different actor name!" << endl;
        cout << endl;
    }//if
    //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found actor
        cout << "Name: " << tempPtr->Data().getActorName() << endl;
        cout << "Year: " << tempPtr->Data().getActorYear() << endl;
        cout << "Award: " << tempPtr->Data().getAward() << endl;
        cout << "Winner: " << tempPtr->Data().getWinner() << endl;
        cout << "Film: " << tempPtr->Data().getFilm() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr = actorTree->findAnotherNode(actorTree->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr != nullptr)
        {
            //print out all the info on found actor
            cout << "Name: " << tempPtr->Data().getActorName() << endl;
            cout << "Year: " << tempPtr->Data().getActorYear() << endl;
            cout << "Award: " << tempPtr->Data().getAward() << endl;
            cout << "Winner: " << tempPtr->Data().getWinner() << endl;
            cout << "Film: " << tempPtr->Data().getFilm() << endl;
            cout << endl;

            tempPtr = actorTree->findAnotherNode(tempPtr, temp);
        }//while
    }//else
}


void searchActorYear(BSTree<Actor, string> *actorTree)
{
    //first, sort the actor on the correct field by calling sorting function
    //declarations area
    Node<Actor ,string> *tempPtr;
    stack<Node<Actor, string>*> sOut;
    Actor tempActor;
    BSTree<Actor, int> *actorTreeYear = new BSTree<Actor, int>;
    int temp;
    Node<Actor, int> * tempPtr2 = nullptr;

    actorTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempActor.setActorName(tempPtr->Data().getActorName());
        tempActor.setActorYear(tempPtr->Data().getActorYear());
        tempActor.setFilm(tempPtr->Data().getFilm());
        tempActor.setWinner(tempPtr->Data().getWinner());
        tempActor.setAward(tempPtr->Data().getAward());

        //push all the data into a new tree, which is sorted on a new field
        actorTreeYear->addNode(tempActor.getActorYear(), tempActor);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Actor database!" << endl;
    cout << "Please enter the year of the actor you'd like to search for: " << endl;
    cin >> temp;
    cin.ignore();

    //call find node function
    tempPtr2 = actorTreeYear->findNode(temp);

    //if actor isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Actor database!" << endl;
        cout << "Please try looking for a different actor year!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found actor
        cout << "Name: " << tempPtr2->Data().getActorName() << endl;
        cout << "Year: " << tempPtr2->Data().getActorYear() << endl;
        cout << "Award: " << tempPtr2->Data().getAward() << endl;
        cout << "Winner: " << tempPtr2->Data().getWinner() << endl;
        cout << "Film: " << tempPtr2->Data().getFilm() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = actorTreeYear->findAnotherNode(actorTreeYear->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found actor
            cout << "Name: " << tempPtr2->Data().getActorName() << endl;
            cout << "Year: " << tempPtr2->Data().getActorYear() << endl;
            cout << "Award: " << tempPtr2->Data().getAward() << endl;
            cout << "Winner: " << tempPtr2->Data().getWinner() << endl;
            cout << "Film: " << tempPtr2->Data().getFilm() << endl;
            cout << endl;

            tempPtr2 = actorTreeYear->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void searchActorFilm(BSTree<Actor, string> *actorTree)
{
    //first, sort the actor on the correct field by calling sorting function
    //declarations area
    Node<Actor ,string> *tempPtr;
    stack<Node<Actor, string>*> sOut;
    Actor tempActor;
    BSTree<Actor, string> *actorTreeFilm = new BSTree<Actor, string>;
    string temp;
    Node<Actor, string> * tempPtr2 = nullptr;

    actorTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempPtr = sOut.top();
        sOut.pop();

        //go through every field
        tempActor.setActorName(tempPtr->Data().getActorName());
        tempActor.setActorYear(tempPtr->Data().getActorYear());
        tempActor.setFilm(tempPtr->Data().getFilm());
        tempActor.setWinner(tempPtr->Data().getWinner());
        tempActor.setAward(tempPtr->Data().getAward());

        //push all the data into a new tree, which is sorted on a new field
        actorTreeFilm->addNode(tempActor.getFilm(), tempActor);
    }

    //tell user what to do
    cout << "Let's search for an entry in the Actor database!" << endl;
    cout << "Please enter the film of the actor you'd like to search for: " << endl;
    getline(cin, temp, '\n');

    //call find node function
    tempPtr2 = actorTreeFilm->findNode(temp);

    //if actor isn't found, then tell user so
    if(tempPtr2 == nullptr)
    {
        cout << temp << " was not found in the Actor database!" << endl;
        cout << "Please try looking for a different actor film!" << endl;
        cout << endl;
    }//if
        //else if it is found, print out what was found and look into multiple records (if any)
    else
    {
        //print out all the info on found actor
        cout << "Name: " << tempPtr2->Data().getActorName() << endl;
        cout << "Year: " << tempPtr2->Data().getActorYear() << endl;
        cout << "Award: " << tempPtr2->Data().getAward() << endl;
        cout << "Winner: " << tempPtr2->Data().getWinner() << endl;
        cout << "Film: " << tempPtr2->Data().getFilm() << endl;
        cout << endl;

        //call findAnotherNode function to see if we have more matching results
        tempPtr2 = actorTreeFilm->findAnotherNode(actorTreeFilm->findNode(temp), temp);

        //while we have more matching results, print them out too
        while(tempPtr2 != nullptr)
        {
            //print out all the info on found actor
            cout << "Name: " << tempPtr2->Data().getActorName() << endl;
            cout << "Year: " << tempPtr2->Data().getActorYear() << endl;
            cout << "Award: " << tempPtr2->Data().getAward() << endl;
            cout << "Winner: " << tempPtr2->Data().getWinner() << endl;
            cout << "Film: " << tempPtr2->Data().getFilm() << endl;
            cout << endl;

            tempPtr2 = actorTreeFilm->findAnotherNode(tempPtr2, temp);
        }//while
    }//else
}

void partialSearchMovieName(BSTree<Movie, string> *movieTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Movie, string> *tempNode;
    stack<Node<Movie, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Movie database!" << endl;
    cout << "Please enter the Name of the movie you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        string str = tempNode->Data().getMovieName();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getMovieName() << endl;
            cout << "Year: " << tempNode->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempNode->Data().getNominations() << endl;
            cout << "Rating: " << tempNode->Data().getRating() << endl;
            cout << "Duration: " << tempNode->Data().getDuration() << endl;
            cout << "Genre1: " << tempNode->Data().getGenre1() << endl;
            cout << "Genre2: " << tempNode->Data().getGenre2() << endl;
            cout << "Release: " << tempNode->Data().getRelease() << endl;
            cout << "Metacritic: " << tempNode->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempNode->Data().getSynopsis() << endl;
            cout << endl;
        }
    }
}


void partialSearchMovieRelease(BSTree<Movie, string> *movieTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Movie, string> *tempNode;
    stack<Node<Movie, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Movie database!" << endl;
    cout << "Please enter the release month of the movie you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        string str = tempNode->Data().getRelease();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getMovieName() << endl;
            cout << "Year: " << tempNode->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempNode->Data().getNominations() << endl;
            cout << "Rating: " << tempNode->Data().getRating() << endl;
            cout << "Duration: " << tempNode->Data().getDuration() << endl;
            cout << "Genre1: " << tempNode->Data().getGenre1() << endl;
            cout << "Genre2: " << tempNode->Data().getGenre2() << endl;
            cout << "Release: " << tempNode->Data().getRelease() << endl;
            cout << "Metacritic: " << tempNode->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempNode->Data().getSynopsis() << endl;
            cout << endl;
        }
    }
}

void partialSearchMovieGenre1(BSTree<Movie, string> *movieTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Movie, string> *tempNode;
    stack<Node<Movie, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Movie database!" << endl;
    cout << "Please enter genre1 of the movie you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        string str = tempNode->Data().getGenre1();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getMovieName() << endl;
            cout << "Year: " << tempNode->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempNode->Data().getNominations() << endl;
            cout << "Rating: " << tempNode->Data().getRating() << endl;
            cout << "Duration: " << tempNode->Data().getDuration() << endl;
            cout << "Genre1: " << tempNode->Data().getGenre1() << endl;
            cout << "Genre2: " << tempNode->Data().getGenre2() << endl;
            cout << "Release: " << tempNode->Data().getRelease() << endl;
            cout << "Metacritic: " << tempNode->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempNode->Data().getSynopsis() << endl;
            cout << endl;
        }
    }
}


void partialSearchMovieGenre2(BSTree<Movie, string> *movieTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Movie, string> *tempNode;
    stack<Node<Movie, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Movie database!" << endl;
    cout << "Please enter genre2 of the movie you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    movieTree->treeToStack(sOut); //n
    
    //we're not iterating n times, we are iterating however many items are in the stack times
    //which makes it n, not n*n, it would be constant # times n (making it n)

    while(!sOut.empty()) //n+n = 2n (which is n)
    {
        tempNode = sOut.top();
        sOut.pop();
        
        string str = tempNode->Data().getGenre2();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))//n
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getMovieName() << endl;
            cout << "Year: " << tempNode->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempNode->Data().getNominations() << endl;
            cout << "Rating: " << tempNode->Data().getRating() << endl;
            cout << "Duration: " << tempNode->Data().getDuration() << endl;
            cout << "Genre1: " << tempNode->Data().getGenre1() << endl;
            cout << "Genre2: " << tempNode->Data().getGenre2() << endl;
            cout << "Release: " << tempNode->Data().getRelease() << endl;
            cout << "Metacritic: " << tempNode->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempNode->Data().getSynopsis() << endl;
            cout << endl;
        }
    }
}

void partialSearchMovieSynopsis(BSTree<Movie, string> *movieTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Movie, string> *tempNode;
    stack<Node<Movie, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Movie database!" << endl;
    cout << "Please enter the synopsis of the movie you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    movieTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        string str = tempNode->Data().getSynopsis();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getMovieName() << endl;
            cout << "Year: " << tempNode->Data().getMovieYear() << endl;
            cout << "Nominations: " << tempNode->Data().getNominations() << endl;
            cout << "Rating: " << tempNode->Data().getRating() << endl;
            cout << "Duration: " << tempNode->Data().getDuration() << endl;
            cout << "Genre1: " << tempNode->Data().getGenre1() << endl;
            cout << "Genre2: " << tempNode->Data().getGenre2() << endl;
            cout << "Release: " << tempNode->Data().getRelease() << endl;
            cout << "Metacritic: " << tempNode->Data().getMetacritic() << endl;
            cout << "Synopsis: " << tempNode->Data().getSynopsis() << endl;
            cout << endl;
        }
    }
}

void partialSearchActorName(BSTree<Actor, string> *actorTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Actor, string> *tempNode;
    stack<Node<Actor, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Actor database!" << endl;
    cout << "Please enter the name of the actor you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    actorTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        string str = tempNode->Data().getActorName();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getActorName() << endl;
            cout << "Year: " << tempNode->Data().getActorYear() << endl;
            cout << "Award: " << tempNode->Data().getAward() << endl;
            cout << "Winner: " << tempNode->Data().getWinner() << endl;
            cout << "Film: " << tempNode->Data().getFilm() << endl;
            cout << endl;
        }
    }
}

void partialSearchActorAward(BSTree<Actor, string> *actorTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Actor, string> *tempNode;
    stack<Node<Actor, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Actor database!" << endl;
    cout << "Please enter the award of the actor you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    actorTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        string str = tempNode->Data().getAward();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getActorName() << endl;
            cout << "Year: " << tempNode->Data().getActorYear() << endl;
            cout << "Award: " << tempNode->Data().getAward() << endl;
            cout << "Winner: " << tempNode->Data().getWinner() << endl;
            cout << "Film: " << tempNode->Data().getFilm() << endl;
            cout << endl;
        }
    }
}

void partialSearchActorFilm(BSTree<Actor, string> *actorTree)
{
    //declarations area;
    string str2; //substring we are looking for
    Node<Actor, string> *tempNode;
    stack<Node<Actor, string> *> sOut;

    //tell user what to do
    cout << "Let's partial search for an entry in the Actor database!" << endl;
    cout << "Please enter the film of the actor you'd like to search for: " << endl;
    getline(cin, str2, '\n');

    for(int i = 0; i < str2.length(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    actorTree->treeToStack(sOut);

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        string str = tempNode->Data().getFilm();

        for(int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        if(string::npos != str.find(str2))
        {
            //print out all the info on found movie
            cout << "Name: " << tempNode->Data().getActorName() << endl;
            cout << "Year: " << tempNode->Data().getActorYear() << endl;
            cout << "Award: " << tempNode->Data().getAward() << endl;
            cout << "Winner: " << tempNode->Data().getWinner() << endl;
            cout << "Film: " << tempNode->Data().getFilm() << endl;
            cout << endl;
        }
    }
}

void writeMovieReportToFile(BSTree<Movie, string> *movieTree, string outfile)
{
    //declarations area
    ofstream out;
    out.open(outfile);
    Node<Movie, string> *tempNode;
    stack<Node<Movie, string>*> sOut;

    movieTree->treeToStack(sOut);

    out << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis";

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        out << "\n";
        out << tempNode->Data().getMovieName();
        out << ",";

        out << tempNode->Data().getMovieYear();
        out << ",";

        out << tempNode->Data().getNominations();
        out << ",";

        out << tempNode->Data().getRating();
        out << ",";

        out << tempNode->Data().getDuration();
        out << ",";

        out << tempNode->Data().getGenre1();
        out << ",";

        out << tempNode->Data().getGenre2();
        out << ",";

        out << tempNode->Data().getRelease();
        out << ",";

        out << tempNode->Data().getMetacritic();
        out << ",";

        out << tempNode->Data().getSynopsis();
        out << ",";
    }
    //tell user they've successfully wrote their database out to a file
    cout << "Movies database successfully written out to " << outfile << endl;
    cout << endl;

    out.close();
}

void writeActorReportToFile(BSTree<Actor, string> *actorTree, string outfile)
{
    //declarations area
    ofstream out;
    out.open(outfile);
    Node<Actor, string> *tempNode;
    stack<Node<Actor, string>*> sOut;

    actorTree->treeToStack(sOut);

    out << "year,award,winner,name,film";

    while(!sOut.empty())
    {
        tempNode = sOut.top();
        sOut.pop();

        out << "\n";
        out << tempNode->Data().getActorYear();
        out << ",";

        out << tempNode->Data().getAward();
        out << ",";

        out << tempNode->Data().getWinner();
        out << ",";

        out << tempNode->Data().getActorName();
        out << ",";

        out << tempNode->Data().getFilm();
        out << ",";
    }
    //tell user they've successfully wrote their database out to a file
    cout << "Actor database successfully written out to " << outfile << endl;
    cout << endl;

    out.close();
}