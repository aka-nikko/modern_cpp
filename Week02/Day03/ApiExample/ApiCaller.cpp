#include"ApiCaller.h"

size_t WriteCallBack(void* ptr, size_t size, size_t nmemb, std::string* data){
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

/*
    Constructor That Takes only URL
    Maps URL and Initialize Session
*/
ApiCaller::ApiCaller(std::string url):
    _curl_session_object_handle(curl_easy_init()), _end_point(url),
    _response{std::make_shared<Response>()}{}

/*
    Constructor That Takes URL and Header Params
    Uses delegation to call Constructor above and assign header to _request_header
*/
ApiCaller::ApiCaller(std::string url, std::string header): ApiCaller(url){
    _request_header=header;
}

void ApiCaller::ExecuteApiCall(){
    curl_easy_setopt(_curl_session_object_handle, CURLOPT_URL, _end_point.c_str());

    /*
        We need a function that can read response received and write
        it (byte-to-byte) into response_string variable.
        This function (writeFunction) is defined above.
    */
    curl_easy_setopt(
        _curl_session_object_handle, 
        CURLOPT_WRITEFUNCTION, 
        +[](void* ptr, size_t size, size_t nmemb, std::string* data){
            data->append((char*)ptr, size * nmemb);
            return size * nmemb;
        }
    );

    /*
        Specify where the data has to be written (address of response_string)
    */
    curl_easy_setopt(
        _curl_session_object_handle, 
        CURLOPT_WRITEDATA, 
        &(_response->responseString())
    );

    /*
        Specify where header data comes from (location of response_string)
    */
    curl_easy_setopt(
        _curl_session_object_handle, 
        CURLOPT_HEADERDATA, 
        &_request_header
    );

    curl_easy_perform(_curl_session_object_handle);

    /*
            Gather info on response code, store it in response_code variable
            Similarly, we store elasped time in respective variable
        */
    curl_easy_getinfo(
        _curl_session_object_handle, 
        CURLINFO_RESPONSE_CODE, 
        &_response->responseStatusCode()
    );

    curl_easy_getinfo(
        _curl_session_object_handle, 
        CURLINFO_TOTAL_TIME, 
        &_response->elapsedTimeSinceExecution()
    );
}

std::ostream &operator<<(std::ostream &os, const ApiCaller &rhs) {
    os << "_end_point: " << rhs._end_point
       << " _response: " << rhs._response;
    return os;
}
