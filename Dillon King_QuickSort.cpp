//  Week 7_Quick Sort
//  Dillon King
// IDE used: Xcode on Macbook with i5

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*With the last element as pivot, the smaller elements are to the left of the pivot and the larger ones are to the right of the pivot*/
int partition(vector<int> &vec, int start, int end)
{
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
    {
        if (vec[i] < vec[pivot])
        {
            swap (vec[i], vec[j]);
            ++j;
        }
    }
    swap (vec[j], vec[pivot]);
    return j;
}
/* When picking the pivot, I used the last element since when I tried picking a random element, the program wouldn't run properly*/

void quickSort (vector<int> &vec, int start, int end)      //Sorts the array
{
    if (start < end)
    {
        int part = partition(vec, start, end);
        quickSort(vec, start, part - 1);
        quickSort (vec, part + 1, end);
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
    inputFile.open("Week7-Integers3.txt");
    
  
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
    
   
    quickSort (nums, 0, (unsigned)nums.size()-1);
   print (nums);
    
    return 0;
}
