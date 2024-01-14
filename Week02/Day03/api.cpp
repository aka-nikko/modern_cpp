#include<iostream>
#include<string>
#include<curl/curl.h>


size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

int main(){
    std::string API = "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR";
    
    //Initialize curl session object
    auto curl = curl_easy_init();

    //If object was initialized correctly
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, API.c_str());
        
        //tring Object to Store Responce Data
        std::string response_string{""};

        //API calls also send header parameters
        //(Not applicable in this example coz we are not modifying anythong)
        std::string header_string{""};

        /*
            We need a function that can read response received and write
            it (byte-to-byte) into response_string variable.
            This function (writeFunction) is defined above.
        */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);

        /*
            Specify where the data has to be written (address of response_string)
        */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        /*
            Specify where header data comes from (location of response_string)
        */
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
        
        /*
            Store response code after execution of api call in this variable
        */
        long response_code{0};

        /*
            Time taken for API call to complete
        */
        double elapsed{0.0};

        /*
            After all setting above, finally execute cul
            with all options provided
        */
        curl_easy_perform(curl);

        /*
            Gather info on response code, store it in response_code variable
            Similarly, we store elasped time in respective variable
        */
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);

        /*
            Clean up the session.
            Reset everything before next request is to be made
        */
        curl_easy_cleanup(curl);

        //Session can be terminated by setting curl session object to NULL
        curl = nullptr;

        std::cout<<"Response Code: "<<response_code<<std::endl;
        std::cout<<"Response Time: "<<elapsed<<std::endl;
        std::cout<<"Response     : "<<response_string<<std::endl;
    }
}