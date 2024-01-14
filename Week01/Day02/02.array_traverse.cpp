#include<iostream>

/*
    0x400
    0x401               10
    0x402
    0x403

    0x404
    0x405               20
    0x406
    0x407

    0x408
    0x409               30
    0x40a
    0x40b
*/

/*
    pass an array of integers
    print all integers in the array
*/
void magic(int* arr, int size){
    for(int i=0;i<size;i++){
        /*
            *(arr+i) allows compiler to
            jump into a memory location
            starting from an offset of 'i' positions
            from the base address stored in "arr"
        */
        *(arr+i);
    }
}

int main(){
    /*
        to go u location
        take the base address, add (size)*i
        eg.
           0x400H + (4 * 2) = 0x408H
    */
    int arr[3]={10, 20, 30};
    return 0;
}