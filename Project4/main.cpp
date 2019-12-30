//
//  main.cpp
//  Project 4
//
//  Created by Gagan Namburi on 7/26/17.
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

using namespace std;

//Prototypes
void print_menu();
unsigned int get_selection();
void print_all(Human humans[], Student students[], unsigned short numstudents);

int main()
{
    srand((unsigned int)time(NULL));
    
    //Variable Declaration
    unsigned int selection = 0;
    int count = 0;
    bool selection_1 = false;
    bool selection_4 = false;
    
    Human *humans = {};
    Student *students = {};
    //Menu of Program
    do
    {
        selection = get_selection();
        
        switch(selection)
        {
            case 1:
            {
                if(selection_1 == true)
                {
                    cout << "You can only enter students once" <<endl;
                    break;
                }
                
                
                cout << "How many students? ";
                cin >> count;
                
                
                humans = new Human[count];
                students = new Student[count];
                
                selection_1 = true;
            }
                break;
            case 2:
                print_all(humans, students, count);
                break;
            case 3:
                break;
            case 4:
                if(selection_4 == true)
                {
                    cout << "You can only enter faculty once" <<endl;
                }
                break;
            case 5:
                break;
        }
    }while(selection != 6);
}

void print_menu()
{
    //Full menu that users first see in the program
    cout << "Welcome to the RCNJ Student Database." <<endl;
    cout << "[1] Add all students" <<endl;
    cout << "[2] Display all students" <<endl;
    cout << "[3] Display students by year" <<endl;
    cout << "[4] Add all faculty" <<endl;
    cout << "[5] Display all faculty" <<endl;
    cout << "[6] Quit" <<endl;
    
    return;
}

unsigned int get_selection()
{
    //Variable Declaration
    unsigned int selection;
    
    //Menu and selection
    do
    {
        print_menu();
        cin >> selection;
    }while(!(selection >= 1 && selection <= 7));
    
    return selection;
}

void print_all(Human humans[], Student students[], unsigned short numstudents)
{
    //Print all students
    for(int i = 0; i < numstudents; i++)
    {
        cout << humans[i].get_fullname() << " - " << students[i].get_rnum() <<endl;
    }
    
    return;
}
