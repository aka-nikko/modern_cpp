#ifndef APICALLER_H
#define APICALLER_H

#include<iostream>
#include<curl/curl.h>
#include<memory>
#include"Response.h"

class ApiCaller{
    private:
        CURL* _curl_session_object_handle{nullptr};
        std::string _end_point{""};
        std::string _request_header{""};
        std::shared_ptr<Response> _response{nullptr};

    public:
        ApiCaller(std::string url);
        ApiCaller(std::string url, std::string header);

        ApiCaller()=delete;
        ApiCaller(const ApiCaller&)=delete;
        ApiCaller(ApiCaller&&)=delete;
        ApiCaller& operator=(const ApiCaller&)=delete;
        ApiCaller& operator=(ApiCaller&&)=delete;
        ~ApiCaller()=default;        
        
        void ExecuteApiCall();

        std::shared_ptr<Response> response() const { return _response; }

        std::string endPoint() const { return _end_point; }

        friend std::ostream &operator<<(std::ostream &os, const ApiCaller &rhs);

};


#endif // APICALLER_H
