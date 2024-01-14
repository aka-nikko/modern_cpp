#ifndef NORESPONSE_H
#define NORESPONSE_H

#include<iostream>

class NoResponse: public std::exception{
    private:
        char* _error_msg = nullptr;
    
    public:
        NoResponse()=delete;
        NoResponse(const NoResponse&)=delete;
        NoResponse(NoResponse&&)=delete;
        NoResponse& operator=(const NoResponse&)=delete;
        NoResponse& operator=(NoResponse&&)=delete;
        
        NoResponse(char* msg): _error_msg(msg){};

        const char* what() const noexcept{
            return _error_msg;
        }

        ~NoResponse()=default;
};


#endif // NORESPONSE_H
