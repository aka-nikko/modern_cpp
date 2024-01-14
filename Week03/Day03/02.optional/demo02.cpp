#include<iostream>
#include<vector>
#include<optional>

void TakeInput(std::vector<int>& data,int N){
    int val=-1;

    for(int i=0;i<N;i++){
        std::cin>>val;
        data[i]=val;
    }
}

/*
    Identify even numbers from data. Store all of them in result
    return result

    Scenario 1: There is at least 1 even number in data
                You identify the number/s. store in result

    Scenario 2: Data is empty.
                Handle by raising exception.

    Scenario 3: Data is not empty. However, all numbers are ODD.
*/

//ReturnEvenNumber may or may not return a value
//A vector of integers as a return value from this function is optional
std::optional<std::vector<int>> ReturnEvenNumbers(std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("Data Empty");
    }

    std::vector<int> result;
    for(int v:data){
        if(v%2==0){
            result.push_back(v);
        }
    }
    if(result.empty()){
        return std::nullopt; //nullopt is a symbol to indicate no value
    }else return result;
}

int main(){
    int N=-1;

    std::cin>>N;

    std::vector<int> v1(N); //Space for N intergers is now reserved on the heap

    std::vector<int> data;

    TakeInput(v1,N);
    
    std::optional<std::vector<int>> even_numbers = ReturnEvenNumbers(v1);
    
    /*
        has_value returns false if optional wrapper contains nulopt
        has_value returns true if valid value found in optional
    */
    if(even_numbers.has_value()){
        /*
            we only come inside if when has_value returns true
            i.e. valid value is present
            i.e. container of even numbers is found in optional
        */
        std::cout<<even_numbers.value().size()<<std::endl;
    }
    
    return 0;
}