#include <iostream>
#include <string>

/*
symbol  value
I       1
IV      4
V       5
IX      9
X       10
XL      40
L       50
XC      90
C       100
CD      400
D       500
CM      900
M       1000
*/



int main() {
    int num = 3998;
    std::string s = "";
    while(num != 0) {
        switch (num) {
        case 1000 ... 4000:
            s += "M";
            num -= 1000;
            break;
        case 900 ... 999:
            s += "CM";
            num -= 900;
            break;
        case 500 ... 899:
            s += "D";
            num -= 500;
            break;
        case 400 ... 499:
            s += "CD";
            num -= 400;
            break;
        case 100 ... 399:
            s += "C";
            num -= 100;
            break;
        case 90 ... 99:
            s += "XC";
            num -= 90;
            break;
        case 50 ... 89:
            s += "L";
            num -= 50;
            break;
        case 40 ... 49:
            s += "XL";
            num -= 40;
            break;
        case 10 ... 39:
            s += "X";
            num -= 10;
            break;
        case 9:
            s += "IX";
            num -= 9;
            break;
        case 5 ... 8:
            s += "V";
            num -= 5;
            break;
        case 4:
            s += "IV";
            num -= 4;
            break;
        case 1 ... 3:
            s += "I";
            num -= 1;
            break;
        default:
            break;
        }
    }
    std::cout << s;
    

    return 0;
}