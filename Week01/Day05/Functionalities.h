#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<memory>
#include<vector>
#include"Customer.h"

using Pointer  = std::shared_ptr<Customer>;
using Container= std::vector<Pointer>;

/*
    Function to create Objects of Type Customer
*/
void CreateObjects(Container& data) noexcept;


/*
    Function to find average age of all customer
*/
float AverageAge(const Container& data) noexcept(false);


/*
    Function to return the Nth object from the container
*/
Pointer NthCustomer(const Container& data, int N);


/*
    Function to find the age of customer whose id is provided
    as a parameter.
*/
int AgeOfGivenCustomerID(const Container& data, const int id);


/*
    Function to find the cvv number of debit card for customer whose
    ID is provided as a parameter
*/
int CVVOfGivenCustomerID(const Container& data, const int id);


/*
    Function to return the expiry date of debit card whose cvv number
    matches with the value given by user.
*/
std::string ExpiryOfGivenCardCVV(const Container& data, const int cvv);


/*
    Function to return a container of all "Pointers" which point to customer
    with age above 50
*/
Container CustomersAgeAbove50(const Container& data);


/*
    Function to return the debitcard pointer for a customer whose
    ID is given as input parameter.
*/
std::shared_ptr<DebitCard> CardOfGivenID(const Container& data, const int id);


/*
    Function to display all data in container.
*/
void DisplayObjects(const Container& data);

#endif // FUNCTIONALITIES_H
