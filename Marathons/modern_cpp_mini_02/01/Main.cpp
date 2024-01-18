#include"Functionalities.h"

int main() {
    //String Variable
    std::string userString="Hello World";

    //Call Lambda Function to Find Non Vowel Characters
    std::string nonVowels=findNonVowels(userString);

    //Display Result
    std::cout<<"Non Vowel Characters: "<<nonVowels<<std::endl;




    //Input Numbers Container
    std::vector<int> numbers{1,2,3,4,5};

    //Call Lambda Function to Find the Sum of Odd Numbers
    int oddSum = sumOfOddNumbers(numbers);

    //Display Result
    std::cout << "Sum of Odd Numbers: "<<oddSum<<std::endl;




    try{
        // Call the lambda function to find the average of even numbers
        double evenAverage = averageOfEvenNumbers(numbers);

        // Display the result
        if (evenAverage != 0.0) {
            std::cout << "Average of even numbers in the list: " << evenAverage << std::endl;
        } else {
            std::cout << "No even numbers in the list." << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };




    // Call the lambda function to get the square of even numbers
    float squareOfEvens = sumOfSquareOfEvenNumbers(numbers);

    //Display the result
    std::cout << "Sub of Squares of Even Numbers: "<< squareOfEvens << std::endl;



    try{
        int n;
        // Get the number of integers from the user
        std::cout << "Enter the number of integers: ";
        std::cin >> n;

        // Call the lambda function to get numbers divisible by 7
        std::vector<int> divisibleBySeven = numbersDivisibleBySeven(n);

        // Display the result
        if (!divisibleBySeven.empty()) {
            std::cout << "Numbers divisible by 7: ";
            for (int num : divisibleBySeven) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No numbers divisible by 7 in the input." << std::endl;
        }
    }catch(std::runtime_error msg){
        std::cout<<msg.what();
    };
    

    return 0;
}
