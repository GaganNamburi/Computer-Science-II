/* CMPS 148
 * Project 4
 * Ramanite.h 
 * Benjamin T. Fine
 * 07/27/2017
 *
 * DO NOT CHANGE THIS FILE
 */

#ifndef RAMANITE_H
#define RAMANITE_H

#include <iostream>
#include <string>
#include "Human.h"

class Ramanite : public Human
{
    protected:
        size_t rnum;

        void generate_rnum();

    public:
        Ramanite();

        /* Accessors */
        size_t get_rnum();

        /* Mutators */
};

#endif
