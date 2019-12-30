#ifndef Item_h
#define Item_h
#include "Book.h"
#include "Movie.h"

class Item: protected Book, protected Movie
{
    private:
    
    public:
        void writeBookFile(std::string b, std::string a, std::string p);
        void writeMovieFile(std::string m, std::string re, unsigned short ra);
        void deleteBookFile();
        void deleteMovieFile();
        void viewBookFile();
        void viewMovieFile();
        void searchBookFile(std::string t);
        void searchMovieFile(std::string t);

};


#endif /* Item_h */
