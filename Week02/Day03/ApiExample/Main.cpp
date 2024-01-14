#include"ApiCaller.h"

int main(){
    std::string _end_point="https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR";
    
    auto _api_ptr = std::make_shared<ApiCaller>(_end_point);

    _api_ptr->ExecuteApiCall();

    std::cout<<"API Endpoint:\n";
    std::cout<<_api_ptr->endPoint()<<std::endl;

    std::cout<<"API Response:\n";
    std::cout<<_api_ptr->response()->responseString()<<std::endl;

    std::cout<<"Status Code : ";
    std::cout<<_api_ptr->response()->responseStatusCode()<<std::endl;

    std::cout<<"Elasped Time: ";
    std::cout<<_api_ptr->response()->elapsedTimeSinceExecution()<<std::endl;

}