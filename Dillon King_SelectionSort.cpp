//  Week 7_Selection Sort
//  Dillon King
// IDE used: Xcode on Macbook on i5

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &vec)        // Sorts the array
{
    float vecsize = vec.size();
     for (int j = 0; j < vecsize - 1; ++j)      // Moves the boundary of the unsorted array
     {
         int min = j;
         for (int i = j+1; i < vecsize; ++i)
         {
             if (vec.at(min) > vec.at(i))       // Finds the min element in the array
             {
                 min = i;
             }
         }
         if (min != j)      //Swaps the elements
             swap (vec.at(j), vec.at(min));
     }
}

void print (vector<int> &vec)       // Prints the selection sorted array
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int input_nums = 0;
    vector<int> nums;
    ifstream inputFile;
    inputFile.open("Week7-Integers2.txt");
    
  
    if (!inputFile)             //Checks to see if the inputFile exists and opens it
    {
        cout << "File Unreadable." << endl;
    }
    else
    {
        while (inputFile >> input_nums) // Pushes numbers into the vector
        {
            nums.push_back(input_nums);
        }
        
        inputFile.close(); // Closes the file
        
        for (int i=0; i<nums.size(); i++)   //Displays the numbers
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
    selectionSort(nums);
    print (nums);
   
    return 0;
}
