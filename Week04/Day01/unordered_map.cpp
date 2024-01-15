#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap{
        {101, "temp1"},
        {102, "temp2"}
    };

    std::cout<<"Employee with ID 101: "<<umap[101]<<std::endl;
    
    umap[103] = "temp3";
    umap.insert(std::make_pair(104, "temp4"));
    umap.insert_or_assign(102, "Name");

    for(auto& map : umap){
        std::cout<<map.first<<" : "<<map.second<<std::endl;
    }
    return 0;
}
