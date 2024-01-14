#include"Functionalities.h"
#include<memory>
#include<vector>
#include"Vehicle.h"

int main(){
    Container mydata;
    CreateObjects(mydata);
    DisplayObjects(mydata);
    
    // for(const auto& vehicle:mydata){
    //     vehicle->CalculateRegistrationCharge();
    // }
    
    return 0;
}