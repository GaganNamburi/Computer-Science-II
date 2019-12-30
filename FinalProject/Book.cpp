//
//  Book.cpp
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
Book::Book()
{
    
}

//Accessors
std::string Book::get_b_title()
{
    return this->b_title;
}

std::string Book::get_author()
{
    return this->author;
}

std::string Book::get_publisher()
{
    return this->publisher;
}

//Mutators
void Book::set_b_title(std::string t)
{
    this->b_title = t;
}

void Book::set_author(std::string a)
{
    this->author = a;
}

void Book::set_publisher(std::string p)
{
    this->publisher = p;
}

void Book::prompt_for_title()
{
    std::cout << "What is the title of the book?" << std::endl;
    getline(std::cin, this->b_title);
}

void Book::prompt_for_author()
{
    std::cout << "What is the name of its author?" << std::endl;
    getline(std::cin, this->author);
}

void Book::prompt_for_publisher()
{
    std::cout << "What is the name of the book's publisher?" << std::endl;
    getline(std::cin, this->publisher);
}

void Book::prompt_for_book_info()
{
    prompt_for_title();
    prompt_for_author();
    prompt_for_publisher();
}
