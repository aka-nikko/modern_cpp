#include<iostream>

class MyClass{
    private:
        int _id;

    public:
        //Default Constructor
        MyClass()=default;

        //Parameterized Constructor
        MyClass(int id):_id(id){}

        //Copy Constructor
        MyClass(const MyClass&){};

        //Copy Assignment Operator
        MyClass& operator=(const MyClass&)=default;

        //Move Constructor
        MyClass(MyClass&&)=default;

        //Move Assignment Operator
        MyClass& operator=(MyClass&&)=default;

        //Destructor
        ~MyClass()=default;

        //Getter Functions

        //Stream Output Operator
};

//Step 04: Signature is matched and Magic is invoked.
MyClass Magic(MyClass& obj){
    //Step 05: temp object is instantiated by Copy Constructor
    MyClass temp(obj);

    //Step 06: Address of temp is printed
    std::cout<<"Address of temp      : "<<&temp<<std::endl;

    //Step 07: temp is returned by value
    return temp;
}

int main(){
    //Step 01: Object gets Instantiated.
    MyClass obj(100);
    //Step 02: Address is printed (obj is in the stack of main function).
    std::cout<<"Address of obj       : "<<&obj<<std::endl;

    //Step 03: Call Magic function. Whatever is return will be saved in return_obj.
    /*
        return_obj is variable which is assigned the return value of Magic
    */
    MyClass return_obj = Magic(obj);
    //Final Step: 
    std::cout<<"Address of return_obj: "<<&return_obj<<std::endl;

    return 0;
}