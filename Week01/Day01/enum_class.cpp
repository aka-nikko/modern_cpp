#include<iostream>

enum class Rank{
    FIRST,
    SECOND,
    THIRD
};

enum class Gear{
    FIRST,
    SECOND,
    THIRD
};

void Magic(int data){

}

int main(){
    enum Rank r1=Rank::FIRST;
    enum Gear g1=Gear::FIRST;

    //Should not be true since we are comparing two enums.
    if(r1==g1){
        std::cout<<"OOPS!!\n";
    }

    //Should not work since we are passing enum.
    Magic(r1);

    return 0;
}