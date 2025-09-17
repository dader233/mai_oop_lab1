#include <iostream>
#include <string>
#include "include/numb_func.h"

int main(){
    std::string line;
    std::cout << "Введите текст(строку букв и цифр)" <<std::endl;
    std::cin >> line;
    std::cout<<std::endl;
    std::string answer = numb_func(line);
    std::cout << "Ответ: " << answer << std::endl;
    return 0;
}