/* NAME: Tammy Husnetdinova
CLASS: CSCI 2421-001
ASSIGNMENT: FINAL PROJECT
DUE DATE: 12/06/18
 */

//preprocessor directives
#include <iostream>
#include <string>
using namespace std;
#ifndef HUSNETDINOVAPROJECT_ACTOR_H
#define HUSNETDINOVAPROJECT_ACTOR_H

class Actor
{
private:
    //variables for all the fields in the actor database
    int actorYear;
    string award;
    int winner;
    string actorName;
    string film;
public:
    //default constructor
    Actor(){actorYear = 0; award = ""; winner = true; actorName = ""; film = "";}

    //getters and setters
    int getActorYear(){return actorYear;}
    void setActorYear(int _actorYear){actorYear = _actorYear;}
    string getAward(){return award;}
    void setAward(string _award){award = _award;}
    int getWinner(){return winner;}
    void setWinner(int _winner){winner = _winner;}
    string getActorName(){return actorName;}
    void setActorName(string _actorName){actorName = _actorName;}
    string getFilm(){return film;}
    void setFilm(string _film){film = _film;}

    //overloaded < operator
    bool operator < (Actor &a){return a.getActorName() < actorName;}

    //print function
    void print()
    {
        cout << "Name: " << actorName << endl;
        cout << "Year: " << actorYear << endl;
        cout << "Winner : " << winner << endl;
        cout << "Award: " << award << endl;
        cout << "Film: " << film << endl;
    }
};

#endif //HUSNETDINOVAPROJECT_ACTOR_H
