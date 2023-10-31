// Programming Challenge #2: Test Scores #1 p.553

// Dillon King

#include <iostream>
#include <iomanip>
using namespace std;


int main()

{
    
    float *testScores = nullptr;
    int numOfTests;
    float average;
    float total = 0.0;
    int count;
    void selectSort(float*, int);
    void showPtr(float*, int);
    
    cout << "How many test scores will you enter? " << endl;
    cin >> numOfTests;
    
    while(numOfTests <= 0)
    {
        cout << "The number cannot be negative.\n";
        cout << "Enter another number: ";
        cin >> numOfTests;
    }
    
    testScores = new float[numOfTests];
    
    for (count = 0; count < numOfTests; count ++)
    {
        cout << "Enter test score " << (count + 1) << ": ";
        cin >> *(testScores + count);
        
        if (*(testScores + count) <= 0.00)
        {
            cout << "Negative scores are not allowed.\n";
            cout <<"Enter another score for this test: ";
            cin >> *(testScores + count);
        }
    }
    
   
    selectSort(testScores, numOfTests);
     
    cout << fixed << showpoint << setprecision(2);
    cout << "\nThe test scores in ascending order, and their average, are:" << endl
    << endl << " Score" << endl
    << " -----" << endl << endl;
    showPtr(testScores, numOfTests);
    
    for(count = 0; count < numOfTests; count++)
    {
        total = total + *(testScores + count);
    }
    
    average = total / numOfTests;
    
    cout << "Average score: " << average << endl;
    
    delete [] testScores;
    testScores = nullptr;
    
    return 0;
}


void selectSort(float * testScores, int size)

{

    int swap_occured = 1;
    int bottom = size-1;
    float temp;
    
    while (swap_occured)
    {
    
      swap_occured = 0;
      for (int pos = 0;  pos < bottom; pos++)

        if (testScores[pos] > testScores[pos + 1])
        {
            temp = testScores[pos];
            testScores[pos] = testScores[pos + 1];
            testScores[pos + 1] = temp;
            swap_occured = 1;
        }
        bottom--;
    }
}

void showPtr(float *testScores, int size)
{
    for(int count = 0; count < size; count++)
        cout << *(testScores + count) << endl;
    cout << endl;
    
}
