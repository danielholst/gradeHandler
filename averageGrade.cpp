//
//  averageGrade.cpp
//  
//
//  Created by Daniel Holst on 2015-04-02.
//
//

#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

struct course{
    string courseName;
    int grade;
};

//display all courses in database
//val is used to only show a specific grade
void display(course DB[], int howMany, int val)
{
    
    for (int i = 0; i < howMany; i++)
    {
        if(val == 3 && DB[i].grade != 3) continue;
        
        if(val == 4 && DB[i].grade != 4) continue;
        
        if(val == 5 && DB[i].grade != 5) continue;
        
        cout << DB[i].grade << "   " << DB[i].courseName << endl;
    }
}

// calculate average grade
double getAverage(course DB[], int howMany)
{
    double sum = 0;
    
    for (int i = 0; i < howMany; i++)
    {
        sum += DB[i].grade;
    }
    
    return sum/howMany;
}

// read in courses to database
int readToDB(ifstream& myfile, course DB[])
{
    course c;
    int counter = 0;
    while (!myfile.eof())
    {
        myfile >> c.grade;
        getline(myfile, c.courseName);
        DB[counter] = c;
        counter++;
    }
    
    return counter -1 ;
}

// Show menu
void showMenu()
{
    cout << endl;
    cout << "==============================" << endl;
    cout << " 1. Show all courses "          << endl;
    cout << " 2. Show average grade "        << endl;
    cout << " 3. Show courses with grade 3 " << endl;
    cout << " 4. Show courses with grade 4 " << endl;
    cout << " 5. Show courses with grade 5 " << endl;
    cout << " 6. Quit "                      << endl;
    cout << "==============================" << endl;
    cout << endl;
}

int main()
{
    const int SIZE = 40;
    course DB[SIZE];
    double average = 0;
    
    //open and read in from file to database (DB)
    ifstream myfile("courses.txt");
    if(!myfile.is_open())
    {
        cout << "Could not open file" << endl;
        return 0;
    }
    int howMany = readToDB(myfile, DB);
    
    int val = 0;
    while (val != 6)
    {
        //show menu
        showMenu();
        
        cin >> val;
        cout << endl;
        switch (val)
        {
            case 1:
                //display courses and grade
                display(DB, howMany, 0);
                break;

            case 2:
                //get average
                cout << "Number of courses = " << howMany << endl << endl;
                average = getAverage(DB, howMany);
                cout << "Your average is: " << average << endl << endl;;
                break;
                
            case 3:
                //show courses with grade 3
                display(DB, howMany, 3);
                break;
            
            case 4:
                //show courses with grade 4
                display(DB, howMany, 4);
                break;
                
            case 5:
                //show courses with grade 5
                display(DB, howMany, 5);
                break;
                
            case 6:
                //quit
                break;
                
        }
    }
    
    return 0;
}