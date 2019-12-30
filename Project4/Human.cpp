//
//  Human.cpp
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

//using namespace std;

void Human::generate_ssn()
{
    this-> ssn = rand() % 999999999+100000000;
}

void Human::prompt_for_name()
{
    std::string line;
    static std::vector<std::string> tokens;
    
    do
    {
        //get the users name
        std::cout << "Please enter the student's name: ";
        std::cin.ignore();
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
    }while(tokens.size() != 2 && tokens.size() != 3);

    return;
}

Human::Human()
{
    prompt_for_name();
    generate_ssn();
}

std::string Human::get_fullname()
{
    return this-> first_name + " " + this-> middle_name + " " + this-> last_name;
}

std::string Human::get_first_name()
{
    return this-> first_name;
}

std::string Human::get_middle_name()
{
    return this-> middle_name;
}

std::string Human::get_last_name()
{
    return this-> last_name;
}

void Human::set_first_name(std::string s)
{
    static std::vector<std::string> tokens;
    
    //Breaks fullname into first name
    tokens.clear();
    size_t pos = 0, found;
    while((found = s.find_first_of(' ', pos)) != std::string::npos)
    {
        tokens.push_back(s.substr(pos, found - pos));
        pos = found+1;
    }
    tokens.push_back(s.substr(pos));
    
    this->first_name = tokens[0];
    
    return;
}

void Human::set_middle_name(std::string s)
{
    static std::vector<std::string> tokens;
    
    //Breaks fullname into middle name
    tokens.clear();
    size_t pos = 0, found;
    while((found = s.find_first_of(' ', pos)) != std::string::npos)
    {
        tokens.push_back(s.substr(pos, found - pos));
        pos = found+1;
    }
    tokens.push_back(s.substr(pos));
    
    if (tokens.size() == 3)
        this->middle_name = tokens[1];
    
    return;
}

void Human::set_last_name(std::string s)
{
    static std::vector<std::string> tokens;
    
    //Breaks fullname into last name
    tokens.clear();
    size_t pos = 0, found;
    while((found = s.find_first_of(' ', pos)) != std::string::npos)
    {
        tokens.push_back(s.substr(pos, found - pos));
        pos = found+1;
    }
    tokens.push_back(s.substr(pos));
    
    this->last_name = tokens[tokens.size()-1];
    
    return;
}
