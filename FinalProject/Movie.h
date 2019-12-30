#ifndef Movie_h
#define Movie_h

#include <iostream>
#include <string>

class Movie
{
    private:
        std::string m_title;
        std::string rel_date;
        unsigned short rating;
    
public:
    Movie();
    
    //Accessors
    std::string get_m_title();
    std::string get_rel_date();
    unsigned short get_rating();
    
    //Mutators
    void set_m_title(std::string m);
    void set_rel_date(std::string r);
    void set_rating(unsigned short rate);
    
    void prompt_for_movie_title();
    void prompt_for_rel_date();
    void prompt_for_rating();
    void prompt_for_movie_info();
};


#endif /* Movie_h */
