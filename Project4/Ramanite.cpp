//
//  Ramanite.cpp
//  Project 4
//
//  Created by Gagan Namburi on 7/28/17.
//  Copyright © 2017 Gagan Namburi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Student.h"
#include "Ramanite.h"
#include "Human.h"
#include "Faculty.h"

void Ramanite::generate_rnum()
{
    this-> rnum = rand() & 99999+10000;
    
    return;
}

Ramanite::Ramanite()
{
    generate_rnum();
}

size_t Ramanite::get_rnum()
{
    return this-> rnum;
}
