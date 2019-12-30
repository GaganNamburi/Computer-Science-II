//
//  Movie.cpp
//  Final Project
//
//  Created by Gagan Namburi on 8/7/17.
//  Copyright © 2017 Gagan Namburi. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Item.h"
#include "Book.h"
#include "Movie.h"

//Default Constructor
Movie::Movie()
{
    
}

//Accessors
std::string Movie::get_m_title()
{
    return m_title;
}

std::string Movie::get_rel_date()
{
    return rel_date;
}

unsigned short Movie::get_rating()
{
    return rating;
}

//Mutators
void Movie::set_m_title(std::string m)
{
    this->m_title = m;
}

void Movie::set_rel_date(std::string r)
{
    this->rel_date = r;
}

void Movie::set_rating(unsigned short rate)
{
    this->rating = rate;
}

void Movie::prompt_for_movie_title()
{
    std::cout << "What is the title of the movie?" << std::endl;
    getline(std::cin, this->m_title);
}

void Movie::prompt_for_rel_date()
{
    std::cout << "When was the movie released?" << std::endl;
    getline(std::cin, this->rel_date);
}

void Movie::prompt_for_rating()
{
    do
    {
        std::cout << "What rating did the movie receive (1-5)?" << std::endl;
        std::cin >> this->rating;
    }while(this->rating < 1 && this->rating >5);
}

void Movie::prompt_for_movie_info()
{
    prompt_for_movie_title();
    prompt_for_rel_date();
    prompt_for_rating();
}
