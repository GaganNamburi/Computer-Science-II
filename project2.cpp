//
//  main.cpp
//  Project 2
//
//  Created by Gagan Namburi on 7/19/17.
//  Copyright © 2017 Gagan Namburi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function Prototypes
void subproblem_1();
string display_hex(void * p);
void subproblem_2();
void subproblem_3();
void subproblem_4();
void subproblem_5();
void subproblem_6();
void subproblem_7();

int main()
{
    srand((int)time(NULL));
    
    //Subproblems in numeric order
    subproblem_1();
    subproblem_2();
    subproblem_3();
    subproblem_4();
    subproblem_5();
    subproblem_6();
    subproblem_7();
}

void subproblem_1()
{
    cout << "Subproblem 1\n\n";
    
    //Variable Declaration
    int num1 = 2;
    int num2 = 8;
    int *p;
    int *q;
    
    p = &num1;
    q = &num2;
    
    //Output for values and addresses
    cout << "Address of num1: " << display_hex(&num1) <<endl;
    cout << "Value of num1: " << num1 <<endl;
    cout << "Value of p: " << display_hex(p) <<endl;
    cout << "Value of *p: " << *p <<endl;
    cout << "Address of num2: " << display_hex(&num2) <<endl;
    cout << "Value of num2: " << num2 <<endl;
    cout << "Value of q: " << display_hex(q) <<endl;
    cout << "Value of *q: " << *q <<endl;
    cout << "Address of p: " << display_hex(&p) <<endl;
    cout << "Address of q: " << display_hex(&q) <<endl;
    cout <<endl;
    
    cout << "Subproblem 1 Completed\n\n";
    
    return;
}

string display_hex(void * p)
{
    stringstream s;
    s << hex << setfill('0') << setw(8) << (long) p << ends;
    return s.str();
}

void subproblem_2()
{
    cout << "Subproblem 2\n\n";
    
    //Variable Declaration
    int num1 = 12;
    int num2 = 24;
    int num3 = 36;
    int *p;
    int *q;
    int *r;
    int temp;
    
    p = &num1;
    q = &num2;
    r = &num3;
    
    //Output for values before swap
    cout << "Value of num1: " << num1 <<endl;
    cout << "Value of num2: " << num2 <<endl;
    cout << "Value of num3: " << num3 <<endl;
    cout << "Value of p: " << display_hex(p) <<endl;
    cout << "Value of q: " << display_hex(q) <<endl;
    cout << "Value of r: " << display_hex(r) <<endl;
    cout << "Value of *p: " << *p <<endl;
    cout << "Value of *q: " << *q <<endl;
    cout << "Value of *r: " << *r <<endl;
    cout <<endl;
    
    //Swaps values of three numbers
    temp = num2;
    num2 = num3;
    num3 = num1;
    num1 = temp;
    
    //Output for values after swap
    cout << "Swapping values" <<endl;
    cout << "Value of num1: " << num1 <<endl;
    cout << "Value of num2: " << num2 <<endl;
    cout << "Value of num3: " << num3 <<endl;
    cout << "Value of p: " << display_hex(p) <<endl;
    cout << "Value of q: " << display_hex(q) <<endl;
    cout << "Value of r: " << display_hex(r) <<endl;
    cout << "Value of *p: " << *p <<endl;
    cout << "Value of *q: " << *q <<endl;
    cout << "Value of *r: " << *r <<endl;
    cout <<endl;
    
    cout << "Subproblem 2 Completed\n\n";
    
    return;
}

void subproblem_3()
{
    cout << "Subproblem 3\n\n";
    
    //Variable Declaration
    int num1 = 13;
    int num2 = 26;
    int num3 = 39;
    int *p;
    int *q;
    int *r;
    int temp;
    
    p = &num1;
    q = &num2;
    r = &num3;
    
    //Output for values before swap
    cout << "Value of num1: " << num1 <<endl;
    cout << "Value of num2: " << num2 <<endl;
    cout << "Value of num3: " << num3 <<endl;
    cout << "Value of p: " << display_hex(p) <<endl;
    cout << "Value of q: " << display_hex(q) <<endl;
    cout << "Value of r: " << display_hex(r) <<endl;
    cout << "Value of *p: " << *p <<endl;
    cout << "Value of *q: " << *q <<endl;
    cout << "Value of *r: " << *r <<endl;
    cout <<endl;
    
    //Swap values of the three numbers
    temp = *q;
    *q = *r;
    *r = *p;
    *p = temp;
    
    //Output for values after swap
    cout << "Swapping values" <<endl;
    cout << "Value of num1: " << num1 <<endl;
    cout << "Value of num2: " << num2 <<endl;
    cout << "Value of num3: " << num3 <<endl;
    cout << "Value of p: " << display_hex(p) <<endl;
    cout << "Value of q: " << display_hex(q) <<endl;
    cout << "Value of r: " << display_hex(r) <<endl;
    cout << "Value of *p: " << *p <<endl;
    cout << "Value of *q: " << *q <<endl;
    cout << "Value of *r: " << *r <<endl;
    cout <<endl;
    
    cout << "Subproblem 3 Completed\n\n";
    
    return;
}

void subproblem_4()
{
    cout << "Subproblem 4\n\n";
    
    //Variable Declaration
    int num1 = 11;
    int num2 = 12;
    int a[5];
    int num3 = 41;
    int num4 = 42;
    int filler = 21;
    
    //Loop to fill array with specific values
    for(int i = 0; i < 5; i++)
    {
        a[i] = filler++;
    }
    
    //Forced loop to try out
    for (int i = -2; i < 7; i++)
    {
        cout << setw(2) << i << " " << setw(2) << a[i] << endl;
    }
    cout <<endl;
    
     cout << "Subproblem 4 Completed\n\n";
    
    return;
}

void subproblem_5()
{
    cout << "Subproblem 5\n\n";
    
    //Variable Declaration
    int a[5] = {1, 4, 7, 10, 13};
    int i;
    int *p;
    
    //Loops to run variable to
    for (i = 0; i < 5; i++)
        cout << i << " " << display_hex(a+i) << " " << a[i] << endl;
    cout << endl;
    
    i = 0;
    p = a;
    
    while (p < (a+5))
    {
        cout << i << " " << display_hex(p) << " " << *p << endl;
        i++;
        p++;
    }
    cout <<endl;
    
    cout << "Subproblem 5 Completed\n\n";
    
    return;
}

void subproblem_6()
{
    cout << "Subproblem 6\n\n";
    
    //Variable Declaration
    int *p;
    p = new int[5];
    int filler = -1;
    
    //Fills array with specific numbers
    for(int i = 0; i < 5; i++)
    {
        p[i] = filler += 4;
    }
    
    //Display pointer address stored in p
    cout << "Pointer address stored in p: " << display_hex(p) <<endl;
    
    //Loop to write values in p
    for(int i = 0; i < 5; i++)
    {
        cout << "Value of p at " << i << ": " << p[i] <<endl;
    }
    delete [] p;
    cout <<endl;
    
    cout << "Subproblem 6 Completed\n\n";
    
    return;
}

void subproblem_7()
{
    cout << "Subproblem 7\n\n";
    
    //Variable Declaration
    int *p;
    unsigned int size = rand() % 20+1;
    p = new int[size];
    int rand_num;
    
    //Fill cells with random numbers from -10 to 10
    for(int i = 0; i < size; i++)
    {
        rand_num = rand() % 21-10;
        p[i] = rand_num;
    }
    
    //Prints pointer address stored in p
    cout << "Pointer address stored in p: " << display_hex(p) <<endl;
    
    //Print values of p per cell
    for(int i = 0; i < size; i++)
    {
        cout << "Value of p at " << i << ": " << p[i] <<endl;
    }
    delete [] p;
    cout <<endl;
    
    cout << "Subproblem 7 Completed\n\n";
    
    return;
}
