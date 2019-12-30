//
//  main.cpp
//  Project 6
//
//  Created by Gagan Namburi on 8/4/17.
//  Copyright © 2017 Gagan Namburi. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_WORD_LENGTH = 80;

/* definition of a node */
struct Node;
typedef Node *Node_ptr;

struct Node
{
    char word[MAX_WORD_LENGTH];
    Node_ptr ptr_to_next_node;
};

/* Function to find the nth term of the fibonacci sequence */
unsigned long fibonacci(int n);

/* Function to assign a linked list to "a_node" */
void assign_list(Node_ptr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(Node_ptr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(Node_ptr a_node);

/* Function to print all the strings in the list "a_node" recursively */
void print_list_forward(Node_ptr a_node);

/* Function to print all the strings in the list "a_node" recursively and in reverse */
void print_list_backward(Node_ptr a_node);

/* Function to print the strings in the list "a_node" backwards */
void print_backward(Node_ptr a_node);

int main()
{
    //Fibonacci recursive function in action
    cout << "Fibonacci(8): " << fibonacci(8) << endl;
    cout << endl;
    
    Node_ptr my_list = NULL;
    
    assign_list(my_list);
    print_list(my_list);
    cout << endl;
    print_list_forward(my_list);
    cout << endl;
    print_list_backward(my_list);
    cout << endl;
    print_backward(my_list);
    cout << endl;

    return 0;
}

//Recursive function for fibonacci method
unsigned long fibonacci(int n)
{
    //Both n=1 and n=2 are 1
    if(n <= 2)
    {
        return 1;
    }
    else
    {
        //Algorithm of adding fibonacci terms
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void assign_list(Node_ptr &a_list)
{
    Node_ptr current_node, last_node;
    
    assign_new_node(a_list);
    
    cout << "Enter first word (or '.' to end list): ";
    cin >> a_list->word;
    
    if (!strcmp(".",a_list->word))
    {
        delete a_list;
        a_list = NULL;
    }
    current_node = a_list;
    
    while (current_node != NULL)
    {
        assign_new_node(last_node);
        
        cout << "Enter next word (or '.' to end list): ";
        cin >> last_node->word;
        
        if (!strcmp(".",last_node->word))
        {
            delete last_node;
            last_node = NULL;
        }
        current_node->ptr_to_next_node = last_node;

        current_node = last_node;
    }
}

void assign_new_node(Node_ptr &a_node)
{
    a_node = new (nothrow) Node;
    if(a_node == NULL)
    {
        cout << "sorry - no more memory\n";
        exit(1);
    }
}

void print_list(Node_ptr a_node)
{
    while(a_node != NULL)
    {
        cout << a_node->word << " ";
        a_node = a_node->ptr_to_next_node;
    }
}

void print_list_forward(Node_ptr a_node)
{
    //List prints forwards using recursion
    if(a_node != NULL)
    {
        cout << a_node->word << " ";
        print_list_forward(a_node->ptr_to_next_node);
    }
}

void print_list_backward(Node_ptr a_node)
{
    //Prints list backwards using recursion
    if(a_node != NULL)
    {
        print_list_backward(a_node->ptr_to_next_node);
        cout << a_node->word << " ";
    }
}

void print_backward(Node_ptr a_node)
{
    //Pointer node for a_node
    Node_ptr ptr_node = a_node;
    
    //Iterator to count a_node
    unsigned int iterator = 0;
    
    //Count amount of spaces until a_node reaches NULL
    while(a_node != NULL)
    {
        iterator++;
        a_node = a_node->ptr_to_next_node;
    }
    
    //Loop to go through a_node backwards and prints strings backwards
    for(unsigned int i = iterator; i > 0; i--)
    {
        a_node = ptr_node;
        //Forwards iterator to go through a_node and move pointer along
        for(unsigned int j = 1; j < i; j++)
        {
            a_node = a_node->ptr_to_next_node;
        }
        
        //Output
        cout << a_node->word << " ";
    }
}
