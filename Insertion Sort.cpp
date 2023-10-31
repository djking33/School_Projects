// Programming Project 3
// Week 7_Insertion Sort
// Dillon King
// IDE used: Xcode on Macbook with i5


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &vec)        //Sorts the array
{
    for (auto it = vec.begin(); it!=vec.end(); it++)
    {
        auto const insertion_point = upper_bound(vec.begin(), it, *it);
        rotate(insertion_point, it, it+1);
    }
}

void print (vector<int> vec)        //Prints the insertion sorted array
{
    for (int x : vec)
        cout << x << " ";
    cout << "\n";
}



int main()
{
    int input_nums = 0;
    vector<int> nums;
    ifstream inputFile;
    inputFile.open("Week7-Integers.txt");
    
  
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
    
    insertionSort(nums);
    print(nums);
    
    return 0;
}


