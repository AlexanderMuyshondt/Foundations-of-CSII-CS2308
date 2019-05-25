/*
Alexander Muyshondt
Assignment 1
CS2308 MTWTF 2pm - 3:40pm
7/17/2017

Atomic Weight of unmodified program: In the main function the
variables were assigned an atomic weight of 2N + 1. The outer for
loop was assigned an atomic value of N + 6. The inner for loop was
assigned N + 5. I multiplied the inner and outer for loop equations
and added them all together to get the cumulative weight of
running the program with an array of size N would be N^2 + 23N + 31.
Using O notation, the theoretical complexity of the program is
O(N^2).

Atomic Weight of modified program: In the main function the
variables were assigned an atomic weight of 2N + 1. The outer for
loop was assigned an atomic value of N + 19. The inner for loop was
assigned N + 7. I multiplied the inner and outer for loop equations
and added them all together to get the cumulative weight of
running the program with an array of size N would be N^2 + 28N + 34.
Using O notation, the theoretical complexity of the program is
O(N^2).

*/

// This program uses the selection sort algorithm to sort an
// array in ascending order.
#include <iostream>
using namespace std;

// Function prototypes
void selectionSort(int [], int);
void showArray(int [], int);

int main()
{
   // Define an array with unsorted values
   const int SIZE = 6;
   int values[SIZE] = {5, 7, 2, 8, 9, 1};

   // Display the values.
   cout << "The unsorted values are\n";
   showArray(values, SIZE);

   // Sort the values.
   selectionSort(values, SIZE);

   // Display the values again.
   cout << "The sorted values are\n";
   showArray(values, SIZE);
   return 0;
}

//**************************************************************
// Definition of function selectionSort.                       *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array.         *
//**************************************************************

void selectionSort(int array[], int size)
{
   int startScan;
   int minIndex;
   int minVal;
   int highIndex;
   int highVal;
   int tempIndex;
   int tempVal;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minVal = array[startScan];
      highIndex = startScan;
      highVal = array[startScan];

      for(int index = startScan + 1; index < size; index++)
      {
         if (array[index] < minVal)
         {
            minVal = array[index];
            minIndex = index;
         }
         if (array[index] > highVal)
         {
             highVal = array[index];
             highIndex = index;
         }
      }

      //Demonstration of swaps using a temp variable
      tempIndex = highIndex;
      tempVal = highVal;
      highIndex = minIndex;
      highVal = array[minIndex];
      minIndex = tempIndex;
      minVal = array[tempIndex];
      array[minIndex] = array[startScan];
      array[startScan] = minVal;
   }
}

//**************************************************************
// Definition of function showArray.                           *
// This function displays the contents of array. size is the   *
// number of elements.                                         *
//**************************************************************

void showArray(int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}
