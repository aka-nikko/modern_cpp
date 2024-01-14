#include<iostream>
#include<functional>
#include<vector>

/*
    Scenario 01:
    Normally people take raw reference of a variable through =
    eg. int n1=10;
        int& ref=n1;  // = assignment
        int& ref{n1}

        std::reference_wrapper<int> ref=n1;
        std::reference_wrapper<int> ref{n1};
*/

/*
    &n1 will print the address of reference container.
    Use get() function to get the address of reference to data
*/
void Magic(std::reference_wrapper<int> ref){
    std::cout<<"Address of ref: "<<&(ref.get())<<std::endl;

    std::vector<std::reference_wrapper<int>> v1{ref};
    std::cout<<"Address of ref: "<<&(v1.at(0).get())<<std::endl;
    /*
        Taking reference of something which is already
        a reference creates akternate name for original data
    */
    int& temp=ref;  //temp takes reference of ref (which is already reference)
                    //temp should now refer to original data n1.
}

int main(){
    int n1=10;
    std::cout<<"Address of n1: "<<&n1<<std::endl;
    Magic(n1);

    return 0;
}