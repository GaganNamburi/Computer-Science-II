//
//  main.cpp
//  Project 1
//
//  Created by Gagan Namburi on 7/13/17.
//  Copyright © 2017 Gagan Namburi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Prototypes
string calculateGrades (int percentage);
void writeFinalReport (double averagePercentage, int numA, int numB, int numC, int numD, int numF);
void writeFinalGrades (bool createFile, string RollNum, int P0, int P1, int P2, int P3, int P4, int P5, int P6, int P7, int Q1, int Q2, int Q3, int Q4, int Q5, int FP, int MS, int FS, int C, int percentage, string grade);

int main(int argc, const char * argv[])
{
    //Reads file
    ifstream readFile("bfine_project1_input.txt");
    
    //Does operations if file is open and error message is file is not open
    if (readFile.is_open())
    {
        string line;
        string rNum;
        int P0, P1, P2, P3, P4, P5, P6, P7, Q1, Q2, Q3, Q4, Q5, FP, MS, FS, C;
        int percentage;
        double total = 0;
        double averagePercentage = 0;
        string grade;
        int numA = 0, numB = 0, numC = 0, numD = 0, numF = 0, count = 0;
        bool createFile = false;
        
        //Checks condition to create file and counts lines
        while(!readFile.eof())
        {
            count++;
            if (count == 1)
            {
                createFile = true;
            }
            else
            {
                createFile = false;
            }
            
            //Processes file
            readFile >> rNum >> P0 >> P1 >> P2 >> P3 >> P4 >> P5 >> P6 >> P7 >> Q1 >> Q2 >> Q3 >> Q4 >> Q5 >> FP >> MS >> FS >> C;
            rNum = string(9 - rNum.length(), '0').append(rNum);
            
            //Calculates percentage
            percentage = double(P0 + P1 + P2 + P3 + P4 + P5 + P6 + P7 + Q1 + Q2 + Q3 + Q4 + Q5 + FP + MS + FS + C) * 100 / 560;
            
            //Assigns grade letter to percentage
            grade = calculateGrades(percentage);
            
            //Writes modified final_grades file
            writeFinalGrades(createFile, rNum, P0, P1, P2, P3, P4, P5, P6, P7, Q1, Q2, Q3, Q4, Q5, FP, MS, FS, C, percentage, grade);
            
            //Counts number of each letter grade in file
            if (grade.find("A") == 0)
            {
                numA++;
            }
            else if (grade.find("B") == 0)
            {
                numB++;
            }
            else if (grade.find("C") == 0)
            {
                numC++;
            }
            else if (grade.find("D") == 0)
            {
                numD++;
            }
            else if (grade.find("F") == 0)
            {
                numF++;
            }
            
            //Calculates total of all percentages in file
            total = total + percentage;
        }
        
        //Closes file
        readFile.close();
        
        //Calculates average percentage
        averagePercentage = total / count;
        
        //Writes final report
        writeFinalReport (averagePercentage, numA, numB, numC, numD, numF);
    }
    else
    {
        //Error message
        cerr << "User inputted file did not open properly." <<endl;
    }
}

void writeFinalGrades (bool createFile, string RollNum, int P0, int P1, int P2, int P3, int P4, int P5, int P6, int P7, int Q1, int Q2, int Q3, int Q4, int Q5, int FP, int MS, int FS, int C, int percentage, string grade)
{
    //Variable Declaration
    ofstream finalGradesFile;
    
    //Checks for conditions to modify file
    if (createFile)
    {
        finalGradesFile.open("gnamburi_final_grades.txt");
    }
    else
    {
        finalGradesFile.open("gnamburi_final_grades.txt", std::ios_base::app);
    }
    
    //Modifies file if file is open or displays error message
    if (finalGradesFile.is_open())
    {
        finalGradesFile << RollNum << " " << P0 << " " << P1 << " " << P2 << " " << P3 << " " << P4 << " " << P5 << " " << P6 << " " << P7 << " " << Q1 << " " << Q2 << " " << Q3 << " " << Q4 << " " << Q5 << " " << FP << " " << MS << " " << FS << " " << C << " " << percentage << " " << grade << endl;
        
        //Closes file
        finalGradesFile.close();
    }
    else
    {
        cerr << "Final grades file did not open properly." << endl;
    }
}

void writeFinalReport (double averagePercentage, int numA, int numB, int numC, int numD, int numF)
{
    //Variable Declaration
    ofstream finalReportFile;
    
    //Opens file
    finalReportFile.open("gnamburi_final_report.txt");
    
    //Checks if file is open and writes final report
    if (finalReportFile.is_open())
    {
        finalReportFile << "The average percent total = " << fixed << setprecision (2) << averagePercentage << endl;
        finalReportFile << "The number of A's = " << numA << endl;
        finalReportFile << "The number of B's = " << numB << endl;
        finalReportFile << "The number of C's = " << numC << endl;
        finalReportFile << "The number of D's = " << numD << endl;
        finalReportFile << "The number of F's = " << numF << endl;
        
        //Closes file
        finalReportFile.close();
    }
    else
    {
        cerr << "Final report file did not open properly." << endl;
    }
}

string calculateGrades (int percentage)
{
    //Variable Declaration
    string grade = "";
    
    //Calculate grade letter based on percentage calculated
    if(percentage <= 100 && percentage >= 92)
    {
        grade = "A";
    }
    else if(percentage <= 91 && percentage >= 90)
    {
        grade = "A-";
    }
    else if(percentage <= 89 && percentage >= 87)
    {
        grade = "B+";
    }
    else if(percentage <= 86 && percentage >= 82)
    {
        grade = "B";
    }
    else if(percentage <= 81 && percentage >= 80)
    {
        grade = "B-";
    }
    else if(percentage <= 79 && percentage >= 77)
    {
        grade = "C+";
    }
    else if(percentage <= 76 && percentage >= 72)
    {
        grade = "C";
    }
    else if(percentage <= 71 && percentage >= 70)
    {
        grade = "C-";
    }
    else if(percentage <= 69 && percentage >= 67)
    {
        grade = "D+";
    }
    else if(percentage <= 66 && percentage >= 60)
    {
        grade = "D";
    }
    else
    {
        grade = "F";
    }
    
    return grade;
}
