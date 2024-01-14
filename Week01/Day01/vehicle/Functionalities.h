#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"Vehicle.h"

/*
    Accept a Pointer to an Array of Pointers.
    Initialize Objects on Heap.
    Store their Addresses in the Array.
*/
void CreateObjects(Vehicle** arr, const int size);

/*
    Loop over Instances.
    Calculate total price and divide it by number of Instances.
*/
float AveragePrice(Vehicle** arr, const int size);


/*
    Return _id of Vehicle with Lowest Price
*/
int LowestPriceId(Vehicle** arr, const int size);

#endif // FUNCTIONALITIES_H
