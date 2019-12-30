/*
 Gagan Namburi
 Dr. Fine
 Computer Science II
 12 July 2017
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void print_menu();
unsigned short get_selection();
string get_name(string &student_name);
double get_gpa();
unsigned int get_year();
void input_new_student(string student_name[], double student_gpa[], unsigned int student_year[], unsigned short student_number[], unsigned short students);
void print_all(string student_name[], unsigned short student_number[], unsigned short students);
void print_by_year(unsigned short students, unsigned int student_year[], string student_name[], unsigned short student_number[]);
void print_statistics(unsigned short students, double student_gpa[]);

int main()
{
    srand((unsigned short)time(NULL));
    
    //Symbolic Constant
    const unsigned int MAX = 100;
    
    //Variable Declaration
    unsigned short selection = 0;
    string student_name[MAX];
    double student_gpa[MAX];
    unsigned int student_year[MAX];
    unsigned short student_number[MAX];
    unsigned short students = 0;
    
    
    //Menu and selections
    do
    {
        selection = get_selection();
        
        switch(selection)
        {
            case 1:
            if(students < MAX)
            {
                input_new_student(student_name, student_gpa, student_year, student_number, students);
                students++;
            }
            else
            {
                cout << "Sorry, the maximum number of students has been exceeded." <<endl;
            }
               
                break;
            case 2:
                print_all(student_name, student_number, students);
                break;
            case 3:
                print_by_year(students, student_year, student_name, student_number);
                break;
            case 4:
                print_statistics(students, student_gpa);
                break;
        }
    }while(selection != 5);
    
}

void print_menu()
{
    //Menu
    cout << "RCNJ Registrar Menu" <<endl;
    cout << "[1] Add a student" <<endl;
    cout << "[2] Display all students" <<endl;
    cout << "[3] Display by year" <<endl;
    cout << "[4] Display statistics" <<endl;
    cout << "[5] Quit" <<endl;
    
    //Return
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
    
    //Return
    return choice;
}

string get_name(string &student_name)
{
    //Variable Declaration
    
    //Get name
    cout << "Please enter the student's name: ";
    getline(cin, student_name);
    
    //Return
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
    
    //Return
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
    
    //Return
    return year;
}

void input_new_student(string student_name[], double student_gpa[], unsigned int student_year[], unsigned short student_number[], unsigned short students)
{
    cin.ignore();
    //Name
    get_name(student_name[students]);
    
    //GPA
    student_gpa[students] = get_gpa();
    
    //Year
    student_year[students] = get_year();
    
    //Random number
    student_number[students] = rand() % 99999+10000;
    cout << "The student with R# " << student_number[students] << " was created." <<endl;
    
    //Return
    return;
}

void print_all(string student_name[], unsigned short student_number[], unsigned short students)
{
    //Print all
    for(int i = 0; i < students; i++)
    {
        cout << student_name[i] << " - " << student_number[i] <<endl;
    }
    
    //Return
    return;
}

void print_by_year(unsigned short students, unsigned int student_year[], string student_name[], unsigned short student_number[])
{
    //Variable Declaration
    unsigned short year;
    bool year_students = 0;
    
    //Ask user year
    do
    {
        cout << "What year would you like to display? ";
        cin >> year;
    }while(!(year >= 1972 && year <= 2015));
    
    //Check the year with loop
    for(int i = 0; i < students; i++)
    {
        if(year == student_year[i])
        {
            cout << student_name[i] << " - " << student_number[i] <<endl;
            year_students = 1;
        }
    }
    
    //If there are no students in selected year
    if(year_students == 0)
    {
        cout << "No students that year." <<endl;
    }
    
    //Return
    return;
}

void print_statistics(unsigned short students, double student_gpa[])
{
    //Variable Declaration
    double average_gpa = 0.0;
    unsigned int above_2 = 0;
    double total_gpa = 0.0;
    
    //Total amount of students
    cout << "Total: " << students <<endl;
    
    //Get stats
    for(int i = 0; i < students; i++)
    {
        total_gpa += student_gpa[i];
        average_gpa = total_gpa/students;
        
        //GPAs above 2
        if(student_gpa[i] > 2.0)
        {
            above_2++;
        }
    }
    cout << "GPA: " << average_gpa <<endl;
    cout << "Above 2.0: " << above_2 <<endl;
    
    //Return
    return;
}
