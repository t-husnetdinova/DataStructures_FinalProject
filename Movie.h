/* NAME: Tammy Husnetdinova
CLASS: CSCI 2421-001
ASSIGNMENT: FINAL PROJECT
DUE DATE: 12/06/18
 */

//preprocessor directives
#include <iostream>
#include <string>
using namespace std;
#ifndef HUSNETDINOVAPROJECT_MOVIE_H
#define HUSNETDINOVAPROJECT_MOVIE_H

class Movie
{
private:
    //variables for all the fields in the movie database
    string movieName;
    int movieYear;
    int nominations;
    double rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;

public:
    //default constructor
    Movie(){movieName = ""; movieYear = 0; nominations = 0; rating = 0.0; duration = 0; genre1 = ""; genre2 = ""; release = ""; metacritic = 0; synopsis = "";}

    //getters and setters
    string getMovieName(){return movieName;}
    void setMovieName(string _movieName){movieName = _movieName;}
    int getMovieYear(){return movieYear;}
    void setMovieYear(int _movieYear){movieYear = _movieYear;}
    int getNominations(){return nominations;}
    void setNominations(int _nominations){nominations = _nominations;}
    double getRating(){return rating;}
    void setRating(double _rating){rating = _rating;}
    int getDuration(){return duration;}
    void setDuration(int _duration){duration = _duration;}
    string getGenre1(){return genre1;}
    void setGenre1(string _genre1){genre1 = _genre1;}
    string getGenre2(){return genre2;}
    void setGenre2(string _genre2){genre2 = _genre2;}
    string getRelease(){return release;}
    void setRelease(string _release){release = _release;}
    int getMetacritic(){return metacritic;}
    void setMetacritic(int _metacritic){ metacritic = _metacritic;}
    string getSynopsis(){return synopsis;}
    void setSynopsis(string _synopsis){synopsis = _synopsis;}

    //overloaded < operator
    bool operator < (Movie &m) {return m.getMovieName() < movieName;}

    //print function
    void print()
    {
        cout << "Name: " << movieName << endl;
        cout << "Year: " << movieYear << endl;
        cout << "Nominations: " << nominations << endl;
        cout << "Rating: " << rating << endl;
        cout << "Duration: " << duration << endl;
        cout << "Genre1: " << genre1 << endl;
        cout << "Genre2: " << genre2 << endl;
        cout << "Release: " << release << endl;
        cout << "Metacritic: " << metacritic << endl;
        cout << "Synopsis: " << synopsis << endl;
    }
};
#endif //HUSNETDINOVAPROJECT_MOVIE_H
