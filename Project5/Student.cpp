/*
 Gagan Namburi
 Dr. Fine
 CMPS 148
 3 August 2017
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Student.h"

void Student::compute_rnum()
{
    size_t rNumber;
    rNumber = rand() % 99999 + 10000;
    
    this->rnum = rNumber;
}

//Accessors
std::string Student::get_fullname()
{
    return this->first_name + " " + this->middle_name + " " + this->last_name;
}

double Student::get_gpa()
{
    return this->gpa;
}

size_t Student::get_year()
{
    return this->year;
}

size_t Student::get_rnum()
{
    return this->rnum;
}

//Mutators
void Student::set_fullname(std::string s)
{
    s = this->first_name + " " + this->middle_name + " " + this->last_name;
}

void Student::set_gpa(double g)
{
    g = this->gpa;
}

void Student::set_year(size_t y)
{
    y = this->year;
}

void Student::prompt_for_name()
{
    std::string line;
    static std::vector<std::string> tokens;
    
    //get the users name
    std::cout << "Please enter the student's name: ";
    getline(std::cin, line);
    
    //break the fullname down to parts
    tokens.clear();
    size_t pos = 0, found;
    while((found = line.find_first_of(' ', pos)) != std::string::npos)
    {
        tokens.push_back(line.substr(pos, found - pos));
        pos = found+1;
    }
    tokens.push_back(line.substr(pos));
    
    this->first_name = tokens[0];
    this->last_name = tokens[tokens.size()-1];
    
    if (tokens.size() == 3)
        this->middle_name = tokens[1];
}

void Student::prompt_for_year()
{
    do
    {
        std::cout << "Please enter the year: ";
        std::cin >> this->year;
    }while(!(this->year >= 1972 && this->year <= 2015));
}

void Student::prompt_for_gpa()
{
    do
    {
        std::cout << "Please enter the GPA: ";
        std::cin >> this->gpa;
    }while(!(this->gpa >= 0.0 && this->gpa <= 4.0));
}

void Student::prompt_for_student_info()
{
    prompt_for_name();
    prompt_for_gpa();
    prompt_for_year();
}

//Function that returns true if the left student enrolled before the right student
bool Student::operator<(const Student & right_student)
{
    bool before_right = 0;
    
    if(this->year < right_student.year)
    {
        before_right = 1;
    }
    
    return before_right;
}

//Function that returns true if the left student enrolls after the right student
bool Student::operator>(const Student & right_student)
{
    bool after_right = 0;
    if(this->year > right_student.year)
    {
        after_right = 1;
    }
    
    return after_right;
}

//Function that returns true if the left student enrolls before
//or at the same time as the right student
bool Student::operator<=(const Student & right_student)
{
    bool before_or_same = 0;
    
    if(this->year <= right_student.year)
    {
        before_or_same = 1;
    }
    
    return before_or_same;
}

//Function that returns true if the left student enrolls after
//or at the same time as the right student
bool Student::operator>=(const Student & right_student)
{
    bool after_or_same = 0;
    
    if(this-> year <= right_student.year)
    {
        after_or_same = 1;
    }
    
    return after_or_same;
}

//Function that returns true if both students have identical information
bool Student::operator==(const Student & right_student)
{
    bool same_info = 0;
    
    if((right_student.year && right_student.gpa) == (this->year && this->gpa))
    {
        if(this->first_name == right_student.first_name)
        {
            if(this->middle_name == right_student.middle_name)
            {
                if(this->last_name == right_student.last_name)
                {
                    same_info = 1;
                }
            }
        }
    }
    
    return same_info;
}

//Function that returns true if both students do nothave identical information
bool Student::operator!=(const Student & right_student)
{
    bool not_same_info = 0;
    
    if((right_student.year && right_student.gpa) != (this->year && this-> gpa))
    {
        if(this->first_name != right_student.first_name)
        {
            if(this->middle_name != right_student.middle_name)
            {
                if(this->last_name != right_student.last_name)
                {
                    not_same_info = 1;
                }
            }
        }
    }
    
    return not_same_info;
}

//Function that fills missing information of right student with information from left student
Student Student::operator+(const Student & right_student)
{
    Student left_student;
    Student fillStudent = right_student;
    
    if(right_student.first_name == "No first name")
    {
        fillStudent.first_name = left_student.first_name;
    }
    
    if(right_student.middle_name == "No middle name")
    {
        fillStudent.middle_name = left_student.middle_name;
    }
    
    if(right_student.last_name == "No last name")
    {
        fillStudent.last_name = left_student.last_name;
    }
    
    if(right_student.gpa == -0.1)
    {
        fillStudent.gpa = left_student.gpa;
    }
    
    if(right_student.year == 0)
    {
        fillStudent.year = left_student.year;
    }
    
    return fillStudent;
}

//Function that fills missing information of left student with information from right student
Student Student::operator-(const Student & right_student)
{
    //Variable Declarations
    Student left_student;
    Student fillStudent = left_student;
    
    if(left_student.first_name == "No first name")
    {
        fillStudent.first_name = right_student.first_name;
    }
    
    if(left_student.middle_name == "No middle name")
    {
        fillStudent.middle_name = right_student.middle_name;
    }
    
    if(left_student.last_name == "No last name")
    {
        fillStudent.last_name = right_student.last_name;
    }
    
    if(left_student.gpa == -0.1)
    {
        fillStudent.gpa = right_student.gpa;
    }
    
    if(left_student.year == 0)
    {
        fillStudent.year = right_student.year;
    }
    
    return fillStudent;
}

//Function that increments gpa by 0.10 unless it is 4.0
Student Student::operator++(int dummy)
{
    Student inc;
    
    if(inc.gpa == 4.0)
    {
        return inc;
    }
    else
    {
        inc.operator++(0.10);
    }
    
    return inc;
}

//Function that decrements gpa by 0.10 unless it is 0.0
Student Student::operator--(int dummy)
{
    Student dec;
    
    if(dec.gpa == 0.0)
    {
        return dec;
    }
    else
    {
        dec.operator--(0.10);
    }
    
    return dec;
}
