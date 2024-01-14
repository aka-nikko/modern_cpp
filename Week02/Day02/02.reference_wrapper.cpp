#include<iostream>
#include<vector>

int main(){
    int n1=10;
    int& ref1=n1;

    /*
        arr is an array of size 1
        arr can store integer lvalue reference

        arr is an arrat of 1 integer lavlue reference
    */
    //We cannot store references into a container
    // int& arr[1]{ref1};
    // std::vector<int&> v1{ref1};

    //If we create a reference of a reference, we end up creating
    //reference of the original data.
    // int& ref2=ref1;
    return 0;
}

/*
    1. References physically dont exist!
        -they have no storage (no memory allocated)
        - they won't have their own address
    2. References cannot be put in a container.
    3. Reference of a reference does not work as intended.
*/