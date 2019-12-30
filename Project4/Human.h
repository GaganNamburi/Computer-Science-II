/* CMPS 148
 * Project 4
 * Human.h 
 * Benjamin T. Fine
 * 07/27/2017
 *
 * DO NOT CHANGE THIS FILE
 */

#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>

class Human
{
    private: 
        size_t ssn;

        void generate_ssn();

    protected:
        std::string first_name;
        std::string last_name;
        std::string middle_name;
    
        size_t age;
        bool gender;

        /* This function will get the fullname, as on string, from the user 
         * and parse it into the three member variables.
         *
         * Note:  You must validate their input.  Makes sure the user gives 
         * you atleast a first and last name AND no more than a first, last, 
         * and middle 
         */
        void prompt_for_name();
        
    public:
        Human();

        /* Accessors */
        std::string get_fullname();
        std::string get_first_name();
        std::string get_middle_name();
        std::string get_last_name();
        
        /* Mutators */
        void set_first_name(std::string s);
        void set_middle_name(std::string s);
        void set_last_name(std::string s);
};

#endif
