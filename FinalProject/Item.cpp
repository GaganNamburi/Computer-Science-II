//
//  Item.cpp
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

//Writes to books.txt
void Item::writeBookFile(std::string b, std::string a, std::string p)
{
    //Variable Declarations
    std::ofstream writeFile;
    
    writeFile.open("books.txt", std::ios::out | std::ios::app);
    
    //Outputs book in format order
    if(writeFile.is_open())
    {
        writeFile << b << " " << a << " " << p << std::endl;
    }
    else
    {
        std::cerr << "File did not open correctly." << std::endl;
    }
    
    writeFile.close();
}

//Writes to movies.txt
void Item::writeMovieFile(std::string m, std::string re, unsigned short ra)
{
    //Variable Declaration
    std::ofstream writeFile;
    
    writeFile.open("movies.txt", std::ios::out | std::ios::app);
    
    //Outputs movie in format order
    if(writeFile.is_open())
    {
        writeFile << m << " " << re << " " << ra << std::endl;
    }
    else
    {
        std::cerr << "File did not open correctly." << std::endl;
    }
    
    writeFile.close();
}

//Deletes books.txt
void Item::deleteBookFile()
{
    //Variable Declarations
    std::ofstream writeFile;
    
    //Deletes entire file
    writeFile.open("books.txt", std::ios::out | std::ios::trunc);
    
    writeFile.close();
}

//Deletes movies.txt
void Item::deleteMovieFile()
{
    //Variable Declarations
    std::ofstream writeFile;
    
    //Deletes entire file
    writeFile.open("movies.txt", std::ios::out | std::ios::trunc);
    
    writeFile.close();
}

//Views all of books.txt
void Item::viewBookFile()
{
    //Variable Declarations
    std::string line;
    std::ifstream readFile;
    
    readFile.open("books.txt");
    
    //Reads and outputs entire file
    if(readFile.is_open())
    {
        while(!readFile.eof())
        {
            getline(readFile, line);
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cerr << "File did not open correctly." << std::endl;
    }
}

//Views all of movies.txt
void Item::viewMovieFile()
{
    //Variable Declarations
    std::string line;
    std::ifstream readFile;
    
    readFile.open("movies.txt");
    
    //Reads and outputs entire file
    if(readFile.is_open())
    {
        while(!readFile.eof())
        {
            getline(readFile, line);
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cerr << "File did not open correctly." << std::endl;
    }
}

//Searches books.txt by title
void Item::searchBookFile(std::string t)
{
    //Variable Declarations
    std::string title, author, publisher;
    std::ifstream readFile("books.txt");
    bool found = false;
    
    if(readFile.is_open())
    {
        //Prints books that match with search results
        while(!readFile.eof())
        {
            readFile >> title >> author >> publisher;
            if(title == t)
            {
                std::cout << "Title: " << title << " " << "Author: " << author << " " << "Publisher: " <<publisher << std::endl;
                found = true;
                break;
            }
        }
        
        //Output if search does not match file
        if(!found)
        {
            std::cout << "There were no matching search results." << std::endl;
        }
    }
    else
    {
        std::cerr << "File did not open correctly." << std::endl;
    }
    
    readFile.close();
}

//Searches movies.txt by title
void Item::searchMovieFile(std::string t)
{
    //Variable Declarations
    std::string title, rel_date, rating;
    std::ifstream readFile("movies.txt");
    bool found = false;
    
    if(readFile.is_open())
    {
        //Prints books that match with search results
        while(!readFile.eof())
        {
            readFile >> title >> rel_date >> rating;
            if(title == t)
            {
                std::cout << "Title: " << title << " " << "Release date: " << rel_date << " " << "Rating: " << rating << " out of 5 stars" << std::endl;
                found = true;
                break;
            }
        }
        
        //Output if search result does not match file
        if(!found)
        {
            std::cout << "There were no matching search results." << std::endl;
        }
        
    }
    else
    {
        std::cerr << "File did not open correctly." << std::endl;
    }
    
    readFile.close();
}
