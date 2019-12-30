//
//  Student.cpp
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

void Student::set_expected_graduation()
{
    this -> year_expected_graduation = year_enrolled + 4;
    
    return;
}

Student::Student()
{
    double gpa;
    do
    {
        std::cout << "Please enter the GPA: ";
        std::cin >> gpa;
    }while(!(gpa >= 0.0 && gpa <= 4.0));
    this->set_gpa(gpa);
    
    size_t year_enrolled;
    do
    {
        std::cout << "Please enter the year enrolled: ";
        std::cin >> year_enrolled;
    }while(!(year_enrolled >= 1972 && year_enrolled <= 2015));
    this->set_year_enrolled(year_enrolled);
    this->set_expected_graduation();
    this->generate_rnum();
}

double Student::get_gpa()
{
    return this-> gpa;
}

size_t Student::get_year_enrolled()
{
    return this-> year_enrolled;
}

size_t Student::get_year_expected_graduation()
{
    return this-> year_expected_graduation;
}

void Student::set_gpa(double gpa)
{
    this->gpa = gpa;
}

void Student::set_year_enrolled(size_t year_enrolled)
{
    this -> year_enrolled = year_enrolled;
}
