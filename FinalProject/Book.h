#ifndef Book_h
#define Book_h

#include <iostream>
#include <string>

class Book
{
    private:
        std::string b_title;
        std::string author;
        std::string publisher;
    
    public:
        Book();
    
        //Accessors
        std::string get_b_title();
        std::string get_author();
        std::string get_publisher();
    
        //Mutators
        void set_b_title(std::string t);
        void set_author(std::string a);
        void set_publisher(std::string p);
    
        void prompt_for_title();
        void prompt_for_author();
        void prompt_for_publisher();
        void prompt_for_book_info();
};

#endif /* Book_h */
