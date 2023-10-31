// Homework 4, Chapter 12 Programming Challenge 4, p. 714
// and net pay.

#include <fstream>
#include <iostream>
using namespace std;

void showJoke (ifstream &);
void showPunchline (ifstream &);

int main()
{
   const int SIZE1 = 500;
   const int SIZE2 = 95;
   char jokefile[SIZE1];
   char punchfile[SIZE2];
   ifstream inputFile1;
   ifstream inputFile2;
   string line;
   
   cout << "The program will print a joke and its punchline.\n" << endl;
   cout << "Enter the name of the file holding the joke (joke.txt): ";
   cin.getline(jokefile, SIZE1);
   
   inputFile1.open(jokefile);
   
   if (!inputFile1)
   {
       cout << "The file " << jokefile << " could not be opened." << endl;
       return 0;
   }
   
   
   
   cout << "Enter the name of the file holding the punch line (punchline.txt): ";
   cin.getline(punchfile, SIZE2);
   
   cout << endl << endl;
   
   inputFile2.open(punchfile);

   if (!inputFile2)
   {
       cout << "The file " << punchfile << " could not be opened." << endl;
       return 0;
   }
   
   showJoke(inputFile1);
   
   showPunchline(inputFile2);
   
   inputFile1.close();
   inputFile2.close();
   return 0;
}

void showJoke (ifstream &inFile)
{
  string input;
   
   getline(inFile, input);
   
   while (inFile)
   {
       cout << input << endl;
       getline(inFile, input);
   }
   
   cout << endl << endl;
}

void showPunchline (ifstream &inFile)
{
   string input;
   if (inFile.is_open())
   {
       while(!inFile.eof())
       {
           getline(inFile, input);
       }
       cout << input << endl;
   }
   
}

