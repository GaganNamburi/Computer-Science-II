//
//  Faculty.cpp
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

Faculty::Faculty()
{
    Ramanite();
}

void Faculty::get_courses(std::string *courses)
{
    
}

size_t Faculty::get_start_date()
{
    return this-> start_date;
}

std::string Faculty::get_office_number()
{
    return this-> office_number;
}
