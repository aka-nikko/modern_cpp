#include"Functionalities.h"

std::function<std::string(std::string&)> findNonVowels=[](std::string& str) {
    std::string result;
    for(char ch : str){
        char lowerCh=std::tolower(ch);
        if(!(lowerCh=='a'||lowerCh=='e'||lowerCh=='i'||lowerCh=='o'||lowerCh=='u')){
            result.push_back(ch);
        }
    }
    return result;
};

std::function<int(std::vector<int>&)> sumOfOddNumbers=[](std::vector<int>& numbers){
    int sum=0;
    for(int num : numbers){
        if(num%2!=0) {
            sum+=num;
        }
    }
    return sum;
};

std::function<float(std::vector<int>&)> averageOfEvenNumbers=[](std::vector<int>& numbers){
    float sum=0;
    int count=0;

    for(int num : numbers){
        if(num%2==0){
            sum+=num;
            count++;
        }
    }

    if(count==0) {
        throw std::runtime_error("No even numbers in the list.");
    }

    return sum/count;
};

std::function<float(std::vector<int>&)> sumOfSquareOfEvenNumbers=[](std::vector<int>& numbers){
    float sumSquare=0;

    for (int num : numbers) {
        if(num%2==0){
            sumSquare=sumSquare+(num*num);
        }
    }

    return sumSquare;
};

std::function<std::vector<int>(int)> numbersDivisibleBySeven=[](int n){
    if (n <= 0) {
        throw std::runtime_error("Invalid input. Please enter a positive number.");
    }

    std::vector<int> result;
    int num;

    std::cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        if (num % 7 == 0) {
            result.push_back(num);
        }
    }

    return result;
};