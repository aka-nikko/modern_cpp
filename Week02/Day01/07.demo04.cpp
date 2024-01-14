#include<iostream>
#include<functional>
#include<vector>
#include<memory>

using INT_VECTOR=std::vector<int>;
using FUNC_VECTOR=std::vector<std::function<void(int)>>;

//Main Class for Operations
class Operations{
    private:
        INT_VECTOR _data;
        FUNC_VECTOR _function;

    public:
        Operations(INT_VECTOR&& data, FUNC_VECTOR&& function):
            _data(data), _function(function){}

        //Paran-Paran operator() overloaded to perform operations
        void operator()(){
            for(const auto& fn : _function){
                for(const int n : _data){
                    fn(n);
                }
            }
        }
        
        //Destructor
        ~Operations()=default;
};

using DataPointer=std::shared_ptr<Operations>;
using DataContainer=std::vector<DataPointer>;

//Function to create object
void CreateObjects(DataContainer& data){
    data.emplace_back(
        std::make_shared<Operations>(
            INT_VECTOR{10,20,30},
            FUNC_VECTOR{
                [](int number){std::cout<<number*number<<std::endl;},
                [](int number){std::cout<<number*number*number<<std::endl;},
                [](int number){std::cout<<number*100<<std::endl;}
            }
        )
    );
}

//Function to apply operations using overloaded () operator
void ApplyOperations(DataContainer& data){
    for(const auto& op : data){
        (*op)();
    }
}

//Main Function
int main(){
    DataContainer data;
    CreateObjects(data);
    ApplyOperations(data);
    return 0;
}