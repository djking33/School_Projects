//  Week 7_Merge Sort
//  Dillon King
// IDE used: Xcode on Macbook with i5

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Sorts the array from start to middle and from middle to end then merges after being sorted
void merge (vector<int> &vec, int start, int middle, int end)
{
    vector<int> temp;   //Used to temporary store integers from merging
    int i, j;
    i = start;
    j = middle + 1;
    
    while (i <= middle && j <= end)
    {
        if (vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            ++i;
        }
        else
        {
            temp.push_back(vec[j]);
            ++j;
        }
    }
    
    while (i <= middle)
    {
        temp.push_back(vec[i]);
        ++i;
    }
    
    while (j <= end)
    {
        temp.push_back(vec[j]);
        ++j;
    }
    
    for (i = start; i <= end; ++i)
    {
        vec[i] = temp[i - start];
    }
}

void mergeSort ( vector<int> &vec, int start, int end)  //Sorts the unsorted array
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        mergeSort (vec, start, middle);
        mergeSort (vec, middle + 1, end);
        merge (vec, start, middle, end);
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
    inputFile.open("Part 5_Input6.txt");
    
  
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
    
   
    mergeSort (nums, 0, (unsigned)nums.size()-1);
   print (nums);
    
    return 0;
}
