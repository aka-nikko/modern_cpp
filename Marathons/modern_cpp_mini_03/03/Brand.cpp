#include"Brand.h"

Brand::Brand(BrandType type, std::string unique_tm, std::array<std::shared_ptr<Car>,3> cars):
    _type(type), _unique_tm(unique_tm) {
        for(int i=0;i<3;i++){
            _cars[i]=cars[i];
        }
    }

std::ostream &operator<<(std::ostream &os, const Brand &rhs) {
    os << "_type: " << static_cast<int>(rhs._type)
       << " _unique_tm: " << rhs._unique_tm
       << " _cars: ";
       for(auto& car : rhs._cars){
        os<<car;
       }
    return os;
}

