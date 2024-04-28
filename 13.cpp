
#include <iostream>

int main() {
    int num = 2;
    switch (num) {
        case 1:
            std::cout << "Number is 1" << std::endl;
        case 2:
            std::cout << "Number is 2" << std::endl;
        case 3:
            std::cout << "Number is 3" << std::endl;
            break;
        default:
            std::cout << "Number is not 1, 2, or 3" << std::endl;
    }
    return 0;
}