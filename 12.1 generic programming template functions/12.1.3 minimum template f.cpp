#include <iostream>
#include <string>
#include <vector>

template<typename T>
int find_minimum(const std::vector<T>& vin){

    if (vin.size() < 1){
        std::cout << "error vector size less than 1" << std::endl;
        EXIT_FAILURE;
    }

    if (vin.size() == 1){
        return vin[0];
    }

    T minimum = vin[0];

    for (int i = 0; i < vin.size(); i++){
        if (vin[i] < minimum){
            minimum = vin[i];
        }
    }

    return minimum;
}


int main(){
    
}