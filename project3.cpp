//
//  main.cpp
//  Project 3
//
//  Created by Gagan Namburi on 7/21/17.
//  Copyright © 2017 Gagan Namburi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Student
{
    private:
    string first_name;
    string last_name;
    string middle_name;
    string fullname;
    double gpa;
    size_t r_num;
    size_t year;
    void compute_rnum() {
        this->r_num = rand() % 99999 + 10000;
    }
    void prompt_for_name(){
        string line;
        static vector<string> tokens;
        
        //get the users name
        cin.ignore();
        cout << "Please enter the student's name: ";
        getline(cin, line);
        
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
    };
    void prompt_for_year(){
        {
            cout << "Please enter year: ";
            cin >> this->year;
        } while (!(this->year >= 1972 && this->year <= 2015));
    };
    void prompt_for_gpa(){
        do
        {
            cout << "Please enter GPA: ";
            cin >> this->gpa;
        } while (!(this->gpa >= 0.0 && this->gpa <= 4.0));
    };
    void prompt_for_student_info(){
        prompt_for_name();
        prompt_for_gpa();
        prompt_for_year();
        compute_rnum();
    };
    
    public:
    Student();
    Student(string fullname);
    Student(string fullname, double gpa, size_t year) {
        this->fullname = fullname;
        this->gpa = gpa;
        this->year = year;
        compute_rnum();
    }
    string get_fullname() {
        //fullname = first_name + middle_name + last_name;
        return this->fullname;
    }
    double get_gpa() {
        return this->gpa;
    }
    size_t get_year() {
        return this->year;
    }
    size_t get_rnum() {
        return this->r_num;
    };
};

Student::Student(void)
{
    
}

void print_menu();
unsigned short get_selection();
string get_name();
double get_gpa();
unsigned int get_year();
Student input_new_student();
void print_all(Student students[], unsigned short numstudents);
void print_by_year(Student students[], unsigned short numstudents);
void print_statistics(Student students[], unsigned short numstudents);


int main()
{
    
    srand((unsigned short)time(NULL));
    
    //Symbolic Constant
    const unsigned int MAX = 100;
    
    //Variable Declaration
    unsigned short selection = 0;
    Student students[MAX];
    unsigned short numstudents = 0;
    int count;
    bool selection_1 = false;
    
    //Menu and selections
    do
    {
        selection = get_selection();
        
        switch(selection)
        {
            case 1:
                if(selection_1 == true)
                {
                    cout << "You can only enter students once" <<endl;
                }
                else
                {
                    cout << "How many students? ";
                    cin >> count;
                    for(int i = 0; i < count; i++) {
                        students[numstudents] = input_new_student();
                        numstudents++;
                    }
                    selection_1 = true;
                }
                break;
            case 2:
                print_all(students, numstudents);
                break;
            case 3:
                print_by_year(students, numstudents);
                break;
            case 4:
                print_statistics(students, numstudents);
                break;
        }
    }while(selection != 5);
    
}

void print_menu()
{
    //Menu
    cout << "RCNJ Registrar Menu" <<endl;
    cout << "[1] Add all students" <<endl;
    cout << "[2] Display all students" <<endl;
    cout << "[3] Display by year" <<endl;
    cout << "[4] Display statistics" <<endl;
    cout << "[5] Quit" <<endl;
    
    return;
}

unsigned short get_selection()
{
    //Variable Declaration
    unsigned short choice;
    
    do
    {
        print_menu();
        cin >> choice;
    }while(!(choice >= 1 && choice <= 5));
    
    return choice;
}

string get_name()
{
    //Variable Declaration
    string student_name;
    
    //Get name
    cout << "Please enter the student's name: ";
    getline(cin, student_name);
    
    return student_name;
}

double get_gpa()
{
    //Variable Declaration
    double gpa;
    
    //Get gpa from user
    do
    {
        cout << "Please enter the GPA: ";
        cin >> gpa;
    }while(!(gpa >= 0.0 && gpa <= 4.0));

    return gpa;
}

unsigned int get_year()
{
    //Variable Declaration
    unsigned short year;
    
    //Get year from user
    do
    {
        cout << "Please enter the year: ";
        cin >> year;
    }while(!(year >= 1972 && year <= 2015));

    return year;
}

Student input_new_student()
{
    cin.ignore();
    //Name
    string name = get_name();
    
    //GPA
    double gpa = get_gpa();
    
    //Year
    int year = get_year();

    return *(new Student(name, gpa, year));
}

void print_all(Student students[], unsigned short numstudents)
{
    //Print all students
    for(int i = 0; i < numstudents; i++)
    {
        cout << students[i].get_fullname() << " - " << students[i].get_rnum() <<endl;
    }
    
    return;
}

void print_by_year(Student students[], unsigned short numstudents)
{
    //Variable Declaration
    unsigned short year;
    bool at_least_one = 0;
    
    //Ask user year
    do
    {
        cout << "What year would you like to display? ";
        cin >> year;
    }while(!(year >= 1972 && year <= 2015));
    
    //Check the year with loop
    for(int i = 0; i < numstudents; i++)
    {
        if(year == students[i].get_year())
        {
            at_least_one = 1;
            cout << students[i].get_fullname() << " - " << students[i].get_rnum() <<endl;
        }
    }
    if(!at_least_one)
    {
        cout << "No students that year." <<endl;
    }

    return;
}

void print_statistics(Student students[], unsigned short numstudents)
{
    //Variable Declaration
    double average_gpa = 0.0;
    double total_gpa = 0.0;
    unsigned int above_2 = 0;
    
    //Total amount of students
    cout << "Total: " << numstudents <<endl;
    
    //Get stats
    for(int i = 0; i < numstudents; i++)
    {
        total_gpa += students[i].get_gpa();
        average_gpa = total_gpa / numstudents;
        
        //GPAs above 2
        if(students[i].get_gpa() > 2.0)
        {
            above_2++;
        }
    }
    cout << "GPA: " << average_gpa <<endl;
    cout << "Above 2.0: " << above_2 <<endl;

    return;
}
