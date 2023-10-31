// Dillon King
//  Project 1
//  CS 3330

#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int employeeId;     // Categories of the information for the employees
    string firstName;
    string lastName;
    string phoneNumber;
    string emailAddress;
    double salary;
public:
    Employee (int _employeeId, string fName, string lName, string phNumber, string email, double _salary) //Constructor function
    {
        employeeId = _employeeId;
        firstName = fName;
        lastName = lName;
        phoneNumber = phNumber;
        emailAddress = email;
        salary = _salary;
    }

   void print()                    // Displays the information in the .txt file
    {
        cout << employeeId << " " << firstName << " " << lastName << " " << phoneNumber << " "
        << emailAddress << " " << fixed << setprecision(2) << salary << endl;
    }
    
    bool operator < (const Employee& emp)    // Used to access members of the object
    {
        return employeeId < emp.employeeId;
    }
    
};


int main(int argc, char** argv)
{
    string info, fName, lName, phNum, email;
    int employeeId;
    double Salary;
    
    ifstream inputFile("EmployeeID.txt");  // Opens the .txt file
    
    
    if(!inputFile)    // Makes sure the file opens correct and lets us know if it doesn't
    {
        cout << "File not found." << endl;
        return 0;
    }
    
    list<Employee> employeeInfo;                // List name inserted into the Employee list
    
    while(getline(inputFile,info))             //Puts the data from the .txt file into the list
    {
        istringstream iss(info);                //Used to to make sure all info comes out as the same data type
        
        if(iss>>employeeId>>fName>>lName>>phNum>>email>>Salary)
        {
            Employee num1 (employeeId, fName, lName, phNum, email, Salary); //Creates categories for the data
            list<Employee>::iterator it; //Access data in the list
            
            for (it=employeeInfo.begin(); it!=employeeInfo.end(); it++){}; //Allows iterator to gather all data until end of file
            
            employeeInfo.insert(it, num1); // Inserts each object into the list
            
        }
        else
        {
            cout << "Error" << endl;    //Lets us know if data from file wasn't able to be written to list
            return 0;
        }
    }

    list<Employee>::iterator itPtr; // Access data in the list
    
    for (itPtr=employeeInfo.begin(); itPtr!=employeeInfo.end(); itPtr++)    //Displays data
    {
        itPtr->print();
    }
};


