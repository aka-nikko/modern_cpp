#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

template<typename T>

void Display(T& container){
    for(auto& val : container){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<int> v1{10,20,30};
    std::vector<int> result(v1.size());
    
    //Example 01: Copy all elements unconditionally from source to dest.
    std::copy(v1.begin(), v1.end(), result.begin());

    //Example 02: Sum of all values.
    std::cout<<"Total is: "<<std::accumulate(v1.begin(), v1.end(), 0)<<std::endl;


    std::cout<<"Product is: "<<
        std::accumulate(v1.begin(), v1.end(), 1, 
            [](int total, int val){
                return total*val;
            }
        )<<std::endl;
    return 0;
}