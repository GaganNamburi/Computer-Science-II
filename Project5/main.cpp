//
//  main.cpp
//  Project 5
//
//  Created by Gagan Namburi on 7/31/17.
//  Copyright © 2017 Gagan Namburi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Student.h"

using namespace std;

//Prototypes
void print_menu();
unsigned int get_selection();
void print_all_students(vector<Student> &info, unsigned int numStudents);
void print_by_year(vector<Student> &info, unsigned int numStudents);

int main()
{
    srand((unsigned int)time(NULL));
    
    //Variable Declarations
    unsigned int selection = 0;
    unsigned short numStudents = 0;
    bool added = 0;
    vector<Student> info;
    Student obj;
    string name;
    double gpa = 0.0;
    size_t year = 0;
    
    //Menu with selection choices
    do
    {
        selection = get_selection();
        
        switch(selection)
        {
            case 1:
                if (added == 0)
                {
                    do
                    {
                        cout << "How many students would you like to add?" << endl;
                        cin >> numStudents;
                    }while(numStudents <= 0);
                    
                    //Stores all the inputted values in vector of objects
                    for(unsigned int i = 0; i < numStudents; i++)
                    {
                        cin.ignore();
                        obj = *new Student;
                        obj.prompt_for_student_info();
                        
                        obj.set_fullname(name);
                        obj.set_gpa(gpa);
                        obj.set_year(year);
                        info.push_back(obj);
                    }
                    added = 1;
                }
                else
                {
                    cout << "Sorry, you can only add students once.\n\n";
                }
                break;
            case 2:
                print_all_students(info, numStudents);
                break;
            case 3:
                print_by_year(info, numStudents);
                break;
        }
    }while(selection != 4);
}

void print_menu()
{
    //Full menu
    cout << "Welcome to the RCNJ Registrar" << endl;
    cout << "[1] Add all students" << endl;
    cout << "[2] View all students" << endl;
    cout << "[3] View all students by year" << endl;
    cout << "[4] Quit" << endl;
    
    return;
}

unsigned int get_selection()
{
    //Variable Declaration
    unsigned int selection;
    
    //Menu selection with validation
    do
    {
        print_menu();
        cin >> selection;
    }while(!(selection >= 1 && selection <= 4));
    
    return selection;
}

void print_all_students(vector<Student> &info, unsigned int numStudents)
{
    for(unsigned int i = 0; i < numStudents; i++)
    {
        cout << info[i].get_fullname() << " " << info[i].get_rnum() << endl;
    }
    
    return;
}

void print_by_year(vector<Student> &info, unsigned int numStudents)
{
    //Variable Declarations
    bool at_least_one = 0;
    size_t year;
    
    do
    {
        cout << "Which year would you like to display?" << endl;
        cin >> year;
    }while(!(year >= 1972 && year <= 2015));
    
    for(unsigned int i = 0; i < numStudents; i++)
    {
        if(year == info[i].get_year())
        {
            at_least_one = 1;
            cout << info[i].get_fullname() << " - " << info[i].get_rnum() << endl;
        }
    }
    
    if(!at_least_one)
    {
        cout << "No students that year." << endl;
    }
}
