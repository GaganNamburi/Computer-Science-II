/* CMPS 148
 * Project 4
 * Student.h 
 * Benjamin T. Fine
 * 07/27/2017
 *
 * DO NOT CHANGE THIS FILE
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Ramanite.h"

class Student : public Ramanite
{
    private:
        double gpa;
        size_t year_enrolled;
        size_t year_expected_graduation;  //always 4 years after enrolled year

        //sets the graduate year when the user gives year enrolled    
        void set_expected_graduation();

    public:
        Student();

        /* Accessors */
        double get_gpa();
        size_t get_year_enrolled();
        size_t get_year_expected_graduation();

        /* Mutators */
        void set_gpa(double gpa);
        void set_year_enrolled(size_t year_enrolled);
};

#endif
