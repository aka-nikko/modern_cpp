#include"CabRide.h"

CabRide::CabRide(std::variant<int,std::string> id, CabRideType type, 
                PaymentMode mode, float fare, std::string drop_location, 
                std::string pickup_location):
    _id(std::move(id)), _type(type), _mode(mode), _fare(fare) {
        if(drop_location.length()<11){
            _drop_location=drop_location;
        }else{
            std::cout<<"Drop Location Should Be Less Than 10 Characters"<<std::endl;
        }
        if(pickup_location.length()<11){
            _pickup_location=pickup_location;
        }else{
            std::cout<<"Pickup Location Should Be Less Than 10 Characters"<<std::endl;
        }
    }

std::ostream &operator<<(std::ostream &os, const CabRide &rhs) {
    os << "_id: "// << rhs._id
       << " _type: " << static_cast<int>(rhs._type)
       << " _mode: " << static_cast<int>(rhs._mode)
       << " _fare: " << rhs._fare
       << " _drop_location: " << rhs._drop_location
       << " _pickup_location: " << rhs._pickup_location;
    return os;
}
