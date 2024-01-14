#include<iostream>
#include<array>

int main(){
    std::array<int, 3> arr1;
    arr1[0]=100;
    arr1[1]=200;
    arr1[2]=300;

    for(int i=0;i<3;i++){
        arr1[i]=(i+1)*100;
    }

    //Print Array
    for(int val:arr1){
        std::cout<<val<<std::endl;
    }

    //Size
    std::cout<<"Size of Array: "<<arr1.size()<<std::endl;

    //First Element
    std::cout<<"First Element: "<<arr1.front()<<std::endl;

    //Last Element
    std::cout<<"Last Element : "<<arr1.back()<<std::endl;

    //arr2d is an array of size 3 where each element 
    //is also an array of size 2
    int arr2[3][2]{
        {70, 30},
        {40, 50},
        {60, 70}
    };

    /*
        An array contains 3 elemtns (3 rows)
        Each element of this array (each row) is itself
        an array of 2 integers
    */
    std::array<std::array<int, 2>, 3> arr2d{
        std::array<int,2>{70, 30},
        std::array<int,2>{40, 50},
        std::array<int,2>{60, 70}
    };

    //Display
    for(std::array<int,2>& row:arr2d){
        for(int element:row){
            std::cout<<element<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}