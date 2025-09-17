#include "../include/numb_func.h"

std::string numb_func(std::string n){
    std::string new_line;
    int asc0 = static_cast<int>('0');
    int asc9 = static_cast<int>('9');
    for (char current_symbol : n){
        int ascii = static_cast<int>(current_symbol);
        if ( ascii >= asc0 & ascii <= asc9 ){
            new_line += current_symbol;
            
        }
    }
 

    return new_line;
}