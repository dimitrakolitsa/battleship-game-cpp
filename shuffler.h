#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * Shuffles an array using an algorithm that initially iterates an index i from the last to second element.
 * And then a second index j is used to select an element randomly between the first element and the i-th element.
 * And finally the elements in positions i and j are swapped.
 *
 * @param myArray the array to be shuffled.
 * @param myArraySize the size of the array to be shuffled.
 */

template <class X> void shuffle(X** myArray, int myArraySize)
{
    int j;
    X* temp=NULL;                          //create a X pointer to help us swap the elements
    for(int i = myArraySize-1; i>0 ; i--)  //loop from the last element (which is in position myArraySize - 1 because we start from zero),
    {                                      //until i>0 (goes until i=1 which is the second element)
        j=rand()%(i + 1);                  //j is a random number between the first element and the i-th element
        temp = myArray[i];                 //using our X pointer we swap the elements
        myArray[i] = myArray[j];
        myArray[j] = temp;

    }
}
