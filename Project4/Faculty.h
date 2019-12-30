#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>

#include "Ramanite.h"

class Faculty : public Ramanite
{
    private:
        std::string office_number;
        size_t start_date;
        std::string courses[3];
        
    public:
        Faculty();
    
        /* Accessors */
        void get_courses(std::string * courses);
        size_t get_start_date();
        std::string get_office_number();
};

#endif
