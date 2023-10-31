// Homework 5, Chapter 13 Programming Challenge 2, p. 808


#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
   string name;
   int idNumber;
   string department, position;
   
public:
   Employee (string, int, string, string);
   Employee (string, int);
   Employee ();
   void setName (string);
   void setIdNumber (int);
   void setDepartment (string);
   void setPosition (string);
   string getName() const;
   int getIdNumber() const;
   string getDepartment() const;
   string getPosition() const;
};

Employee::Employee (string n, int id, string dept, string pos)
{
   name = n;
   idNumber = id;
   department = dept;
   position = pos;
}

Employee::Employee (string n, int id)
{
   name = n;
   idNumber = id;
   department = "";
   position = "";
}

Employee::Employee ()
{
   name = "";
   idNumber = 0;
   department = "";
   position = "";
}

void Employee::setName (string n)
{
   name = n;
}

void Employee::setIdNumber (int id)
{
   idNumber = id;
}

void Employee::setDepartment (string dept)
{
   department = dept;
}

void Employee::setPosition (string pos)
{
   position = pos;
}

string Employee::getName () const
{
   return name;
}

int Employee::getIdNumber () const
{
   return idNumber;
}

string Employee::getDepartment () const
{
   return department;
}

string Employee::getPosition () const
{
   return position;
}

void displayEmployee(Employee);

int main()
{
   Employee susan ("Susan Meyers", 47899, "Accounting", "Vice President");
   Employee mark ("Mark Jones", 39119);
   Employee joy;
   
   mark.setDepartment("IT");
   mark.setPosition("Programmer");
   
   joy.setName("Joy Rogers");
   joy.setIdNumber(81774);
   joy.setDepartment("Manufacturing");
   joy.setPosition("Engineer");
   
   displayEmployee(susan);
   displayEmployee(mark);
   displayEmployee(joy);
   
   return 0;
}

void displayEmployee (Employee info)
{
   cout << "Name: " << info.getName() << endl;
   cout << "ID Number: " << info.getIdNumber() << endl;
   cout << "Department: " << info.getDepartment() << endl;
   cout << "Position: " << info.getPosition() << endl << endl;
}

