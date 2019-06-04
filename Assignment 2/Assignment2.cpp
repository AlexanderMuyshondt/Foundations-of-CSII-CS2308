/****************************
 Alexander Muyshondt
 Program 2
 PR2_adm1.cpp
 7/23/2017
 CS2308
 ****************************/

// This program uses the bubble sort algorithm to sort an
// array in ascending order.
#include <iostream>
using namespace std;

// Function prototypes
void sortArray(int *, int);
void showArray(int *, int);
int *iprepend(int *, int *);

int main()
{
    const int SIZE = 5;
    int statArray[SIZE] = {SIZE, 4, 3, 2, 1};
    int numValues;
    int *destination = 0;
    int *source = 0;
    int *ptr = 0;
    
    //Get number of values to be sorted from user
    cout << "Enter the number of integers to be sorted: ";
    cin  >> numValues;
    
    // Fill array with unsorted values
    cout << "Enter " << numValues << " integers to be sorted:\n";
    ptr = new int[numValues];
    for(int i = 0; i < numValues; i++)
    {
        cin >> ptr[i];
    }
    
    // Display the values.
    cout << "The unsorted values are:\n";
    showArray(ptr, numValues);
    
    // Sort the values.
    sortArray(ptr, numValues);
    
    // Display them again.
    cout << "The sorted values are:\n";
    showArray(ptr, numValues);
    
    //Create dynamic destination array
    cout << "\nThe program will now prepend a static source array to a dynamic destination array.\n";
    source = statArray;
    destination = new int[numValues];
    destination[0] = numValues;
    for(int i = 0; i < numValues; i++)
    {
        destination[i + 1] = 0;
    }
    
    // Display the source values.
    cout << "\nThe source array values are:\n";
    showArray(source, SIZE);
    
    // Display the destination values.
    cout << "\nThe source array values are:\n";
    showArray(destination, numValues);
    
    //Call to iprepend function
    int *ipr;
    ipr = iprepend(destination, source);
    
    // Display the destination values.
    cout << "\nThe prepended array values are:\n";
    showArray(ipr, ipr[0]);
    
    // Free dynamically allocated memory
    delete [] ptr;
    delete [] destination;
    
    return 0;
}

//***********************************************************
// Definition of function sortArray                         *
// This function performs an ascending order bubble sort on *
// array. size is the number of elements in the array.     *
//***********************************************************

void sortArray(int * array, int size)
{
    bool swap;
    int temp;
    
    do
    {
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (array[count] > array[count + 1])
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of array. size is the *
// number of elements.                                        *
//*************************************************************

void showArray(int * array, int size)
{
    for (int count = 0; count < size; count++)
        cout << array[count] << " ";
    cout << endl;
}

//*************************************************************
// Definition of function iPrepend .                          *
// This function prepends the contents of a static array      *
//to another dynamic array.                                   *
//*************************************************************


int * iprepend (int * destination, int * source)
{
    int tempSize = ((source[0] + destination[0]) - 1);
    int count = 0;
    int *tempArray;
    tempArray = new int[tempSize];
    for(int i = 0; i < (source[0] - 1); i++)
    {
        tempArray[i] = source[i + 1];
        count++;
    }
    
    for(int i = 0; i < destination[0]; i++)
    {
        
        tempArray[count] = destination[i];
        count++;

    }
    
    tempArray[0] = tempSize;
    
    return tempArray;
}
