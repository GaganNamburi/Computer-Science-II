

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Item.h"
#include "Book.h"
#include "Movie.h"

using namespace std;

//Prototypes
void print_menu();
unsigned short menu_selection();
char file_choice(string action);

int main()
{
    //Variable Declaration
    unsigned short selection = 0;
    Book book;
    Movie movie;
    Item file;
    vector<Book> books;
    vector<Movie> movies;
    string title;
    ofstream writeFile;
    char type;
    
    //Menu and choices
    do
    {
        selection = menu_selection();
        
        switch(selection)
        {
            case 1:
                cin.ignore();
                book = *new Book;
                book.prompt_for_book_info();
                
                file.writeBookFile(book.get_b_title(), book.get_author(), book.get_publisher());
                books.push_back(book);
                break;
            case 2:
                cin.ignore();
                movie = *new Movie;
                movie.prompt_for_movie_info();
                
                file.writeMovieFile(movie.get_m_title(), movie.get_rel_date(), movie.get_rating());
                movies.push_back(movie);
                break;
            case 3:
                type = file_choice("view");
                if(type == 'B')
                {
                    file.viewBookFile();
                }
                else if(type == 'M')
                {
                    file.viewMovieFile();
                }
                break;
            case 4:
                type = file_choice("delete");
                if(type == 'B')
                {
                    file.deleteBookFile();
                }
                else if(type == 'M')
                {
                    file.deleteMovieFile();
                }
                break;
            case 5:
                type = file_choice("search");
                cout << "Which title would you like to search?" <<endl;
                cin.ignore();
                getline(cin, title);
                if(type == 'B')
                {
                    file.searchBookFile(title);
                }
                else if(type == 'M')
                {
                    file.searchMovieFile(title);
                }
                break;
        }
    }while(selection != 6);
}

void print_menu()
{
    cout << "Welcome to the Library" << endl;
    cout << "[1] Enter books" << endl;
    cout << "[2] Enter movies" << endl;
    cout << "[3] View all" << endl;
    cout << "[4] Delete library" << endl;
    cout << "[5] Search library" << endl;
    cout << "[6] Quit" << endl;
}

unsigned short menu_selection()
{
    unsigned short selection = 0;
    
    do
    {
        print_menu();
        cin >> selection;
    }while(!(selection >= 1 && selection <= 6));
    
    return selection;
}

char file_choice(string action)
{
    char type;
    
    do
    {
        cout << "Which library would you like to " << action << "? (M/m for movies, B/b for books)" << endl;
        cin >> type;
        type = toupper(type);
    }while(!(type == 'B' || type == 'M'));
    
    return type;
}

